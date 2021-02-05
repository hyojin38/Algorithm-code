#include <iostream>
#include <deque>
using namespace std;
int N;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	deque<int> Deq;
	for (int i = N; i >= 1; i--) Deq.push_back(i);

	while (Deq.size() > 1) {
		Deq.pop_back();
		int temp = Deq.back();//back. end 
		Deq.pop_back();
		Deq.push_front(temp);
	}
	if (Deq.size() == 1) {
		cout << Deq.front();
	}


	return 0;
}