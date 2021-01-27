#include<iostream>
#include <string>
#include <vector>
#include <queue>
#define endl "\n"
#define MAX 251
using namespace std;
int R, C,W,S;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int visited[MAX][MAX];
vector<vector<int>> Map;
queue<pair<int, int>> Q;
void Input() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string temp;
		cin >> temp;
		vector<int> M;
		Map.push_back(M);
		for (int j = 0; j < C; j++) {
			char ch = temp[j];
			if (ch == '.')		Map[i].push_back(0);
			else if (ch == '#') {
				Map[i].push_back(-1);
				visited[i][j] = 1;
			}
			else if (ch == 'v') Map[i].push_back(1);	//특대
			else if (ch == 'o') Map[i].push_back(2);  //양
			//cout << Map[i][j];
		}
		//cout << endl;
	}
}
void BFS(int x, int y) {
	
	int s = 0; //양
	int w = 0;	//늑대
	

	while (Q.empty() == 0) {
		
		x = Q.front().first;
		y = Q.front().second;
		Q.pop();
		if (Map[x][y] == 1) w++;
		else if (Map[x][y] == 2) s++;

		for (int i = 0; i < 4; i++) {

			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
			if (visited[nx][ny] == 1) continue;
			if (Map[nx][ny] == -1) continue;

			visited[nx][ny] = 1;
			Q.push(make_pair(nx, ny));

		}

	}

	if (w >= s) {
		W += w;
	}
	else {
		S += s;
	}

}
void Solution() {

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {

			if (Map[i][j] != -1 && visited[i][j] == 0) {
				visited[i][j] = 1;
				Q.push(make_pair(i, j));
				BFS(i,j);
			}
		}
	 }
	cout << S <<" "<< W;
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);
	Input();
	Solution();
	return 0;
}