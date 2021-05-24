#include<iostream>
#include<queue>
#include <vector>
#define MAX 35
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int MAP[MAX][MAX];
double Result;
int Rx = 15;
int Ry = 15;
double disMAP[4];
int N;
void Input() {
	cin >> N;
	double temp;
	for (int i = 0; i < 4; i++) {
		cin >> temp;
		disMAP[i] = temp / 100;

	}
}
void dfs(double ans, int cnt, int x, int y, bool visited[MAX][MAX]) {
	if (cnt == N) {
		Result += ans;
		return;
	}
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (visited[nx][ny] == true) continue;
		visited[nx][ny] = true;
		double nans = ans * disMAP[k];

		dfs(nans, cnt + 1, nx, ny, visited);
		visited[nx][ny] = false;
	}

}
void Solution() {
	bool visited[MAX][MAX];
	visited[Rx][Ry] = true;
	dfs(1, 0, Rx, Ry, visited);
	cout << fixed << Result;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout.precision(10);
	//freopen("Text.txt", "r", stdin);

	Input();
	Solution();


	return 0;
}