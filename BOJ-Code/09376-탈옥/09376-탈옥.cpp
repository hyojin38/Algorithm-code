#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define endl "\n"
#define MAX 100+1

using namespace std;

char MAP[MAX][MAX];
int h, w, Ans;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

vector <pair <int, int> > endV;
void Init() {
	Ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			MAP[i][j] = 0;
		}
	}
}
void Input() {
	cin >> h >> w;
	string temp;
	for (int i = 0; i < h; i++) {
		cin >> temp;
		for (int j = 0; j < w; j++) {
			MAP[i][j] = temp[j];
			if (i == 0 || j == 0 || i == h - 1 || j == w - 1) {
				if (MAP[i][j] != '*') {
					endV.push_back({ i,j });
				}
			}

			if (MAP[i][j] == '$') {

			}
			else if (MAP[i][j] == '#') {

			}
		}
	}
}
void print() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << MAP[i][j];
		}
		cout << endl;
	}
}
void DFS(int x, int y, bool visited[MAX][MAX], int cntdoor, int cntcatch) {

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
		if (MAP[nx][ny] == '*') continue;
		if (visited[nx][ny] == true) continue;

		if (MAP[nx][ny] == '.') {
			visited[nx][ny] = true;
			DFS(nx, ny, visited, cntdoor, cntcatch);
			visited[nx][ny] = false;
		}
		else if (MAP[nx][ny] == '#') {
			visited[nx][ny] = true;
			DFS(nx, ny, visited, cntdoor + 1, cntcatch);
			visited[nx][ny] = false;
		}
		else if (MAP[nx][ny] == '$') {
			visited[nx][ny] = true;
			cntcatch++;
			DFS(nx, ny, visited, cntdoor, cntcatch);
			visited[nx][ny] = false; 1
		}
	}


}
void Solution() {

	for (int i = 0; i < endV.size(); i++) {
		int ex = endV[i].first;
		int ey = endV[i].second;

		int cntdoor = 0;
		bool visited[MAX][MAX];
		int cntcatch = 0;
		if (MAP[ex][ey] == '#') {//巩老版快
			cntdoor++;
		}
		else if (MAP[ex][ey] == '$') {//了荐老 版快
			cntcatch++;
		}
		visited[ex][ey] = true;
		DFS(ex, ey, visited, cntdoor, cntcatch);

	}


}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	int TC;
	cin >> TC;
	for (int tc = 0; tc < TC; tc++) {
		Init();
		Input();
		Solution();
		//print();
		cout << Ans;

	}
	return 0;
}