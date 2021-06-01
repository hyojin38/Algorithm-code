//방법2
#include <iostream>
#include <vector>
#include <stack>
#define MAX 2000000+5
#define endl "\n"

using namespace std;
vector <int> V;
int N;
int arr[MAX];
int arrsize;
int ans[MAX];

void Input() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		V.push_back(temp);

	}

}
int bSearch(int val, int first, int last)
{
	if (first > last) return first;

	int mid = (first + last) / 2;
	if (val == arr[mid])
		return mid;
	else if (val < arr[mid]) //입력이 작음
		return bSearch(val, first, mid - 1);
	else//입력이 더 큼
		return bSearch(val, mid + 1, last);
}
void Solution() {


	for (int i = 0; i < N; i++) {
		int idx = V[i];
		if (i == 0) {
			arr[i] = idx;
			arrsize = 1;
			ans[0] = 0;
		}
		else {
			int pos = bSearch(idx, 0, arrsize - 1);
			arr[pos] = idx;
			ans[i] = pos;
			//cout << pos;
			if (pos == arrsize) {
				arrsize++;

			}
		}

	}

	//cout << arrsize<<endl;
	int fcnt = arrsize - 1;
	stack <int> st;

	for (int i = V.size() - 1; i >= 0; i--) {
		if (ans[i] == fcnt) {
			st.push(V[i]);
			fcnt--;
		}
		if (fcnt < 0) {
			break;
		}
	}
	int stsize = st.size();
	cout << st.size() << endl;
	for (int i = 0; i < stsize; i++) {
		cout << st.top() << " ";
		st.pop();
	}



}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	Solution();
	return 0;
}