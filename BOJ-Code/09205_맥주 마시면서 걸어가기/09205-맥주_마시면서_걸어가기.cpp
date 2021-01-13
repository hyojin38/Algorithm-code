//9205 맥주 마시면서 걸어가기
//20210113
//hyojin
#include <iostream>
#include <cstring>
#include <queue>
#include <math.h>
#include <vector>
using namespace std;
#define endl "\n"
int TC, N;
int Hx, Hy, Rx, Ry;
int beer;
bool Answer;
vector<pair<pair<int, int>,int> > V;//편의점 좌표
queue <pair<pair<int, int>, int> >  Q;//BFS
int visit[102];
void Input();
void Init();
void Solution();
void bfs();
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	freopen("Text.txt", "r", stdin);
	cin >> TC;
	for (int i = 0; i < TC; i++) {
		Init();
		Input();
		Solution();
		if (Answer != false)
			cout << "happy" << endl;
		else {
			cout << "sad" << endl;
		}
	}
	return 0;
}
void Init() {
	V.clear();
	while (!Q.empty()) {
		Q.pop();
	}
	memset(visit, 0, sizeof(visit));
	Answer = false;
	beer = 20;
}
void Input() {
	cin >> N; //편의점 수
	cin >> Hx >> Hy;
	int cnt = 0;
	V.push_back(make_pair(make_pair(Hx, Hy),cnt++));
	for (int i = 0; i < N; i++) { // 편의점 좌표
		int x, y;
		cin >> x >> y;
		V.push_back(make_pair(make_pair(x, y), cnt++));

	}
	cin >> Rx >> Ry;

	V.push_back(make_pair(make_pair(Rx, Ry), cnt));
}
void Solution(){


	//BFS
	Q.push(make_pair(make_pair(Hx, Hy),0));

	bfs();

}
void bfs() {
	while (Q.empty()!=true)
	{
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int n = Q.front().second;
		Q.pop();
		visit[n] = 1;//방문체크
		
		if (n==N+1) {
			Answer = true;
			return;
		}
		for (int i = 0; i < V.size(); i++) { 
			// 거리가 가능한가 체크
			if (visit[i] == 1) {
				continue;
			}
			int nx, ny,nn;
			nx = V[i].first.first;
			ny = V[i].first.second;
			nn = V[i].second;
			int cal = abs(x - nx) + abs(y - ny);
			if (cal > 1000) {
				continue;
			}
	
			Q.push(make_pair(make_pair(nx, ny), nn));

		}
	}
}