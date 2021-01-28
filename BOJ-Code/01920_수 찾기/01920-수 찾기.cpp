//ÀÌÁøÅ½»ö
#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;
vector<int> V;
int N,M,answer;
void solution(int f, int s, int e, int mid) {
	int ns, ne, nmid;
	if (f<V[s] || f> V[e] || mid==e || mid == s) {
		answer = 0;
		return;
	}
	if (f == V[mid] || f==V[s] || f==V[e]  ) {
		answer = 1;
		return;
	}else if(f<V[mid]){
		ns = s;
		ne = mid;
		nmid = (ns + ne) / 2;
		solution(f, ns, ne, nmid);
	}
	else if (f > V[mid]) {
		ns = mid;
		ne = e;
		nmid = (ns + ne) / 2;
		solution(f, ns, ne, nmid);
	}

}
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		V.push_back(temp);
	}
	sort(V.begin(), V.end());
	cin >> M;
	for (int i = 0; i < M; i++) {

		int f;
		cin >> f;
		int s = 0;
		int e = N - 1;
		int mid = N / 2;
		solution(f, s, e, mid);

		cout << answer << endl;
	}

	return 0;
}