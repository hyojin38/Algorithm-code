package Programmers;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
public class Level1_문자열_내림차순으로_배치하기 {
	
	static String S;
	 public static void main(String[] args) throws NumberFormatException, IOException {
		 // Scanner sc = new Scanner(System.in);
	     // System.out.print(Arrays.toString(solution(n)));
		 	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			S= br.readLine();
		 
			//BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			//int TC=Integer.parseInt(br.readLine());
			
			System.out.println(solution(S));
	    }
	 
	 private static String solution(String s) {
		//문자열 s에는 영문 대소문자로만 구성 
		 char[] arr=s.toCharArray();
		 Arrays.sort(arr);//작은것부터 
		 //우리는 큰것부터 작은 순으로 출력하고 싶음
		 String ans="";
//		 for(int i=arr.length-1;i>=0;i--) {
//			 ans+=arr[i]+"";
//		 }
//		 return ans;
		 return new StringBuilder(new String(arr)).reverse().toString();
	 }
}
