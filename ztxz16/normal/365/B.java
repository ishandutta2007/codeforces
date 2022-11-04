import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
	public static void main(String args[])
	{
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		int n = cin.nextInt(), ans = 2, now;
		int[] a = new int[n + 5];
		for (int i = 1; i <= n; i++)
			a[i] = cin.nextInt();
		if (n == 1)
		{
			System.out.println(1);
			return;
		}
		
		now = 2;
		for (int i = 3; i <= n; i++)
		{
			if (a[i] == a[i - 1] + a[i - 2])
				now++;
			else
				now = 2;
			ans = Math.max(ans, now);
		}
		
		System.out.println(ans);
	}
}