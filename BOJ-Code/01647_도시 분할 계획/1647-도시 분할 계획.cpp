#include<iostream>
#include<vector>
#include<algorithm>
#define MAX  1000001
#define endl "\n"

using namespace std;
vector <pair<int, pair<int, int> > > V;
int P[MAX];
int N, M,Ans;
vector <int> VC;
void Input() {
	cin >> N >> M;
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		V.push_back(make_pair(c, make_pair(a, b)));
	}
	
}
void MakeSet(int x) {
	P[x] = x;
}
int FindSet(int x) {
	if (P[x] == x) return x;
	else return P[x]=FindSet(P[x]);
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
	
	int cnt = 0;
	sort(V.begin(), V.end());
	for (int i = 1; i <= N; i++) {
		MakeSet(i);
	}
	int a, b;
	for (int i = 0; i < V.size(); i++) {
		a = V[i].second.first;
	    b = V[i].second.second;
		if (!SameRoot(a, b)) {
			UnionSet(a, b);
			//VC.push_back(V[i].first);
			Ans += V[i].first;
			cnt++;
		}
		if (cnt == N - 2) {
			cout << Ans;
			return;
		}
			//break;// MST가 N개의 정점을 N-1개의 선으로 연결하는 것인데 1개를 잇기 전 끝내
	}

	for (int i = 0; i < VC.size() - 1; i++) {
		Ans += VC[i];
	}
	cout << Ans;

}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	Solution();

	return 0;
}

