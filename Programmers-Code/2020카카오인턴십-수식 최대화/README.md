# [PG]  2020 카카오인턴십_수식 최대화

### 문제 바로가기

>  https://programmers.co.kr/learn/courses/30/lessons/67257

### 알고리즘

> 

### 문제 풀이 및 주의

> ### string 숫자와 연산자로 분류 
>
> #### [1.isdigit 함수]
>
> ##### - int isdigit(int c);	
>
> 매개변수로 들어온 char 타입이 10진수로 변경가능하면 1(true) 아니면0(false)반환
>
> 함수 원형을 살펴보면 매개변수 타입이 char이 아닌 int 타입인것을 확인 할 수 있다.
>
> 이것은 char 타입이 아스키 코드 번호로 들어갈 수 있기 때문이다.
>
> 즉 아스키 코드표에서 48~57에 해당하는 문자 '0'~'9'가 들어오면 true를 반환하는 형태이다 
>
> ```c++
> #include <cctype>
> 
> string str="B123456789";
> cout<<isdigit(str[0])<<endl;//0 flase
> ```




>### vector 특정 원소 지우기
>
>#### - erase(int position)
>
>```c++
>v.erase(v.begin()+1);// vector v에서 1번째 원소를 지운다
>```
>
>#### - erase(int start, int end)
>
>```c++
>v.erase(v.begin()+1, v.begin+3);// vector v에서 1번째부터 2번째까지의 원소를 지운다
>```
>
>```c++
>vector<int> v(5);
>for(int i = 0 ; i < 5; i++) v[i] = i+1; // 1 2 3 4 5
>
>   1. 
>   v.erase(v.begin() + 1);
>   for(int it : v) cout << it << " "; // 1 3 4 5
>
>   2. 
>   v.erase(v.begin() + 1, v.begin() + 3);
>   for(int it : v) cout << it << " "; // 1 4 5
>```



> ### next_permutation 함수
>
> 

