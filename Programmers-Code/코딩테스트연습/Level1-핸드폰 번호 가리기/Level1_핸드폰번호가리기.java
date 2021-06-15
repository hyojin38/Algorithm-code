package Programmers;
import java.util.Scanner;
public class Level1_핸드폰번호가리기 {
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
