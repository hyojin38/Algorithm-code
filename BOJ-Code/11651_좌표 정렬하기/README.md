# [BOJ] 11651 좌표 정렬하기

### 문제 바로가기

>  https://www.acmicpc.net/problem/11651

### 알고리즘

> 정렬

### 문제 풀이 및 주의

> #### 1.vector 정렬
>
> ```c++
> bool cmp(const pair<int,int>&a, const pair<int, int> &b){
> 	if(a.first==b.first){
> 		return a.second<b.second; //1.2.3 증가하는 순이 됩니다
> 	}
> 	return a.first<b.first;
> }
> ```
>
> 
>
> #### 2. 시간초과
>
> ```c++
> #define endl "\n"
> ```
>
> 
