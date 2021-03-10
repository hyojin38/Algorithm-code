# [BOJ] 01039 교환

### 문제 바로가기

>  https://www.acmicpc.net/problem/1039

### 알고리즘

> 그래프 이론. 그래프 탐색. BFS 

### 문제 풀이 및 주의

> **주의**
>
> 시간초과. 이미했던 경우라면 다시 하지 않도록 visited[1000000+1] [10+1] 으로 체크하기

> **1. String - char - int **
>
> ```c++
> String s;
> int a;
> a= s[1] -'0'; //int 로 가져올때는 -'0'
> s[2]=a; //이럴 경우 담기는 것은 a의 숫자가 아닙니다.
> ```
>



> **2.  atoi . atof. atol**
>
> char * 타입의 문자열을 정수로, 실수로 (=숫자로) 변경하는 함수
>
> **atoi** =char* to int = 문자열 정수로
>
> **atof** = char* to double= 문자열을 실수 타입으로
>
> **atol** = char * to long int = 문자열을 long 정수 타입으로
>
> 문자열을 공백 or 숫자가 아닌숫자가 나올때 까지 숫자로 변환해준다



>**3. stoi. stof. stol. stod**
>
>C++11에서 부터 새롭게 생김. C++의 string 클래스를 정수로, 실수로 변경하는 함수
>
>**stoi** = string to int
>
>**stof** = string to float
>
>**stol** = string to long int
>
>**stod** = string to double
>
>```c++
>stoi(문자열,  포인터 타입 [nullptr], 진수[10진수생략가능] )
>     
>    string str1 = "33BlockDMask";
>        //test2
>    size_t sz;
>    int num2 = stoi(str1, &sz);
>    cout << "test2. stoi(str1, &sz);" << endl;
>    cout << " - str1 : " << str1 << endl; //33BlockDMask
>    cout << " - num2 : " << num2 << endl; //33
>    cout << " - sz : " << sz << endl;    //2
>    cout << " - str1[sz] : " << str1[sz] << endl;  //B
>    cout << " - str1.substr(sz) : " << str1.substr(sz) << endl; //BlockDMask"
> 
>```
>