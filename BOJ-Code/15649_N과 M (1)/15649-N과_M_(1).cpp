#include <iostream>
#include <queue>
#include <vector>
#define MAX 8
#define endl "\n"
using namespace std;

int N, M;
int visitied[MAX + 1];
vector<int> V;
void solution(int cnt) {

	if (cnt == M) {
		for (int i = 0; i < M; i++) { //주의
			cout << V[i]<<" ";
		}
		cout << endl;
		return; //주의
	}

	for (int i = 0; i < N; i++) {
		if (visitied[i] == 1)
			continue;

		visitied[i] = 1;
		V.push_back(i + 1);
		//cout << cnt <<i + 1;
		solution(cnt + 1);
		V.pop_back();
		visitied[i] = 0;
	}


}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen("Text.txt", "r", stdin);

	cin >> N >> M;
	solution(0);


	return 0;
}