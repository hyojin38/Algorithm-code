#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#define MAX 20+1
#define endl "\n"
using namespace std;
int R, C, Ans;
int MAP[MAX][MAX];
bool check[28];//1~27
bool visited[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void Input() {
	cin >> R >> C;
	char input;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> input;
			MAP[i][j] = input - '0'-16;//알파벳을 숫자로 표기 1~26 //A:27 이므로
		
		}
	}
}
void DFS(int x, int y,int cnt) {

	if (cnt > Ans) {
		Ans = cnt;
		if (Ans == 26)
			return;
	}

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx < 1 || ny < 1 || nx > R || ny > C) continue;
		if (visited[nx][ny] == true) continue;
	
		if (check[MAP[nx][ny]] == true) continue;
		visited[nx][ny] = true;
		check[MAP[nx][ny]] = true;
	
		DFS(nx, ny, cnt + 1);
		visited[nx][ny] = false;
		check[MAP[nx][ny]] = false;

	}

}
void Solution() {

	check[MAP[1][1]] = true;
	visited[1][1] = true;
	DFS(1,1,1);

	cout << Ans;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	Solution();
	return 0;
}