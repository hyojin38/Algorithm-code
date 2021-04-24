#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"
#define MAX 20000+1
#define INF 1000000000//1000000000 0�� 9��
using namespace std;

int V, E, K;
vector< vector<pair<int, int> > > MAP; //��������
int costs[MAX];//���������� �ּҺ������

void Input() {
	cin >> V >> E;//������ ����
	cin >> K;//��������
	//������ 1���� V����(�ִ� 20000)
	MAP.resize(V + 1);

	int u, v, w;//u���� v���� ����ġ w
	for (int i = 1; i <= E; i++) {
		cin >> u >> v >> w;
		MAP[u].push_back({ v,w });
		//MAP[v].push_back({ v,w });
	}

	//�⺻������ ������� ���� ��� ����� ����
	for (int i = 0; i <= V; i++) {
		costs[i] = INF;
	}

}
void Dijkstra() {

	priority_queue <pair<int, int> > PQ;
	PQ.push({ 0,K });// ���. node
	costs[K] = 0;

	while (!PQ.empty()) {
		int cost = -PQ.top().first;
		int curnode = PQ.top().second;
		PQ.pop();

		for (int i = 0; i < MAP[curnode].size(); i++) { // curnode�� ����� node�� üũ
			int nextnode = MAP[curnode][i].first;
			int ncost = MAP[curnode][i].second;
			//cout << nextnode << " " << ncost << endl;
			if (costs[nextnode] > cost + ncost) {
				costs[nextnode] = cost + ncost;
				PQ.push({ -costs[nextnode],nextnode });//nextnode�������µ��ּҺ��, �����������
			}
		}
	}

}
void Solution() {
	Dijkstra();

	for (int i = 1; i <= V; i++) {
		if (costs[i] == INF) cout << "INF" << endl;
		else cout << costs[i] << endl;
	}
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen("Text.txt", "r", stdin);

	Input();
	Solution();

	return 0;
}