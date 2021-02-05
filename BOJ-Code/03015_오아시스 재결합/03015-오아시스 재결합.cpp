#include <iostream>
#include <stack>
using namespace std;
int N;
long long Ans;
void Solution() {
	Ans = 0;
	cin >> N;

	stack<pair<int, int>> st;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		pair <int, int> p = make_pair(temp, 1);
		
		int size=st.size();
		if (size== 0) {
			st.push(p);
		}
		else {
			for(int j=0;j< size;j++) {

				if (st.top().first < temp) {//2 vs 5
					//cout << st.top().first << "vs" << temp << "(" << st.top().second << ")" << endl;
					Ans += st.top().second;
					st.pop();
				}
				else if (st.top().first > temp) {
					Ans += 1; // p.secont (1) ���� ��ŭ ����
					//cout << st.top().first << "vs" << temp << "(2���� +1 )" << endl;
					break;//���̻� �ڷ� �� �ʿ䰡 ����
				}
				else {//st.top().first == temp
					Ans += st.top().second;
					p.second += st.top().second;
					st.pop();
					
				}
			}
			st.push(p);
		}
		

	}
	
	
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);
	Solution();
	cout << Ans;
	return 0;
}

