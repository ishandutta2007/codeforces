import java.io.*;
import java.util.*;
import java.math.*;

public class a
{
	public static void main(String args[])
	{
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		int n = cin.nextInt(), m = cin.nextInt(), k = cin.nextInt(), ans, i;
		int[] s = new int[1005];
		for (i = 1; i <= n; i++)	
			s[cin.nextInt()]++;
		if (s[1] > m)
			ans = (s[1] - m) + Math.max(s[2] - k, 0);
		else
			ans = Math.max(0, s[1] + s[2] - m - k);
		System.out.println(ans);
	}
}