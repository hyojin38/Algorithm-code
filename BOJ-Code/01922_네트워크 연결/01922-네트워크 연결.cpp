#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
#define MAX 1001
using namespace std;
int N, M, Cost;
vector <pair<int, pair<int, int> > > V;
int P[MAX];
void Input() {
	cin >> N;
	cin >> M;
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		V.push_back(make_pair(c, make_pair(a, b)));
	}
}
void sortV() {
	sort(V.begin(), V.end()); //1.정렬
}

void MakeSet(int x) {
	P[x] = x;
}
int FindSet(int x) {
	if (x == P[x]) return x;
	else return FindSet(P[x]);
}
void UnionSet(int a, int b) {
	a = FindSet(a);
	b = FindSet(b);

	if (a != b) {
		P[b] = a;
	}
}
bool SameRoot(int a, int b) {
	a = FindSet(a);
	b = FindSet(b);
	if (a == b) return true;
	else return false;
}
void Solution() {

	sortV();
	for (int i = 1; i <= N; i++) {
		MakeSet(i);
	}
	for (int i = 0; i < M; i++) {
		int a = V[i].second.first;
		int b = V[i].second.second;
		if (SameRoot(a, b) == false) { //a와 b가 연결되어 있지 않다
			UnionSet(a, b);
			Cost+= V[i].first;
		}
	}
}
int main(void) {


	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	Solution();
	cout << Cost;
	return 0;
}