# [BOJ] 1525 퍼즐

### 문제 바로가기

>  https://www.acmicpc.net/problem/1525

### 알고리즘

> - [그래프 이론](https://www.acmicpc.net/problem/tag/7)
> - [그래프 탐색](https://www.acmicpc.net/problem/tag/11)
> - [너비 우선 탐색](https://www.acmicpc.net/problem/tag/126)

### 문제 풀이 및 주의

> #### 1. BFS로 0을 이동시키면서 확인하겠다 (0을 9로 바꿔서 진행)

> #### 2. map 사용하여 검색 시간 단축
>
> ```c++
> #include <map>
> 
> map < ll , int > check;
> 
> int main(){
> 	ll a=123456789;
>     ll b=987654321;
>     
> 	check.insert({a,0});
> 	
>     if(check.count(b)==0){ // count는 key값이 없다면 0, 있다면1
>         check.insert({b,0});
>     }
> }
> ```

>#### 3. %와 / 이용하여 저장은 string 계산은 2차원으로 진행

>#### 4. < string > find
>
>```c++
>int idx = str_a.find('9');
>```

> #### 5. 입력이 바로 맞을 수 있습니다
