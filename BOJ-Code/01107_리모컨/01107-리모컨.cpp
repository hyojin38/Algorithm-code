#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, C;
int Ans;
vector<bool> Mlist(10, false);//버튼 고장 true


void Input() {
	cin >> N;
	
	cin >> C;
	int temp;
	for (int i = 0; i < C; i++) {
		cin >> temp;
		Mlist[temp] = true;
	}

	//int to string
	string str = to_string(N);

}
//누를 수 있는 ㅂㄴ호인가
bool Possible(int x) {
	//while 문은 x가 0이 아닌 경우에만 돌기때문에 0 따로 체크
	if (x == 0)
	{
		if (Mlist[0] == true) // 고장
			return false;
		else
			return true;
	}
	while (x) {
		if (Mlist[x % 10] == true)
			return false;
		x = x / 10;
	}
	return true;

}
void Solution() {
	Ans = abs(N - 100); // +.-로만 움직였을때 

	int TempAns;
	for (int i = 0; i <= 1000000; i++) {
		//누를 수 있는 번호라면
		if (Possible(i)) {
			TempAns = to_string(i).length();//번호길이
			TempAns = TempAns + abs(i - N);
			Ans = min(Ans, TempAns);
		}
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