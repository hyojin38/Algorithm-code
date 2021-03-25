# [BOJ] 9251 LCS

### 문제 바로가기

>  https://www.acmicpc.net/problem/9251

### 알고리즘

> DP. 문자열

### 문제 풀이 및 주의

> 다시 풀기 [풀이 참고]

>```C++
>#include<iostream>
>#include<vector>
>#include<algorithm>
>#include<string>
>#include<cstring>
>#define MAX 1000+2
>
>using namespace std;
>
>string s1, s2;
>int N, M;
>char S1[MAX], S2[MAX];
>int dp[MAX][MAX];
>
>void Solution() {
>	cin >> s1 >> s2;
>	N=s1.size();
>	M= s2.size();
>
>	for (int i = 1; i <= N; i++) {
>		S1[i] = s1[i-1];
>	}
>	for (int i = 1; i <= M; i++) {
>		S2[i] = s2[i-1];
>	}
>	for (int i = 1; i <= N; i++) {
>		for (int j = 1; j <= M; j++) {
>			dp[i][j] = max({ dp[i][j - 1],dp[i - 1][j] ,
>							 dp[i - 1][j - 1] + (S1[i] == S2[j]) });
>        }
>	}
>	cout << dp[N][M];
>}
>int main() {
>	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
>	freopen("Text.txt", "r", stdin);
>
>	Solution();
>
>	return 0;
>}
>```



> ```
> 만약, 비교하는 위치의 문자가 서로 같으면   
>  현재 위치의 값 = 왼쪽 대각선 값 + 1  (배열 범위를 벗어났으면 0이라고 가정 )
> 다르다면  
>  현재 위치의 값 = MAX{왼쪽 값, 위쪽 값}  
> ```

| 0    | 0    | A    | C    | A    | Y    | K    | P    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 0    | 0    | 0    | 0    | 0    | 0    | 0    | 0    |
| C    | 0    | 0    | 1    | 1    | 1    | 1    | 1    |
| A    | 0    | 1    | 1    | 2    | `2`  | 2    | 2    |
| P    | 0    | 1    | 1    | 2    | 2    | 2    | 3    |
| C    | 0    | 1    | 2    | 2    | 2    | 2    | 2    |
| A    | 0    | 1    | 2    | 3    | 3    | 3    | 3    |
| K    | 0    | 1    | 2    | 3    | 3    | 4    | 4    |

> 결과: 행에서 현재까지 나온 문자열과 열에서 현재까지 나온 문자열 사이의 LCS 길이
>
> EX) [2,5]: ACAY와 CA 사이의 최장 공통수열(LCS)의 길이는 2

