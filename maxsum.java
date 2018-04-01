package maxsum;

import java.util.Scanner;

public class maxsum {
	public static int maxSubArray(int N,int a[]){
		int sum=0,mins=0,ans=0;
		for (int i = 1;i <= N; i++){
	        sum += a[i];
	        if (sum - mins > ans)
	            ans = sum - mins;
	        if (mins > sum)
	            mins = sum;
		}
		return ans;
	}
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int N=sc.nextInt();
		int[] a = new int[100];
		for(int i=0;i<N;i++) {
	         a[i] = sc.nextInt();
	     }
		sc.close();
		int sum = maxSubArray(N,a);
		System.out.print(sum);
	} 
}
