# [BOJ] 20058 마법사상어와 파이어스톰

### 문제 바로가기

>  https://www.acmicpc.net/problem/20058

### 알고리즘

> 구현. 시뮬
>

### 문제 풀이 및 주의

>**주의 1. 문제 읽기**
>
>레벨 2면 4x4 행렬 안에서 2x2 4개가 시계방향으로 돈다고 생각. 그게 아니라
>
>4x4행렬의 row 1이 새로운 4x4 행렬의 col 4, row 2가 col 3, row 3가 col 2, row 4가 col 1... 



> **주의2. 문제 특수사항 **
>
> L이 0인경우 생각하기



> **pow**
>
> base 가 되는 숫자의 n제곱을 구하는것 (base의 n승= base ^ n) 
>
> ```c++
> #include <cmath>
> //1. double pow(double base,double n)
> //2. float pow(float bas, float n)
> //3. long double pos(long double base, long double n)
> 
> cout<< pos(10,2)<<endl; // 암묵적 형변환에 의해서 10은 (float)10 이런식으로 들어갈 것이다
> ```

> **sqrt**
>
> 매개변수 x로 들어온 숫자에 루트 씌워 계산한 값을 반환(루트 x의 값= 제곱근을 구해주는 함수)
>
> ```c++
> #include <cmath>
> //double        sqrt(double x)
> //float           sqrt(float x)
> //long double    sqrt(long double x)
> // double        sqrt(T x) //T는 template를 의미 
> //c++는 함수 오버로딩이 가능하기 때문에 같은 이름의 함수라도 매개변수를 다르게 선언할 수 있다.
> 
> cout<<sqrt(9)<<endl;
> cout<<sqrt(85.4)<<endl;
> 
> ```
>
> 


