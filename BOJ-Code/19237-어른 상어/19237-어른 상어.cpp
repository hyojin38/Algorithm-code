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
	int cnt; //���� ��� ��
	vector<int> V; //���� ��� num vector
};
check MAP[MAX][MAX];
visited MAP2[MAX][MAX];
int dx[5] = {0,-1,1,0,0};
int dy[5] = {0,0,0,-1,1};

struct shark{
	int x, y, d,num;//x,y,����.���° ���
	int nd[5][5] = {}; //�켱����
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
	V.push_back({ s,true }); //0��° �����

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
	//����� ���� :1�� 2�Ʒ� 3���� 4������
	for (int i = 1; i <= M; i++) {
		cin>> V[i].first.d;
	}
	
	//����� �켱����
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
		if (V[i].second == false) {//���� �ȿ� �ִ�
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
	//cout << shnum << "����";
	//1.������ ĭ �� �ƹ� ���� ���� ĭ�� ����
	for (int a = 1; a <= 4; a++) {//4���ݺ�
		int b = s.nd[d][a];//�켱����
		//cout << b;
		int nx = x + dx[b];
		int ny = y + dy[b];
		int nd = b;//�ٶ󺸴� ����

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
		//2.�ڽ��� ���� �ִ� ĭ
		for (int a = 1; a <= 4; a++) {//4���ݺ�
			int b = s.nd[d][a];//�켱����
			int nx = x + dx[b];
			int ny = y + dy[b];
			int nd = b;//�ٶ󺸴� ����

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
		//3. �̵� �Ұ���
		MAP2[x][y].cnt++;
		MAP2[x][y].V.push_back(shnum);
		return;
	}
	//cout << endl;
}
void Sol2() {//���� ����

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (MAP[i][j].t != 0 ) { //��������
				if (i == (V[MAP[i][j].snum].first.x) && j == (V[MAP[i][j].snum].first.y))continue;
				else MAP[i][j].t= MAP[i][j].t - 1;
			}
			if (MAP[i][j].t == 0) MAP[i][j].snum = 0;//0�� �Ǹ� snum�� 0
		}
	
	}
}
void Clear() {
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (MAP2[i][j].cnt !=0) {
			//	cout << i << "." << j << "��" << MAP2[i][j].cnt << "��ŭ ��� :";
				int min = M + 1;
				for (int k = 0; k < MAP2[i][j].V.size(); k++) {
					//cout << MAP2[i][j].V[k] << ",";
					if (MAP2[i][j].V[k] < min) {
						min = MAP2[i][j].V[k];
					}
				}
				//��÷
				//cout << "��" << min << "��÷"<<endl;
				//�̴�÷�� ����
				for (int k = 0; k < MAP2[i][j].V.size(); k++) {
					if (MAP2[i][j].V[k] != min) {
						int temp= MAP2[i][j].V[k];
						V[temp].second = true;
						Scnt--;
						//cout << "Scnt:"<<Scnt;
					}
				}
				
			}
			//MAP ����
			MAP2[i][j].cnt = 0;
			MAP2[i][j].V.clear();
		}

	}


	
}
void Sol3() {
	for (int i = 1; i <= M; i++) { //��� ���
		if (V[i].second == false) {//���� �ȿ� �ִ�
			Move(i);
		}
	}	
}
void Solution() {
	int T = 0;
	Sol1();//1.�ڽ��� ��ġ�� �ڽ��� ������ �Ѹ�
	while (true) {
		T++;
		//cout << T<<"]"<<endl;
		
		Sol3();//3. 1���� ��� ��� ���ÿ� �����¿� �� �ϳ��� �̵��ϸ� ���� �Ѹ�
		Clear();//4. ���� �̵��� �� ��ĭ�� �������� �� ������ ���� ���� ��ȣ ���� �i�ܳ�
		Sol1();//1.�ڽ��� ��ġ�� �ڽ��� ������ �Ѹ�
		Sol2();//2.��������
		
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

