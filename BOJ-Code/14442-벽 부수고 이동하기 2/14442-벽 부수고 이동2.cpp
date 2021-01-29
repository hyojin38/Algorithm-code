#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#define endl "\n"
#define MAX 1001

vector<vector<int>> Map;
int visited[MAX][MAX];
int N, M, Answer, K;
queue<pair<pair<int, int>, pair<int,int> > >  Q;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void Input() {

	cin >> N >> M >> K;
	for (int i = 0; i <N; i++)
	{
		vector<int> v;
		Map.push_back(v);
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			Map[i].push_back(s[j]-'0');
			visited[i][j] = -1;
			//cout << Map[i][j];
		}
		//cout << endl;

	}
}
void BFS() {
	
	Q.push(make_pair(make_pair(0, 0), make_pair(K,1)));
	visited[0][0] = K;
	if (0 == N - 1 && 0 == M - 1) {
		Answer = 1;
		return;
	}
	while (Q.empty() == 0) {
		int x=Q.front().first.first;
		int y=Q.front().first.second;
		int k = Q.front().second.first;
		int n = Q.front().second.second;
		//cout << n;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nk = k;
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (Map[nx][ny] == 1 && k == 0) continue;
			if (Map[nx][ny] == 1 && k > 0) nk = k - 1;
			if (visited[nx][ny] >= nk ) continue;
			//cout <<nx<<","<<ny<<","<< k<< ","<< n + 1<<endl;
			visited[nx][ny] = nk;
			if (nx == N-1 && ny == M-1) {
				Answer = n + 1;
				return;
			}
			Q.push(make_pair(make_pair(nx, ny), make_pair(nk, n + 1)));
		}

	}

}
void Solution() {
	Answer = -1;
	BFS();
	cout << Answer;
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	Solution();
	
	return 0;
}



