# c++ 개념 정리

## 1. string

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

## 2. Vector

#####    vector 특정 원소 지우기


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



## 3.Bitset

```c++
#include <bitset>

  
    bitset<10> bit; // bitset을 선언, 총 10개의 비트를 의미한다.
 

    bit.reset();     // 전체 비트를 0으로 리셋한다.
    bit.set();    // 전체 비트를 1로 셋팅한다.
   

    int size = (int)bit.size();    // 비트셋으로 선언한 bit의 할당된 수를 구한다
   
    int any= bit.any();    // 비트셋중 하나라도 1이면 1을 반환, 모두 0이면 0을 반환한
다.// 현재는 1이다.
	int none=bit.none(); //비트셋 중 모두가 0이어야 1을 반환
    
	bit.flip(3);     // 4번째 비트 반전 n+1번째 비트 반전
 	bit.flip();      // 전체 비트 반전


    bit.set(0, true);    // 첫번째 비트는 true, 네번째 비트는 false 할당
    bit.set(3, false);
 
	//cout>>
    bit.test(0) // n+1번째 비트 검사 (1인지 0인지) // 첫번째 비트 검사
    bit[4] // 다섯번째 비트 검사(배열형식으로도 가능하다.)


    string str = bit.to_string();    // 비트를 string으로 변환


    cout << "bit.to_ulong() :: " << bit.to_ulong() << endl;    // 비트를 숫자로 변환 //bit.to_ulong() / bit.to_ullong()
 
```

원하는 비트 몇 개를 쓰기 위한 bitset STL이다. 

이때 0이면 채워지지 않은 것, 1이면 채워진 것



