# [BOJ] 06087 레이저 통신

### 문제 바로가기

>  https://www.acmicpc.net/problem/6087

### 알고리즘

> 그래프 이론, 그래프 탐색, BFS

### 문제 풀이 및 주의

> **[문제 유형]** DFS 시간초과
>
> **[BFS 사용]**
>
> 1.탐색하고자 하는 좌표가 맵의 범위 내 (0~ W,H)
>
> 2.탐색하고자 하는 좌표가 MAP에서 갈 수 있는 곳인가? (*)
>
>  	+  왔던 곳으로 돌아가면 continue
>
> 3.현재 탐색방향과 다르다면 ncnt=cnt+1
>
> 4.탐색하고자 하는 좌표의 이전 거울 갯수와 현재 ncnt 보다 더크거나 같으면 갱신. Q 넣기
>
> **[Queue]**
>
> queue<pair<pair<int,int>,pair<int,int>>> Q
>
> Q(make_pair(make_pair(x,y),make_pair(i,j)));
>
> **[초기화]**
>
> 배열 987654321.. 하나씩 초기화 해주기 