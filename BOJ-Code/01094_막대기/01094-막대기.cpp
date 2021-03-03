#include<iostream>
#include<cstring>
#include<stack>
#define endl "\n"

using namespace std;

double L,X;
stack<double> stick;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen("Text.txt", "r", stdin);

	L = 64;
	cin >> X;
	stick.push(64);
	int T = 0;
	while (true) {
		T++;
		
		if (L > X) {
			double shot = stick.top();
			stick.pop();
			double shot2 = shot / 2;

			if (L - shot2 >= X) {
				stick.push(shot2);
				L -= shot2;
			}
			else {
				stick.push(shot2);
				stick.push(shot2);
			}
		}
		//cout << T << ";" << L << endl;
		if (X == L) {
			break;
		}

	}
	cout << stick.size();



	return 0;
}
