#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#define MAX 50+1

using namespace std;

int N, M,Ans;
int Mx, My;//민식이 위치
char MAP[MAX][MAX];
bool visited[MAX][MAX][64];//111111은 63
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int Key[6];//abcdef
struct minsik {
	int x, y, key, cnt;
};
queue <minsik> Q;

void print() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << MAP[i][j];
		}
		cout << endl;
	}
}
void Input() {
	cin >> N >> M;

	string str;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 1; j <= M; j++) {
			char ch = str[j - 1];
			if (ch == '0') {
				Mx = i;
				My = j;
				MAP[i][j] = '.';
			}
			else if (ch == '1') {
				MAP[i][j] = ch;
			}
			else {
				MAP[i][j] = ch;
			}
		
		}

	}



}
bool Door(int key, int x, int y) {//열쇠 가지고 있는지 확인 {중요 잘 모름}
	char ch = MAP[x][y];
	if ((key & (1 << (ch - 'A'))) == 0) return false;
	else return true;
}
void BFS() {

	Q.push({ Mx,My,0,0 });//Minsik ( x, y, key, cnt)
	visited[Mx][My][0] = true;

	while (!Q.empty())
	{
		minsik m = Q.front();
		int x = m.x;
		int y = m.y;
		int key = m.key;
		int cnt = m.cnt;
		Q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if (MAP[nx][ny] == '#') continue;
			if (visited[nx][ny][key] == true) continue;

			//문
			if (MAP[nx][ny] >= 'A' && MAP[nx][ny] <= 'F') {
				if (Door(key,nx, ny)) {
					visited[nx][ny][key] = true;
					Q.push({ nx,ny,key,cnt + 1 });
				}
			}
			//열쇠
			else if (MAP[nx][ny] >= 'a' && MAP[nx][ny] <= 'f') {
				int nkey = (key | (1 << MAP[nx][ny] - 'a'));
				visited[nx][ny][nkey] = true;
				Q.push({ nx,ny,nkey,cnt + 1 });
			}
			//탈출
			else if (MAP[nx][ny] == '1') {
				Ans=cnt + 1;
				return;
			}
			else {
				visited[nx][ny][key] = true;
				Q.push({ nx,ny,key,cnt + 1 });
			}

		}

	}


}
void Solution() {
	Ans = -1;
	BFS();
	cout << Ans;
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);
	
	Input();
	Solution();

	return 0;
}