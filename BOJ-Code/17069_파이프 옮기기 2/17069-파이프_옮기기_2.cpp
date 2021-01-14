#include <iostream>
#include <cstring>
#include <queue>
#include<vector>
using namespace std;
#define endl "\n"
#define MAX 33

int N;
vector<vector<int>> Map;
long DP[MAX][MAX][3];
void Input() {
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		vector<int> V;
		Map.push_back(V);
		for (int j = 0; j < N; j++) {
			cin >> temp;
			Map[i].push_back(temp);
		}

	}
	memset(DP, 0, sizeof(DP));

}


void Solution() {
	DP[0][1][0] = 1;//시작 가로
	// 0 가로 1세로 2대각선
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if((i==0&& j==0)  || (i == 0 && j == 1)) continue;
			if (Map[i][j] == 1) continue;
			//가로
			if (j - 1 >= 0) {
				DP[i][j][0] += DP[i][j - 1][0];
				DP[i][j][0] += DP[i][j - 1][2];
			}
			
			//세로
			if (i - 1 >= 0) {
				DP[i][j][1] += DP[i-1][j][1];
				DP[i][j][1] += DP[i-1][j][2];
			}
			//대각선
			
			if (i - 1 >= 0 && j - 1 >= 0) {
				if (Map[i - 1][j] == 1 || Map[i][j - 1] == 1) 
					continue;
				DP[i][j][2] += DP[i - 1][j - 1][0];
				DP[i][j][2] += DP[i - 1][j-1][1];
				DP[i][j][2] += DP[i - 1][j-1][2];
			}

		}
	}
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	Solution();
	long long Answer = 0;
	
	for (int i = 0; i < 3; i++) {
		//cout << DP[N - 1][N - 1][i]<<endl;
		Answer += DP[N - 1][N - 1][i];
	}
	cout << Answer;
}