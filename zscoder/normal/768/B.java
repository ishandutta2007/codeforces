import java.util.*;

public final class Test
{
	static int numofdigits(long n)
	{
		if(n==0) return 1;
		int cnt = 0;
		while(n>0)
		{
			n>>=1;
			cnt++;
		}
		return cnt;
	}

	static long solve(long n, long r, int d)
	{

		if(r<0) return 0;
		if(n<=1)
		{
			return n;
		}
		long mid = 1;
		mid<<=(d-1);
		mid--;
		//System.out.printf("%d %d %d %d\n",n,r,d,mid);
		//System.out.println(mid);
		if(r<mid)
		{
			return solve(n/2,r,d-1);
		}
		else if(r==mid)
		{
			return n/2+(n&1);
		}
		else
		{

			return n/2+(n&1)+solve(n/2,r-mid-1,d-1);
		}
	}

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		/*
		int n = sc.nextInt();
		int arr[] = new int[100001];
		for(int i = 0; i < n; i++)
		{
			arr[i] = sc.nextInt();
		}
		Arrays.sort(arr,0,n);
		int cnt = 0;
		for(int i = 0; i < n; i++)
		{
			if(arr[i] > arr[0] && arr[i] < arr[n-1]) cnt++;
		}
		System.out.println(cnt);
		*/
		long n,l,r;
		n=sc.nextLong();
		l=sc.nextLong();
		r=sc.nextLong();
		int nod = numofdigits(n);
		l--; r--;
		long ans = solve(n,r,nod)-solve(n,l-1,nod);
		System.out.println(ans);
	}
}