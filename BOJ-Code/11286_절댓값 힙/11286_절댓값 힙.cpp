#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"
using namespace std;

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	priority_queue < pair<int, int >, vector < pair<int, int > >, greater<pair<int, int> > > PQ;
	int N;
	cin >> N;

	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		int pbot;
		if (x != 0) {
			if (x > 0) {
				pbot = 1;
				PQ.push({ x,pbot });
			}
			else if (x < 0) {
				pbot = -1;
				PQ.push({ -1 * x,pbot });
			}
		}
		else if (x == 0) {
			//절댓값이 가장 작은 값을 뽑고,
			//배열에서 제거
			if (PQ.empty()) {
				cout << 0 << endl;
			}
			else {
				if (PQ.top().second == -1) {
					cout << -1 * (PQ.top().first) << endl;
				}
				else if (PQ.top().second == 1) {
					cout << PQ.top().first << endl;
				}
				PQ.pop();
			}

		}
	}
	return 0;
}