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
void Downgreen(int t,int x, int y) {
	if (t == 1) {
		for (int x = 1; x <=5; x++) {
			if (green[x][y] == true) {
				green[x - 1][y] = true;
				return;
			}
		}
		green[5][y] = true;
		return;
	}
	else if (t == 2) {
		for (int x = 1; x <= 5; x++) {
			if (green[x][y] == true || green[x][y + 1] == true) {
				green[x - 1][y] = true; green[x - 1][y + 1] = true;
				return;
			}
		}
		green[5][y] = true; green[5][y + 1] = true;
		return;
	}
	else if (t == 3) {
		for (int x = 1; x <= 5; x++) {
			if (green[x][y] == true) {
				green[x - 1][y] = true; green[x - 2][y] = true;
				return;
			}
		}
		green[5][y] = true; green[4][y] = true;
		return;
	}
}
void Downblue(int t, int x, int y) {
	if (t == 1) {
		for (int x = 1; x <= 5; x++) {
			if (blue[x][y] == true) {
				blue[x - 1][y] = true;
				return;
			}
		}
		blue[5][y] = true;
		return;
	}
	else if (t == 2) {
		for (int x = 1; x <= 5; x++) {
			if (blue[x][y] == true) {
				blue[x - 1][y] = true; blue[x - 2][y] = true;
				return;
			}
		}
		blue[5][y] = true; blue[4][y] = true;
		return;
	}
	else if (t == 3) {
		for (int x = 1; x <= 5; x++) {
			if (blue[x][y] == true || blue[x][y - 1] == true) {
				blue[x - 1][y] = true; blue[x - 1][y - 1] = true;
				return;
			}
		}
		blue[5][y] = true; blue[5][y - 1] = true;
		return;
	}

}
void greenLineBreak(int t) {
	
	
	for (int y = 0; y <= 3; y++) {
		green[t][y] = false;
	}
	
	if(t!=0) {
		for (int x = t - 1; x >= 0; x--) {
			
			for (int y = 0; y <= 3; y++) {
				if (green[x][y] == true) {
					green[x][y] = false;
					green[x + 1][y] = true;
				}
			}
		}
	}
	
	
}
void blueLineBreak(int t) {

	for (int y = 0; y <= 3; y++) {
		blue[t][y] = false;
	}

	if (t != 0) {
		for (int x = t - 1; x >= 0; x--) {

			for (int y = 0; y <= 3; y++) {
				if (blue[x][y] == true) {
					blue[x][y] = false;
					blue[x + 1][y] = true;
				}
			}
		}
	}


}
void Breakgreen() {
	for (int x = 0; x <=5 ; x++) {
		int cnt = 4;
		for (int y = 0; y <= 3; y++) {
			if (green[x][y] == true) cnt--;
			else break;
		}
		if (cnt == 0) {
			greenLineBreak(x);
			Ans++;
		}
	}
}
void Breakblue() {
	for (int x = 0; x <= 5; x++) {
		int cnt = 4;
		for (int y = 0; y <= 3; y++) {
			if (blue[x][y] == true) cnt--;
			else break;
		}
		if (cnt == 0) {
			blueLineBreak(x);
			Ans++;
		}
	}
}
void BreakLightgreen(int cnt) {
	for (int i = 5; i <= 5 + 1 - cnt; i++) {
		for (int j = 0; j <= 3; j++) {
			green[i][j] = false;
		}

	}
	for (int i = 5 - cnt; i >= 0; i--) {
		for (int j = 0; j <= 3; j++) {
			if (green[i][j] == true) {
				green[i + cnt][j] = true;
				green[i][j] = false;
			}
		}
	}
}
void BreakLightblue(int cnt) {
	for (int i = 5; i <= 5+1-cnt; i++) {
		
		for (int j = 0; j <= 3; j++) {
			blue[i][j] = false;
		}
		
	}

	for (int i = 5 - cnt; i >= 0; i--) {
		for (int j = 0; j <= 3; j++) {
			if (blue[i][j] == true) {
				blue[i + cnt][j] = true;
				blue[i][j] = false;
			}
		}
	}
}
void Lightgreen() {
	int cnt = 0;
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 3; j++) {
			if (green[i][j] == true) {
				cnt++; break;
			}
		}
	}

	
	if (cnt > 0) {
		BreakLightgreen(cnt);
	}

}
void Lightblue() {
	int cnt = 0;
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 3; j++) {
			if (blue[i][j] == true) {
				cnt++; break;
			}
		}
	}

	if (cnt > 0) {
		BreakLightblue(cnt);
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
void Solution() {

	int t, x, y;
	for (int i = 0; i < N; i++) {
		cin >> t >> x >> y;
		cout << i << "¹øÂ°"<<endl;
		Downgreen(t, x, y);
		Downblue(t, y, 3-x);
		printgreen();
		//printblue();
		cout << endl;
		Breakgreen();
		Breakblue();
		
		Lightgreen();
		Lightblue();
		printgreen();
		//printblue();
		
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