#include<iostream>
#include<stack>
#include<string>
#include<stack>
#include<deque>
using namespace std;
#define endl "\n"
deque<char> S;
string input,boom;
void Input() {
	cin >> input >> boom;

}
void Solution() {
	int size = boom.size();
	for (int i = 0; i < input.size(); i++) {

		char endchar = boom[size - 1];
		S.push_back(input[i]);
		if (input[i] == endchar && S.size() >= size) {
			stack<char> S2;
			for (int k = size-1; k >= 0; k--) {
				char checkchar = S.back();
				if (checkchar == boom[k]) {
					S.pop_back();
					S2.push(checkchar);
				}
				else {
					int size2 = S2.size();
					for (int i = 0; i < size2; i++) {
						S.push_back(S2.top());
						S2.pop();
					}

				}
			}

		}
	}
	size = S.size();
	if (size == 0) {
		cout << "FRULA";
	}
	else {
		for (int i = 0; i < size; i++) {
			cout << S.front();
			S.pop_front();
		}
	}
	

}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	Solution();


	return 0;
}