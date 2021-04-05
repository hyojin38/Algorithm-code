#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define MAX 50+1
#define endl "\n"

using namespace std;

struct Fireball {
	int x, y, m, s, d;
};
struct Fireballs {
	int cnt;
	vector <Fireball> FV;
};

int N, M, K, Ans;
vector <Fireball> FVector;
Fireballs MAP[MAX][MAX];
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

//Fireballs MAPafter[MAX][MAX];

void print() {
	cout << FVector.size() << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << MAP[i][j].FV.size();

		}
		cout << endl;
	}
}
void Init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			MAP[i][j].cnt = 0;
			MAP[i][j].FV.clear();
		}
	}
}
void Input() {
	cin >> N >> M >> K;

	int x, y, m, s, d;
	Fireball f;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> m >> s >> d;
		f.x = x; f.y = y; f.m = m; f.s = s; f.d = d;
		FVector.push_back(f);

	}


}
void sol1() {// 1
	//MAP초기화
	Init();

	int size = FVector.size();
	Fireball f;
	int x, y, m, s, d;
	int nx, ny;

	for (int i = 0; i < size; i++) {
		f = FVector[i];
		x = f.x; y = f.y; m = f.m; s = f.s; d = f.d;
		//cout << x << y << m << s << d << endl;
		//자신의 방향d으로 속력s만큼 이동
		for (int k = 0; k < s; k++) {
			nx = x + dx[d];
			ny = y + dy[d];
			if (nx == 0) nx = N;
			if (ny == 0) ny = N;
			if (nx > N) nx = 1;
			if (ny > N) ny = 1;
			x = nx;
			y = ny;
		}
		//cout << nx << ny << m << s << d << endl;

		f.x = nx; f.y = ny;

		//MAP에 저장

		Fireballs fs = MAP[nx][ny];
		fs.cnt++;
		fs.FV.push_back(f);
		MAP[nx][ny] = fs;

		//cout << MAP[nx][ny].cnt<<" "<<nx<<"."<<ny<<endl;
		//cout<< endl;

	}

	//print();

}
void sol2(int x, int y) { // 2개 이상의 파이어볼이 있는 칸
	Fireballs fs = MAP[x][y];
	vector<Fireball> V = fs.FV;
	int Sm = 0;
	int Ss = 0;
	bool Sdcheck = false;
	for (int i = 0; i < fs.cnt; i++) {
		Sm += V[i].m;//질량
		Ss += V[i].s;//속력
		//cout << "방향";
		if (i != 0) {
			bool tmp;
			tmp = (((V[i - 1].d) % 2) != ((V[i].d) % 2));
			//cout << "tmp"<<tmp <<endl; //같지않으면 ture;
			Sdcheck = Sdcheck || tmp;
			//cout << "tmp합"<<Sdcheck<<endl;
		}
	}


	Fireball f;
	f.x = x; f.y = y;
	f.m = Sm / 5;
	f.s = Ss / fs.cnt;
	int dir = 0;
	if (f.m > 0) { //4.질량이 0인 파이어볼은 소멸

		for (int i = 0; i < 4; i++) {
			if (Sdcheck == false) {
				//cout << "모두 동일"; //0,2,4,6
				f.d = dir;
			}
			else {
				if (i == 0) dir++;
				f.d = dir;
			}
			dir += 2;

			//벡터에 집어넣음
			FVector.push_back(f);
		}


	}

}
void Solution() {

	for (int k = 0; k < K; k++) {
		//cout << k <<"]"<< endl;
		//1. 모든 파이어볼 자신의 방향으로 속력 칸만큼이동
		sol1();

		FVector.clear();
		//2.이동이 모두 끝난뒤 2개 이상의 파이어볼이 있는칸
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (MAP[i][j].cnt >= 2) sol2(i, j);
				else if (MAP[i][j].cnt > 0) {
					//FVector에 집어넣기
					Fireball f = MAP[i][j].FV.front();
					FVector.push_back(f);
				}
			}
		}

	}

	// 남아있는 파이어볼 질량의 합
	for (int i = 0; i < FVector.size(); i++) {
		Ans += FVector[i].m;
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
