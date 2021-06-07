# [BOJ] 1937 - 욕심쟁이 판다

### 문제 바로가기

>  https://www.acmicpc.net/problem/1937

### 알고리즘

> DP. DFS

### 문제 풀이 및 주의

> #### DP로 차근차근 풀어보기
>
> DP[ a ] [ b ]=c // a,b에 있을때 최대로 살 수 있는 날짜 c
>
> dp가 0일때 dfs(x,y);
>
> x,y 기준 동,서,남,북 탐색
>
> 1.nx,ny dp가 0이면 dfs(nx,ny)
>
> 2.이후 dp[nx] [ny] + 1 과 tempAns(1: 하루만 살수있다) 비교 tempAns 갱신

