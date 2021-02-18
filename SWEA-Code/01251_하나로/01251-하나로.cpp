#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>//�ø�
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
	//cout << (dx *dx + dy *dy); �� dx^2�� ����??
	return (dx *dx + dy * dy); //�����ͳ��� ����

}
void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {//x�Է�
		cin >> X;
		Island[i][0] = X;
	}
	for (int i = 0; i < N; i++) {//x�Է�
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
	else return Parent[x] = Findset(Parent[x]); // Parent[x] = Findset(x); �ƴ�!!!
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

	cout << fixed; //�Ҽ����� �������� ǥ���ϰڴ�
	cout.precision(0); //0�ڸ����� ǥ���ϰڴ�

	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		Init();
		Input();
		Solution();
		cout << "#" << tc << " " <<Ans*E << endl; //�߰��� LL �� double �ְ� ���ϱ⸸ �ϸ� �� �ݿø� �ϸ鼭 ���� ���� �۾���
		// �����Ͽ� (LL) *double
		// ��δ� double +double +double ���� �ϴ��� 
	}



	return 0;
}