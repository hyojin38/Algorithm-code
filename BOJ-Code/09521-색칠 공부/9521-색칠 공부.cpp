#include <iostream>
#include <vector>
#define MAX 1000000+1

using namespace std;

int N, K;
vector<int> Notmatch[MAX];

int colorMAP[MAX];
int Ans;

void Input() {

	cin >> N >> K;

	int temp;
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		bool check = false;
		for (int j = 0; j < Notmatch[temp].size(); j++) {
			if (Notmatch[temp][j] == i) check = true;
		}
		if (check == false) {
			Notmatch[temp].push_back(i);
		}

		check = false;
		for (int j = 0; j < Notmatch[i].size(); j++) {
			if (Notmatch[i][j] == temp) check = true;
		}
		if (check == false) {
			Notmatch[i].push_back(temp);
		}

	}
}
void DFS(int idx, int cnt) {
	if (cnt > N) {
		Ans++;
		return;
	}
	//vector <int> V = Notmatch[idx];
	vector <int> Vxcolor;

	for (int i = 0; i < Notmatch[idx].size(); i++) {
		if (Notmatch[idx][i] == idx) continue;//? 아무 제한이 없대
		else {
			int color = colorMAP[Notmatch[idx][i]];
			if (color == 0) continue;
			else Vxcolor.push_back(color);
		}
	}

	for (int i = 1; i <= K; i++) {//1~K 중 N개 선택
		for (int x = 0; x < Vxcolor.size(); x++) {
			//cout << Vxcolor[x];
			if (i == Vxcolor[x]) i++;
		}
		if (i > K) continue;
		colorMAP[idx] = i;
		//cout << idx<<":" <<i << endl;
		DFS(idx + 1, cnt + 1);
		colorMAP[idx] = 0;
	}
}
void Solution() {
	DFS(1, 1);
	cout << Ans;
}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);
	Input();
	Solution();
	return 0;
}