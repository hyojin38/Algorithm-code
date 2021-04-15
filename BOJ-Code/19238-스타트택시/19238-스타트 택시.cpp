#include <iostream>
#include <vector>
#include <queue>

#define MAX 20+1
#define endl "\n"

using namespace std;

int N, M, P;
int MAP[MAX][MAX];
int Sx, Sy, Ex, Ey;
bool checkM[400+ 1] = { false, }; //M���� �°� �����ߴ°� üũ
vector <pair<pair<int, int>, pair<int, int> > > V;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue <pair<pair <int, int>, int > > Q;

void Input() {
	cin >> N >> M >> P;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
		}
	}
	cin >> Sx >> Sy;
	int x, y, dx, dy;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> dx >> dy;
		V.push_back({ { x,y }, {dx,dy} });
		checkM[i] = false;
		
	}
}

int BFS(int sx, int sy, int ex, int ey, int selectPdir) { // s-e ������ �ִܰŸ�
	while (!Q.empty()) {
		Q.pop();
	}
	bool visited[MAX][MAX];
	Q.push({ { sx,sy }, 0 });
	visited[sx][sy] = true;

	while (!Q.empty()) {
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int cnt = Q.front().second;
		Q.pop();

		if (selectPdir != -1 && selectPdir < cnt)
			return selectPdir + 1;
		if (x == ex && y == ey) {
			return cnt;
		}

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			int ncnt = cnt + 1;

			if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
			if (MAP[nx][ny] == 1) continue;
			if (visited[nx][ny] == true) continue;

			visited[nx][ny] = true;
			Q.push({ {nx,ny} ,ncnt });
		}


	}
	//������ �� ���� ���
	return -1;

}
bool Sol1() {
	//����ġ���� �ִܰŸ� ����
	int sx = Sx;
	int sy = Sy;
	int selectPnum = -1;
	int selectPdir = -1;

	for (int i = 0; i < M; i++) {
		if (checkM[i] == true) continue;
		int dx = V[i].first.first;
		int dy = V[i].first.second;
		int tempdir = BFS(sx, sy, dx, dy, selectPdir);
		//cout << tempdir;
		if (tempdir == -1)continue; //�������� ���ϴ°��
		if (selectPnum == -1) {
			selectPdir = tempdir; selectPnum = i;
			//cout << i << "��";
		}
		else {
			if (selectPdir > tempdir) {
				selectPdir = tempdir; selectPnum = i;
				
			}
			else if (selectPdir == tempdir) {
				if (V[selectPnum].first.first > dx) { selectPdir = tempdir; selectPnum = i; //cout << "xwin"<<i;
				}
				else if (V[selectPnum].first.first == dx) {
					if (V[selectPnum].first.second > dy) {
						selectPdir = tempdir; selectPnum = i;
						//cout << "ywin" << i;
					}
				}
			}
		}
		//cout << endl;
	}

	if (selectPdir == -1) {
		return false;
	}
	//���ᰡ���Ѱ�?
	//cout << "����:" << selectPnum << "�մ� " << P << "-" << selectPdir;
	if (P >= selectPdir) {
		Sx = V[selectPnum].first.first;
		Sy = V[selectPnum].first.second;
		Ex = V[selectPnum].second.first;
		Ey = V[selectPnum].second.second;
		checkM[selectPnum] = true;
		P -= selectPdir;
		//cout << P << endl;
		return true;
	}
	else {
	
		return false;
	}



}
bool Sol2() {
	//����ġ���� ���������� �ִܰŸ� 
	int sx = Sx;
	int sy = Sy;
	int dx = Ex;
	int dy = Ey;
	int dir = BFS(sx, sy, dx, dy, -1);

	if (dir == -1) {
		return false;
	}
	//cout << "����:" << P << "-" << dir;
	//���ᰡ���Ѱ�?
	if (P >= dir) {
		Sx = Ex;
		Sy = Ey;
		P -= dir;
		//cout << P << "->" ;
		P = P + (dir * 2);
		//cout << P << endl;
		return true;
	}
	else {
		
		return false;
	}

}
void Solution() {

	for (int i = 0; i < M; i++) {
		//cout << i;
		//cout << "���� ��" <<endl;
		//1.����ġ���� �¿�� ����
		if (!Sol1()) { cout << -1; return; }
		//2. �� �������� �̵�
		if (!Sol2()) { cout << -1; return; }
	}
	//cout << endl;
	cout << P;


}
int main() {

	freopen("Text.txt", "r", stdin); 
	cin.tie(NULL); cout.tie(NULL);

	Input();
	Solution();

	return 0;
}