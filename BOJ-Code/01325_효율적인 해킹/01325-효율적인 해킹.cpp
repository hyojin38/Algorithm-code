#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define endl "\n"
#define MAX 100001
using namespace std;
int N, M ,Cnt,BigCnt;
// int MAP[MAX][MAX]; 배열로 넣기에 너무 크다
vector<int> Map[MAX];
bool visited[MAX];
vector<int> result;
void Input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B; //A가 B를 신뢰한다 
		Map[B].push_back(A);//B를 해킹하면 A도 가능
	}
}
void DFS(int num) {
	
	visited[num] = true;
	for (int i = 0; i < Map[num].size(); i++) {
		int nextnum = Map[num][i];

		if (visited[nextnum] == true) continue;
		Cnt++;
		DFS(nextnum);
	}

}
void Solution() {

	//가장 깊이 있게 가는 컴퓨터 찾기?	
	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof(visited));
		Cnt = 0;
		DFS(i);

		if (Cnt > BigCnt) {
			BigCnt = Cnt;
			result.clear();
			result.push_back(i);
		}
		else if (Cnt == BigCnt) {
			result.push_back(i);
		}
	}
	
	//정렬
	sort(result.begin(), result.end());

}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);


	Input();
	Solution();
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;
}