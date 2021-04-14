#include<iostream>
#include<vector>
#include<queue>

#define MAX 200+2
#define endl "\n"

using namespace std;

int N, K, T;
int MAP[MAX];
queue<int> Robot;
bool check[MAX];
void Input() {
	cin >> N >> K;
	for (int i = 1; i <= 2 * N; i++) {
		cin >> MAP[i];
	}
}
void print() {
	for (int i = 1; i <= N; i++) {
		if (check[i]) cout << "0" << " ";
		else cout << "x";
	}cout << endl;

	for (int i = 1; i <= N; i++) {
		cout << MAP[i] << " ";
	}cout << endl;
	for (int i = N*2; i >= N+1; i--) {
		cout << MAP[i] << " ";
	}cout << endl;
}
void sol1() {//��Ʈ ��ĭ ȸ��
	//��Ʈȸ��
	int temp[MAX];
	for (int i = 1; i <= 2 * N;i++) {
		if (i == 2 * N) {
			temp[1] = MAP[i];
		}
		else {
			temp[i + 1] = MAP[i];
		}
	}
	for (int i = 1; i <= 2 * N; i++) {
		MAP[i] = temp[i];
	}

	//�κ��̵�1
	for (int i = N-1; i >= 1; i--) {
		check[i + 1] = check[i];
	}
	check[1] = false;

	//�κ��̵�2
	int s = Robot.size();
	for (int i = 0; i < s; i++) {
		int r = Robot.front();
		Robot.pop();
		int nr=r+1;
		if (nr <= N) {
			Robot.push(nr);
		}
	}

}
void sol2() {
	int s = Robot.size();
	for (int i = 0; i <s; i++) {
		//���� ���� ��Ʈ�� �ö� �κ� ���� �̵�
		int r = Robot.front();
		Robot.pop();
		int nr = r + 1;
		if (nr <= N) {
			if (check[nr] == false && MAP[nr] >= 1) {//��ĭ �տ� �κ��� ����� �Ѵ� +//��ĭ �տ� ������
					MAP[nr]--;
					Robot.push(nr);
					check[r] = false;
					check[nr] = true;
			}
			else {
				Robot.push(r);
			}
		}
		else { //������
			check[r] = false;
		}

	}
}
void sol3() {

	if (check[1] == false && MAP[1]>0) {
		Robot.push(1);
		check[1] = true;
		MAP[1]--;
	}
}
bool sol4() {
	int cnt = 0;
	for (int i = 1; i <= N * 2; i++) {
		if (MAP[i] == 0) cnt++;
	}
	if (cnt >= K) return false;
	else return true;
}
void Solution() {
	T = 0;
	while (true) {
		T++;
	//1.��Ʈ ��ĭ ȸ��
		sol1();

	//2.���� ���� ��Ʈ�� �ö� �κ� ���� �̵�
		sol2();
	
	//3.�κ��ø���
		sol3();

	//4. ������ 0�� ĭ k���̻��̸� ���� ����
		if (!sol4()) return;

	}
	
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	Solution();
	cout << T;

	return 0;
}