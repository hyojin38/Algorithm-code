# [BOJ] 09935 - 문자열 폭발

### 문제 바로가기

>  https://www.acmicpc.net/problem/9935

### 알고리즘

> 자료구조. 문자열. 스택

### 문제 풀이 및 주의

> deque. stack 이용
>
> 맨 마지막의 문자가 같으면 비교시작.  비교 중 같지 않다면 다시 deque에 넣어주기
>
>  앞에서 부터 출력해야 하므로 deque로 사용

#### deque

```
Deq.front();
Deq.back();
Deq.pop-front();
Deq.pop_back();
Deq.push_back();
```

