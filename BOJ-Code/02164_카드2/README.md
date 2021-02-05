# [BOJ] 02164 - 카드2

### 문제 바로가기

>  https://www.acmicpc.net/problem/2164

### 알고리즘

> 자료구조. 큐

### 문제 풀이 및 주의

> [Deque 런타임 에러] 
>
> ``` c++
> 	while (1) {
> 		Deq.pop_back();
> 		int temp = Deq.back();//back. end 
> 		Deq.pop_back();
> 		Deq.push_front(temp);
> 		if (Deq.size() == 1) {
> 			cout << Deq.front();
> 			break;
> 		}
> 	}
> ```
>
> 