#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int T;
int N, M;

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);
	cin >> T;
	//�־����� ���� �������� �׻� ���� �׷����� 
	for (int tc = 0; tc < T; tc++) {
		cin >> N >> M;
		int a, b;
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
		}
		cout << N - 1 << endl;
	}
	return 0;
}