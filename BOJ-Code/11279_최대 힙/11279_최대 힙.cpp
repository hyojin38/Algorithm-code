#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"
using namespace std;

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	//1.배열에 자연수 x를 넣는다
	//2.배열에서 가장 큰 값 출력하고 그값을 배열에서 제거한다

	priority_queue <long long, vector<long long>, less<long long> >  PQ;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long x;
		cin >> x;
		PQ.push(x);
		if (x == 0) {
			cout << PQ.top() << endl;
			PQ.pop();
		}
	}
	return 0;
}