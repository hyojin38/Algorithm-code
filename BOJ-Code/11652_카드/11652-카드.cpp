#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
typedef  long long ll;
using namespace std;

ll N,Ans,Cnt,nCnt;
vector<ll> V;
bool cmp(const ll a, const ll b) {
	return a > b;
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);
	cin >> N;
	for (ll i = 0; i < N; i++) {
		ll temp;
		cin >> temp;
		V.push_back(temp);
	}
	sort(V.begin(), V.end() ,cmp);
	for (ll i = 0; i < V.size(); i++) {
		//cout << V[i];
		if (i == 0 || V[i-1] != V[i]) {
			nCnt = 1;
		}else if (V[i - 1] == V[i]) {
			nCnt++;
		}
		if (nCnt >= Cnt) {
			Cnt = nCnt;
			Ans = V[i];
		}
	}

	cout << Ans;
	return 0;
}