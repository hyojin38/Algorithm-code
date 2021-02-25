//주의 일단 들어가면 방에 불을 킬 수 있는 스위치가 있음
// 스위치로 불을 키고
//불이 켜져 있으면 해당 방으로 옮겨 갈 수 있다
//질문은 총 켜지는 불의 갯수
#include<iostream>
#include<vector>
#include<queue>
#pragma warning(disable:4996)
#define endl "\n"
#define MAX 101

using namespace std;

int N, M, Ans;
struct Light {
	int x;
	int y;
};
int MAP[MAX][MAX];
bool visitedlight[MAX][MAX];
queue <pair<int, int> > Q;
queue <pair<int, int> > EQ;
vector<Light> ListMap[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void Input() {

	cin >> N >> M;

	int x, y, a, b; //a,b의 불을 켜는 스위치는 x,y에 있다
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> a >> b;
		Light linput = { a,b };
		ListMap[x][y].push_back(linput);
	}


}

void Qpush(int x, int y) {
	vector<Light> V = ListMap[x][y];
	for (int i = 0; i < V.size(); i++) {
		int cx = V[i].x;
		int cy = V[i].y;
		if (MAP[cx][cy] == 1 || visitedlight[cx][cy] == true) continue;
		//수정  visitedlight[cx][cy]==1 이면 Q에 들어가지 않음

		Q.push(make_pair(cx, cy));
		//cout << cx << "," << cy << endl;
		visitedlight[cx][cy] = true;
		Ans++;


	}

}
void bfs() {
	MAP[1][1] = 1;
	Qpush(1, 1);//1.1부터 출발하는 베시
	Ans++;// 첫번째 방에는 불이 켜져 있다
	visitedlight[1][1] = true;

	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		bool check = false;
		Q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
			if (MAP[nx][ny] == 0) continue;



			MAP[x][y] = 1;

			Qpush(x, y);
			for (int i = 0; i < EQ.size(); i++) {
				int cx = EQ.front().first;
				int cy = EQ.front().second;
				EQ.pop();
				Q.push(make_pair(cx, cy));
			}
			check = true;
		}
		if (!check) EQ.push(make_pair(x, y));

	}
}
void Solution() {
	bfs();//1,1부터 출발하는 베시
	cout << Ans;

}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);
	//Init();
	Input();
	Solution();
	return 0;
}