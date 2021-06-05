//테크노미노가 놓인 칸의 수의 합의 최댓값 출력
#include <iostream>
#include <vector>
#include <queue>
#define MAX 500+1	
using namespace std;

int N, M;
int MAP[MAX][MAX];
int Ans = 0;
void Input() {
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}
}
int count1(int x, int y) {
	int ans = 0;
	if (x + 3 >= N) return 0;
	else {
		for (int i = 0; i < 4; i++) {
			ans += MAP[x + i][y];
		}
	//	cout << ans << "입니다";
		return ans;
	}

}
int count2(int x, int y) {
	if (y+ 3 >= M) return 0;
	else {
		int ans = 0;
		for (int i = 0; i < 4; i++) {
			ans += MAP[x][y+i];
		}
		return ans;
	}
}
int count3(int x, int y) {
	if (x+1>=N||y + 1 >= M) return 0;
	else {
		int ans = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				ans += MAP[x+i][y + j];
			}
		}
		return ans;
	}
}
int count4_6_10_9(int x, int y) {
	int ans = 0;
	for (int j = 0; j < 3; j++) { //아래면
		ans += MAP[x+1][y + j];
	}
	int temp = ans;
	for (int i = 0; i < 3; i++) {
		if (ans < temp + MAP[x][y+i]) {
			ans = temp + MAP[x][y+i];
		}
	}
	return ans;
}
int count4_4_5_8(int x, int y) {
	
	int ans = 0;
	for (int j = 0; j < 3; j++) {//윗면
		ans += MAP[x][y + j];
	}
	int temp = ans;
	for (int i = 0; i < 3; i++) {//아랫면
		if (ans < temp + MAP[x + 1][y+i]) {
			ans = temp + MAP[x + 1][y+i];
		}
	}
	return ans;
}
int count4_11(int x, int y) {
	int ans = 0;
	for (int i = 0; i < 2; i++) {
		ans += MAP[x + i][y + 1];
	}

	ans += MAP[x + 1][y];
	ans += MAP[x ][y+2];

	return ans;
}
int count4_7(int x, int y) {
	int ans = 0;
	for (int i = 0; i < 2; i++) {
		ans += MAP[x + i][y + 1];
	}

	ans += MAP[x + 1][y+2];
	ans += MAP[x][y];

	return ans;
}
int count4(int x, int y) {
	if (x + 1 >= N || y + 2 > M) return 0;
	// 4 .5.6.7.8
	int temp = 0;
	temp = max(temp, count4_6_10_9(x, y));
	temp = max(temp, count4_4_5_8(x, y));
	temp = max(temp, count4_7(x, y));
	temp = max(temp, count4_11(x, y));
	return temp;
}
int count5_r(int x, int y) {
	// 오른쪽 고정
	int ans = 0;
	for (int j = 0; j < 3; j++) {//오른쪽
		ans += MAP[x+j][y + 1];
	}
	int temp = ans;
	for (int i = 0; i < 3; i++) {//왼쪽
		if (ans < temp + MAP[x + i][y]) {
			ans = temp + MAP[x + i][y];
		}
	}
	return ans;
}
int count5_l(int x, int y) {
	// 왼쪽 고정
	int ans = 0;
	for (int j = 0; j < 3; j++) {//왼쪽
		ans += MAP[x + j][y];
	}
	int temp = ans;
	for (int i = 0; i < 3; i++) {//오른쪽
		if (ans < temp + MAP[x + i][y+1]) {
			ans = temp + MAP[x + i][y+1];
		}
	}
	return ans;
}
int count5_1(int x, int y) {
	int ans = 0;
	for (int i = 0; i < 2; i++) {
		ans += MAP[x + 1][y + i];
	}

	ans += MAP[x][y];
	ans += MAP[x+2][y + 1];

	return ans;
}
int count5_2(int x, int y) {
	int ans = 0;
	for (int i = 0; i < 2; i++) {
		ans += MAP[x + 1][y + i];
	}

	ans += MAP[x][y+1];
	ans += MAP[x + 2][y];

	return ans;
}
int count5(int x, int y) {
	if (x + 2 >= N || y + 1 > M) return 0;
	//가로 2 세로3
	int temp = 0;
	temp = max(temp, count5_r(x, y));
	temp = max(temp, count5_l(x, y));
	temp = max(temp, count5_1(x, y));
	temp = max(temp, count5_2(x, y));
	return temp;
}
int max(int a, int b) {
	if (a > b)return a;
	else return b;
}

void Sol(int x, int y) {
	Ans=max(Ans, count1(x, y));
	Ans = max(Ans, count2(x, y));
	Ans = max(Ans, count3(x, y));
	Ans = max(Ans, count4(x, y));
	Ans = max(Ans, count5(x, y));




}
void Solution() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			Sol(i, j);
			//cout << i << "," << j <<"="<< Ans;
		}
	}

	cout << Ans;
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	Solution();
	return 0;
}