# [BOJ] 01094 막대기

### 문제 바로가기

>  https://www.acmicpc.net/problem/1094

### 알고리즘

> 수학. 비트마스킹. vector에 값을 넣어줌 - vector size로 계산

### 문제 풀이 및 주의

> **1. 산술연산자**
>
> ```
> 4/3 //1 이 나옴
> ```
>
> ​	int형 이하의 자료형에서 산술 연산시 int로 변환되어 수행되기 때문에 연산의 결과가 int .
>
>  	소수점 이하는 버려지고 정수부문만 반환됨( 반올림된 값이 아님 )
>
> **2. 해결방법**
>
>  	두 피연산자 중 하나를 실수로 혹은 둘 다 실수로 바꾼다
>
>  	int + long = long + long = long
>
>  	long +int = long +long =long
>
> ​	 int + float = float + float =float
>
> ​	 두 피연산자가 다를 경우 큰 값에 맟춰지고. 반환값도 큰 값이 된다. (컴파일러가 해주는 묵시적 형변환 : 타입이 다른 두 피연산자가 사칙연산 수행할 경우 오버플로우 발생 가능성이 높아 이를 최소화 하고자 컴파일러가 자동으로 큰쪽에 맞춰줌)



> **3. 비트마스킹 **
>
>  결국 1,2,4,8,16,32 등 2의 배수의 수로 만들라는 의미. 비트만 세어주면 된다
>
> ```c++
> #include <iostream>
> 
> int n, ans;
> 
> int main(void)
> {
>   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
>     cin >> n;
> 
>   for(int i = 0 ; i < 7 ; i++)  // 최대값 64니까 2의 6승까지만 비트마스킹
>   {
>    
>     if(n & (1 << i))  ans++;  // 해당 자릿수에 비트가 있으면 증가
>   }
>   cout << ans << '\n';
> }
> ```
>
> 



