//���� �ϴ� ���� �濡 ���� ų �� �ִ� ����ġ�� ����
// ����ġ�� ���� Ű��
//���� ���� ������ �ش� ������ �Ű� �� �� �ִ�
//������ �� ������ ���� ����
#include<iostream>
#include<vector>
#include<queue>
#pragma warning(disable:4996)
#define endl "\n"
#define MAX 101

using namespace std;

int N, M, Ans;
struct Light {
	int x;
	int y;
};
int MAP[MAX][MAX];
bool visitedlight[MAX][MAX];
queue <pair<int, int> > Q;
queue <pair<int, int> > EQ;
vector<Light> ListMap[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void Input() {

	cin >> N >> M;

	int x, y, a, b; //a,b�� ���� �Ѵ� ����ġ�� x,y�� �ִ�
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> a >> b;
		Light linput = { a,b };
		ListMap[x][y].push_back(linput);
	}


}

void Qpush(int x, int y) {
	vector<Light> V = ListMap[x][y];
	for (int i = 0; i < V.size(); i++) {
		int cx = V[i].x;
		int cy = V[i].y;
		if (MAP[cx][cy] == 1 || visitedlight[cx][cy] == true) continue;
		//����  visitedlight[cx][cy]==1 �̸� Q�� ���� ����

		Q.push(make_pair(cx, cy));
		//cout << cx << "," << cy << endl;
		visitedlight[cx][cy] = true;
		Ans++;


	}

}
void bfs() {
	MAP[1][1] = 1;
	Qpush(1, 1);//1.1���� ����ϴ� ����
	Ans++;// ù��° �濡�� ���� ���� �ִ�
	visitedlight[1][1] = true;

	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		bool check = false;
		Q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
			if (MAP[nx][ny] == 0) continue;



			MAP[x][y] = 1;

			Qpush(x, y);
			for (int i = 0; i < EQ.size(); i++) {
				int cx = EQ.front().first;
				int cy = EQ.front().second;
				EQ.pop();
				Q.push(make_pair(cx, cy));
			}
			check = true;
		}
		if (!check) EQ.push(make_pair(x, y));

	}
}
void Solution() {
	bfs();//1,1���� ����ϴ� ����
	cout << Ans;

}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);
	//Init();
	Input();
	Solution();
	return 0;
}