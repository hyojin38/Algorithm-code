package Programmers;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
public class Level1_���￡��_�輭��_ã�� {
	
	static String[] seoul= {"J","Kim"};
	
	 public static void main(String[] args) throws NumberFormatException, IOException {
		 // Scanner sc = new Scanner(System.in);
	     // System.out.print(Arrays.toString(solution(n)));
		 	//BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			//N= Integer.parseInt(br.readLine());
		 
			//BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			//int TC=Integer.parseInt(br.readLine());
			
			System.out.println(solution(seoul));
	    }
	 
	 private static String solution(String[] seoul) {
		String Ans="�輭���� ";
		 for(int i=0;i<seoul.length;i++) {
			 if(seoul[i].equals("Kim")) {
				 Ans+=i+"�� �ִ�";
				 return Ans;
			 }
		 }
		return Ans;
		
	 }
}
