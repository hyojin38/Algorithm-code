#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <stack>
#include <list>

using namespace std;

int sti(string st) {
	string temp;
	for (int i = 2; i < st.size(); i++) {
		temp += st[i];
	}
	return stoi(temp);
}

string solution(int n, int k, vector<string> cmd) {

	list <int> lt;
	for (int i = 0; i < n; i++) {
		lt.push_back(i);
	}
	list <int>::iterator k_iter = lt.begin();
	for (int i = 0; i < k; i++) {
		k_iter++;
	}
	//cout<<*k_iter;

	string answer(n, 'O');
	stack <int> stst;

	int end = n - 1;
	int size = cmd.size();

	for (int i = 0; i < size; i++) {
		string st = cmd[i];

		if (st[0] == 'D') {//현재 선택된 행에서 x칸 아래에 있는 행 선택
			int x = sti(st);
			for (int j = 0; j < x; j++) {
				k_iter++;
			}
		}
		else if (st[0] == 'U') {//현재 선택된 행에서 x칸 위에 있는 행 선택
			int x = sti(st);
			for (int j = 0; j < x; j++) {
				k_iter--;
			}
		}
		else if (st[0] == 'C') {//현재 선택된 행 삭제 후 바로 아래 행 선택
			stst.push(*k_iter);
			k_iter = li.erase(k_iter);

			//             int tempk=k;

			//             if(k==end){
			//                 while(true){
			//                     k--;
			//                     if(answer[k]=='O'){
			//                         end=k;
			//                         break;
			//                     }
			//                 }                
			//             }else{
			//                 while(true){
			//                      k++;
			//                     if(answer[k]=='O') break;
			//                 }

			//             }
		}
		else if (st[0] == 'Z') {//가장 최근 삭제된 행 복구
			int x = stst.top();
			stst.pop();

			list <int>::iterator z_iter = lt.begin();
			for (int i = 0; i < x; i++) {
				z_iter++;
			}

			if (end < x) end = x;
			answer[x] = 'O';
		}
	}

	return answer;
}