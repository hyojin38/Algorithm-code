#include <iostream>
#include <vector>
#include <queue>
#include<vector>
#define MAX 502
using namespace std;
bool visit[MAX] = { false };
vector<vector<int>> map(MAX);
void Solution();
int cnt = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("Text.txt", "r", stdin);


	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		map[u].push_back(v);
		map[v].push_back(u);
	}
	Solution();
	cout << cnt;
}
void Solution() {
	queue<int> q;
	visit[1] = true;
	q.push(1);
	for (int i = 0; i <= map[1].size(); i++) {
		int now = q.front();
		q.pop();
		for (int j = 0; j < map[now].size(); j++) {
			int next = map[now][j];//vector 2차원배열처럼 사용가능
			if (visit[next] == false) {
				visit[next] = true;
				q.push(next);
				cnt++;
			}
		}
	}
}