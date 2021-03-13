# include <iostream>
#include <vector>
#include <queue>
#include<cstring>
#define endl "\n"
#define MAX 20+1

using namespace std;

int N,M,T;
bool check;
int MAP[MAX][MAX];
int visited[MAX][MAX];
int SX, SY ,SS; //물고기 X,Y,SIZE;
queue<pair<pair<int, int>, int> > Q;
queue<pair<pair<int, int>, int> > HQ;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout<< MAP[i][j];
		}
		cout << endl;
	}
}
void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 9) {
				SX = i;
				SY = j;
				MAP[i][j] = 0;
			}
			else if (MAP[i][j] != 0) {
				Q.push({ {i,j},MAP[i][j] });
				M++;
			}
		}
	}

}
bool hunt() {
	if (M == 0) return false;
	int s = Q.size();
	for (int i = 0; i < s; i++) {
		if (Q.front().second < SS && MAP[Q.front().first.first][Q.front().first.second] != 0) { //먹을 수 있다
			HQ.push({ {Q.front().first.first,Q.front().first.second},Q.front().second });
		}
		if (MAP[Q.front().first.first][Q.front().first.second] != 0) {
			Q.push({ {Q.front().first.first,Q.front().first.second},Q.front().second });
		}		
		Q.pop();
	}
	//cout << HQ.size()<<endl;
	if (HQ.size() > 0) return true;
	else return false;
}

int dist(int px, int py) {
	for (int i = 0; i < N; i++) {
		memset(visited[i], 0, sizeof(visited[i]));
	}
	//SX,SY, px,py
	
	queue < pair <pair <int, int >, int > > QD;
	QD.push({{ SX,SY},0 } );
	visited[SX][SY] = 1;
	int d;
	while (!QD.empty()) {
		int x = QD.front().first.first;
		int y = QD.front().first.second;
		d = QD.front().second;
		QD.pop();
		//cout << "dist"<<x<<","<<y<<"." << d << endl;
		if (x == px && y == py) {
			return d;
		}
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (MAP[nx][ny] > SS) continue; // 지나갈 수 없다
			if (visited[nx][ny] == 1) continue;

			visited[nx][ny] = 1;
			int nd = d+1;
			
			QD.push({ {nx,ny},nd });

		}
	}
	return -1;
}
void Solution() {
	T = 0;
	SS = 2;
	int ESS = 0;
	int px, py, ps, pd=0;
	bool check = true;
	while (true) {

		//더 이상 먹을 수 있는 물고기가 공간에 없다
		if (hunt() == false) {
			check = true;
			return;
		}

		if (HQ.size() == 1) {
			px = HQ.front().first.first;
			py = HQ.front().first.second;
			ps = HQ.front().second;
			pd = dist(px, py);
			if (pd == -1) {
				check = true;
				return;
			}		
			//cout <<"pd"<< pd;
			check = false;
			HQ.pop();
		}
		else if(HQ.size()>1) {
			//HQ 중 가장 거리 가까운 물고기 선택
			int hqn = HQ.size();
			int ipx, ipy, ips, id;
			int idcnt = 0;
			for (int i = 0; i < hqn; i++) {
				ipx = HQ.front().first.first;
				ipy = HQ.front().first.second;
				ips = HQ.front().second;
				HQ.pop();
				
				id = dist(ipx, ipy);
				//cout << id << ":";
				
				if (id != -1) {//갈수 있다
					idcnt++;
					check = false;
					if (idcnt == 1 || id < pd) {
						px = ipx;
						py = ipy;
						ps = ips;
						pd = id;
					}
					else if (id == pd) {
						if (ipx < px) {
							px = ipx;
							py = ipy;
							ps = ips;
						}
						else if (ipx == px) {
							if (ipy < py) {
								px = ipx;
								py = ipy;
								ps = ips;
							}
						}
					}
				}
		
			}
			if (idcnt == 0) {
				check = true;
				return;
			}

		}

		if (check == false) {
			T = pd + T;
			//cout << SS<<")"<<SX<<","<<SY<<"-"<<px<<","<<py<<"="<<T<<endl;
			ESS++;
			MAP[px][py] = 0;
			M--;
			SX = px;
			SY = py;

			if (ESS >= SS) {
				ESS = ESS - SS;
				SS++;
			}
		}
			
	
		
		
		//print();
	}
	

}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	//print();
	Solution();
	cout << T;

	return 0;

}