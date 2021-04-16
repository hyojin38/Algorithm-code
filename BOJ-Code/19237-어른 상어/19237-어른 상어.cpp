#include <iostream>
#include <vector>
#include <queue>
#define MAX 20+1
#define endl "\n"

using namespace std;

int N, M, K,Scnt;
struct check {
	int t, snum;
};
struct visited
{
	int cnt; //모인 상어 수
	vector<int> V; //모인 상어 num vector
};
check MAP[MAX][MAX];
visited MAP2[MAX][MAX];
int dx[5] = {0,-1,1,0,0};
int dy[5] = {0,0,0,-1,1};

struct shark{
	int x, y, d,num;//x,y,방향.몇번째 상어
	int nd[5][5] = {}; //우선순위
};
vector <pair<shark, bool> > V;
void printcnt() {
	cout << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << MAP[i][j].snum;
		}
		cout << endl;
	}
}
void printtime() {
	cout << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << MAP[i][j].t;
		}
		cout << endl;
	}
}
void Input() {
	shark s;
	check c;
	c.snum = 0;
	c.t = 0;
	V.push_back({ s,true }); //0번째 만들기

	cin >> N >> M >> K;
	Scnt = M;
	//cout << M;
	for (int i = 1; i <= M; i++) {
		V.push_back({ s ,false });
	}
	int temp;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> temp;
			if (temp == 0) {
				c.snum = 0;
				c.t = 0;
				MAP[i][j] = c;
			}else if (temp != 0) {
				V[temp].first.x = i;
				V[temp].first.y = j;
				V[temp].first.num = temp;
				
			}
			//cout << MAP[i][j].snum;
		}
		//cout << endl;
	}
	//상어의 방향 :1위 2아래 3왼쪽 4오른쪽
	for (int i = 1; i <= M; i++) {
		cin>> V[i].first.d;
	}
	
	//상어의 우선순위
	for (int i = 1; i <= M; i++) {
		
		for (int k = 1; k <= 4; k++) {
			for (int kk = 1;kk <= 4; kk++) {
				cin >> V[i].first.nd[k][kk];
				
			}
		 }	
	}
	
}
void Sol1() {
	for (int i = 1; i <= M; i++) {
		if (V[i].second == false) {//아직 안에 있다
			check c;
			c.snum = i;
			c.t = K;
			int x = V[i].first.x;
			int y = V[i].first.y;
			//cout << i << "(" << x << "." << y << "d:" << V[i].first.d<<")";
			MAP[x][y] = c; 

		}
	}
	//printcnt();
}
void Move(int shnum) {
	bool move = false;
	shark s = V[shnum].first;

	int x = s.x;
	int y = s.y;
	int d = s.d;
	//cout << shnum << "방향";
	//1.인접한 칸 중 아무 냄새 없는 칸의 방향
	for (int a = 1; a <= 4; a++) {//4번반복
		int b = s.nd[d][a];//우선순위
		//cout << b;
		int nx = x + dx[b];
		int ny = y + dy[b];
		int nd = b;//바라보는 방향

		if (nx <= 0 || ny <= 0 || nx > N || ny > N)  continue;
		if (MAP[nx][ny].t != 0) continue;
		if (move == true) continue;

		move = true;
		MAP2[nx][ny].cnt++;
		MAP2[nx][ny].V.push_back(shnum);
		V[shnum].first.x = nx;
		V[shnum].first.y = ny;
		V[shnum].first.d = nd;
		return;

	}
	if (move == false) {
		//2.자신의 냄새 있는 칸
		for (int a = 1; a <= 4; a++) {//4번반복
			int b = s.nd[d][a];//우선순위
			int nx = x + dx[b];
			int ny = y + dy[b];
			int nd = b;//바라보는 방향

			if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
			if (MAP[nx][ny].snum != shnum) continue;
			if (move == true) continue;

			move = true;
			MAP2[nx][ny].cnt++;
			MAP2[nx][ny].V.push_back(shnum);
			V[shnum].first.x = nx;
			V[shnum].first.y = ny;
			V[shnum].first.d = nd;
			return;
		}
	}
	if (move == false) {
		//3. 이동 불가능
		MAP2[x][y].cnt++;
		MAP2[x][y].V.push_back(shnum);
		return;
	}
	//cout << endl;
}
void Sol2() {//냄새 감소

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (MAP[i][j].t != 0 ) { //냄새감소
				if (i == (V[MAP[i][j].snum].first.x) && j == (V[MAP[i][j].snum].first.y))continue;
				else MAP[i][j].t= MAP[i][j].t - 1;
			}
			if (MAP[i][j].t == 0) MAP[i][j].snum = 0;//0이 되면 snum도 0
		}
	
	}
}
void Clear() {
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (MAP2[i][j].cnt !=0) {
			//	cout << i << "." << j << "에" << MAP2[i][j].cnt << "만큼 상어 :";
				int min = M + 1;
				for (int k = 0; k < MAP2[i][j].V.size(); k++) {
					//cout << MAP2[i][j].V[k] << ",";
					if (MAP2[i][j].V[k] < min) {
						min = MAP2[i][j].V[k];
					}
				}
				//당첨
				//cout << "중" << min << "당첨"<<endl;
				//미당첨은 퇴출
				for (int k = 0; k < MAP2[i][j].V.size(); k++) {
					if (MAP2[i][j].V[k] != min) {
						int temp= MAP2[i][j].V[k];
						V[temp].second = true;
						Scnt--;
						//cout << "Scnt:"<<Scnt;
					}
				}
				
			}
			//MAP 정리
			MAP2[i][j].cnt = 0;
			MAP2[i][j].V.clear();
		}

	}


	
}
void Sol3() {
	for (int i = 1; i <= M; i++) { //모든 상어
		if (V[i].second == false) {//아직 안에 있다
			Move(i);
		}
	}	
}
void Solution() {
	int T = 0;
	Sol1();//1.자신의 위치에 자신의 냄새를 뿌림
	while (true) {
		T++;
		//cout << T<<"]"<<endl;
		
		Sol3();//3. 1초후 모든 상어 동시에 상하좌우 중 하나로 이동하며 냄새 뿌림
		Clear();//4. 모든상어가 이동한 후 한칸에 여러마리 상어가 남으면 가작 작은 번호 빼고 쫒겨남
		Sol1();//1.자신의 위치에 자신의 냄새를 뿌림
		Sol2();//2.냄새감소
		
		if (T > 1000) {
			cout << -1;
			return;
		}if (Scnt == 1 ) {//&& V[1].second == false
			cout << T;
			return;
		}
	}

}
int main() {

	freopen("Text.txt", "r", stdin);
	cin.tie(NULL); cout.tie(NULL);

	Input();
	Solution();

	return 0;
}

