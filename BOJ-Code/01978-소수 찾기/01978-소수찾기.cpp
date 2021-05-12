#include <iostream>
#include <vector>

using namespace std;

bool findPrimeNum(int x) {
	//��Ʈ x���� ���� ������ �������� 0�ΰ� Ȯ��
	if (x == 1) return false;
	int a = 1;
	while (true) {
		a++;
		if (a*a > x) break;
		if (x % a == 0) return false;
		
	}
	return true;//�Ҽ���
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	int N;
	int Ans=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		//cout << i<<"-"<<Ans<<endl;
		if (findPrimeNum(x)) Ans++;
	}
	cout << Ans;

	return 0;


}