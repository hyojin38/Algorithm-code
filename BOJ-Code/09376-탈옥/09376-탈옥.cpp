#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define endl "\n"
#define MAX 100+1

using namespace std;

char MAP1[MAX][MAX];
char MAP2[MAX][MAX];

int h, w;
int Ans;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

vector <pair <int, int> > endV;
void Init() {
	Ans = -1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			MAP1[i][j] = 0;
			MAP2[i][j] = 0;
		}

	}

}
void Input() {
	cin >> h >> w;
	string temp;
	for (int i = 0; i < h; i++) {
		cin >> temp;
		for (int j = 0; j < w; j++) {
			MAP1[i][j] = temp[j];
			MAP2[i][j] = MAP1[i][j];

			if (i == 0 || j == 0 || i == h - 1 || j == w - 1) {
				if (MAP1[i][j] != '*') {
					endV.push_back({ i,j });
				}
			}

		}
	}

}
void print() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << MAP1[i][j];
		}
		cout << endl;
	}
}
void  DFS2(int x, int y, bool visited[MAX][MAX], int cntdoor, int cntcatch) {
	if (Ans != -1 && cntdoor > Ans) {
		return;
	}
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
		if (MAP2[nx][ny] == '*') continue;
		if (visited[nx][ny] == true) continue;

		if (MAP2[nx][ny] == '.') { //갈수 있다
			visited[nx][ny] = true;
			DFS2(nx, ny, visited, cntdoor, cntcatch);
			visited[nx][ny] = false;
		}
		else if (MAP1[nx][ny] == '#') { //문일경우
			visited[nx][ny] = true;
			MAP2[nx][ny] = '.';
			DFS2(nx, ny, visited, cntdoor + 1, cntcatch);
			visited[nx][ny] = false;
			MAP2[nx][ny] = '#';
		}
		else if (MAP1[nx][ny] == '$') {
			//cout <<" "<< cntdoor;
			if (Ans == -1) {
				Ans = cntdoor;
			}
			if (cntdoor < Ans) {
				//	cout << endl;
				Ans = cntdoor;
			}
			return;
		}
	}


}
void DFS(int x, int y, bool visited[MAX][MAX], int cntdoor, int cntcatch) {
	if (Ans != -1 && cntdoor > Ans) {
		return;
	}
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
		if (MAP1[nx][ny] == '*') continue;
		if (visited[nx][ny] == true) continue;

		if (MAP1[nx][ny] == '.') { //갈수 있다
			visited[nx][ny] = true;
			DFS(nx, ny, visited, cntdoor, cntcatch);
			visited[nx][ny] = false;
		}
		else if (MAP1[nx][ny] == '#') { //문일경우
			visited[nx][ny] = true;
			MAP2[nx][ny] = '.';
			DFS(nx, ny, visited, cntdoor + 1, cntcatch);
			visited[nx][ny] = false;
			MAP2[nx][ny] = '#';
		}
		else if (MAP1[nx][ny] == '$') {
			visited[nx][ny] = true;
			cntcatch++;
			//	cout << cntdoor << " 2번잡으러 " << endl;
			MAP2[nx][ny] = '.';
			//DFS(nx, ny, visited, cntdoor, cntcatch);
			bool visited2[MAX][MAX];

			DFS2(nx, ny, visited2, cntdoor, cntcatch);
			//	cout << endl"2번잡기 끝 "<<Ans << endl;
			MAP2[nx][ny] = '$';
			visited[nx][ny] = false;
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
		if (MAP1[ex][ey] == '#') {//문일경우
			cntdoor++;
		}

		if (MAP1[ex][ey] == '$') {//죄수일 경우
			cntcatch++;
			visited[ex][ey] = true;
			DFS2(ex, ey, visited, cntdoor, cntcatch);
		}
		else {
			visited[ex][ey] = true;
			DFS(ex, ey, visited, cntdoor, cntcatch);
		}


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
		cout << Ans << endl;


	}
	return 0;
}