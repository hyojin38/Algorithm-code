// 5567 결혼식
// 20210112
// hyojin

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define endl "\n"
#define MAX 1000
int N,M,Answer;
int Map[MAX][MAX];
int check[MAX];
queue<pair<int,int>> Q;


void Solution() {
	for (int i = 1; i <= N; i++) {
		if (Map[1][i] == 1) {
			Q.push(make_pair(i, 1));
			check[i] = 1;
		}
	}
	while (Q.empty()==false) {
		int frend = Q.front().first;
		int cnt = Q.front().second;
	
		Q.pop();
		Answer++;

		if (cnt == 1) {
			for (int i = 2; i <= N; i++) {
				if (Map[frend][i] == 1) {
					if (check[i] == 1) {
						continue;
					}
					else {
						Q.push(make_pair(i, cnt + 1));
						check[i] = 1;
					}

				}
			}

		}

	}
}
void init() {
	for (int i = 0; i < MAX; i++) {
		memset(Map[i], 0, sizeof(Map[i]));
	}
	memset(check, 0, sizeof(check));
	check[1] = 1;
	Answer = 0;
}
void input() {
	cin >> N; //동기 수
	cin >> M;
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		Map[x][y] = 1;
		Map[y][x] = 1;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("Text.txt", "r", stdin);

	init();
	input();
	Solution();
	cout << Answer;

	return 0;
}