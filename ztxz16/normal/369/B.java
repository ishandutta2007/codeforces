import java.io.*;
import java.util.*;
import java.math.*;

public class b
{
	public static void main(String args[])
	{
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		int n = cin.nextInt(), k = cin.nextInt(), l = cin.nextInt(), r = cin.nextInt(), sall = cin.nextInt(), sk = cin.nextInt(), i, now;
		int[] ans = new int[1005];
		sall -= sk;
		for (i = 1; i <= n; i++)
			ans[i] = l;
		sall -= (n - k) * l;
		sk -= k * l;
		now = 1;
		while (sk > 0)
		{
			ans[now]++;
			now++;
			if (now > k)
				now = 1;
			sk--;
		}
		
		now = k + 1;
		while (sall > 0)
		{
			ans[now]++;
			now++;
			if (now > n)
				now = k + 1;
			sall--;
		}
		
		for (i = 1; i <= n; i++)
			if (i == n)
				System.out.println(ans[i]);
			else
				System.out.print(ans[i] + " ");
	}
}