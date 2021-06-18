package Programmers;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
public class Level1_자릿수_더하기 {
	
	static long n;
	 public static void main(String[] args) throws NumberFormatException, IOException {
		 // Scanner sc = new Scanner(System.in);
	     // System.out.print(Arrays.toString(solution(n)));
		 	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			n=Integer.parseInt(br.readLine());
			
			//BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			//int TC=Integer.parseInt(br.readLine());
			
			System.out.println(solution(n));
	    }
	 
	    private static int solution(long n) {
	    	String str= String.valueOf(n);
	    	int ans=0;
	    	for(int i=0;i<str.length();i++) {
	    		ans+=Integer.parseInt(str.charAt(i)+"");
	    	}
	    	return ans;
	    }
}
