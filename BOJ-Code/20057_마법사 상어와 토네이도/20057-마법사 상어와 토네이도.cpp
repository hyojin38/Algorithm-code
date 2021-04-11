#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"
#define MAX 500+1

using namespace std;

int N, Ans,Cnt;
int MAP[MAX][MAX];
int Sx, Sy;
int dx[4] = { 0,1,0,-1};//<-. 아래,->,위 순서
int dy[4] = { -1,0,1,0};
int dp[6] = { 1,7,2,10,5,55 };

struct moveT{
	int x,y,nx,ny,d,cnt;
};
queue <moveT> Q;

void Input() {
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
		}
	}

}
int Tonado3(int tp, int d, int f, int x, int y) { // %만큼 반영
	int t = 0;
	for (int i = 0; i < 2; i++) {
		int nx = x + dx[d]*f;
		int ny = y + dy[d]*f;

		if (nx <= 0 || ny <= 0 || nx > N || ny > N) {
			nx = 0; ny = 0;
			MAP[nx][ny] += tp;
		}
		else {
			MAP[nx][ny] += tp;
			
		}
		t += tp;
		d += 2;
	}
	return t;
}
int Tonado4(int tp, int d, int f, int x, int y) { // %만큼 반영
	int t = 0;
	int nx = x + dx[d] * f;
	int ny = y + dy[d] * f;

	if (nx <= 0 || ny <= 0 || nx > N || ny > N) {
		nx = 0; ny = 0;
		MAP[nx][ny] += tp;
	}
	else {
		MAP[nx][ny] += tp;
	}
	t += tp;
	return t;
}
void Tonado5(int tp, int d, int f, int x, int y) { //알파만큼 반영
	int nx = x + dx[d] * f;
	int ny = y + dy[d] * f;

	if (nx <= 0 || ny <= 0 || nx > N || ny > N) {
		nx = 0; ny = 0;
		MAP[nx][ny] += tp;
	}
	else {
		MAP[nx][ny] += tp;
	}

}
void Tonado2(int x, int y, int nx, int ny,int d) {
	int t = MAP[nx][ny];
	double tp = (double)t / 100;
	int nd;
	if (d == 0 || d == 2) {
		nd = 1;
	}
	else if (d == 1 || d == 3) {
		nd = 0;
	}
	
	t-=Tonado3((int)(tp*1),nd,1,x,y);
	t-=Tonado3((int)(tp*2),nd,2,nx,ny);
	t-=Tonado3((int)(tp * 7), nd, 1, nx, ny);
	t-=Tonado3((int)(tp*10),nd,1,nx+dx[d],ny+dy[d]);
	t-=Tonado4((int)(tp * 5), d, 1, nx + dx[d], ny + dy[d]);
	Tonado5(t, d, 1, nx, ny);

	MAP[nx][ny] = 0;

}
void print() {
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << MAP[i][j] << " ";
		}
		cout << endl;
	}
}
void Solution() {
	//int qq = 18;
	//double q = (double)qq / 100;// 0.18;
	//cout << (int)(q * 7);
	
	Sx = Sy = (N / 2) + 1;
	Cnt = 1;
	int d = 0;
	int x = Sx;
	int y = Sy;
	int nx, ny;
	while (true) {
		for (int i = 0; i < 2; i++) { 
			for (int j = 0; j < Cnt; j++) { //j칸이동을 i번 d방향으로
				nx = x + dx[d];
				ny = y + dy[d];
				Tonado2(x, y, nx, ny, d);
				//cout << x << "," << y <<">"<<MAP[0][0]<< endl;
				//print();
				if (nx == 1 && ny == 1) break;
				x = nx;
				y = ny;
			}
			if (nx == 1 && ny == 1) break;
			d++; if (d == 4)d = 0;
		}
		if (nx == 1 && ny == 1) break;
		Cnt++;
	}

	cout << MAP[0][0];

}
int main() {


	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);
	Input();
	Solution();

	return 0;
}