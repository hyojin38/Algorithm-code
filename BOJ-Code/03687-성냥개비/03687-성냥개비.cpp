#include <iostream>
#include <vector>
#include <string>

#define INF 1e18

using namespace std;

typedef long long ll;

int tc;
int n;

ll num[9] = { 0,0,1,7,4,2,0,8,10 };
ll dp[101] = { 0,0,1,7,4,2,6,8,10, };

ll min(ll x, ll y) { if (x > y)return y; else return x; }
int main(void) {
	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	for (int i = 9; i <= 100; i++) {
		dp[i] = INF;
		for (int j = 2; j <= 7; j++) {
			dp[i] = min(   dp[i - j] * 10 + num[j], dp[i]); //7,2 //6,3 //5,4 //4.5//
		}
	}

	cin >> tc;

	for (int t = 1; t <= tc; t++) {

		cin >> n;

		cout << dp[n] << " ";

		if (n % 2 == 0) { //Â¦¼ö
			int x = n / 2; //x¹ø ¹Ýº¹
			for (int i = 0; i < x; i++) {
				cout << 1;
			}
		}
		else {
			cout << 7;
			int x = (n / 2 )- 1;
			for (int i = 0; i < x; i++) {
				cout << 1;
			}
		}
		cout << endl;
	}
}
