#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define endl "\n"
#define MAX 100001
using namespace std;
int N, M ,Cnt,BigCnt;
// int MAP[MAX][MAX]; �迭�� �ֱ⿡ �ʹ� ũ��
vector<int> Map[MAX];
bool visited[MAX];
vector<int> result;
void Input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B; //A�� B�� �ŷ��Ѵ� 
		Map[B].push_back(A);//B�� ��ŷ�ϸ� A�� ����
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

	//���� ���� �ְ� ���� ��ǻ�� ã��?	
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
	
	//����
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