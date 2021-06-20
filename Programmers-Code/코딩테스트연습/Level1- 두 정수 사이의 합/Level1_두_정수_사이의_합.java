package Programmers;
import java.util.Scanner;
public class Level1_x만큼간격이있는n개의숫자 {

	 public static void main(String[] args) {
	        Scanner sc = new Scanner(System.in);
	        int a = sc.nextInt();
	        int b = sc.nextInt();
	        
	        System.out.println(solution(a,b));
	  
	       
	    }
	public long solution(int a, int b) {
    	    long answer = 0;
      	  long one=min(a,b);
     	   long two=max(a,b);
     	   for(long i=one;i<=two;i++){
      	      answer+=i;
            
      	  }
     	   return answer;
  	  }
  	  static public long min(int a,int b){
  	      if(a<b)return a;
  	      else return b;
  	  }  
  	  static public long max(int a,int b){
    	    if(a>b)return a;
   	     else return b;
	    }
}
