package Programmers;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
public class Level1_�Ҽ�ã�� {
	
	static int N;
	 public static void main(String[] args) throws NumberFormatException, IOException {
		 // Scanner sc = new Scanner(System.in);
	     // System.out.print(Arrays.toString(solution(n)));
		 	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			N= Integer.parseInt(br.readLine());
		 
			//BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			//int TC=Integer.parseInt(br.readLine());
			
			System.out.println(solution(N));
	    }
	 
	 private static int solution(int n) {
		//1~�Է� ���� ���� n ���̿� �ִ� �Ҽ��� ���� 
		 int answer=0;
		 for(int i=2;i<=n;i++) {
			 boolean check=true;
			 for(int j=2;j<=Math.sqrt(i);j++) {
				 if(i%j==0)
				 {	 
					check=false;
				 	break;
				 }	
			 }
			 if(check==true)answer++;
		 }
		
		return answer;
	 }
}
