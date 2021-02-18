#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>//올림
#define MAX 1000+1
#define endl "\n"
typedef long long LL;
using namespace std;

LL N, X, Y, TC,Ans;
double E;
LL Island[MAX][2];
LL Parent[MAX];
vector <pair <LL, pair<LL, LL> > > V;
void Init(){
	for (int i = 0; i < N; i++) {
		Island[i][0] = 0;
		Island[i][0] = 0;
	}
	V.clear();
	Ans = 0;
	E = 0.0;
}
LL calc_dis(int i, int j) {
	LL dx = Island[i][0] - Island[j][0];
	LL dy = Island[i][1] - Island[j][1];
	//cout << (dx *dx + dy *dy); 와 dx^2의 차이??
	return (dx *dx + dy * dy); //해저터널의 제곱

}
void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {//x입력
		cin >> X;
		Island[i][0] = X;
	}
	for (int i = 0; i < N; i++) {//x입력
		cin >> Y;
		Island[i][1] = Y;
	}
	cin >> E;
	//double P;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			LL D;
			D=calc_dis(i, j);
			V.push_back(make_pair(D, make_pair(i, j)));
		}
	}

}

void Makeset(int x) {
	Parent[x] = x;
}
int Findset(int x) {
	if (Parent[x]== x) return x;
	else return Parent[x] = Findset(Parent[x]); // Parent[x] = Findset(x); 아님!!!
}
void Union(int x, int y) {
	x = Findset(x);
	y= Findset(y);
	if (x != y) {
		Parent[y] = x;
	}
}
bool SameParent(int x, int y) {
	x = Findset(x);
	y = Findset(y);
	if (x == y) return true;
	else return false;
}
void Solution() {
	sort(V.begin(), V.end());

	for (int i = 0; i < N; i++)
		Makeset(i);

	for (int i = 0; i < V.size(); i++) {
		LL x = V[i].second.first;
		LL y = V[i].second.second;

		if (SameParent(x, y)==false) {
			Union(x, y);
		
			Ans += V[i].first;
		}

	}
	



}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	cout << fixed; //소수점을 고정시켜 표현하겠다
	cout.precision(0); //0자리까지 표현하겠다

	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		Init();
		Input();
		Solution();
		cout << "#" << tc << " " <<Ans*E << endl; //중간에 LL 에 double 넣고 더하기만 하면 다 반올림 하면서 세부 숫자 작아져
		// 통일하여 (LL) *double
		// 모두다 double +double +double 으로 하던지 
	}



	return 0;
}