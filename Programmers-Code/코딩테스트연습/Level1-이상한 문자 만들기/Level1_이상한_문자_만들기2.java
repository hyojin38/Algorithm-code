package Programmers;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
public class Level1_�̻���_����_����� {
	
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
	    	    			if(num%2==0) {//�빮�ڷ�
	    		    			Ans+=Upper(ch);
	    		    		}else { //�ҹ��ڷ�
	    		    			Ans+=Lower(ch);
	    		    		}
	    	    			num++;
	    		    	}
	    	    		
	    	    	}
	    	    	return Ans;
	        }
	        public static char Lower(char ch) {// �빮�ڸ� �ҹ��ڷ�
	            if( (((int)'A')<=(int)ch) && ((int)'Z')>=(int)ch){ //�빮�ڸ� 
	                return (char)(((int)ch)+32); //�ҹ��ڷ�
	            }else return ch; //�ҹ��ڸ� �ҹ��ڷ�
	        }
	        public static char Upper(char ch) {// �ҹ��ڸ� �빮�ڷ�
	            if( (((int)'A')<=(int)ch) && ((int)'Z')>=(int)ch){ //�빮�ڸ�
	                return ch; //�״��
	            }else return (char)(((int)ch)-32); //�ƴϸ� �ҹ��ڷ�
	        }
}
