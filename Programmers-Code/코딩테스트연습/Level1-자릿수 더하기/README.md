# [PG] Level1-제일 작은 수 제거하기

### 문제 바로가기

>  https://programmers.co.kr/learn/courses/30/lessons/12931

### 문제 풀이 및 주의

> #### 풀이
>
> 1)  int n 을 string으로 변경 
>
> String str= String.valueOf(n);
>
> 2) 끊어서 각 값을 더하기
>
> ans+= Integer.parseInt( !!!!여기는 string!!!!) ;
>
> str.charAt(i)는 char형태 이므로 string으로 만들기 위해 +""을 붙인다
>
> ans+=Integer.parseInt(str.charAt(i)+"");
