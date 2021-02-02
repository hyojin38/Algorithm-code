#include <iostream>
#include <string>
#include <stack>
using namespace std;
#define endl "\n"
int N;
stack<char> S1;
stack<char> S2;

void Solution() {
	string st;
	cin >> st;
	for (int i = 0; i < st.size(); i++) {
		char temp = st[i];
		if (temp == '<') {
			if (S1.size() != 0) {
				S2.push(S1.top());
				S1.pop();
			}
		}else if(temp=='>')
		{
			if (S2.size() != 0) {
				S1.push(S2.top());
				S2.pop();
			}
		}
		else if (temp == '-')
		{
			if (S1.size() != 0) {
				S1.pop();
			}
		}
		else {
			S1.push(temp);
		}
	}
}
void Output() {
	int size = S1.size();
	for (int i = 0; i < size; i++) {
		S2.push(S1.top());
		S1.pop();
	}
	size = S2.size();
	for (int i = 0; i < size; i++) {
		cout<<S2.top();
		S2.pop();
	}
	cout << endl;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {

		Solution();
		Output();
	}

	return 0;
}