#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#define MAX 101
using namespace std;
int R, C, N, x, y,checkN;
int map[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = {1,-1,0,0 };
int check[MAX][MAX];
bool visited[MAX][MAX];
vector<int> V;
vector <pair<int, int> > checkV;
vector <pair<int, int> > dropV;
void print() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if(map[i][j]==0)	cout <<'.';
			if (map[i][j] == 1)	cout << 'x';
		}
		cout << endl;
	}
	cout << endl;
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
bool Broke(int turn,int H) {
	if (turn % 2 == 0) {//->
		for (int i = 0; i < C; i++) {
			if (map[H][i] == 1) {
				map[H][i] = 0;
				x = H;
				y = i;
				return true;
			}
		}
		return false;
	}
	else {//<-
		for (int i = C; i >=0; i--) {
			if (map[H][i] == 1) {
				map[H][i] = 0;
				x = H;
				y = i;
				return true;
			}
		}
		return false;
	}


}
void DropNext(int px, int py) {//DFS
	for (int i = 0; i < 4; i++) {
		//cout << px << py;
		int nx = px + dx[i];
		int ny = py + dy[i];
		if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
		if (map[nx][ny] == 0) continue;
		if (visited[nx][ny] == true) continue;

		if (nx == R - 1) {
			checkN = 1;
		}
		visited[nx][ny] = true;
		checkV.push_back(make_pair(nx, ny));
		DropNext(nx, ny);

	}


}
void Drop() { //1붙어있음 //0 떨어짐
	
	memset(check, 0, sizeof(visited));
	memset(visited, false, sizeof(visited));
	dropV.clear();
	for (int i = 0; i < 4; i++) {
		checkN = -1;
		checkV.clear();
		int nx=x+dx[i];
		int ny=y+dy[i];
		if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
		if (map[nx][ny] == 0) continue;
		if (visited[nx][ny] == true) continue;

		checkV.push_back(make_pair(nx, ny));
		visited[nx][ny]=true;
		DropNext(nx, ny);
		if (checkN == -1) {
			for (int j = 0; j < checkV.size(); j++) {
				check[checkV[j].first][checkV[j].second] = -1;
				dropV.push_back(make_pair(checkV[j].first, checkV[j].second));
			}
		}
		else {
			for (int j = 0; j < checkV.size(); j++) {
				check[checkV[j].first][checkV[j].second] = 1;
			}
		}
	}

	if (dropV.size() != 0) {
		for (int j = 0; j < dropV.size(); j++) {
			int nx = dropV[j].first;
			int ny = dropV[j].second;
			map[nx][ny] = 0;
		}//지우기
		int down = 1;
		bool check = false;
		while (true) {//내리기
			for (int j = 0; j < dropV.size(); j++) {
				int nx = dropV[j].first;
				int ny = dropV[j].second;
				if (map[nx + down][ny] == 1 || (nx+down==R)) check = true;
			}
			if (check) {//그리기
				for (int j = 0; j < dropV.size(); j++) {
					int nx = dropV[j].first;
					int ny = dropV[j].second;
					map[nx + down-1][ny] = 1;
				}
				break;
			}
			else {
				down++;
			}
		}
	}	
	
}
void Solution() {
	for (int i = 0; i < N; i++) {
		int H;
		H = V[i];
		H = R - H ;
		//높이에 있는 것 부수기
		if (Broke(i,H)) {
		
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
	print();
	return 0;
 }