package Programmers;
import java.util.Scanner;
public class Level1_�ڵ�����ȣ������ {
		 public static void main(String[] args) {
		        Scanner sc = new Scanner(System.in);
		        String phone_number=sc.nextLine();
		        System.out.print(solution(phone_number));
		      
		    }
	
	 static private String solution(String phone_number) {
	     
	     String answer = "";
	     
	     for(int i=0;i<phone_number.length();i++){
	         if(i<(phone_number.length() - 4))
	             answer+="*";
	         else
	          answer+=phone_number.charAt(i);
	     }
	     return answer;
	 }
			
}
