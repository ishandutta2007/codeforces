import java.util.*;

public class Main{
	public static long min(long a, long b){
		return a<b?a:b;
	}
	public static void main(String[] argc){
		Scanner sc = new Scanner(System.in);
		long n=sc.nextInt();
		long c=0;
		long a=0;
		long c1=sc.nextInt();
		long c2=sc.nextInt();
		String s=sc.next();
		for(int i=0; i<n; i++)
			if(s.charAt(i)=='1')
				a++;
		long ans=c1+c2*(n-1)*(n-1);
		for(long i=2; i<=a; i++){
			c=n-i;
			if(c%i==0){
				c/=i;
				ans=min(ans, c1*i+c2*c*c*i);
			}
			else{
				long cc=c%i;
				c/=i;
				ans=min(ans, c1*i+c2*(cc*(c+1)*(c+1)+(i-cc)*c*c));
			}
		}
		System.out.println(ans);
	}
}