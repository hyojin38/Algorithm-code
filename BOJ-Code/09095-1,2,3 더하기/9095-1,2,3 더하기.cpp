#include<iostream>
#define endl "\n"
using namespace std;

int N;
int Ans;

void DFS(int cnt, int sum) {
	if (sum > N) {
		return;
	}
	if (sum == N) {
		Ans++;
		return;
	}

	for (int i = 1; i <= 3; i++) {
		if (sum + i > N) continue;
		DFS(cnt + 1, i + sum);
	}
}
void Solution() {
	DFS(0, 0);
	cout << Ans << endl;
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);
	int TC;
	cin >> TC;

	for (int tc = 0; tc < TC; tc++) {
		Ans = 0;
		cin >> N;
		Solution();
	}


	return 0;
}