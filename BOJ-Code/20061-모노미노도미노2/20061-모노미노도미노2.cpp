#include<iostream>
#include<vector>
#include <queue>

#define endl "\n"

using namespace std;
int N,Ans;
bool green[6][4];
bool blue[6][4];
void Input() {
	cin >> N;
}
void printgreen() {
	for (int x = 0; x <= 5; x++) {
		for (int y = 0; y <= 3; y++) {
			cout << green[x][y] << " ";
		}
		cout << endl;
	}
}
void printblue() {
	for (int x = 0; x <= 5; x++) {
		for (int y = 0; y <= 3; y++) {
			cout << blue[x][y] << " ";
		}
		cout << endl;
	}
}

void DownBlock(bool Map[6][4], int t, int x, int y) { //1. 블록입력됨

	if (t == 1) {
		for (int x = 1; x <= 5; x++) {
			if (Map[x][y] == true) {
				Map[x - 1][y] = true;
				return;
			}
		}
		Map[5][y] = true;
		return;
	}
	else if (t == 2) {
		for (int x = 1; x <= 5; x++) {
			if (Map[x][y] == true || Map[x][y + 1] == true) {
				Map[x - 1][y] = true; Map[x - 1][y + 1] = true;
				return;
			}
		}
		Map[5][y] = true; Map[5][y + 1] = true;
		return;
	}
	else if (t == 3) {
		for (int x = 1; x <= 5; x++) {
			if (Map[x][y] == true) {
				Map[x - 1][y] = true; Map[x - 2][y] = true;
				return;
			}
		}
		Map[5][y] = true; Map[4][y] = true;
		return;
	}

}

void LineBreak(bool Map[6][4],int t) {// 3.4개 가득 찬경우 없애는 단계

	for (int x = t - 1; x >= 0; x--) {
		for (int y = 0; y <= 3; y++) {
			Map[x+1][y] = Map[x][y];
		}
	}
	//맨 위를 정의해주어야한다
	for (int y = 0; y <= 3; y++) {
		Map[0][y] = false;
	}
	

}

void Break(bool Map[6][4]) { // 2. 행이 가득 찬것이 있는지 확인

	for (int x = 0; x <= 5; x++) {
		int cnt = 4;
		for (int y = 0; y <= 3; y++) {
			if (Map[x][y] == true) cnt--;
			else break;
		}
		if (cnt == 0) {
			//cout << "잇다";
			LineBreak(Map,x); //3. 부수기
			Ans++;
		}
	}

}

void BreakLight(bool Map[6][4],int cnt) {


	for (int i = 5 - cnt; i >= 0; i--) {
		for (int j = 0; j <= 3; j++) {
			Map[i + cnt][j] = Map[i][j];
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j <= 3; j++) {
			Map[i][j] = false;
		}
	}
	


}
void Light(bool Map[6][4]) {
	int cnt = 0;
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 3; j++) {
			if (Map[i][j] == true) {
				cnt++; break;
			}
		}
	}

	if (cnt > 0) {
		BreakLight(Map,cnt);
	}

}
void Count() {
	int cnt = 0;
	for (int x = 0; x <= 5; x++) {
		for (int y = 0; y <= 3; y++) {
			if (green[x][y] == true) cnt++;
			if (blue[x][y] == true)cnt++;
		}
	}
	cout << cnt;
}

void transPos(int* t, int* x, int* y) { //블루 그린 변형

	//(x.y)->(y,3-x)

	int tx = *x;
	int ty = *y;

	*x = ty, *y = 3 - tx;

	if (*t == 2) *t = 3;
	else if (*t == 3) {
		*t = 2;
		*y = *y - 1;
	}

}

void Solution() {

	int t, x, y;
	for (int i = 0; i < N; i++) {
		//cout << i << "번째" << endl;
		cin >> t >> x >> y;

		
		DownBlock(green, t, x, y);
		transPos(&t, &x, &y);
		DownBlock(blue, t, x, y);

		//printgreen();

		Break(green); // 꽉찬 행이 있는지 확인
		Break(blue);
		//printgreen();

		Light(green); //밝은 영역에 있는가 
		Light(blue); //밝은 영역이 있는가

		//printgreen();

	}
	
	cout << Ans<<endl;
	Count();
	
}
int main() {
	
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);
	
	Input();
	Solution();

	return 0;
}