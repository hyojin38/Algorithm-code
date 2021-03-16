#include <iostream>
#include <queue>
#include <vector>
#define endl "\n";
#define MAX 100000+1

using namespace std;
int N;
vector <vector <int> > V(MAX, vector <int>(0));
bool visited[MAX];
int root[MAX];
queue<int > Q;

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);
	
	cin >> N;
	int a, b;
	
	
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);

	}

	//bfs
	Q.push(1);
	visited[1] = true;
	int x;
	while(!Q.empty()){
		x=Q.front();
		Q.pop();
		int y;
		for (int i = 0; i < V[x].size(); i++) {
			y = V[x][i];

			if (visited[y] == true) continue;
			visited[y] = true;
			root[y] = x;
			Q.push(y);

		}
	
	}

	for (int i = 2; i <= N; i++) {
		cout << root[i] << endl;
	}

	return 0;
}