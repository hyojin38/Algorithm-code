package Programmers;
import java.util.Arrays;
import java.util.Scanner;
public class Level1_�ڿ���������迭�θ���� {
	
	static long n;
	 public static void main(String[] args) {
	        Scanner sc = new Scanner(System.in);
	        n = sc.nextLong();
	        
	        System.out.print(Arrays.toString(solution(n)));
	      
	    }
	    private static int[] solution(long n) {
	    	String temp= String.valueOf(n);
	    	char[] Ans=temp.toCharArray();
	    	int[] Ans2=new int[Ans.length];
	    	for(int i=0;i<Ans2.length;i++) {
	    		Ans2[i]=Ans[i]-'0';
	    	}
	    	return Ans2;
	    }
}
