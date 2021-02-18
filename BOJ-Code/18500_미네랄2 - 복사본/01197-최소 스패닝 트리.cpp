#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
#define MAX 10000+1
typedef long long LL;
using namespace std;

int V, E;
LL Ans;
vector < pair<int, pair<int, int> > > Vec;
int P[MAX];
void Input() {

	cin >> V >> E;
	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		Vec.push_back(make_pair(c, make_pair(a, b)));
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
	if (x != y)
		P[y] = x;
}
bool CheckRoot(int x, int y) {
	x = FindSet(x);
	y = FindSet(y);
	if (x == y) return true;
	else return false;
}
void Soution() {

	sort(Vec.begin(), Vec.end());

	for (int i = 0; i <= V; i++) MakeSet(i);

	for (int i = 0; i < Vec.size(); i++) {
		int a = Vec[i].second.first;
		int b = Vec[i].second.second;

		if (!CheckRoot(a, b)) {
			Union(a, b);

			Ans += Vec[i].first;
		}

	}
	cout << Ans;
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	Soution();

	return 0;
}
