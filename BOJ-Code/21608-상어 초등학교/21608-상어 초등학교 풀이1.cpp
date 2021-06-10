#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 20+1
#define MMAX 400+1 
using namespace std;

struct seat
{
	int x, y;
	int cntfav;
	int cntzero;
};
int N;
int X, Y;
int favorite[MMAX][4];
int MAP[MAX][MAX];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int Ans;

vector< seat > seatsV;
vector< seat > seatsV2;
void Input() {
	cin >> N;
}
bool Sol1(int me, int a, int b, int c, int d) {//1. 좋아하는 학생이 인접한 칸이 가장 많은칸 찾기
	seatsV.clear();
	int MAXFAV = 0;

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			if (MAP[x][y] == 0) {
				int cntzero = 0;
				int cntfav = 0;
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
					if (MAP[nx][ny] == 0) cntzero++;
					if (MAP[nx][ny] == a || MAP[nx][ny] == b || MAP[nx][ny] == c || MAP[nx][ny] == d) cntfav++;

				}
				seat S;
				S.x = x;
				S.y = y;
				S.cntfav = cntfav;
				S.cntzero = cntzero;

				if (MAXFAV == cntfav) {
					seatsV.push_back(S);
				}
				else if (MAXFAV < cntfav) {
					seatsV.clear();
					seatsV.push_back(S);
					MAXFAV = cntfav;
				}
			}
		}
	}

	if (seatsV.size() == 1) {
		return true;
	}
	else {
		return false;
	}

}
bool compare(seat A, seat B) {
	if (A.cntzero > B.cntzero) return true;
	else return false;
}
void print() {
	for (int i = 0; i < seatsV2.size(); i++) {
		cout << seatsV2[i].x << "," << seatsV2[i].y << endl;
	}
}
bool Sol2() {

	sort(seatsV.begin(), seatsV.end(), compare);
	int maxcnt = seatsV[0].cntzero;
	//cout << maxcnt<<endl;
	//print();
	seatsV2.clear();
	for (int i = 0; i < seatsV.size(); i++) {
		if (maxcnt > seatsV[i].cntzero) {
			break;
		}
		seatsV2.push_back(seatsV[i]);

	}
	if (seatsV2.size() == 1) {
		return true;
	}
	else return false;
}
bool comparex(seat A, seat B) {
	if (A.x < B.x) return true;
	else return false;
}
void Sol3() {

	sort(seatsV2.begin(), seatsV2.end(), comparex);
	//print();
	int minX = seatsV2[0].x;
	vector <int > Yvec;
	for (int i = 0; i < seatsV2.size(); i++) {
		if (minX < seatsV2[i].x) {
			break;
		}
		Yvec.push_back(seatsV2[i].y);
	}
	int minY = 30;
	for (int i = 0; i < Yvec.size(); i++) {
		if (minY > Yvec[i]) {
			minY = Yvec[i];
		}
	}

	X = minX;
	Y = minY;

}
void CountPoint() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			int cnt = 0;
			int me = MAP[i][j];
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
				if (MAP[nx][ny] == favorite[me][0] || MAP[nx][ny] == favorite[me][1] || MAP[nx][ny] == favorite[me][2] || MAP[nx][ny] == favorite[me][3]) cnt++;
			}
			if (cnt == 1) {
				Ans += 1;
			}
			else if (cnt == 2) {
				Ans += 10;
			}
			else if (cnt == 3) {
				Ans += 100;
			}
			else if (cnt == 4) {
				Ans += 1000;
			}
			else continue;

		}

	}
}
void Solution() {

	for (int i = 0; i < N*N; i++) {

		int me;
		cin >> me;

		for (int j = 0; j < 4; j++) {
			cin >> favorite[me][j];
		}
		//1. 좋아하는 학생이 인접한 칸이 가장 많은칸 찾기
		if (Sol1(me, favorite[me][0], favorite[me][1], favorite[me][2], favorite[me][3])) {
			X = seatsV[0].x;
			Y = seatsV[0].y;
		}
		else {
			//2.인접한 칸 중 빈칸이 많은 칸
			if (Sol2()) {
				X = seatsV2[0].x;
				Y = seatsV2[0].y;
			}
			else {
				Sol3();
			}
		}

		MAP[X][Y] = me;

	}
	CountPoint();
	cout << Ans;
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen("Text.txt", "r", stdin);
	Input();

	Solution();
	return 0;
}