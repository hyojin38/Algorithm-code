#include<iostream>
#include<cstring>
#include <algorithm>
#define MAX 101
using namespace std;
int N, K, Ans;
int W[MAX];
int V[MAX];
int DP[MAX][100001];

int knapsack(int n, int weight) {

	if (DP[n][weight] > 0) return  DP[n][weight];
	if ( n == N) return 0;
	
	int v1 = 0;
	if (weight + W[n] <= K) {
		v1 = V[n] + knapsack(n + 1, weight + W[n]); //포함
	}
	int v2 = knapsack(n + 1, weight); //미포함
	return  DP[n][weight] = max(v1, v2);

}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> W[i];
		cin >> V[i];
	}
	knapsack(0, 0);

	cout << DP[0][0]; //가치합의 최댓값
	return 0;
}