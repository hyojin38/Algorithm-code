#include<iostream>
#include <set>
#include <vector>
#include <string>
#define endl "\n"
using namespace std;
int K, L;
vector<string> V, Ans;
set<string> S;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);
	cin >> K >> L;

	for (int i = 0; i < L; i++) {
		string temp;
		cin >> temp;
		V.push_back(temp);
	}

	for (int i = L-1; i >= 0; i--) {
		string temp = V[i];
		if (S.find(temp) == S.end()) {//중복된것이 없다
			S.insert(temp);
			Ans.push_back(temp);
		}
	}
	int size = Ans.size();

	for (int i = size - 1; i >= size - K; i--) {
		if (i < 0) {
			break;
		}
		cout << Ans[i] << endl;
	}
	return 0;
}
