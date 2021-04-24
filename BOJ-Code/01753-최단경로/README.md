# [BOJ]  01753 최단경로

### 문제 바로가기

>  https://www.acmicpc.net/problem/1753

### 알고리즘

> 다익스트라 알고리즘 
>

### 문제 풀이 및 주의

>**다익스트라 기본** [Dijkstra]
>
>방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오. 단, 모든 간선의 가중치는 10 이하의 자연수이다.
>
>```c++
>#include <iostream>
>#include <vector>
>#include <queue>
>#define endl "\n"
>#define MAX 20000+1
>#define INF 1000000000//1000000000 0을 9개
>using namespace std;
>
>int V, E ,K;
>vector< vector<pair<int, int> > > MAP; //간선정보
>int costs[MAX];//시작점부터 최소비용정보
>
>void Input() {
>	cin >> V >> E;//정점과 간선
>	cin >> K;//시작정점
>	//정점은 1부터 V까지(최대 20000)
>	MAP.resize(V + 1);
>
>	int u, v, w;//u에서 v까지 가중치 w
>	for (int i = 1; i <= E; i++) {
>		cin >> u >> v >> w;
>		MAP[u].push_back({ v,w });
>		//MAP[v].push_back({ v,w });
>	}
>
>	//기본적으로 연결되지 않은 경우 비용은 무한
>	for (int i = 0; i <= V; i++) {
>		costs[i] = INF;
>	}
>
>}
>void Dijkstra() {
>	
>	priority_queue <pair<int, int> > PQ;
>	PQ.push({ 0,K });// 비용. node
>	costs[K] = 0;
>
>	while (!PQ.empty()) {
>		int cost = -PQ.top().first;
>		int curnode = PQ.top().second;
>		PQ.pop();
>
>		for (int i = 0; i < MAP[curnode].size(); i++) { // curnode와 연결된 node를 체크
>			int nextnode = MAP[curnode][i].first;
>			int ncost = MAP[curnode][i].second;
>			//cout << nextnode << " " << ncost << endl;
>			if (costs[nextnode] > cost + ncost) {
>				costs[nextnode] = cost + ncost;
>				PQ.push({ -costs[nextnode],nextnode });//nextnode까지가는데최소비용, 다음노드정보
>			}
>		}
>	}
>
>}
>void Solution() {
>	Dijkstra();
>	
>	for (int i = 1; i <= V; i++) {
>		if (costs[i] == INF) cout << "INF" << endl;
>		else cout << costs[i] << endl;
>	}
>}
>int main() {
>
>	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
>	//freopen("Text.txt", "r", stdin);
>
>	Input();
>	Solution();
>
>	return 0;
>}
>```
>
>