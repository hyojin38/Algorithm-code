# [PG] Level1-핸드폰 번호 가리기

### 문제 바로가기

>  https://programmers.co.kr/learn/courses/30/lessons/12948

### 문제 풀이 및 주의

> #### 문자열 String 내장 함수
>
> 1.  charAt(int index)
>
>    Arr의 index 위치에 저장되어있는 문자 반환
>
>    ```java
>    System.out.println(Arr.charAt(2));
>    ```
>
>    
>
> 2. IndexOf(String Key) / lastIndexOf(String key)
>
>    문자열 중 입력받은 문자가 있다면 해당 문자의 index위치를 반환 , 없다면 -1 리턴
>
>    lastIndexOf는 끝에서 부터 조회하는 함수
>
>    
>
> 3. length()
>
>    문자열의 길이를 조회하는 함수
>
>    
>
> 4. equals(string st)
>
>    두개의 문자열이 동일한 값을 가지고 있는지 비교하여 결과값 리턴
>
>    ```java
>    String st1="RED";
>    String st2=st1;
>    String st3="RED";
>    String st4=new String("RED");
>    String st5="Green";
>    
>    System.out.println(st1==st2);//true
>    System.out.println(st1.equals(st2));//true
>    
>    System.out.println(st1==st3);//true
>    System.out.println(st1.equals(st3));//true
>    
>    System.out.println(st1==st4);//false
>    System.out.println(st1.equals(st4));//true
>    
>    System.out.println(st1==st5);//false
>    System.out.println(st1.equals(st5));//false
>    
>    
>    ```
>
>    
>
>    Q. st3 예제의 경우 새로만든 것이라서 다른 주소값을 가리킬텐데 왜 st1==st3일까?
>
>    A: JAVA는 기본적으로 로컬함수(같은 제어블록)내에서 같은 문자열이 나오면 공유 상수 pool에서 관리하기 때문에 새로 메모리를 잡지 않고 원래 있던 주소로 배정해준다
>
>    
>
> 5. substring(int startindex) / substring(int startindex,int endindex) 
>
>    문자열 중 특정 부분을 뽑아낼 경우
>
>    ```java
>    String str1="자바 문자열공부 화이팅!";
>    
>    System.out.println(str1.substring(3,6))//3~5 문자열
>    ```
>
>    
>
> 6. toUpperCase() / toLowerCase()
>
>    문자열 모두 대문자로 변경하고자 할때/ 소문자로 변경
>
>    
>
> 7. concat() // +
>
>    문자열 + 문자열 이어줄때 (합칠경우)
>
>    ```java
>    String str1="자바 문자열";
>    String str2="공부 화이팅!";
>    
>    System.out.println(str1.concat(str2));
>    System.out.println(str1+str2);
>    ```
>
>    
>
> 8. startWith(char ch) / endWith(char ch)
>
>    문자열이 지정한 문자로 시작/끝인지 판단 후 있으면 true 없으면 false 를 반환한다. 대소문자 구별한다
>
>    
>
> 9. replaceAll("ab","ba")
>
>    문자열 중 특정 문자를 다른문자로 바꾸고 싶을때
>
>    ```java
>    String str1="자바 문자열!!";
>    
>    System.out.println(str1.replaceAll("문자열","알고리즘"));
>    ```
>
> 10. replace(바꾸려는 기존 문자열, 새로 바꿀 문자열)
>
>     특정 문자를 원하는 문자료 변경하고 싶은 경우 사용
>
>     
>
> 
>
> 배열 변수를 선언하는 방법에는 
>
> 첫번째 초기값과 함께 선언하는 경우
>
> 두번째 배열의 길이만 설정하여 변수를 먼저 생성하고 나중에 값을 지정해주는 방법이 있다
>
>  	2.  배열의 길이는 .length 이용하여 구한다
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

https://cceeun.tistory.com/32
