#include <iostream>
#include <vector>
#define MAX 10000+1
#define MAXF(a,b) (a)>(b) ? (a):(b)
using namespace std;

int N;
int Ans = 0;
int MAPPnum[MAX];
int visited[MAX];
vector<int> Tree[MAX];

int DP[2][MAX] = { 0, };
void Input() {
	cin >> N;

	int temp;
	vector <int> V;
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		MAPPnum[i] = temp;
		Tree[i] = V;
	}

	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		Tree[a].push_back(b);
		Tree[b].push_back(a);
	}

}
void Init() {
	for (int i = 1; i <= N; i++) {
		DP[0][i] = 0;
		DP[1][i] = MAPPnum[i];
	}
}
void Solution(int n) {

	if (visited[n] == true) return;

	visited[n] = true;

	for (int i = 0; i < Tree[n].size(); i++) {
		int next = Tree[n][i];
		if (visited[next]) continue;

		Solution(next);

		DP[0][n] += MAXF(DP[0][next], DP[1][next]);
		DP[1][n] += DP[0][next];
	}
}
void Solution() {

	Init();
	Solution(1);
	cout << (MAXF(DP[0][1], DP[1][1]));
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	Solution();

	return 0;
}