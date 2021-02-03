#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;
long int N,Ans;
stack<int> s;

void Solution() {
	long int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		long int size = s.size();
		if (size != 0) {
			for (int j = 0; j < size; j++) {
				if (s.top() <= temp) s.pop();
				else break;
			}
		}
		s.push(temp);
	//	cout << s.size() << " ";
		Ans += s.size();

	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	cin >> N;
	Solution();
	
	cout << Ans-N;
	return 0;
}