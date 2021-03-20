#include<iostream>
#include <string>
#include <vector>

#include <cstring>
#include <string.h>
#define MAX 1000000+1

using namespace std;

vector<int> solution(string inp_str) {

	bool Ans[6];
	vector<int> answer;
	
	char schar[MAX];
	int group[5];
	
	vector<pair<char, int> > V; //5개 이상 포함되는가
	char bc;
	int cnt;
	
	
	//1
	int size = inp_str.size();
	if (size < 8 && size>15) {
		Ans[1] = true;
		
	}
	 size;
	for (int i = 0; i < size; i++) {
		char s = inp_str[i];
		schar[i] = s;

		int g = 0;
		
		//2
		if (s >= 'A'&&s <= 'Z') {
			g = 1;
		}
		else if (s >= 'a'&& s <= 'z') {
			g = 2;
		}
		else if (s >= '0'&& s <= '9') {
			g = 3;
		}else if (s== '~' || s == '!' || s == '@' || s == '#' || s == '$' || s== '%' || s == '^' || s == '&' || s == '*') {
			g = 4;
		}
		else {
			Ans[2] = true;
			//answer.push_back(2);
		}
		group[g]++;

		//4연속되는 같은 문자 있는지 확인 
		if (i == 0) {
			bc = s;
			cnt=1;
			
		}else {
			if (bc == s) {
				cnt++;
				if (cnt == 4) {
					Ans[4] = true;
				}
			}
			else {
				cnt = 1;
				bc = s;
			}
		}
		
		//어떤문자라도 같은 문자 5개 이상 포함 불가능
		bool check=false;
		for (int i = 0; i < V.size(); i++) {
			char vs = V[i].first;
			if (vs == s) {
				V[i].second++;
				if (V[i].second >= 5) {
					Ans[5] = true;
				}
				check = true;
				//break;
			}
		}
		if (check == false) {
			V.push_back({ s,1 });
		}

	}

	//3
	int cnt3 = 3;
	for (int i = 1; i <= 4; i++) {
		if (group[i] > 0) cnt3--;
	}
	if( cnt3 <=0) Ans[3] = true;

	//4개 이상 연속

	//오름차순 정렬
	for (int i = 1; i <= 5; i++) {
		if (Ans[i] == true) {
			answer.push_back(i);
		}
	}
	if (answer.size() == 0) {
		answer.push_back(0);
	}
	return answer;
}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	freopen("Text.txt", "r", stdin);
	string s = "CaCbCgCdC888834A";
	
	vector <int> temp;
	temp =solution(s);
	for (int i = 0; i < temp.size(); i++) {
		cout << temp[i];
	}
	return 0;

}
