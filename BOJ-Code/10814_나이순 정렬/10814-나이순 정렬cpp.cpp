#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#define MAX 100000+1
#define endl "\n"

using namespace std;
struct Person {
	int age;
	string name;
	int join;
};

vector< Person > V;
bool cmp(Person u, Person v) {
	if (u.age < v.age)
		return true;
	else if (u.age == v.age)
		return u.join < v.join;
	else
		return false;
}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("Text.txt", "r", stdin);

	int N;
	cin >> N;
	int age;
	string name;
	Person P;
	for (int i = 0; i < N; i++) {
		 cin >>age>> name;
		 P.age = age;
		 P.name = name;
		 P.join = i;
		 V.push_back(P);
	}
	sort(V.begin(), V.end(),cmp);

	for (int i = 0; i < N; i++) {
		cout << V[i].age<<" "<<V[i].name<<endl;
	}
	return 0;
}