#include<iostream>
#include<queue>
#include<vector>
#include<vector>
#include<algorithm>
#define MAX 10+1
#define endl "\n"
using namespace std;

int N,Ans;
int P[MAX]; //인구수
bool MAP[MAX][MAX]; //인접 구역 체크
vector<int> V1;
bool V1visited[MAX];
void Input() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}
	int temp;
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		int j;
		for (int k = 0; k < temp; k++) {
			cin >> j;
			MAP[i][j] = true;
		}
	}


}
int Connect(int Acnt) {
	int A =0;
	int B=0;
	
	//A그룹 연결되어 있는가
	int connectcheck[MAX] = { 0, };

	queue <int> Qconnect;

	for (int i = 0; i < Acnt; i++) {
		int x =V1[i];
		connectcheck[x] = 1;
	}

	int cnta = V1.size();
	int cntb = N - cnta;
	int a = V1[0];
	int b;
	for (int i = 1; i <= N; i++) {
		if (connectcheck[i] == 0) {
			b = i;
			break;
		}
	}

	Qconnect.push(a);
	connectcheck[a] = -1; //갈 수 있음
	
	A += P[a];
	cnta--;
	while (!Qconnect.empty()) {
		a = Qconnect.front();
		Qconnect.pop();

		for (int i = 1; i <= N; i++) {
			if (MAP[a][i] == true && connectcheck[i]==1) {
				Qconnect.push(i);
				connectcheck[i] = -1;
				A += P[i];
				cnta--;
			}
		}
	}
	if (cnta != 0) return -1;


	Qconnect.push(b);
	connectcheck[b] = -1; //갈 수 있음
	B += P[b];
	cntb--;
	
	while (!Qconnect.empty()) {
		b = Qconnect.front();
		Qconnect.pop();

		for (int i = 1; i <= N; i++) {
			if (MAP[b][i] == true && connectcheck[i] == 0) {
				Qconnect.push(i);
				connectcheck[i] = -1;
				B += P[i];
				cntb--;
			}
		}
	}
	
	if (cntb != 0) return -1;

	
	return (abs(A-B)) ;
}
void DivArea(int A ,int B, int cnt, int idx) { //A 만큼 나누기

	if (cnt == A) {
	/*	cout << "[";
		for (int i = 0; i < A; i++) {
			cout << V1[i] << ",";
		}*/
	//	cout << "]"<<endl;
		int ans = Connect(A);
		//int ans = -1;
		if (ans != -1 && Ans>ans ) {
		//	cout << ans;
			Ans = ans;
		}
		return;
	}

	for (int i = idx; i <= N; i++) {
		
		if (V1visited[i] == true) continue;
		V1visited[i] = true;
		V1.push_back(i);
		DivArea(A, B, cnt + 1, i);
		V1visited[i] = false;
		V1.pop_back();

	}



}
void Solution() {
	Ans = 987654321;

	//구역 나누기
	
	for (int i = 1; i <= (N / 2); i++) {
	//	cout << i << endl;
		DivArea(i,N-i,0,1);
	}
	if (Ans == 987654321) Ans = -1;

	cout << Ans;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	Solution();

	return 0;
}