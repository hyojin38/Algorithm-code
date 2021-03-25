#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#define MAX 1000+2

using namespace std;

string s1, s2;
int N, M;
char S1[MAX], S2[MAX];
int dp[MAX][MAX];

void Solution() {
	cin >> s1 >> s2;
	N=s1.size();
	M= s2.size();

	for (int i = 1; i <= N; i++) {
		S1[i] = s1[i-1];
		//cout << S1[i];
	}
	for (int i = 1; i <= M; i++) {
		S2[i] = s2[i-1];
		//cout << S2[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = max({ dp[i][j - 1],dp[i - 1][j] ,
							 dp[i - 1][j - 1] + (S1[i] == S2[j]) });
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	cout << dp[N][M];


}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Solution();

	return 0;
}