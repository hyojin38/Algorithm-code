#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> v;
void solution(int k) {
	v.clear();
	for (int i = 0; i < k; i++) {
		string inputst;
		cin >> inputst;
	
		if (inputst[0] == 'I') {
			//ť�� �־��� ���� ����
			int temp;
			cin >> temp;
			/*string numst;
			for (int j = 2; j < inputst.size(); j++) {
				numst += inputst[j];
			}
			int num = stoi(numst);*/
		//	cout << temp << "in" << endl;
			v.push_back(temp);
		}
		else if (inputst[0] == 'D') {
			sort(v.begin(), v.end());
			int temp;
			cin >> temp;
			if (v.size() >= 1) {
				if (temp == 1) {//ť�� �ִ� ����
				//	cout << v[v.size() - 1] << "out" << endl;
					v.erase(v.end()-1 );
				}
				else { //�ּڰ� ����
				//	cout << v[0] << "out" << endl;
					v.erase(v.begin());
				}
			}
			else {
				continue;
			}
		}

	}

	if (v.size() >= 1) {
		sort(v.begin(), v.end());
		cout << v[v.size() - 1]<<" "<<v[0]<<endl;
	}
	else {
		cout << "EMPTY" << endl;

	}
	
}
void main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int k;
		cin >> k;
		cout << k;
		solution(k);

	}

}