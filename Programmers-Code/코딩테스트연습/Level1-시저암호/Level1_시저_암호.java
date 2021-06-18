package Programmers;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
public class Level1_시저_암호 {
	
	static int N;
	 public static void main(String[] args) throws NumberFormatException, IOException {
		 // Scanner sc = new Scanner(System.in);
	     // System.out.print(Arrays.toString(solution(n)));
		 	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			N= Integer.parseInt(br.readLine());
		 
			//BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			//int TC=Integer.parseInt(br.readLine());
			
			System.out.println(solution(N));
	    }
	 
	 private static int solution(int s) {
		 int ans=0;
		 for(int i=1;i<=Math.sqrt(s);i++) {
			 if(i*i >s) return ans;
			 if(s%i==0) {
				 int temp=s/i;
				// System.out.println(i);
				 ans+=i;
				  if(i!=temp){
	                     ans+=temp;
	                }
			 }
			 
		 }
		return ans;
	 }
}
