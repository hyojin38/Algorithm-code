package Programmers;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
public class Level1_이상한_문자_만들기 {
	
	static String str;
	 public static void main(String[] args) throws NumberFormatException, IOException {
		 // Scanner sc = new Scanner(System.in);
	     // System.out.print(Arrays.toString(solution(n)));
		 	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			str=br.readLine();
		 	//n=Integer.parseInt(br.readLine());
			
			//BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			//int TC=Integer.parseInt(br.readLine());
			
			System.out.println(solution(str));
	    }
	 
	 private static String solution(String s) {
	    	int num=0;
	    	    	String Ans="";
	    	    	for(int i=0;i<s.length();i++) {
	    	    		char ch=s.charAt(i);
	    	    		if(ch==' ') {
	    	    			Ans+=" ";
	                        num=0;
	    	    			continue;
	    	    		}else {
	    	    			if(num%2==0) {//대문자로
	    		    			Ans+=Upper(ch);
	    		    		}else { //소문자로
	    		    			Ans+=Lower(ch);
	    		    		}
	    	    			num++;
	    		    	}
	    	    		
	    	    	}
	    	    	return Ans;
	        }
	        public static char Lower(char ch) {// 대문자를 소문자로
	            if( (((int)'A')<=(int)ch) && ((int)'Z')>=(int)ch){ //대문자면 
	                return (char)(((int)ch)+32); //소문자로
	            }else return ch; //소문자면 소문자로
	        }
	        public static char Upper(char ch) {// 소문자를 대문자로
	            if( (((int)'A')<=(int)ch) && ((int)'Z')>=(int)ch){ //대문자면
	                return ch; //그대로
	            }else return (char)(((int)ch)-32); //아니면 소문자로
	        }
}
