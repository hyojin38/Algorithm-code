//²É±æ
//20210525 9½Ã 40ºÐ

#include <iostream>
#include <vector>
#include <queue>
#define MAX 10+1
using namespace std;

int N;
int MAP[MAX][MAX];
bool visited[MAX][MAX];
bool check[MAX][MAX];
vector <pair<int, int> > V;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int Ans = 600;
void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
}
void DFS(int x, int y, int cnt,int cost) {
	if (cnt == 3) {
		if (cost < Ans) {
			Ans = cost;
		/*	cout << Ans;
			for (int i = 0; i < 3; i++) {

				cout << V[i].first << "." << V[i].second << "|";
			}
			cout << endl;*/
		}
		return;
	}

	for (int i = x; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == x && j == 0) {
				j = y;
			}
			if (visited[i][j] == true) continue;
			if (i == 0 || j == 0 || i == N-1 || j == N-1) continue;
			bool check2 = false;
			for (int k = 0; k < 4; k++) {
				int ni = i + dx[k];
				int nj = j + dy[k];
				if (check[ni][nj] == true) {
					check2 = true; break;
				}
			}
			if (check2 == true || check[i][j] == true) continue;

			//ÀÔ·Â
			int ncost = MAP[i][j];
			visited[i][j] = true;
			check[i][j] = true;
			for (int k = 0; k < 4; k++) {
				int ni = i + dx[k];
				int nj = j + dy[k];
				check[ni][nj] = true;
				ncost += MAP[ni][nj];
			}
			V.push_back({ i,j });
			DFS(i, j, cnt + 1,cost+ncost);
			V.erase(V.begin() + cnt);
			check[i][j] = false;
			for (int k = 0; k < 4; k++) {
				int ni = i + dx[k];
				int nj = j + dy[k];
				check[ni][nj] = false;
			}
			visited[i][j] = false;


		}
	}


}
void Solution() {
	DFS(0, 0,0,0);
	//1.n*n°³ Áß 3°³ ¼±ÅÃ

	//2. Á¶°Ç È®ÀÎ
	//2-1 È­´Ü¹ÛÀ¸·Î ²ÉÀÙÀÌ ³ª°¡¸é ¾ÈµÊ
	//2-2 ²ÉÀÙÀÌ ´Ù¸¥ ²ÉÀÙ°ú ´êÀ¸¸é ¾ÈµÊ

	//°¡Àå ½Ñ °¡°Ý¿¡ È­´Ü ´ë¿©°¡´ÉÇÑ°¡

	cout << Ans;
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);
	Input();
	Solution();
	return 0;
}