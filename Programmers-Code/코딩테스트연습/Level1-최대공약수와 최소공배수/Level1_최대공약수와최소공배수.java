package Programmers;
import java.util.Scanner;
public class Level1_최대공약수와최소공배수 {

	 static int gcd;
	 static int lcm;
     static int[] Ans;
	 public static void main(String[] args) {
	        Scanner sc = new Scanner(System.in);
	        int a = sc.nextInt();
	        int b = sc.nextInt();
	        
	        Ans=solution(a,b);
	
	        for(int i=0;i<Ans.length;i++) {
	            System.out.println(Ans[i]);
	        }
	 
	  
	      
	       
	    }

		    
	    private static int[] solution(int n, int m) {
	       
	        GCD(max(n,m),min(n,m));
	        lcm=gcd*(n/gcd)*(m/gcd);
	         int[] answer = {gcd,lcm};
	        return answer;
	    }
	    private static int min(int a,int b){
	        if(a<b)return a;
	        else return b;
	    }
	    private static int max(int a,int b){
	        if(a>b)return a;
	        else return b;
	    }
	    private static void GCD(int a, int b){
	        int mod =a%b;
	        if(mod==0){
	            gcd=b;
	        }else{
	            GCD(b,mod);
	        }
	    }
		
}
