#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define MAX 1000+1
#define endl "\n"
using namespace std;

int H, W;
int MAP[MAX][MAX];
int visited[MAX][MAX];
int dx[] = { 0,1,1,1,0,-1,-1,-1 };
int dy[] = { 1,1,0,-1,-1,-1,0,1 };
queue<pair<int, int> > Q;
vector <pair <int, int> > V1; //존재하는 모래성
vector <pair <int, int> > V2;//무너짐
void Input() {
	cin >> H >> W;
	string temp;
	char chtemp;
	for (int i = 0; i < H; i++) {
		cin >> temp;
		for (int j = 0; j < W; j++) {
			chtemp = temp[j];
			if (chtemp == '.') {
				MAP[i][j] = 0;
				visited[i][j] = 1;
			}
			else {
				MAP[i][j] = chtemp - '0';
				V1.push_back({ i,j });
			}

		}
	}
}

void print() {
	cout << endl;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << MAP[i][j];
		}
		cout << endl;
	}

}
void getAdjacentSea() {
	//getAdfacentSea()
	for (int i = 0; i < V1.size(); i++) {
		int x = V1[i].first;
		int y = V1[i].second;
		int st = MAP[x][y];

		int stcnt = 0;
		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
			if (MAP[nx][ny] > 0) continue;
			stcnt++;
		}
		if (st <= stcnt) {
			Q.push({ x,y });//1.사라질 것들을 담음
			visited[x][y] = 1;
		}
	}
}
void Solution() {
	int cnt = 0;
	getAdjacentSea();
	//BFS();


	while (!Q.empty())
	{
		//파도에 부서진다
		int s = Q.size();
		queue<pair<int, int> > nQ;
		for (int i = 0; i < s; i++) {
			//사라질것들
			int x = Q.front().first;
			int y = Q.front().second;
			Q.pop();
			nQ.push({ x,y });
			MAP[x][y] = 0;//파도가 쳐서 사라짐

		}//Q는 비고 nQ에 담음

		while (!nQ.empty()) {

			int x2 = nQ.front().first;
			int y2 = nQ.front().second;
			nQ.pop();

			for (int k = 0; k < 8; k++) {
				int nx = x2 + dx[k];
				int ny = y2 + dy[k];

				if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
				if (MAP[nx][ny] == 0) continue;
				if (visited[nx][ny] == 1)continue;
				int kkcnt = 0;
				for (int kk = 0; kk < 8; kk++) {
					int nnx = nx + dx[kk];
					int nny = ny + dy[kk];

					if (nnx < 0 || nny < 0 || nnx >= H || nny >= W) continue;
					if (MAP[nnx][nny] > 0) continue;
					kkcnt++;
				}
				if (kkcnt >= MAP[nx][ny]) {
					Q.push({ nx,ny }); //다음 사라질 것들
					visited[nx][ny] = 1;
				}


			}

		}




		cnt++;//파도가 친다


	}

	cout << cnt;

}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen("Text.txt", "r", stdin);

	Input();
	Solution();

	return 0;
}