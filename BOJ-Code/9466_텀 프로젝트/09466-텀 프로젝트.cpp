#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 100001
#define endl "\n"
using namespace std;

int T;
int N, Ans;




int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	cin >> T;

	for (int i = 1; i <= T; i++) {

		int cnt[MAX] = { 0, };
		int point[MAX] = { 0, };

		cin >> N;
		Ans = N;

		int y;
		for (int x = 1; x <= N; x++) {
			cin >> y;
			//cout << x<<"-";
			
			cnt[x] = 1;
			point[x] = y;

			// 자기자신
			if (x == y) { Ans--; }
			// 자기 자신이 아닌경우
			else {
				int a, b;
				a = x;
				b = y;
				while (true) {
					a = b;
					b = point[a];
					//cout << a <<":"<<b<<endl;
					if (b == 0 || a == b) {
						break;
					}
					else if(b!=x){
						//cout << "."<<b;
						point[x] = b;
						cnt[x]= cnt[a]+cnt[x];
					}
					else if (b == x) {
						point[x] = b;
						cnt[x] =cnt[a] + cnt[x];
						Ans = Ans - cnt[x];
						break;
					}

				}
			}


		}

		cout << Ans << endl;
	}

	return 0;
}