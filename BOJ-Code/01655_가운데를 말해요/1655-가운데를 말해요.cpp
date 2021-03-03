#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

int N;
vector <int> V;
int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);
	//1~100,000 NÀÔ·Â
	cin >> N;

	//
	int center = 0;
	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		V.push_back(temp);
		sort(V.begin(), V.end());

		//bool check = false;//È¦¼ö Â¦¼ö
		//if (i % 2 == 0) check = true; //Â¦¼ö

		//int center = i / 2;
		//if (check == true) center -= 1;
		if (i != 1 && i % 2 == 1) center++;
		cout << V[center] << endl;
	}

	
	return 0;
}