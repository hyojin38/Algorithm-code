# < bitset > 

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

