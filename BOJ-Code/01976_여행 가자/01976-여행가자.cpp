#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#define MAX 200+1
using namespace std;

vector <pair<int, int> > V;
int N, M;
int P[MAX];
void makeset(int x) {
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
	if (a == b)return true;
	else return false;
}
void Solution() {
	for (int i = 1; i < N; i++) {
		makeset(i);
	}
	for (int i = 0; i < V.size(); i++) {
		int a = V[i].first;
		int b = V[i].second;
		if (!SameRoot(a, b)) {
			UnionSet(a, b);
		}
	}

	int root;
	int temp;
	cin >> temp;
	root = FindSet(temp);
	for (int i = 0; i < M; i++) {
		cin >> temp;
		if (root != FindSet(temp)) {
			cout << "NO";
			return;
		}

	}
	cout << "YES";

}
int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	cin >> N;//도시 수
	cin >> M;//여행계획에 속한 도시 수

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int temp;
			cin >> temp;
			if (temp == 1) {
				V.push_back({ i,j });
			}
		}
	}
	Solution();
}