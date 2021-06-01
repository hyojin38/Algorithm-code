//방법2
#include <iostream>
#include <vector>

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
		}
		else {
			int pos = bSearch(idx, 0, arrsize - 1);

			arr[pos] = idx;
			if (pos == arrsize) {
				arrsize++;

			}
		}

	}

	cout << arrsize << endl;



}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	Solution();
	return 0;
}