//�Ӹ����=ȸ�� �Ųٷ� �о ����� �д°Ͱ� ���� �����̳� ���� ���� ���ڿ� ��
#include<iostream>
#include <vector>

#define endl "\n"
#define MAX 2000+1

using namespace std;

int N,M,S,E;
vector <int> Arr;
int DP[MAX][MAX];

void Input() {
	cin >> N;
	int temp; 
	Arr.push_back(0); //1���� �����ϱ� ����

	for (int i = 1; i <= N; i++) {
		cin >> temp;
		Arr.push_back(temp);
	}
	cin >> M;
	
}
void makeDP() {

	for (int i = 1; i <= N; i++)
		DP[i][i] = 1; // �Ѱ��� �Ӹ����

	for (int i = 1; i <= N - 1; i++) { //�ΰ�¥�� �Ҹ����
		if (Arr[i] == Arr[i + 1]) // Arr[1]==Arr[2] �̸� DP[1][2]=1
			DP[i][i + 1] = 1;     // 7 7 8 9 8 8 �� ���� ��� 1.2   5.6 �� �Ӹ���� 
	}


	// 1- 3,4,5
	// 2- 4.5
	// 3- 5

	for (int s = 2; s <= N - S; s++) {
		for (int i = 1; i <= N; i++) {
	
			int j = i + s;
			if (j > N) continue;
			if (DP[i + 1][j - 1] == 1 && Arr[i] == Arr[j]) // 1.3  ���̸� Ȯ���ϱ� ���ؼ��� = 2.2�� �� �Ӹ�Ʈ������ && Arr[1]==Arr[3] ���� Ȯ�� �ʿ�
				DP[i][j] = 1;
			else { DP[i][j] = 0; }
		}
	}
	//for (int i = 1; i <= N; i++) {
	//	for (int j = i + 2; j <= N; j++) {
	//		if (DP[i + 1][j - 1] == 1 && Arr[i] == Arr[j]) // 1.3  ���̸� Ȯ���ϱ� ���ؼ��� = 2.2�� �� �Ӹ�Ʈ������ && Arr[1]==Arr[3] ���� Ȯ�� �ʿ�
	//			DP[i][j] = 1;
	//		else DP[i][j] = 0;
	//	}
	//}

	//cout << endl;
	//for (int i = 1; i <= N; i++) {
	//	for (int j = 1; j <= N; j++) {
	//		cout<< DP[i][j]<<" ";
	//	}
	//	cout << endl;
	//}

}
void Solution() {
	cin >> S >> E;

	if (DP[S][E] == 1)
		cout << 1 << endl;
	else
		cout << 0 << endl;

	

}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	
	makeDP();
	for (int i = 0; i < M; i++) {
		Solution();
	}
	return 0;
}