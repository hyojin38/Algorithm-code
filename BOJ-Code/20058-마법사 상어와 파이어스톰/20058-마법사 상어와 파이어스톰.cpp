#include<iostream>
#include<vector>
#include<queue>
#define endl "\n"
#define MAX 64+1
using namespace std;

int N, Q,M;
int A1, A2;
int MAP[MAX][MAX];
int tempMAP[MAX][MAX];
vector<int> FireStormV;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
bool visited[MAX][MAX];
queue <pair<int, int> > QAns;

int Squar(int x) {
	int a = 1;
	if (x != 0) {
		for (int i = 1; i <= x; i++) {
			a *= 2;
		}
	}
	else {
		a = 1;
	}
	return a;
}
void print() {
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= M; j++) {
			cout << MAP[i][j];
		}
		cout << endl;
	}
}
void Input() {
	cin >> N >> Q;
	M = Squar(N);
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> MAP[i][j];
		
		}
	
	}
	int temp;
	for (int i = 0; i < Q; i++) {
		cin >> temp;
		FireStormV.push_back(temp);
	}

}

//void Storm1(int x, int y, int b, int d) { //tempMAP에 저장
//	for (int i = x; i < x + b; i++) {
//		for (int j = y; j < y + b; j++) {
//			int nx = i + dx[d]*b;
//			int ny = j + dy[d]*b;
//			tempMAP[nx][ny] = MAP[i][j];
//		}
//	}
//}
void Storm2(int x, int y, int a) { //tempMAP을 MAP에 저장
	for (int i = x; i < x + a; i++) {
		for (int j = y; j < y + a; j++) {
			MAP[i][j] = tempMAP[i][j];
		}
	}
}
void F1(int x, int y,int a) { // 
	int ny = y + a-1;
	for (int i = x; i < x + a; i++) {
		int nx = x;
		for (int j = y; j < y + a; j++) {
			tempMAP[nx][ny] = MAP[i][j];
			nx++;
		}
		ny--;
	}
	Storm2(x, y, a);
} 
void FireStorm1(int L) {
	int a= Squar(L);//제곱근
	//int b = a / 2;
	for (int i = 1; i <= M; i=i+a) {
		for (int j = 1; j <= M; j = j + a) {
			F1(i, j,a);
		}
	}

}
void FireStorm2() {//얼음이있는 칸 3개 인접하지 않으면 1 줄어든다 != 얼음이 있는 칸 2개이상 인접하면
	vector<pair<int, int> > V;
	
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= M; j++) {
			int cnt = 0;
			if (MAP[i][j] == 0) continue;

			for (int d = 0; d < 4; d++) {
				int nx = i + dx[d];
				int ny = j + dy[d];
				if (nx <= 0 || ny <= 0 || nx > M || ny > M) continue;
				if (MAP[nx][ny] == 0) continue;
				cnt++;
			}
			if (cnt < 3) {
				V.push_back({ i,j });
			}
		}
	}

	for (int i = 0; i < V.size(); i++) {
		MAP[V[i].first][V[i].second]--;
	}

}
void Sum() {
	A1 = 0;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= M; j++) {
			A1 += MAP[i][j];
		}
	}
	cout << A1 << endl;
}
void BFS() {
	int cnt = 1;
	while (!QAns.empty()) {
		int x = QAns.front().first;
		int y = QAns.front().second;
		QAns.pop();

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx<0 || ny<0 || nx>M || ny>M) continue;
			if (MAP[nx][ny] == 0) continue;
			if (visited[nx][ny] == true) continue;

			QAns.push({ nx,ny });
			visited[nx][ny] = true;
			cnt++;
		}

	}

	if (A2 < cnt) {
		A2 = cnt;
	}

}
void Sum2() {
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= M; j++) {
			if (MAP[i][j] != 0) {
				QAns.push({ i,j });
				visited[i][j] = true;
				BFS();

			}
		}
	}

	cout << A2;
}
void Solution() {

	//1.파이어스톰
	for (int L = 0; L < FireStormV.size(); L++) {
		if (FireStormV[L] != 0) {
			FireStorm1(FireStormV[L]);
		}
		FireStorm2();
		
	}
	
	//2.남아있는 얼음의 합
	Sum();
	//3.남아있는 얼음 중 가장 큰 덩어리가 차지하는 칸의 수
	Sum2();
}
int main() {

	freopen("Text.txt", "r", stdin); cin.tie(NULL); cout.tie(NULL);
	Input();
	Solution();

	return 0;

}