#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define endl "\n"
#define MAX 101
using namespace std;
int W, H,Answer;
vector <pair<int, int>> P;//Point (시작지점 끝지점)
char Map[MAX][MAX];
int visited[MAX][MAX];
queue <pair< pair<int, int>,pair<int, int> >> Q; //x, y ,진행방향 ,놓은 거울의 갯수
int dx[4] = {0,0,1,-1};
int dy[4] = { 1,-1 ,0,0};

void Input() {
	cin >> W >> H; 
	char temp;
	for (int x = 0; x < H; x++) {
		for (int y = 0; y < W; y++) {
			cin >> temp;
			Map[x][y]=temp;
			visited[x][y] = 987654321; //초기화
			//cout << Map[x][y]<<" "<<visited[x][y];

			if (temp == 'C') {
				P.push_back(make_pair(x, y));
			}
			
		}
	//	cout << endl;
	}
}
void BFS() {

	int Sx = P[0].first;
	int Sy = P[0].second;
	int Ex = P[1].first;
	int Ey = P[1].second;

	for (int i = 0; i < 4; i++) {
		Q.push(make_pair(make_pair(Sx, Sy), make_pair(i, 0)));
	}
	visited[Sx][Sy] = 0;
	while (!Q.empty()) {
		int x = Q.front().first.first;
		int y= Q.front().first.second;
		int dir=  Q.front().second.first;
		int cnt = Q.front().second.second;

		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int ncnt;
			int ndir = i;

			if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
			if (Map[nx][ny] == '*') continue;
			if ((dir == 0 && ndir == 1) || (dir == 1 && ndir == 0) || (dir == 2 && ndir == 3) || (dir == 3 && ndir == 2)) continue;

			if (dir == ndir) ncnt = cnt;
			else if(dir != ndir) ncnt = cnt + 1;

			if (visited[nx][ny] >= ncnt) {
				visited[nx][ny] = ncnt;
				Q.push(make_pair(make_pair(nx, ny), make_pair(ndir, ncnt)));
			}
			
		}


	}
	
	cout << visited[Ex][Ey];
}
void Solution() {
	
	BFS();
	

}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);
	Input();
	Solution();
	return 0;
}
