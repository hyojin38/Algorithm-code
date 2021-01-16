#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
#define endl "\n"
#define MAX 100001

using namespace std;
int N,K,T, Answer;
int MAP[2][MAX];
queue<pair<pair<int, int>,int>> Q;
int visited[2][MAX] = { 0, };
int dx[3];
void Input() {
	cin >> N >> K;
	string s1,s2;
	
	cin >> s1 >>s2;
	for (int i = 0; i < N; i++) {
		MAP[0][i]=s1[i]-'0';
		MAP[1][i]=(s2[i] - '0');//char을 int 형으로 바꾸기 위해 -'0'
		
	}
	
	T = 0;
	
}
void BFS() {
	int dx[] = { 1, -1 ,K };
	while (!Q.empty()) {
		int LR = Q.front().first.first;
		int x = Q.front().first.second;
		int T = Q.front().second;
		
		Q.pop();

		for (int k = 0; k < 3; k++) {
			int nx = x + dx[k];
			int nLR=LR;
			if (k == 2) {
				if (LR == 1) nLR = 0;
				else if (LR == 0) nLR = 1;
			}
			int nT = T + 1;

			if (nx < 0) continue;
			if (nx <= T) continue;
			if (nx >= N) {

				Answer = 1;
				return;
			}
			if (visited[nLR][nx] == 1) continue;
			if (MAP[nLR][nx] == 0) continue; //넘어갔을때 초기화 0 으로 인하여 continue 됨
			
		//	cout << nLR << " " << nx << " " << nT << endl;
	
			visited[nLR][nx] = 1;
			Q.push(make_pair(make_pair(nLR, nx), nT));

		}



	}
	


}
//0위험 1이동가능
void Solution() {
	
	//게임이 클리어 가능한가
	visited[0][0] = 1;
	Q.push(make_pair(make_pair(0, 0),0));

	// visited[0][1] = 1;
	BFS();
	cout << Answer;

}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	Solution();
	return 0;
}
