#include<iostream>
#include <vector>
#include <cmath>
using namespace std;
int gcd;
int lcm;
int max(int a, int b) {
	if (a > b)return a;
	else return b;
}
int min(int a, int b) {
	if (a< b)return a;
	else return b;
}
void GCD(int a, int b) {
	int mod = a % b;
	if (mod == 0) {
		gcd = b;
	}
	else {
		GCD(b,mod);
	}
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	int a, b;
	cin >> a >> b;
	GCD(max(a, b), min(a, b));
	lcm = gcd * (a / gcd)*(b / gcd);
	cout << gcd << endl << lcm;
	return 0;
}