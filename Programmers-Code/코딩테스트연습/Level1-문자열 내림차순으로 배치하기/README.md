# [PG] Level1-문자열 내림차순으로 배치하기

>  https://programmers.co.kr/learn/courses/30/lessons/12917

### 문제 풀이 및 주의

> #### String vs StringBuilder vs StringBuffer
>
> **1. String에서 concat, + 사용 시 속도가 왜 느려지나?**
>
> String은 새로운 값 할당할 때 마다 새로 생성된다
>
> String 내부에 private final car value[]; 를 볼수 있따
>
> 즉 string에 저장된 문자열은 char의 배열 형태로 private:외부에서 접근 x, final: 초기값으로 주어진 string 값은 불변이다. 라는 것을 알 수 있다. 따라서 새로 생기는것
>
> - 수십번 string이 더해지면 string의 주소값이 stack에 쌓이고
> - 클래스들은 Garbage Collector가 호출되기 전까지 heap에 지속적 쌓여 메모리 관리 측면에서 치명적이다
>
>  
>
> **2.StringBuffer, StringBuilder를 사용하는 이유는?**
>
> stringbuffer와 stringbuilder는 memory에 append 하는 방식으로 클래스 직접 생성하지 않는다
>
> 논리적으로 따져보면 클래스가 생성될때 method와 variable도 같이 생성되는데 이런 시간 사용이 없다.
>
>  
>
> **3. StringBuffer, StringBuilder의 차이는?**
>
> StringBuffer는 변경가능하고 Thread Safe로 multiple thread 환경에서 안전한 클래스이다 
>
> StringBuilder는 변경가능 하지만 Synchronization 적용 x
>
> 
>
> #### BufferedReader
>
> ```java
> StringBuffer sbuffer = new StringBuffer("SB");
> StringBuilder sbuilder = new StringBuilder("SB");
> 
> return new StringBuilder(new String(sol)).reverse().toString();
>     }
> ```
>
> **sb.append(값)**
>
> \- StringBuffer, StringBuilder 뒤에 값을 붙인
>
> **sb.insert(인덱스, 값)**
>
> \- 특정 인덱스부터 값을 삽입한다
>
> **sb.delete(인덱스, 인덱스)**
>
> \- 특정 인덱스부터 인덱스까지 값을 삭제한다
>
> **sb.indexOf(값)**
>
> \- 값이 어느 인덱스에 들어있는지 확인한다
>
> **sb.substring(인덱스, 인덱스)**
>
> \- 인덱스부터 인덱스까지 값을 잘라온다
>
> **sb.length()**
>
> \- 길이 확인
>
> **sb.replace(인덱스, 인덱스, 값)**
>
> \- 인덱스부터 인덱스까지 값으로 변경
>
> **sb.reverse()**
>
> \- 글자 순서를 뒤집는다

