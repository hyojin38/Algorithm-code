#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#define endl "\n"
using namespace std;
char Map[12][6];
int visited[12][6];
int check,Answer;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector <pair<int, int>> V;
queue <pair<int, int>> Q;


void Input() {

	string s;
	for (int i = 0; i < 12; i++) {
		cin >> s;
		for (int j = 0; j < 6; j++) {
			Map[i][j] = s[j];
		}
	}
}
void print() {
	for (int i = 0; i < 12; i++) {
	
		for (int j = 0; j < 6; j++) {
			cout << Map[i][j];
		}
		cout << endl;
	}
}
void Break() {
		for (int i = 0; i < V.size(); i++) {
			int x = V[i].first;
			int y = V[i].second;
			//cout << x << y;
			int down = 0;
			for (int k = x - 1; k >= 0; k--) {

				if (Map[k][y] == '.') {
					if (down == 0) {
						Map[x][y] = '.';
					}break;
				}
				else {
					down++;
					//cout << Map[k][y];
					Map[k + 1][y] = Map[k][y];
					Map[k][y] = '.';
				}
			}
		}
		
	
}
void BFS(int x, int y) {

	while (Q.empty() == 0) {
		Q.pop();
	}
	vector <pair<int, int>> V2;
	Q.push(make_pair(x, y));
	V2.push_back(make_pair(x, y));
	int cnt = 1;
	while (Q.empty() == 0) {
		x = Q.front().first;
		y = Q.front().second;
		char color = Map[x][y];

		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			char ncolor = Map[nx][ny];
			
	
			if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
			if (Map[nx][ny] != color) continue;
			if (visited[nx][ny] == true) continue;
			
			visited[nx][ny] = true;
			Q.push(make_pair(nx, ny));
			cnt++;
			V2.push_back(make_pair(nx, ny));
		}

	}
	//cout << cnt;
	if (cnt >= 4) {
 
		for (int i = 0; i < V2.size(); i++) {
			V.push_back(make_pair(V2[i].first, V2[i].second));
		}
		check++;

	}
	V2.clear();

	
}
void Solution() {

	
	while (true) {
		V.clear();
		//2차원배열 초기화
		for (int i = 0; i < 12; i++) {
			memset(visited[i], false, sizeof(visited[i]));
		}
		
		check = 0;

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (Map[i][j] != '.'&&visited[i][j] == false) {
					visited[i][j] = true;
					BFS(i, j);
				}
			}
		}
		//cout << check<<endl;
		if (check > 0) {
			Answer++;
			Break();
			
		}
		else if(check==0) {
			cout << Answer;
			return;
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