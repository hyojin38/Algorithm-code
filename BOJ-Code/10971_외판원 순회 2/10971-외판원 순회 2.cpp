#include <iostream>
#include <vector>
#include <queue>
#define	MAX 10+1
#define endl "\n"

using namespace std;
int N,Ans;
int MAP[MAX][MAX];
bool visited[MAX];
void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
}
void DFS(int ss, int s, int cnt, int cost) {
	//cout << s;
	if (cost > Ans && Ans != 0) return;
	if (cnt == N) {
		//cout << ":";
		if (MAP[s][ss] == 0) return;
		else {
			if (Ans == 0) {
				Ans = cost + MAP[s][ss]; 
			}
			else if (Ans > cost + MAP[s][ss]) {
				Ans = cost + MAP[s][ss];
			}
		//	cout << Ans << endl;
			return;
		}
	}
	for (int i = 0; i < N; i++) {
		if (visited[i] == true) continue;
		if (MAP[s][i] == 0) continue;
		visited[i] = true;
		DFS(ss, i, cnt + 1, cost + MAP[s][i]);
		visited[i] = false;
	}

}
void Solution() {

	for (int i = 0; i < N; i++) {
		visited[i] = true;
		DFS(i,i,1 ,0);
		visited[i] = false;
	}
	cout << Ans;


}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	Solution();
	return 0;
}