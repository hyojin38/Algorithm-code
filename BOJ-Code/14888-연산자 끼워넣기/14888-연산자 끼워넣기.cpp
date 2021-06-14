#include<iostream>
#include<vector>

using namespace std;

int N;
vector<int> V;
int Sign[4];
bool visited[11 + 1];

long long MAX = -10000000000;
long long MIN = 10000000000;
long long sing0(long long a, long long b) { return a + b; }
long long sing1(long long a, long long b) { return a - b; }
long long sing2(long long a, long long b) { return a * b; }
long long sing3(long long a, long long b) { return a / b; }

void DFS(int idx, long long result) {//1.0

	if (idx == N) {
		if (result > MAX) {
			MAX = result;
		}
		if (result < MIN) {
			MIN = result;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (Sign[i] == 0) continue;
		Sign[i]--;
		long long temp;
		if (i == 0) {
			temp = sing0(result, V[idx]);
		}
		else if (i == 1) {
			temp = sing1(result, V[idx]);
		}
		else if (i == 2) {
			temp = sing2(result, V[idx]);
		}
		else if (i == 3) {
			temp = sing3(result, V[idx]);
		}
		DFS(idx + 1, temp);
		Sign[i]++;

	}
}
void Input() {
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		V.push_back(temp);
	}
	for (int i = 0; i < 4; i++) {
		cin >> Sign[i];
	}
}
void Solution() {

	DFS(1, V[0]);
	cout << MAX << endl;
	cout << MIN << endl;

}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	Input();
	Solution();
	return 0;
}