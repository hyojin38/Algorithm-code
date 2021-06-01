#include <iostream>
#include <vector>
#define MAX 1000+1

using namespace std;

int A;
vector <int> V;
int DP[MAX];
int Ans;
void Input() {
	cin >> A;
	for (int i = 0; i < A; i++) {
		int temp;
		cin >> temp;
		V.push_back(temp);
		DP[i] = 1;
	}

}
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}void Solution() {
	for (int i = 1; i < A; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (V[i] < V[j]) {
				DP[i] = max(DP[i], DP[j] + 1);
			}
		}
	}

	for (int i = 0; i < A; i++) {
		//cout << DP[i]<<" ";
		if (DP[i] > Ans) Ans = DP[i];
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