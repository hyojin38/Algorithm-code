# [PG] Level1-최대공약수와 최소공배수

### 문제 바로가기

>  https://programmers.co.kr/learn/courses/30/lessons/12940\|

### 문제 풀이 및 주의

> **유클리드 호제법 **

> 1. 큰수를 작은수로 나눈다
> 2. 나눈수를 나머지로 계속 나눈다
> 3. 나머지가 0이 나오면 나누는 수가 최대공약수
>
> ```java
>  private static int[] solution(int n, int m) {
> 
>      GCD(max(n,m),min(n,m));
>      lcm=gcd*(n/gcd)*(m/gcd);
>      int[] answer = {gcd,lcm};
>      return answer;
>  }
> private static int min(int a,int b){
>     if(a<b)return a;
>     else return b;
> }
> private static int max(int a,int b){
>     if(a>b)return a;
>     else return b;
> }
> private static void GCD(int a, int b){
>     int mod =a%b;
>     if(mod==0){
>         gcd=b;
>     }else{
>         GCD(b,mod);
>     }
> }
> ```

