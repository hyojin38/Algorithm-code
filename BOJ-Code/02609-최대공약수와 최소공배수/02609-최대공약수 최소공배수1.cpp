#include<iostream>
#include <vector>
#include <cmath>
using namespace std;
int Ans1;
int Ans2;
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}

void Sol(int a, int b) {
	int pbot = min(a, b);

	for (int i = pbot; i > 0; i--) {

		if (a%i == 0 && b%i == 0) {
			Ans1 = i;
			Ans2 = (a/i) * (b/i)*Ans1;
			
			return;
		}

	}
	return;

}
void Solution(int a, int b) {
	Ans1 = 1;
	Ans2 = 1;
	Sol(a, b);
	cout << Ans1 << endl;
	cout << Ans2;

}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	int a, b;
	cin >> a >> b;
	Solution(a, b);
	return 0;
}