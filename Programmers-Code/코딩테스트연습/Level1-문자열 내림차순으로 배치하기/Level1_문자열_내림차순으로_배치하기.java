package Programmers;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
public class Level1_���ڿ�_������������_��ġ�ϱ� {
	
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
		//���ڿ� s���� ���� ��ҹ��ڷθ� ���� 
		 char[] arr=s.toCharArray();
		 Arrays.sort(arr);//�����ͺ��� 
		 //�츮�� ū�ͺ��� ���� ������ ����ϰ� ����
		 String ans="";
//		 for(int i=arr.length-1;i>=0;i--) {
//			 ans+=arr[i]+"";
//		 }
//		 return ans;
		 return new StringBuilder(new String(arr)).reverse().toString();
	 }
}
