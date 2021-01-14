# [BOJ] 17069 파이프 옮기기 2

### 문제 바로가기

>  https://www.acmicpc.net/problem/17069

### 알고리즘

> DP

### 문제 풀이 및 주의

> **[문제 제대로 읽기]** N의 최대범위가 증가 : DP 사용 시간 줄이기
>
> **[2차원 vector 입력 주의]**
>
> ```C++
> vector<vector<int>> V;
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
> //런타임에러 : 2차원 벡터 v 입장에서 비어있는 v2를 입력받은것 
> V.push_back(v2); 
> v2.push_back(temp);
> cout<<V[i][j]
> ```
>
> **[ int vs long vslong long vs BigInteger]** (자료형 위키 : [https://en.wikipedia.org/wiki/...](https://en.wikipedia.org/wiki/C%2B%2B11#Type_long_long_int))
>
> ##### int
>
> 정수 자료형 int는 32/64비트 환경에 상관없이 4바이트의 정보를 기록할 수 있는 자료형
>
> signed int(부호가 있는 정수)를 기준으로 기록할 수 있는 양의 정수 범위는 0 ~ 2,147,483,647(16진수로 7FFFFFFF)
>
> ##### long long 
>
>  int 로 계산할 수 있는 범위가 넘어설때 . 이를 산술 넘침 혹은 Overflow라 함
>
> 4바이트의 저장 공간만으로는 좀 더 큰 정수를 계산할 수 없게 되었고, 점점 커져가는 메모리 공간, 계산량에 어느 정도 대비할 필요가 있어서 1999년도 C언어 표준안(C99)에서 8바이트의 크기를 가지는 정수 자료형 long long이 소개되었고, C++은 2011년도 C++ 표준안(C++11)에서 이 자료형을 지원하게 되었죠. long long은 8바이트의 공간을 가지는 자료형이기에 signed long long을 기준으로 하면 최대 계산할 수 있는 양의 정수 범위는 0 ~ 9,223,372,036,854,775,807(16진수로 7FFFFFFFFFFFFFFF)이다

![image-20210114181031802](C:\Users\Hyojin\AppData\Roaming\Typora\typora-user-images\image-20210114181031802.png)



