//swea 1251 하나로
//20210218
//계산 값이 미세하게 틀림
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include <cstring>  //memset 주의
typedef long long  ll;  // typedef longlong ll 암기~
#define MAX 1001
#define endl "\n"

using namespace std;


ll TC,N,X,Y, Ans;
double T;
ll island[MAX][2];
vector<pair< ll, pair<ll, ll > > > V; //최소 환경 부담금 정수형태 반올림
ll check[MAX];
ll P[MAX];

void dfs(ll cnt, ll idx) {
	if (cnt == 2) {
		ll x1, y1, x2, y2;
		ll p1, p2;
		cnt = 0;
		for (ll i = 0; i < N; i++) {
			if (check[i] == true) {
				if (cnt == 0) {
					x1 = island[i][0];
					y1 = island[i][1];
					p1 = i;
					cnt++;
				}
				else {
					x2 = island[i][0];
					y2 = island[i][1];
					p2 = i;
					break;
				}
			}
		}
		//거리공식 (유클리드 맨하탄 해밍)
		ll L, P;
		ll dx= abs(x1-x2);
		ll dy = abs(y1-y2);
		L = sqrt(dx*dx + dy * dy);
		P = T * L * L;
		V.push_back(make_pair(P, make_pair(p1, p2)));
		
		return;
	}

	for (ll i = idx; i < N; i++) {
		if (check[i] == true) continue;
		check[i] = true;//0
		dfs(cnt + 1, i+1);
		check[i] = false;
	}
}
void Input() {
	cin >> N;
	for (ll i = 0; i < N; i++) { //x
		cin >> X;
		island[i][0]=X;
	}
	for (ll i = 0; i < N; i++) { //x
		cin >> Y;
		island[i][1] = Y;
	}
	cin >> T;
	//조합 터널
	dfs(0,0); // N개 중 2개 뽑기 V완성


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
	if (x != y) {
		P[y] = x;
	}
}
bool checkP(int x, int y) {
	x = FindSet(x);
	y = FindSet(y);
	if (x == y) return true;
	else return false;
}
void Solution() {

	sort(V.begin(), V.end());
	for(int i=0;i<N;i++)
		MakeSet(i);
	for (int i = 0; i < V.size(); i++) {
		ll x = V[i].second.first;
		ll y = V[i].second.second;

		if (!checkP(x, y)) {
			Union(x, y);
			Ans += V[i].first;
		}
	
	}

}
void Init() {
	Ans = 0;;
	V.clear();
	memset(check, false, sizeof(check));
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);
	cin >> TC;
	
	for (int tc = 1; tc <= TC; tc++) {
		Init();
		Input();
		Solution();
		cout << "#" << tc << " " << (ll)Ans<<endl;
	}
	
	return 0;
}
