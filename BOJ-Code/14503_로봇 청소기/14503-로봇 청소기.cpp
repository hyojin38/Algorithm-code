#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define endl "\n"
#define MAX 50+1
using namespace std;
int N, M, Ans,R,C,D;
bool turnoff =false;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int MAP[MAX][MAX];
int visited[MAX][MAX];

queue <pair<pair<int, int>, int> > Q;
void Input() {

	cin >> N >> M;
	cin >> R >> C >> D;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}
}
void print() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << visited[i][j]<< " ";
		}
		cout << endl;
	}
}
void DFS(int x,int y, int d) {
        //0 북 1 동 2 남 3 서
		//1. 현위치 청소
		
		// 2.현방향 기준 왼쪽 부터 차례로 탐색
	int cnt = 0;
		for (int i = 3; i >=0; i--) {
			int ni = i + d;
			if (ni >= 4) ni -= 4;

			int nx = x + dx[ni];
			int ny = y + dy[ni];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (MAP[nx][ny] == 1) {
				cnt++;
				continue;
			}
			if (visited[nx][ny] != 0) {
				cnt++;
				continue;
			}
			Ans++;
			visited[nx][ny] = Ans;
			DFS(nx, ny, ni);
			if (turnoff == true) return;
		}
		if (cnt == 4) {
			int ni;
			if (d >= 2) ni = d - 2;
			else ni = d + 2; //후진
			int nx = x + dx[ni];
			int ny = y + dy[ni];
			if ((nx < 0 || ny < 0 || nx >= N || ny >= M) || (MAP[nx][ny] == 1)) {
				cout << Ans << endl;
				turnoff = true;
				return;
			}
			else DFS(nx, ny, d);
		}

}
void Solution() {
	Ans++;
	visited[R][C] = 1;
	DFS(R,C,D);
	//print();

}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);
	
	Input();
	Solution();
	return 0;

}