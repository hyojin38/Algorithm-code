#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define endl "\n"

using namespace std;

int N,Answer;
vector<vector<int>> V;
void DFS(int x1, int y1, int x2, int y2);

void Input() {
	cin >> N;
	
	int temp;
	for (int i = 0; i < N; i++) {
		vector<int> v2;
		V.push_back(v2);
		for (int j = 0; j < N; j++) {
			cin >> temp;
			V[i].push_back(temp);//V[i]에 담겨있는 벡터에 temp입력
		}
	}
}
void right(int x, int y) {
	int nx = x;
	int ny = y + 1;
	if (ny >= N) return;
	if (V[nx][ny] == 1) return;

	DFS(x, y, nx, ny);
}
void cross(int x, int y) {
	int nx = x + 1;
	int ny = y + 1;
	if (ny >= N || nx >= N) return;
	if (V[nx][ny] == 1 || V[nx-1][ny] == 1|| V[nx][ny-1] == 1) return;

	DFS(x, y, nx, ny);
}
void down(int x, int y) {
	int nx = x + 1;
	int ny = y;
	if (nx >= N) return;
	if (V[nx][ny] == 1) return;

	DFS(x, y, nx, ny);
}
void DFS(int x1, int y1, int x2, int y2) {

	int type;//1 가로 2 세로 3 대각선
	if (x1 == x2 && y2 == y1 + 1) type = 1;
	else if (x1+1 == x2 && y2 == y1) type = 2;
	else if (x1 + 1 == x2 && y2 == y1 + 1) type = 3;

	if (x2 == N-1 && y2 == N-1) {
		Answer++;
		return;
	}
	
	if (type == 1) {
		right(x2,y2);
		cross(x2,y2);
	}
	else if (type == 2) {
		down(x2, y2);
		cross(x2, y2);
	}
	else {
		cross(x2, y2);
		down(x2, y2);
		right(x2, y2);
	}

	               

}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	freopen("Text.txt", "r", stdin);
	Input();
	DFS(0, 0, 0, 1);
	cout << Answer;
	return 0;
}