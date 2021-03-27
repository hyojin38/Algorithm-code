#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, C;
int Ans;
vector<bool> Mlist(10, false);//��ư ���� true


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
//���� �� �ִ� ����ȣ�ΰ�
bool Possible(int x) {
	//while ���� x�� 0�� �ƴ� ��쿡�� ���⶧���� 0 ���� üũ
	if (x == 0)
	{
		if (Mlist[0] == true) // ����
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
	Ans = abs(N - 100); // +.-�θ� ���������� 

	int TempAns;
	for (int i = 0; i <= 1000000; i++) {
		//���� �� �ִ� ��ȣ���
		if (Possible(i)) {
			TempAns = to_string(i).length();//��ȣ����
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