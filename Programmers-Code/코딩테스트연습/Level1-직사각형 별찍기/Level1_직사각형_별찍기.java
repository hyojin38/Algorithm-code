package Programmers;
import java.util.Scanner;
public class Level1_직사각형_별찍기 {

	 public static void main(String[] args) {
	        Scanner sc = new Scanner(System.in);
	        int a = sc.nextInt();
	        int b = sc.nextInt();
	        
	        Sol(a,b);
	      
	    }
	    private static void Sol(int a,int b){
	    
	        for(int i=0;i<b;i++){
	            for( int j=0;j<a;j++){
	                System.out.print("*");
	            }
	            System.out.println();
	        }
	    }
}
