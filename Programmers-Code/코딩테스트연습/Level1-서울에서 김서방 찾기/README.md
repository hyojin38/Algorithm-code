# [PG] Level1-서울에서 김서방 찾기

### 문제 바로가기

>  https://programmers.co.kr/learn/courses/30/lessons/12919

### 문제 풀이 및 주의
> #### String 비교는 equals로 한다
> ```java
> if(seoul[i].equals("Kim"))

> #### 배열
>
>   1. 배열은 길이가 고정되어 있다
>
>      배열 변수를 선언하는 방법에는 
>
>      첫번째 초기값과 함께 선언하는 경우
>
>      두번째 배열의 길이만 설정하여 변수를 먼저 생성하고 나중에 값을 지정해주는 방법이 있다
>
>   2. 배열의 길이는 .length 이용하여 구한다
>
> ```java
> import java.utill.Scanner;
> 
> public class Solution{
>     public static void main(String[] args){
>        String[] Ans1={"월","화","수"};
> 
>        String[] Ans2=new String[4];
>         Ans2[0]="목";
>         Ans2[1]="금";
>         Ans2[2]="토";
>         Ans2[3]="일";
> 
>        for(int i=0;i<Ans.length;i++){
>            System.out.println(Ans1[i]);
>        }
> 
>     }
> 
>     private static void Sol(int a,int b ){
>        System.out.print(a,b);
>     }
> }
> ```
>
> 3. 배열 출력
>
>     ```java
>     System.out.println(Arrays.toString(arr));
>     ```
>
> 4. 배열의 복사
>
>     clone() : Object함수로서 객체를 복사한다
>
>     하지만 참조변수 or 배열은 clone 또한 주소값으 가지므로 원래객체에 영향을 미친다
>
>     
>
> 5. 배열은 [] 를 통해 접근가능

