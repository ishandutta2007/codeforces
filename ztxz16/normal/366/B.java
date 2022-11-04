import java.util.*;
import java.io.*;
import java.math.*;

public class Main
{
	public static void main(String args[])
	{
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		int n = cin.nextInt(), k = cin.nextInt(), x, sel;
		int[] sum = new int[100005];
		for (int i = 1; i <= n; i++)
		{
			x = cin.nextInt();
			sum[(i - 1) % k] += x;
		}
		
		sel = 0;
		for (int i = 1; i < k; i++)
			if (sum[i] < sum[sel])
				sel = i;
		System.out.println(sel + 1);
	}
}