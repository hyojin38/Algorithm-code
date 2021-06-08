# [BOJ] 02533 - 사회망 서비스(SNS)

### 문제 바로가기

>  https://www.acmicpc.net/problem/2533

### 알고리즘

> TreeDP 
>
> - [다이나믹 프로그래밍](https://www.acmicpc.net/problem/tag/25)
> - [트리](https://www.acmicpc.net/problem/tag/120)
> - [트리에서의 다이나믹 프로그래밍](https://www.acmicpc.net/problem/tag/92)

### 문제 풀이 및 주의

>  **DP[ 0 || 1 ] [ cur ] = num**
>
>cur 번인 내가 일반인(0)일때 자식 노드 친구들이 얼리어답터일 최솟값 num
>
>cur 번인 내가 얼리어답터(1)일때 자식 노드 친구들이 얼리어답터일 최솟값 num 
>
>- DP[1] [cur]은 내가 얼리어답터 이므로 1로 초기화
>
>```C++
>int DP[2][MAX]={0,};
>```
>
>​	+ 자식 노드를 탐색 : 일반적 DFS와 다르게 방문했던 노드를 다시 방문하면 안된다(?)
>
>
>
>2. 현재 노드의 자식 노드에서 얻을 수 있는 값을 DP테이블에 반영
>
>- 나 일반인 : 자식 친구들 무조건 얼리어답터 마을
>
> DP[0] [cur] += DP[1] [next]
>
>- 나 얼리어답터 : 자식 친구들 얼리어답터이든 일반이든 상관 없다 `따라서 얼리어답터의 수가 최소인것`
>
> DP[0] [cur] += max( DP[0] [next] , DP[1] [next] )
>



> **Tree**
>
> tree 이기 때문에 어디서 시작하든 그 노드가 root가 된다



>**MIN define**
>
>```c++
>#define MIN (a,b) (a)<(b) ? (a):(b)
>```

