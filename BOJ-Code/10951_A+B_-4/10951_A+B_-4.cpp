#include <iostream>
#include <cstring>
#include<queue>

using namespace std;

#define endl "\n"

int main() {
	
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		freopen("Text.txt", "r", stdin);
		while (true)
		{
			int x, y;
			cin >> x >> y;
			if (cin.eof()) {
				break;
			}
			cout << x + y << endl;
		}
		
	return 0;
}

