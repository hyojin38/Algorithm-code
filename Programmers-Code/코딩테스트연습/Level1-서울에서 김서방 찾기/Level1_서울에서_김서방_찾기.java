package Programmers;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
public class Level1_서울에서_김서방_찾기 {
	
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
		String Ans="김서방은 ";
		 for(int i=0;i<seoul.length;i++) {
			 if(seoul[i].equals("Kim")) {
				 Ans+=i+"에 있다";
				 return Ans;
			 }
		 }
		return Ans;
		
	 }
}
