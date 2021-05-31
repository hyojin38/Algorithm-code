//가장 긴 증가하는 부분수열2
//DP 양쪽에서 하는 방법이용
#include <iostream>
#include <vector>
#define MAX 1000+1
using namespace std;

int N;
vector <int> V;
int DP1[MAX];
int DP2[MAX];
int Ans = 0;
void Input() {
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		V.push_back(temp);
		DP1[i] = DP2[i] = 1;
	}
}
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
void Solution() {

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (V[i] > V[j]) {
				DP1[i] = max(DP1[i], 1 + DP1[j]);
			}
		}
	}

	for (int i = N - 2; i >= 0; i--) {
		for (int j = i + 1; j < N; j++) {
			if (V[i] > V[j]) {
				DP2[i] = max(DP2[i], 1 + DP2[j]);

			}
		}
	}

	for (int i = 0; i < N; i++) {
		int temp = DP1[i] + DP2[i] - 1;
		if (Ans < temp) Ans = temp;
	}
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	Solution();
	cout << Ans;
	return 0;
}