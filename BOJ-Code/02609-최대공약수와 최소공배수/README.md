# [BOJ] 2069 - 최대공약수와 최소공배수

### 문제 바로가기

>  https://www.acmicpc.net/problem/2069

### 알고리즘

> 수학

### 문제 풀이 및 주의

> **방법 1. min(A,B) ~ 1 까지 나누어지는 수 찾기 GCD **
>
>  ```c++
>  min= Min(A,B);
>  for(int i=Min;i>0;i++){
>  	if(A%i==0 &&B%i==0) {
>  		GCD=i;
>  		LCM=i*(A%i)*(B%i);
>  		return;
>  	}	
>  }
>  ```
>
>  문제점: a와b가 서로소일 경우 **O(min(a,b))의 시간 복잡도** 



> **방법 2. 유클리드 호제법 **
>
> 1. 큰수를 작은수로 나눈다
> 2. 나눈수를 나머지로 계속 나눈다
> 3. 나머지가 0이 나오면 나누는 수가 최대공약수
>
> ```c++
> int max(int a, int b) {
> 	if (a > b)return a;
> 	else return b;
> }
> int min(int a, int b) {
> 	if (a< b)return a;
> 	else return b;
> }
> void GCD(int a, int b) {
> 	int mod = a % b;
> 	if (mod == 0) {
> 		gcd = b;
> 	}
> 	else {
> 		GCD(b,mod);
> 	}
> }
> int main() {
> 
> 
> 	GCD(max(a, b), min(a, b));
> 	
> 	lcm = gcd * (a / gcd)*(b / gcd);
> 	
> 	cout << gcd << endl << lcm;
> 	return 0;
> }
> ```
>
> 
