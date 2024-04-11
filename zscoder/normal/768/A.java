import java.util.*;

public final class Test
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
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
	}
}