# < string > 

> ### [isdigit 함수]
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
>
> 

>#### int -> string [ to_string() 함수]
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

> #### string to int [stoi함수. stoll함수]
>
> ```c++
> #include <string>
> int stoi(const string& str [,size_t* idx=0, int base=10] )
> //3번째 인수 디폴트값 10
> //이를 변경해주면 n진수의 문자열을 10진수의 수로 변경할 수 있다
> ```
>
> 
