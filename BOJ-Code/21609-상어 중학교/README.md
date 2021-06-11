# [BOJ] 21609-상어 중학교

### 문제 바로가기

>  https://www.acmicpc.net/problem/21609

### 알고리즘

> - [구현](https://www.acmicpc.net/problem/tag/102)

>#### C++ sort 구조체 정렬
>
>```c++
>#include <algorithm>
>struct Seat{
>int x,y;  
>};
>bool compare( Seat A, Seat B){
>
>	if(A.x>B.x) return true; //> 오름차순 정렬
>
>	else return false;
>
>}
>
>sort(V.begin(),V.end(),compare);
>```

