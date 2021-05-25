#include <iostream>
#include <vector>
#include<queue>
#define MAX 20000+1
using namespace std;
int V, E;
int visited[MAX] = { 0, };
//1번 정점에서만 탐색을 해서는 안된다
//주어진 그래프가 연결그래프가 아닐 수 있습니다

bool BFS(vector<int>  Vec[MAX],int start) {

	queue<int>  Q;
	visited[start] = 1;//1과2만 들어갈것
	Q.push(start);

	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();

		int p = visited[x];
		int np;
		if (p == 1) np = 2;
		else if (p == 2) np = 1;

		for (int i = 0; i < Vec[x].size(); i++) {
			int nx = Vec[x][i];
		//	cout << x << "-" << nx << endl;
			if (visited[nx] == 0) {
			//	cout << "!!";
				Q.push(nx);
				visited[nx] = np;
			}
			else if (visited[nx] == 1) {
				if (np == 2) return false;
			}
			else if (visited[nx] == 2) {
				if (np == 1) return false;
			}
		}

	}

	return true;
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	int K;
	cin >> K;
	
	for (int tc = 0; tc < K; tc++) {
		vector <int>  Vec[MAX];
		for (int i = 0; i < MAX; i++) {
			visited[i] = 0;
		}
		cin >> V >> E;//정점 간선
		for (int i = 0; i < E; i++) {
			int a, b;
			cin >> a >> b;
			Vec[a].push_back(b);
			Vec[b].push_back(a);
		}

		bool temp = true;
		for (int i = 1; i <= V; i++) {
			if (visited[i] == 0) {
				if (BFS(Vec, i) == false) 	temp = false;
			}
			if (temp == false)break;
		}

		//bfs
		if (temp) cout << "YES" << endl;
		else cout << "NO" << endl;
		
	}

	return 0;
}