#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 20+1
#define MMAX 400+1
using namespace std;

int N;
int MAP[MAX][MAX];
bool check[MMAX];
int Ans;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector<int> friends[MMAX];
vector< pair < pair <int, int>, pair <int, int> > > V;
vector<  pair <int, int> > V2;

void Input() {

	cin >> N;

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
				if (MAP[nx][ny] == friends[me][0] || MAP[nx][ny] == friends[me][1] || MAP[nx][ny] == friends[me][2] || MAP[nx][ny] == friends[me][3]) cnt++;
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

		}
	}
}
void Solution() {

	int me;

	for (int i = 0; i < N*N; i++) {
		cin >> me;
		//cout << "["<< me<<"]";
		int temp;
		bool checkfre = false;//좋아하는 친구들 자리에 앉아있나?
		for (int i = 0; i < 4; i++) {
			cin >> temp;
			friends[me].push_back(temp);
		}
		int X, Y;
		int maxNUM1 = 0;
		int maxNUM2 = 0;
		V.clear();

		for (int x = 1; x <= N; x++) {
			for (int y = 1; y <= N; y++) {
				if (MAP[x][y] == 0) {
					int num1 = 0;
					int num2 = 0;

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
						if (MAP[nx][ny] == 0) num2++;
						if (MAP[nx][ny] == friends[me][0] || MAP[nx][ny] == friends[me][1] || MAP[nx][ny] == friends[me][2] || MAP[nx][ny] == friends[me][3]) num1++;
					}
					if (num1 == maxNUM1) {
						V.push_back({ {x,y},{num1,num2} });
						if (num2 > maxNUM2) {
							maxNUM2 = num2;
						}
					}
					else if (num1 > maxNUM1) {
						maxNUM1 = num1;
						V.clear();
						V.push_back({ {x,y},{num1,num2} });
						maxNUM2 = num2;

					}
				}
			}
		}


		if (V.size() == 1) {
			//1.빈칸 중 좋아하는 학생이 가장 많은 칸
			X = V[0].first.first;
			Y = V[0].first.second;
		}
		else {
			//2. 1을 만족하는 칸 중 인접칸 중 빈칸이 많은칸
			//소트 쓰고싶다
			V2.clear();
			for (int i = 0; i < V.size(); i++) {
				if (maxNUM2 == V[i].second.second) {
					int x = V[i].first.first;
					int y = V[i].first.second;
					V2.push_back({ x,y });
				}
			}
			if (V2.size() == 1) {
				X = V2[0].first;
				Y = V2[0].second;
			}
			else {
				int cnt = 21;
				for (int i = 0; i < V2.size(); i++) {
					int x = V2[i].first;
					int y = V2[i].second;

					if (x < cnt) {
						cnt = x;
						X = x; Y = y;
					}
					else if (x == cnt) {
						if (Y > y) Y = y;
					}
				}
				//3. 행번호 가장작은

				//4. 열번호 가장작은 
			}
		}




		//cout << X << Y;
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