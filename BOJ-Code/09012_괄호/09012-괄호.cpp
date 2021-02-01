#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
using namespace std;
#define endl "\n"
int N;
string Ans;

void Solution() {
	//queue<char> Q;
	stack<char> Q;
	Ans = "YES";
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		if (c == '(') {
			Q.push(c);
		}
		else if (c == ')') {
			if (Q.empty() == 1) {
				Ans = "NO";
				return;
			}
			else {
				Q.pop();
			}
		}
	}
	if (Q.empty()== 0) {
		Ans = "NO";
	}
}
int main () {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		Solution();
		cout << Ans << endl;
	}
	return 0;
}