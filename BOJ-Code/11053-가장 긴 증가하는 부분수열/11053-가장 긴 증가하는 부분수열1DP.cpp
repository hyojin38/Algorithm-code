//가장 긴 증가하는 부분수열 
//방법1. DP 사용
#include <iostream>
#include <vector>
#include <cmath>
#define MAX 1000+1
using namespace std;

int A,Ans=0;
vector <int > V;
int DP[MAX];
void Input() {
	cin >> A;
	int temp;
	for (int i = 0; i < A; i++) {
		cin >> temp;
		V.push_back(temp);
	}
	
}
int max(int a, int b) {
	if (a > b)return a;
	else return b;
}
void Solution1() {
	//DP를 활용한 풀이
	for (int i = 0; i < A; i++) {
		DP[i] = 1;
	}
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < i; j++) {
			if (V[j] < V[i]) {
				DP[i] = max(DP[i], DP[j] + 1);
			}
		}
		if (DP[i] > Ans) Ans = DP[i];
	}

	/*for (int i = 0; i < A; i++) {
		cout << DP[i];
	}*/
	cout << Ans;
}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	Solution1();
	//Solution2();

	return 0;
}