#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define MAX 1000+1
#define endl "\n"
using namespace std;

int H, W;
int MAP[MAX][MAX];
int dx[] = { 0,1,1,1,0,-1,-1,-1 };
int dy[] = { 1,1,0,-1,-1,-1,0,1 };
vector <pair <int, int> > V1; //존재하는 모래성
vector <pair <int, int> > V2;//무너짐
void Input() {
	cin >> H >> W;
	string temp;
	char chtemp;
	for (int i = 0; i < H; i++) {
		cin >> temp;
		for (int j = 0; j < W; j++) {
			chtemp = temp[j];
			if (chtemp == '.') MAP[i][j] = 0;
			else {
				MAP[i][j] = chtemp - '0';
				V1.push_back({ i,j });
			}

		}
	}
}
bool Break() {

	vector <pair<int, int> > Vtemp = V1;
	V1.clear();
	V2.clear();
	int cnt = 0;
	for (int i = 0; i < Vtemp.size(); i++) {
		int x = Vtemp[i].first;
		int y = Vtemp[i].second;
		int st = MAP[x][y];

		int vs = 0;
		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
			if (MAP[nx][ny] > 0) continue;
			vs++;
		}

		//cout << x << "." << y << "vs;" << vs << "st:" << st << endl;
		if (vs >= st) {//무너질 수 있다
			V2.push_back({ x,y });
			cnt++;
		}
		else {
			V1.push_back({ x,y });
		}

	}
	if (cnt > 0) {
		for (int i = 0; i < V2.size(); i++) {
			int x = V2[i].first;
			int y = V2[i].second;
			MAP[x][y] = 0;

		}
		return true;
	}
	else {
		return false;
	}



}
void print() {
	cout << endl;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << MAP[i][j];
		}
		cout << endl;
	}

}
void Solution() {
	int cnt = 0;
	while (true) {

		if (Break() == false) {
			break;
		}
		//	print();
		cnt++;
		//cout << cnt;
	}
	cout << cnt;

}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen("Text.txt", "r", stdin);

	Input();
	Solution();

	return 0;
}