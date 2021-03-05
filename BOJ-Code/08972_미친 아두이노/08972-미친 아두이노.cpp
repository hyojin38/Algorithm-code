#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
#define MAX 100+1
#define endl "\n"

int R, C;
char MAP[MAX][MAX];
int RMAP[MAX][MAX];

int X, Y, Cnt;
bool Ans;
int dx[10] = { 0,1,1,1,0,0,0,-1,-1,-1 };
int dy[10] = { 0,-1,0,1,-1,0,1,-1,0,1 };
queue <pair<int, int> > Rlist;
queue <pair<int, int> > tmepRlist;
vector<int> MOVE;

void Print() {
	if (Ans == true) {
		cout << "kraj " << Cnt;//게임 끝나기 전까지 이동 횟수
	}
	else {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << MAP[i][j] ;
			}
			cout << endl;
		}
	}
}
void Input() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char temp;
			cin >> temp;
			MAP[i][j] = temp;
			if (temp == 'R') 		Rlist.push({ i,j });
			else if (temp == 'I') {
				X = i;
				Y = j;
			}
		}
	}
	string S;
	cin >> S;

	for (int i = 0; i < S.size(); i++) {
		MOVE.push_back(S[i] - '0');
	}
}
void Solution() {
	int t = MOVE.size();
	for (int i = 0; i < t; i++) {
		//1.종수 아두이노 이동 
		int k = MOVE[i];
		MAP[X][Y] = '.';
		X = X + dx[k];
		Y = Y + dy[k];
		Cnt++;
		//2. 보드 벗어나는 입력은 주어지지 않음. 아두이노 만나면 게임 종료
		if (MAP[X][Y] == 'R') {
			Ans = true;
			return;
		}
		MAP[X][Y] = 'I';


		//3.미친 아두이노 이동(8가지)
		for (int a = 0; a < R; a++) {
			for (int b = 0; b < C; b++) {
				RMAP[a][b] = 0;
			}
		}
		int Rlistsize = Rlist.size();
		while (!tmepRlist.empty()) {
			tmepRlist.pop();
		}

		//가장 가까워지는 칸
		for (int j = 0; j < Rlistsize; j++) {
			int rx = Rlist.front().first;
			int ry = Rlist.front().second;
			Rlist.pop();
			MAP[rx][ry] = '.';
			int nx, ny, result = 987654321;//후보 x,y,가장가까운 거리
			for (int k = 1; k < 10; k++) {
				if (k == 5) continue;
				int nrx = rx + dx[k];
				int nry = ry + dy[k];

				if (nrx < 0 || nry < 0 || nrx >= R || nry >= C) continue;
				int resulttemp = (abs(X - nrx) + abs(Y - nry));
				if (result > resulttemp) {
					result = resulttemp;
					nx = nrx;
					ny = nry;
				}
			}
			tmepRlist.push({ nx,ny });
			RMAP[nx][ny]++;
		}
		//위치 찍기
		for (int j = 0; j < Rlistsize; j++) {
			int rx = tmepRlist.front().first;
			int ry = tmepRlist.front().second;
			tmepRlist.pop();
			//미친 아두이노가 종수 칸으로 이동한 경우
			if (MAP[rx][ry] == 'I') {
				Ans = true;
				return;
			}
			//1개 아두이노 이동
			else if (RMAP[rx][ry] == 1 && MAP[rx][ry] == '.') {
				Rlist.push({ rx,ry });
				MAP[rx][ry] = 'R';
			}
			//2개 이상의 미친 아두이노가 같은 칸에 있는경우
			else if (RMAP[rx][ry] >= 2) {
				MAP[rx][ry] = '.';
			}



		}
		cout << Cnt << endl;
		Print();

	}


}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();

	Solution();
	Print();
	return 0;
}