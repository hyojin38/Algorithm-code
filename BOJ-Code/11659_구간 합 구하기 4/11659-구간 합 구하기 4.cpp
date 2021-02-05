//누적합 미리 구하여 해결

#include <iostream>
#include <vector>
#define endl '\n'
#define Max 100001
using namespace std;
int N,M;
int SUM[Max];
int Input[Max];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >>M;
	for (int i = 0; i < N; i++) {
		cin >> Input[i];
		if (i == 0) SUM[i] = Input[i];
		else {
			SUM[i] = SUM[i - 1] + Input[i];
		}

	}

	int x, y;
	int ans;
	for (int i =0; i <M; i++) {
		cin >> x >> y;
		if (x == 1) {
			ans = SUM[y - 1];
		}
		else {
			ans = SUM[y - 1]-SUM[x-1-1];
		}
	
		cout << ans << endl;
	}

	return 0;
}