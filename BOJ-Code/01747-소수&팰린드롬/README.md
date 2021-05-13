# [BOJ]  1747 소수&팰린드롬

### 문제 바로가기

>  https://www.acmicpc.net/problem/1747

### 알고리즘

> - [수학](https://www.acmicpc.net/problem/tag/124)
> - [문자열](https://www.acmicpc.net/problem/tag/158)
> - [브루트포스 알고리즘](https://www.acmicpc.net/problem/tag/125)
> - [정수론](https://www.acmicpc.net/problem/tag/95)
> - [소수 판정](https://www.acmicpc.net/problem/tag/9)
> - [에라토스테네스의 체](https://www.acmicpc.net/problem/tag/67)

### 문제 풀이 및 주의

> 조건 제대로 읽기 : N 보다 크거나 같고

>#### int -> string
>
>```
>#include <string>
>
>int x=123;
>double d=12.345;
>
>string str1= to_string(x);
>string str2= to_string(d);//12.345000 소수점 6자리까지 포함된다
>```
>
>int 타입의 경우 동일하게 변경되지만 double은 소수점 6자리까지 포함된다.
>
>해당 특성을 파악하고 float, double, long double 등을 변환할 때는 주의해서 사용.

