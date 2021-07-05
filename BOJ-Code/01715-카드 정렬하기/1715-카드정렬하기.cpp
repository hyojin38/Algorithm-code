#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"
using namespace std;

int N;
int Ans = 0;
priority_queue <int, vector<int>, greater<int> > PQ;
void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		PQ.push(x);
	}


}
void Solution() {
	int T = 0;

	while (true) {

		if (PQ.size() == 1) {
			return;
		}
		else {
			int first = PQ.top();
			PQ.pop();
			int second = PQ.top();
			PQ.pop();
			PQ.push(first + second);
			Ans += (first + second);
			T++;
		}

	}

}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	Solution();
	cout << Ans;
	return 0;
}