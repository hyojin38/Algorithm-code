#include <iostream>
#include <vector>
#include<queue>
#define endl "\n"
#define MAX 100+2

using namespace std;

struct Record
{
	bool check;
	int x, y, ex, ey, d;
};
int MAP[MAX][MAX];
Record RecordMAP[MAX][MAX][4];
int Ans,N;
int dx[] = { 0,0,1,-1 };
int dy[]={1,-1,0,0 };
struct hall
{
	vector <pair<int, int> > hallV;
};
hall Hall[11];

void Init() {

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			MAP[i][j] = 0;
		}
	}
	Ans = 0;
	N = 0;
	hall H;
	for (int i = 6; i <= 10; i++) {
		Hall[i] = H;
	}
}
void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] >= 6 && MAP[i][j] <= 10) {
				Hall[MAP[i][j]].hallV.push_back( {i,j} );
			}
		}
	}
}
int Start(int sx, int sy, int d) {

	queue <pair<pair<int, int>,pair<int, int> > > Q; 

	Q.push({ {sx,sy},{d,0} });

	while (!Q.empty()) {
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int d = Q.front().second.first;
		int score = Q.front().second.second;
		Q.pop();
		
		int nx = x + dx[d];
		int ny = y + dy[d];
		//cout << nx << "." << ny << endl;


		if (MAP[nx][ny] == -1 || (nx == sx && ny == sy)) { //ºí·¢È¦ || ½ÃÀÛÁ¡
	/*Á¾·á*/
			
			return score;

		}
		if (nx <= 0 || ny <= 0 || nx > N || ny > N) { //º®
			/*¹Ý´ë¹æÇâ*/
			int nd;
			if (d == 1 || d == 3) nd = d - 1;
			else if (d == 0 || d == 2) nd = d + 1;
			Q.push({ {nx,ny} ,{nd,score + 1} });
		}
		else if (MAP[nx][ny] == 0) { //ºó°æ¿ì
			Q.push({ {nx,ny} ,{d,score} });
		}
		else if (MAP[nx][ny] >= 6 && MAP[nx][ny] <= 10) { //¿úÈ¦
			int hallnum = MAP[nx][ny];
			vector <pair<int, int> > hV = Hall[hallnum].hallV;

			if (nx == hV[0].first && ny == hV[0].second) {
				nx = hV[1].first;
				ny = hV[1].second;
			}
			else {
				nx = hV[0].first;
				ny = hV[0].second;
			}

			Q.push({ {nx,ny} ,{d,score} });

		}
		else if (MAP[nx][ny] < 6 && MAP[nx][ny] >=1) {
			int nd;
			if (MAP[nx][ny] == 1) {
				if (d == 1) {
					nd = 3; 
				}
				else if (d == 2) {
					nd = 0; 
				}
				else if (d == 3) {
					nd = 2;  
				}
				else if (d == 0) {
					nd = 1; 
				}

			}
			else if (MAP[nx][ny] == 2) {
				if (d == 1) nd = 2;
				else if (d == 3) nd = 0;
				else if (d == 2) nd = 3;
				else if (d == 0) nd = 1;
			}
			else if (MAP[nx][ny] == 3) {
				if (d == 0) nd = 2;
				else if (d == 3) nd = 1;
				else if (d == 1) nd = 0;
				else if (d == 2) nd = 3;
			}
			else if (MAP[nx][ny] == 4) {
				if (d == 0) nd = 3;
				else if (d == 2) nd = 1;
				else if (d == 1) nd = 0;
				else if (d == 3) nd = 2;
			}
			else if (MAP[nx][ny] == 5) {
				if (d == 1 || d == 3) nd = d - 1;
				else if (d == 0 || d == 2) nd = d + 1;
			}
			Q.push({ {nx,ny},{nd,score + 1 } });
		}
	
		

	}



}
void Solution() {

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			if (MAP[x][y] == 0) {
				//cout << "[" << x << "," << y << "]" ;
				for (int d = 0; d < 4; d++) {
					int s=Start(x, y, d);
					//cout << s << " ";
					if (s > Ans) Ans = s;
				}
				//cout << endl;
			}
		}
	}


}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);


	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
	
		Init();
		Input();
		Solution();

		cout << "#" << tc << " " << Ans << endl;
	}

	return 0;

}