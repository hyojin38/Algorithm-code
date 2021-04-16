#include <iostream>
#include <vector>
#include <queue>
#define MAX 4+1
#define endl "\n"

using namespace std;

int Ans;
struct Fishdetail
{
	int dir, x, y, isdeath;
};
Fishdetail FishCheck[16 + 1];
int FishMAP[MAX][MAX];
struct Fish
{
	Fishdetail FishCheck[16 + 1];
	int FishMAP[MAX][MAX];
};
struct Shark
{
	int Sx, Sy, Sd,Ssum;
};
queue <pair<Fish,Shark> > Q;
int dx[9] = {0,-1,-1,0,1,1,1,0,-1};
int dy[9] = {0,0,-1,-1,-1,0,1,1,1};

void printMAP(int FishMAP[][MAX]) {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			cout << FishMAP[i][j]<<" ";
		}
		cout << endl;
	}
}
void Input() {
	int a, b;
	Fishdetail f;
	f.isdeath = false;

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			cin >> a >> b;//a��ȣ .b����
			FishMAP[i][j] = a;
			
			f.dir= b;
			f.x = i;
			f.y = j;
			FishCheck[a] = f;
		}
	
	}
	
	
}
void Sol1() {

	int Sx = 1;
	int Sy =1 ;
	int fishnum = FishMAP[1][1];
	Fishdetail f = FishCheck[fishnum];
	int Sdir = f.dir;
	f.isdeath = true;// ����� ����
	FishMAP[1][1] = 0;//0.0 ���ڸ�
	FishCheck[fishnum] = f;

	Fish fish;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			fish.FishMAP[i][j] = FishMAP[i][j];
		}
	}
	for (int i = 1; i <= 16; i++) {
		fish.FishCheck[i] = FishCheck[i];
	}

	Shark shark;
	shark.Sx = Sx; shark.Sy = Sy; shark.Sd = Sdir; shark.Ssum = fishnum;
	if (shark.Ssum > Ans) {
		Ans = shark.Ssum;
	}
	Q.push({ fish,shark });

}

void Sol2() {
	while (!Q.empty()) {
		//cout << endl;
		//cout << Q.size()<<endl;
		Fish fish;
		Shark shark;
	
		fish = Q.front().first;
		shark = Q.front().second;
	
		Q.pop();
		//cout << "����� �̵���"<<endl;
		//printMAP(fish.FishMAP);

		//2.����� �̵��Ѵ�
		
		for (int i = 1; i <= 16; i++) {
		
			if (fish.FishCheck[i].isdeath == true)continue;
			int fx = fish.FishCheck[i].x;
			int fy = fish.FishCheck[i].y;
			int fdir = fish.FishCheck[i].dir;
			bool checkmove = false;

			for (int d = 0; d < 8; d++) {
				int fndir = fdir + d;
				if (fndir > 8) fndir -= 8;
				int fnx = fx+dx[fndir];
				int fny = fy + dy[fndir];

				//cout << fnx << "," << fny << "(" << fndir << ") |";
				if (fnx <= 0 || fny <= 0 || fnx > 4 || fny > 4) continue;
				if (fnx == shark.Sx && fny == shark.Sy) continue;
				if (checkmove == true) continue;

				if (fish.FishMAP[fnx][fny] == 0) { //����ִٸ�
					fish.FishMAP[fnx][fny] = i;
					fish.FishMAP[fx][fy] = 0;
					fish.FishCheck[i].x = fnx;
					fish.FishCheck[i].y = fny;
					fish.FishCheck[i].dir = fndir;
					checkmove = true;
				}
				else if (fish.FishMAP[fnx][fny] != 0) {//����Ⱑ �ִ�
					int temp = fish.FishMAP[fnx][fny];
					fish.FishMAP[fnx][fny] = i;
					fish.FishMAP[fx][fy] = temp;

					fish.FishCheck[i].x = fnx;
					fish.FishCheck[i].y = fny;
					fish.FishCheck[i].dir = fndir;

					fish.FishCheck[temp].x = fx;
					fish.FishCheck[temp].y = fy;
					checkmove = true;
				}

			}
	
		}
		//cout << "����� �̵� ��";
		//printMAP(fish.FishMAP);
		//cout << shark.Sx << "." << shark.Sy << "����";
		//cout << shark.Sd<<endl;
		//3.�� �̵��Ѵ�
		for(int n=1;n<=4;n++) {
			Fish fish2 = fish;
			Shark shark2 = shark;

			int x = shark.Sx;
			int y = shark.Sy;
			int d = shark.Sd;
			int sum = shark.Ssum;

			int nx = x+ dx[d]*n;
			int ny = y+ dy[d]*n;

			if (nx <= 0 || ny <= 0 || nx > 4 || ny > 4) {  continue;  }
			if (fish.FishMAP[nx][ny] == 0) { continue; }

			//cout << "��Ƹ���!" << endl;
			//��Ƹ���
			int fishnum = fish.FishMAP[nx][ny];
			//fishnum ����
			fish2.FishMAP[nx][ny] = 0;
			fish2.FishCheck[fishnum].isdeath = true;
			//���
			shark2.Sd = fish2.FishCheck[fishnum].dir;
			shark2.Sx = nx;
			shark2.Sy = ny;
			shark2.Ssum = sum+fishnum;
			
			//cout << shark.Ssum << "->" << shark2.Ssum << "(" << fishnum << "����)" << endl;
			if (shark2.Ssum > Ans) {
				
				Ans = shark2.Ssum;
			}
			Q.push({ fish2,shark2 });

		}
		//�� �̵��Ҽ� �ִ� ĭ�� ���ٸ� ���� ���
	/*	if (movecnt == 0) {
			cout << Ans;
			return;
		}*/
	}


}
void Solution() {
	//1.û�ҳ� �� 0,0�� ����
	Sol1();
	Sol2();
	cout << Ans;
}
int main() {

	freopen("Text.txt", "r", stdin);
	cin.tie(NULL); cout.tie(NULL);
	Input();
	
	Solution();

	return 0;

}