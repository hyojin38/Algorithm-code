#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#define endl "\n"
#define MAX 10000+1

using namespace std;

int N;
deque <int> STACK;

void Fpush() {
	int x;
	cin >> x;
	STACK.push_back(x);
}
void Fpop() {
	int x;
	if (STACK.size() == 0) {
		cout << -1 <<endl;
	}
	else {
		x = STACK.back();
		STACK.pop_back();
		cout << x<<endl;
	}
	
}
void Fsize() {
	cout << STACK.size()<<endl;
}
void Fempty() {
	if (STACK.size() == 0) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}

}
void Ftop() {
	int x;
	if (STACK.size() == 0) {
		cout << -1 << endl;
	}
	else {
		x = STACK.back();
		cout << x << endl;
	}
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	cin >> N;
	string sign;
	for (int i = 0; i < N; i++) {

		cin >> sign;
		if (sign == "push") {
			Fpush();
		}
		else if (sign == "pop") {
			Fpop();
		}
		else if (sign == "top") {
			Ftop();
		}else if(sign == "size") {
			Fsize();
		}
		else if (sign == "empty") {
			Fempty();
		}
	}

	return 0;
}