package Programmers;
import java.util.Arrays;
import java.util.Scanner;
public class Level1_정수내림차순으로배치하기 {
	
	static long n;
	 public static void main(String[] args) {
	        Scanner sc = new Scanner(System.in);
	        n = sc.nextLong();
	        
	        System.out.print(solution(n));
	      
	    }
	    private static long solution(long n) {
	        //1.long 형태의 n을 한자리씩 떼기 위해서 string으로 변환
	        String before= String.valueOf(n);
	        //2. 정렬을 위하여 Array로 변환-> char array
	        char[] arr= before.toCharArray();
	        //3. 정렬
	        Arrays.sort(arr);
	        System.out.print(Arrays.toString(arr));
	        //4. 정렬한 arr을 long 으로
	        String after = "";
	        for(int i=arr.length-1;i>=0;i--) {
	        	after=after+arr[i];
	        }
	        //string을 long으로
	        long Ans=Long.parseLong(after);
	        return Ans;
	    }
}
