import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
	public static void main(String args[])
	{
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		int n = cin.nextInt(), m = cin.nextInt(), d = cin.nextInt();
		int i, j, x, now, tot, full, ans = m;
		int[] belong = new int[n + 5], sum = new int[m + 5], bad = new int[2000005];
		for (i = 0; i < m; i++)
		{
			tot = cin.nextInt();
			for (j = 1; j <= tot; j++)
				belong[cin.nextInt()] = i;
			sum[i] = 0;
		}
		
		full = (1 << m) - 1;
		now = 0;
		for (i = 1; i <= d; i++)
		{
			x = belong[i];
			sum[x]++;
			if (sum[x] == 1)
				now += (1 << x);
		}
		
		bad[now] = 1;
		for (i = d + 1; i <= n; i++)
		{
			x = belong[i - d];
			sum[x]--;
			if (sum[x] == 0)
				now -= (1 << x);
			x = belong[i];
			sum[x]++;
			if (sum[x] == 1)
				now += (1 << x);
			bad[now] = 1;
		}
		
		for (i = 0; i <= full; i++)
		{
			for (j = 0; j < m; j++)
				bad[i | (1 << j)] |= bad[i];
			if (bad[i] == 0)
			{
				now = m;
				for (j = i; j > 0; j -= (j & (0 - j)))
					now--;
				ans = Math.min(ans, now);
			}
		}
		
		System.out.println(ans);
	}
}