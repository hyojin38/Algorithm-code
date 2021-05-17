#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include <stack>
using namespace std;


int L, C;
vector <pair<char, bool> > V;
bool check[16];
vector <char> Ans;

void Input() {

	cin >>L >> C;

	char temp;

	for (int i = 0; i < C; i++) {
		cin >> temp;
		if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u')
			V.push_back({ temp,true });
		else
			V.push_back({temp, false});
	}
	
	sort(V.begin(), V.end());

}
void DFS(int idx, int cnt,int a) {
	if (cnt == L) {
	
		if (a < 1 || (L-a) < 2) return;
	
		for (int i = 0; i < L; i++) {
			cout << Ans[i] ;
		}
		cout << endl;
		return;
	}

	for (int i = idx; i < C; i++) {
		if (check[i] == true) continue;
		check[i] = true;
		int add = 0;
		if (V[i].second == true) add = 1;
		char ch = V[i].first;
		Ans.push_back(ch);
		DFS(i, cnt + 1, a + add);
		check[i] = false;
		Ans.pop_back();
	}
}
void Solution() {

	DFS(0, 0,0);
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	Solution();

	return 0;

}