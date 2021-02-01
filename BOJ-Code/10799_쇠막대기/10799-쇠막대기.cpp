#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
using namespace std;
#define endl "\n"
int Ans;

void Solution() {
	string str;
	cin >> str;
	char temp;
	char pre;
	stack<char> S;
	for(int i=0;i<str.size();i++) {
		temp=str[i];
		//cout << temp;
			if (temp == ')') {
				if (pre == '(') {
					//cout << S.size();
					S.pop();
					Ans += S.size();
				}
				else {
					//cout << S.size();
					S.pop();
					Ans+=1;
				}
			}
			else if (temp == '(') {
				S.push(temp);
			}
		
	
		pre = temp;

	}
}
int main () {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Solution();
	cout << Ans;
	return 0;
}