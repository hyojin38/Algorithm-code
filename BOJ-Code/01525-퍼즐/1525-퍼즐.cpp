#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define endl "\n"
typedef long long ll;
using namespace std;

ll  Ans = 123456789;
ll Result;
map <ll, int> check;
queue <pair<ll,int> > Q;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void Input() {

	ll temp;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> temp;
			if (temp == 0) {
				temp = 9;
			}
			Result = Result * 10 + temp;
		}
	}
	//cout << Result;
	check.insert({ Result, 0 });
	Q.push({ Result,0 });
}
void Solution() {
	if (Ans == Result) {
		cout << 0; return;
	}
	while (!Q.empty()) {
		ll a = Q.front().first;
		int cnt = Q.front().second;
		Q.pop();
		string str_a = to_string(a);
		int idx = str_a.find('9');
		
		int x = idx / 3;
		int y = idx % 3;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || ny < 0 || nx >= 3 || ny >= 3) continue;

			int nidx = nx * 3 + ny;
			char nidx_num = str_a[nidx];
			string str_b = str_a;
			str_b[idx] = nidx_num;
			str_b[nidx] = '9';
			ll b = stoll(str_b);

			//중복체크 map
			if (check.count(b)==0) { //count 없으면 0 있으면 1

				if (b == Ans) {
					cout << cnt + 1;
					return;
				}
				check.insert({ b,0 });
				Q.push({ b,cnt + 1 });
			}
		}
	}

	cout << -1;
	return;
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	Solution();

	return 0;
}

