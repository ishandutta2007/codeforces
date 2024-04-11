import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
	public static void main(String args[])
	{
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		int n = cin.nextInt(), k = cin.nextInt(), x, ans = 1;
		int[] s = new int[n + 5];
		for (int i = 1; i <= n; i++)
		{
			x = cin.nextInt();
			s[i] = s[i - 1] + x;
		}
		
		for (int i = 2; i + k - 1 <= n; i++)
			if (s[i + k - 1] - s[i - 1] < s[ans + k - 1] - s[ans - 1])
				ans = i;
		System.out.println(ans);
	}
}