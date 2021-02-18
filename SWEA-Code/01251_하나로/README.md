# [SWEA] 01251 하나로

### 알고리즘

> 그래프이론. MST

### 문제 풀이 및 주의

> #### MST
>
> ```c++
> void MakeSet(int x){
> 	P[x]=x;
> }
> int FindSet(int x){
> 	if(x==P[x]) return true;
> 	else return P[x]=FindSet(P[x]); // 주의!!!!
> }
> void MakeSet(int x,int y){
> 	x=FindSet(x);
> 	y=FindSet(y);
> 	if(x!=y){
> 		P[y]=x;
> 	}
> }
> bool CheckRoot(int x,int y){
> 	x=FindSet(x);
> 	y=FindSet(y);
> 	if(x==y) return true;
> 	else return flase;
> }
> ```
>

> #### double 반올림
>
> ```c++
>	cout << fixed; //소수점을 고정시켜 표현하겠다
> 	cout.precision(0); //0자리까지 표현하겠다
>```

> ####  memset
>
> ```c++
> #include <cstring> // 중요
> 
> memset(size,0,sizeof(size));
> ```

> ####  제곱
>
> ```c++
> LL Ans= x*x;  // ^2 절대 아님 ^는 비트연산자
> 			  //두항의 같은자리의 비트가 서로 다를 경우 1을 반환하는 XOR비트
> 
> #include <cmath>
> 
> double pow(double base,double n)
> int pow(int base,int n)
> ```

> ####  LL type 
>
> ```c++
> typedef long long LL;
> ```

