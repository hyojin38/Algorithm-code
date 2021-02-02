#include <iostream>
#include <stack>
#include <string>

#define endl "\n"
using namespace std;
stack<char> S1;
stack<char> S2;
int N;
void Input() {
	string temp;
	cin >> temp;
	char ch;
	for (int i = 0; i < temp.size(); i++) {
		S1.push(temp[i]);
	}

	cin >> N;

}
void Solution() {
	for (int i = 0; i < N; i++) {
		char temp;
		cin >> temp;
		if (temp == 'L') {
			if (S1.size() != 0) {
				char x = S1.top();
				S2.push(x);
				S1.pop();
			}
		}
		else if (temp == 'D') {
			if (S2.size() != 0) {
				char x = S2.top();
				S1.push(x);
				S2.pop();
			}
		}
		else if (temp == 'B') {
			if (S1.size() != 0) {
				S1.pop();
			}
		}
		else {
			char temp2;
			cin >> temp2;
			S1.push(temp2);
		}
	}
}
void Answer() {
	int size = S1.size();
	if (S1.size() != 0) {
		for (int i = 0; i < size; i++) {
			char temp = S1.top();
			S2.push(temp);
			S1.pop();
		}
	}
	size = S2.size();
	for (int i = 0; i < size; i++) {
		cout << S2.top();
		S2.pop();
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	Solution();
	Answer();
	return 0;
}