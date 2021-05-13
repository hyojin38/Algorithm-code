#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

bool FindPrimeNum(int x) {
	//�Ҽ� 1�� �ڱ��ڽ��� ����� ���������� �ʴ´�
	int a = 1;
	if (x == 1) return false;

	while (true)
	{
		a++;
		if (a*a > x) break;
		if (x % a == 0) return false;//�Ҽ��ƴ�
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

	if (x % 2 == 0) {//¦��
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
	
	//� ���� �־�������, N���� ũ�ų� ����, �Ҽ��̸鼱 �Ӹ������ ���� ���� ���� ���� ���ϱ�

	int N;
	cin >> N;

	//�Ҽ� ���ϱ�. �Ӹ���� ���ϱ�
	
	while (true) {
		
		if (Solution(N)) {
			cout << N;
			break;
		}
		N++;
	}

	return 0;
}