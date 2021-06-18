# [PG] Level1-소수 찾기

### 문제 바로가기

>  https://programmers.co.kr/learn/courses/30/lessons/12921

### 문제 풀이 및 주의

> #### 소수찾기:1과 자기 자신으로만 나누어 지는 수
>
>  i 가 소수인가 아닌가 판별
>
> 1. for(int j=2;j>=Math.sqrt(i);j++) 반복문 돌면서
> 2. 나머지가 0으로 나누어 떨어지면 소수가 아니다
>
> 1은 소수가 아니다
