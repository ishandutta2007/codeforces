import java.util.*;
import java.io.*;
import java.math.*;

public class Main
{
	public static void main(String args[])
	{
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		int n = cin.nextInt();
		for (int i = 1; i <= 4; i++)
		{
			int a = cin.nextInt(), b = cin.nextInt(), c = cin.nextInt(), d = cin.nextInt();
			int x = Math.min(a, b), y = Math.min(c, d);
			if (x + y <= n)
			{
				System.out.printf("%d %d %d\n", i, x, n - x);
				return;
			}
		}
		
		System.out.println(-1);
		return;
	}
}