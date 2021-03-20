#include<iostream>
#include <string>
#include <vector>

#include <cstring>
#include <string.h>


using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {

	//si contents hw portal game
	int Ans[5] = { 0, };
	vector <string> table2;

	for (int i = 0; i < 5; i++) {
		vector<string> strArr;
		string s = table[i];
		char schar[10000] = "";
		for (int i = 0; i < s.size(); i++) {
			schar[i] = s[i];
		}

		char *ptr = strtok(schar, " ");//구분자 " "
		int score = 7;
		while (ptr != NULL) {
			//cout << ptr << endl;
			//table2[i].push_back(string(ptr));
			score--;
			strArr.push_back(string(ptr));
			string ln = string(ptr);
			//lang 확인
			if (score <= 5) {
				for (int k = 0; k < languages.size(); k++) {
					string myln = languages[k];
					if (ln == myln) {
						Ans[i] = preference[k] * score + Ans[i];
						//cout << myln << " ";
						//cout << preference[k]<< "*"<<score<<"="<< preference[k] * score<<": "<<Ans[i]<<" ";
						break;
					}
				}
			}
			else {
				table2.push_back(string(ptr));
			}
		
			ptr = strtok(NULL, " ");
		}

		
	}

	int result = Ans[0];
	int resultnum = 0;
	for (int i = 1; i < 5; i++) {
		if (result < Ans[i]) {
			result = Ans[i];
			resultnum = i;
		}
		else if (result == Ans[i]) {
			//사전순으로 먼저오는 순
			if (table2[resultnum] > table2[i]) {
				result = Ans[i];
				resultnum = i;
			}
		}

	}
	string answer = table2[resultnum];
	return answer;
}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	vector <string> table = { "SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA" };
	vector <string> languages = { "PYTHON", "C++", "SQL" };
	vector <int>  preference = { 7,5,5 };

	cout<<solution(table,languages,preference);

	return 0;

}
