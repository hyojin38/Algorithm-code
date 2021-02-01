# [BOJ] 09012 괄호

### 문제 바로가기

>  https://www.acmicpc.net/problem/9012

### 알고리즘

> 자료구조. 문자열. 스택

### 문제 풀이 및 주의

> queue
>
> ```c++
> //First in First Out
> //1.2.3.4.5 순서로 넣으면 1.2.3.4.5 순서로 나온다
> 
> #include <queue>
> 
> queue<int> Q;
> Q.push(1);
> Q.push(2);
> cout<<Q.front(); //1 출력
> Q.pop();//1 빠짐
> ```
>
> stack
>
> ```c++
> //1,2,3,4,5 순서로 넣으면 5.4.3.2.1 순서로 꺼낼수 있다
> //접시 쌓는다 생각
> 
> #include <stack>
> 
> stack<int> s;
> s.push(1);
> s.push(2);
> s.pop();// 2가 꺼내어짐
> cout<<s.top();// 1이 출력됨
> s.pop();// 1 삭제
> 
> ```
>
> 