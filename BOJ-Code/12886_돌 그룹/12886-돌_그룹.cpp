#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include<set>

#define endl "\n"
#define MAX 501
//typedef long long ll;
using namespace std;
set <pair<pair<int,int>,int >> visited;

queue <pair<pair<int, int>, int>> Q;

int A, B, C;
int result;


void Input() {
	cin >> A >> B >> C;
	Q.push(make_pair(make_pair(A, B), C));
	visited.insert(make_pair(make_pair(A, B), C));

}
void sol2(int tempA,int tempB,int tempC) {
	if (visited.find(make_pair(make_pair(tempA, tempB), tempC)) == visited.end()) {
		visited.insert(make_pair(make_pair(tempA, tempB), tempC));
		Q.push(make_pair(make_pair(tempA, tempB), tempC));
	}
}
void Solution() { //BFS

	while (Q.empty() == 0) {

		int a = Q.front().first.first;
		int b = Q.front().first.second;
		int c = Q.front().second;;
		
		Q.pop();

		if (a == b && a== c &&b==c) {
			result = 1;
			return;
		}

		int tempA, tempB, tempC;

		if (a < b) {
			tempB = b - a;
			tempA = a + a;
			tempC = c;
			sol2(tempA,tempB,tempC);
		}
		if (a > b) {
			tempB = b +b;
			tempA = a -b;
			tempC = c;
			sol2(tempA, tempB, tempC);
		}
		if (a < c ) {
			tempA = a + a;
			tempB = b;
			tempC = c-a;
			sol2(tempA, tempB, tempC);
		}
		if (a > c) {
			tempA = a -c ;
			tempB = b;
			tempC = c +c;
			sol2(tempA, tempB, tempC);
		}
		if (b < c) {
			tempA = a ;
			tempB = b +b;
			tempC = c - b;
			sol2(tempA, tempB, tempC);
		}
		if (b > c) {
			tempA = a ;
			tempB = b -c;
			tempC = c + c;
			sol2(tempA, tempB, tempC);
		}

	}


}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)	;
	freopen("Text.txt", "r",stdin);

	Input();
	Solution();
		cout << result;
	return 0;
}