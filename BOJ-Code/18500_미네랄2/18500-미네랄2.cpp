#include<iostream>
#include<vector>
#include<queue>
#define MAX 101
using namespace std;
int R, C, N, x, y;;
int map[1][2];
int Map[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = {1,-1,0,0 };
bool visited[MAX][MAX];
vector<int> V;
void print() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
		
			cout << map[i][j];
		}
		cout << endl;
	}
}
void Input() {
	cin >> R >> C;
	char init;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> init;
			if (init == '.') {
				map[i][j] = 0;
			}
			else {
				map[i][j] = 1;
			}
			
		}
	
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		V.push_back(temp);
	}
	
}
bool Broke(int H) {
	
	for (int i = 0; i < C; i++) {
		if (Map[H][i] == 1) {
			Map[H][i] = 0;
			x = H;
			y = i;
			return true;
		}
	}
	return false;

}
void DropNext(int dx, int dy) {


	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
		if (Map[nx][ny] == 0) continue;
		if (visited[nx][ny] == true) continue;

		visited[nx][ny] = true;
		DropNext(nx, ny);

	}

}
void Drop() {
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < 4; i++) {
		int nx=x+dx[i];
		int ny=y+dy[i];
		if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
		if (Map[nx][ny] == 0) continue;
		if (visited[nx][ny] == true) continue;

		visited[nx][ny]=true;
		DropNext(nx, ny);

	}
}
void Solution() {
	for (int i = 0; i < N; i++) {
		int H;
		H = V[i];
		H = R - H ;
		//높이에 있는 것 부수기
		if (Broke(H)) {
			//떨어지게 하기
			Drop();
		}
		


	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);


	Input();
	Solution();
	return 0;
 }