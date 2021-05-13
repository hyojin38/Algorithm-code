#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

bool FindPrimeNum(int x) {
	//소수 1과 자기자신을 빼고는 나누어지지 않는다
	int a = 1;
	if (x == 1) return false;

	while (true)
	{
		a++;
		if (a*a > x) break;
		if (x % a == 0) return false;//소수아님
	}
	
	return true;


}
bool Pallindrome(int x) {
	//012//5->5/2=2 
	//01//4 ->4/2=2 ->1
	string num = to_string(x);
	int numsize = num.size();
	
	if (numsize == 1) return true;

	int mid;

	if (x % 2 == 0) {//짝수
		mid = numsize / 2 - 1;
	}
	else {
		mid = numsize / 2;
	}
	//cout << mid <<" ";

	for (int i = 0; i < mid; i++) {
		
		int end = (numsize - 1 - i);
		//cout << i << ' ' << end << endl;
		if (num[i] == num[end]) continue;
		else {

			return false;
		}
	}
	return true;

}
bool Solution(int x) {
	//cout << x << ")";
	if (FindPrimeNum(x) && Pallindrome(x) ) {
		//cout << "@@@";
		return true;
	}
	return false;

}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);
	
	//어떤 수가 주어졌을때, N보다 크거나 같고, 소수이면선 팰린드롬인 수중 가장 작은 수를 구하기

	int N;
	cin >> N;

	//소수 구하기. 팰린드롬 구하기
	
	while (true) {
		
		if (Solution(N)) {
			cout << N;
			break;
		}
		N++;
	}

	return 0;
}