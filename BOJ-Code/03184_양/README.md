# [BOJ] 03184 양

### 문제 바로가기

>  https://www.acmicpc.net/problem/3184

### 알고리즘

> 그래프 이론. 그래프 탐색 . BFS

### 문제 풀이 및 주의

> [2차원 vector 입력 주의]
>
> ```C++
>vector<vector<int>> V;
> 
> vector<int> v2;
> V.push_back(v2);
> 
> // 주의 
> V[i].push_back(temp);//V[i]에 담겨있는 벡터에 temp입력
> cout << V[i][j]; //출력
> cout << V.at[i].at[j];//동일 출력
> ```
> 
> ```c++
>//런타임에러 : 2차원 벡터 v 입장에서 비어있는 v2를 입력받은것 
> V.push_back(v2); 
> v2.push_back(temp);
> cout<<V[i][j]
> ```
> 