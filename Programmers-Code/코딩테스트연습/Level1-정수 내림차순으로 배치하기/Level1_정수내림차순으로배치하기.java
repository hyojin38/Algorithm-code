package Programmers;
import java.util.Arrays;
import java.util.Scanner;
public class Level1_���������������ι�ġ�ϱ� {
	
	static long n;
	 public static void main(String[] args) {
	        Scanner sc = new Scanner(System.in);
	        n = sc.nextLong();
	        
	        System.out.print(solution(n));
	      
	    }
	    private static long solution(long n) {
	        //1.long ������ n�� ���ڸ��� ���� ���ؼ� string���� ��ȯ
	        String before= String.valueOf(n);
	        //2. ������ ���Ͽ� Array�� ��ȯ-> char array
	        char[] arr= before.toCharArray();
	        //3. ����
	        Arrays.sort(arr);
	        System.out.print(Arrays.toString(arr));
	        //4. ������ arr�� long ����
	        String after = "";
	        for(int i=arr.length-1;i>=0;i--) {
	        	after=after+arr[i];
	        }
	        //string�� long����
	        long Ans=Long.parseLong(after);
	        return Ans;
	    }
}
