# [BOJ] 01406 에디터

### 문제 바로가기

>  https://www.acmicpc.net/problem/1406

### 알고리즘

> 자료구조. 스택

### 문제 풀이 및 주의

> [ STL size() 사용시 for 문 주의 ]
>
> ```C++
>for(int i=0;i<s.size();i++){
>     s.pop();
> }//size가 기존과는 다르게 줄어들어 for문 반복 횟수 차이 발생
> ```
> 