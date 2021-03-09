#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100000+1
#define endl "\n"
using namespace std;
int N;
vector<pair<int, int> > V;
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	cin >> N;
	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		V.push_back({ x,y });
	}
	sort(V.begin(), V.end(),cmp);
	for (int i = 0; i < N; i++) {
		cout << V[i].first << " " << V[i].second<<endl;
	}
	return 0;

}