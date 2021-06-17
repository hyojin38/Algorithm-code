# [PG] Level1- 자연수 뒤집어 배열로 만들기

### 문제 바로가기

>  https://programmers.co.kr/learn/courses/30/lessons/12932

### 문제 풀이 및 주의

> #### 흐름 파악
>
> 1. long n-> String 끊어야 하므로
> 2. String -> char[] 뒤집기 위해서 
> 3. char[] -> int[] 숫자 배열로 
>
> #### char->int
>
> 1. ```java
>    int i1 = c1 - '0';//아스키코드 사용
>    ```
>
> 2. ```java
>    char c1 = '9';
>    Character.getNumericValue(c1) // 9 
>    ```

