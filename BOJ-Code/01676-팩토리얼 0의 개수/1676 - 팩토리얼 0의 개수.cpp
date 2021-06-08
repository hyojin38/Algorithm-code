#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);
	int N;
	cin >> N;

	int cnt10 = 0;
	int cnt5 = 0;
	int cnt2 = 0;

	for (int i = N; i >= 1; i--) {

		queue <int> Q;
		Q.push(i);

		while (!Q.empty()) {
			int temp = Q.front();
			Q.pop();

			if (temp % 10 == 0) {
				cnt10++;
				temp = temp / 10;
				Q.push(temp);
			}
			else if (temp % 2 == 0) {
				cnt2++;
				temp = temp / 2;
				Q.push(temp);
			}
			else if (temp % 5 == 0) {
				cnt5++;
				temp = temp / 5;
				Q.push(temp);
			}
		}

	}

	int count = 0;
	count = max(cnt5, cnt2);
	count = count - abs(cnt5 - cnt2);
	count = count + cnt10;
	cout << count;

	return 0;
}