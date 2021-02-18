#include <iostream>
#include <vector>
#include<algorithm>
#define endl "\n"
#define MAX 1000000+1

using namespace std;

int TC,n, m;
vector <pair<int, pair<int, int> > > V;
int P[MAX];
void Input() {
	cin >> n >> m;
	int c,a,b;
	for (int i = 0; i < m; i++) {
		cin >> c >> a >> b;
		V.push_back(make_pair(c, make_pair(a, b)));
	}
}
void MakeSet(int x) {
	P[x] = x;
}
int FindSet(int x) {
	if (P[x] == x) return x;
	else return P[x] = FindSet(P[x]);
}
void Union(int x, int y) {
	x = FindSet(x);
	y = FindSet(y);
	if (x != y) P[y] = x;
}
bool CheckRoot(int x, int y) {
	x = FindSet(x);
	y = FindSet(y);
	if (x == y)return true;
	else return false;
}
void Solution() {

	for (int i = 1; i <= n; i++) {
		MakeSet(i);
	}

	for (int i = 0; i < V.size(); i++) {
		int a = V[i].second.first;
		int b = V[i].second.second;
		int c = V[i].first;

		if (c == 0) {
			Union(a, b);
		}
		else {
			if (CheckRoot(a, b)) cout << 1;
			else cout << 0;
		}


	}


}
void Init() {
	V.clear();
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		Init();
		Input();
		cout << "#" << tc << " ";
		Solution();
		cout << endl;
	}
	
	return 0;
}