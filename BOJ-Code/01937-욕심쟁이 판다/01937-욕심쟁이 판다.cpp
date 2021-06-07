#include <iostream>
#include <vector>

#define MAX 500+1
typedef long long ll;
using namespace std;

int N;
ll MAP[MAX][MAX];
ll DP[MAX][MAX];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };


void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}

}
void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << DP[i][j];
		}
		cout << endl;
	}
}
void DFS(int x, int y) {

	int tempk = 1;
	for (int k = 0; k < 4; k++) {

		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (MAP[nx][ny] <= MAP[x][y]) continue;
		if (DP[nx][ny] == 0) {
			DFS(nx, ny);
		}

		if (tempk < 1 + DP[nx][ny]) {
			tempk = 1 + DP[nx][ny];
		}
	}
	DP[x][y] = tempk;




}
void Solution() {
	//print();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (DP[i][j] == 0) {
				DFS(i, j);
			}
		}
	}
}
ll max(ll a, ll b) {
	if (a > b) return a;
	else return b;
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	Solution();
	ll Ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//cout << DP[i][j]<<" ";
			Ans = max(Ans, DP[i][j]);
		}
		//cout << endl;
	}
	cout << Ans;
	return 0;
}