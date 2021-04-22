#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define endl "\n"
#define MAX 12+2
using namespace std;

int T,Ans;
int Acorenum, Alinenum;
int coreNUM;
int N;
int MAP[MAX][MAX];
struct core
{
	int x, y;
};
vector<core> V;
bool Connect[12];
int dx[] = { 0,0,1,-1,0 };//동서남북정지
int dy[] = { 1,-1,0,0,0 };


void Init() {
	coreNUM = 0;
	Ans = 0;
	for (int i = 0; i <= MAX; i++) {
		for (int j = 0; j <= MAX; j++) {
			MAP[i][j] = 0;
		}
	}
	V.clear();
	memset(Connect, false, sizeof(Connect));
}
void print() {
	for (int i = 0; i <= N+1; i++) {
		for (int j = 0; j <= N+1; j++) {
			cout<< MAP[i][j];
		}
		cout << endl;
	}
}
void Input() {

	cin >> N;
	for (int i = 1; i <=N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 1) {
				//1. 가장자리에 위치한 코어는 이미 전원에 연결되어 있음
				if (i == 1 || i == N || j == 1 || j == N) {
					coreNUM++;
				}
				else {
					V.push_back({ i,j });
				}
			}
		}
	}

	/* 전원 표시 -1*/
	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= N + 1; j++) {
			if (i == 0 || j == 0 ||i ==N+1 ||j==N+1) {
				MAP[i][j] = -1;
			}
		}
	}

}
int cross(int cnum, int d) { // 전원 cnum번을 d 방향으로 연결한다
	
	int x = V[cnum].x;
	int y = V[cnum].y;
	int cnt = 0;

	while (true) {
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (MAP[nx][ny] == 0) {//빈칸- 계속진행
			x = nx;
			y = ny;
			cnt++;
		}
		else if (MAP[nx][ny] == 1 || MAP[nx][ny]==2) {//다른 코어 또는 전선 -진행 불가능
			return 0;
		}
		else if (MAP[nx][ny] == -1) { // 전원 - 도달
			//map에 표현
			for (int i = 1; i <= cnt; i++) {
				MAP[V[cnum].x + (dx[d] * i)][V[cnum].y + (dy[d] * i)]=2;
				
			}
		//	print();
			return cnt;
		}

	}
	

}
void Cut(int cnum, int d, int line) {

	int x = V[cnum].x;
	int y = V[cnum].y;
	for (int i = 1; i <= line; i++) {
		int nx = x + dx[d]*i;
		int ny = y + dy[d]*i;
		if (MAP[nx][ny] == 2) MAP[nx][ny] = 0;
	}

}
void DFS(int cnum,int linesum, int coresum ) {
	//가지치기해줘야한다
	if ((V.size() - cnum) + coresum < Acorenum) return;

	if (cnum ==V.size()) {
		if (Acorenum == 0 && Alinenum == 0) {//처음
			Acorenum = coresum;
			Alinenum = linesum;
		}
		else {
			if (Acorenum < coresum) { //더 많은 core 연결
				Acorenum = coresum;
				Alinenum = linesum;
			}
			else if (Acorenum == coresum && Alinenum > linesum) {
				Alinenum = linesum;
			}
		}
		return;
	}

	for (int d = 0; d < 5; d++) {
		int core = 0;
		int line =0;
		if (d != 5) {
			line = cross(cnum, d);
		}
		if (line >= 1) {//연결되었다
			Connect[cnum] = true;
			core = 1;
		 }
		DFS(cnum + 1, linesum + line, coresum + core);
		//연결끊기
		if (line >= 1) {
			Cut(cnum, d, line);
			Connect[cnum] = false;
		}
	}
}
void Solution() {
	Acorenum = 0;
	Alinenum = 0;
	DFS(0, 0, 0);//시작 코어 num	 //연결된 라인 길이 합	 // 연결된 코어 수 
	Acorenum += coreNUM;
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		
		Init();
		Input();
		//print();
		Solution();
		Ans = Alinenum;
		cout << "#" << tc << " " << Ans << endl;

	}
	

	return 0;

}