package Programmers;
import java.util.Scanner;
public class Level1_x만큼간격이있는n개의숫자 {

	 public static void main(String[] args) {
	        Scanner sc = new Scanner(System.in);
	        int x = sc.nextInt();
	        int n = sc.nextInt();
	        
	        long[] Ans=Sol(x,n);
	        for(int i=0;i<n;i++) {
	        	 System.out.println(Ans[i]);
	   	      
	        }
	       
	    }
	    private static long[] Sol(int x,int n){
	    
	    	  long[] answer=new long[n] ;
	          long ans=x;
	          for(int i=0;i<n;i++){
	              answer[i]=ans;
	              ans+=x;
	          }
	          return answer;
	    }
}
