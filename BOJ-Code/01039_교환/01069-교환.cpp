#include<iostream>
#include<vector>
#include<queue>
# include<string>
#define MAX 1000000+1
#define endl "\n"

using namespace std;
string NUM;
int N[10 + 1];
int K, M, Ans = 0;
int NUMtemp[10 + 1];
//�̹� üũ�� ���� �ִ� ��
int visited[1000000 + 1][10 + 1];

void Input() {
	cin >> NUM >> K;
	M = NUM.size();
	for (int i = 0; i < M; i++) {
		N[i] = NUM[i]-'0';
	}
	cin >> K;
}
int AtoN() {
	int ans = N[M - 1];

	int x = 10;
	for (int i = M - 1 - 1; i >= 0; i--) {
		ans = (N[i]) * x + ans;
	
		x *= 10;

	}

	return ans;
}
void dfs(int cnt) {
	if (cnt == K) {

		int temp = AtoN();
		if (Ans < temp) {
			Ans = temp;
		}
		return;
	}

	int a, b, check;
	//M�� �߿��� 2�� ����
	for (int i = 0; i < M; i++) {
		for (int j = i; j < M; j++) {
			if (i == j) continue;
			//�� �� �ٲٱ�
			
			a = N[i] ;
			b = N[j] ;
		
			if (b == 0 && i == 0) continue; // �ٲۼ��� 0���� ����
			N[i] = b;
			N[j] = a;
		
			check = AtoN();

			if (visited[check][cnt + 1] == 1) {
		
				N[i] = a;
				N[j] = b;
				continue;
			}
			
			visited[AtoN()][cnt + 1] = 1;
			dfs(cnt + 1);
			N[i] = a;
			N[j] = b;
		}
	}
}
void Solution() {

	dfs(0);
	if (Ans == 0) {
		cout << -1;
	}
	else {
		cout << Ans;
	}

}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);
	Input();
	Solution();
	
	return 0;
}