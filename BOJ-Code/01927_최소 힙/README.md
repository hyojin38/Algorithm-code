# [BOJ] 1927 - 최소 힙

### 문제 바로가기

>  https://www.acmicpc.net/problem/11279

### 알고리즘

> heap, prioirty_queue

### 문제 풀이 및 주의

prioirty_queue

- 우선순위 큐를 구현한 stl
- prioirty_queue container은 vector, deque container 와 붙어서 사용 가능
- 내부적으로는 algorithm 에 있는 힙 관련 함수들을 사용하여 구현 되어있다
- 내부 구조 default는 vector container 기반이다
- 정렬기준 default는 내림차순(less) 기반이다 (큰것부터 나옴)
- greater < 자료형> 을 넣으면 작은것 부터 나온다 

```c++
#include <queue>

using namespace std;

//템플릿 선언 부분
//template < typename T,
//                typename Container = vector<T>,
//                typename Compare = less<typename Container::velue_type> >
//class priority_queue;

prioirty_queue < int > PQ1; //기본 생성자
prioirty_queue < int , deque<int> > PQ2; // 내부 컨테이너 변경
prioirty_queue < int , vector <int>, greater <int> PQ2; //정렬 기준 변경

```

