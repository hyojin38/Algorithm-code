#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define MAX 10000+1
using namespace std;
typedef long long ll;
long long  N;
ll MAP[MAX];
vector<long long > V;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	freopen("Text.txt", "r", stdin);
	cin >> N;
	ll temp;
	for (ll i = 0; i < N; i++) {
		cin >> temp;
		if (MAP[temp] == 0) {
			V.push_back(temp);
		}
		MAP[temp]++;
	
	}
	sort(V.begin(), V.end());
	ll cnt;
	for (ll i = 0; i < V.size(); i++) {
		temp = V[i];
		cnt = MAP[temp];
		for (ll j = 0; j < cnt; j++) {
			cout << temp << endl;
		}
	}


	return 0;
}