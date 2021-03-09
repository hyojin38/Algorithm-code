# [BOJ] 10414 나이순 정렬

### 문제 바로가기

>  https://www.acmicpc.net/problem/10414

### 알고리즘

> 정렬

### 문제 풀이 및 주의

> 나이가 같은경우 -> 입력 순서대로 정렬
>
>  sort() 의 경우 기준에 따라 정렬하고  두 원소가 같을경우 기존의 순서를 유지해준다는 보장이 없기때문에 순서를 유지하려면 비교 함수에서도 체크 해 줘야한다.
>
> **stable_sort(V.begin(),V,end)** 사용
>
> ```c++
> #include<iostream>
> #include<vector>
> #include<algorithm>
> #include<cstring>
> #include<string>
> #define MAX 100000+1
> #define endl "\n"
> 
> using namespace std;
> vector< pair<int, string> > V;
> bool cmp(const pair<int, string> &a, const pair<int, string> &b) {
> 
> 	return a.first < b.first;
> }
> int main() {
> 
> 	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
> 	freopen("Text.txt", "r", stdin);
> 
> 	int N;
> 	cin >> N;
> 	int age;
> 	string name;
> 	for (int i = 0; i < N; i++) {
> 		 cin >>age>> name;
> 		 V.push_back({ age,name });
> 	}
> 	stable_sort(V.begin(), V.end(),cmp);
> 
> 	for (int i = 0; i < N; i++) {
> 		cout << V[i].first<<" "<<V[i].second<<endl;
> 	}
> 	return 0;
> }
> ```
>
> **구조체에 나이.이름 외에 가입순서를 변수로 넣어 비교함수 sort**
>
> ```c++
> #include<iostream>
> #include<vector>
> #include<algorithm>
> #include<cstring>
> #include<string>
> #define MAX 100000+1
> #define endl "\n"
> 
> using namespace std;
> struct Person {
> 	int age;
> 	string name;
> 	int join;
> };
> 
> vector< Person > V;
> bool cmp(Person u, Person v) {
> 	if (u.age < v.age)
> 		return true;
> 	else if (u.age == v.age)
> 		return u.join < v.join;
> 	else
> 		return false;
> }
> 
> int main() {
> 
> 	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
> 	freopen("Text.txt", "r", stdin);
> 
> 	int N;
> 	cin >> N;
> 	int age;
> 	string name;
> 	Person P;
> 	for (int i = 0; i < N; i++) {
> 		 cin >>age>> name;
> 		 P.age = age;
> 		 P.name = name;
> 		 P.join = i;
> 		 V.push_back(P);
> 	}
> 	sort(V.begin(), V.end(),cmp);
> 
> 	for (int i = 0; i < N; i++) {
> 		cout << V[i].age<<" "<<V[i].name<<endl;
> 	}
> 	return 0;
> }
> ```
>
> 

