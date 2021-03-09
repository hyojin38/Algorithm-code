#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 100000+1
#define endl "\n"
using namespace std;

vector<pair<int, int> > V;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	
	if (a.second == b.second) {
		return a.first < b.first; //증가하는 순
	}
	return a.second < b.second;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);
	
	int N;
	int x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {

		cin >> x >> y;
		V.push_back({ x,y });
	}
	sort(V.begin(), V.end(), cmp);

	for (int i = 0; i < N; i++) {

		cout<< V[i].first <<" " <<V[i].second<<endl;
	
	}


	return 0;
}