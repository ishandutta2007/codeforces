import java.io.*;
import java.util.*;
import java.math.*;

public class b
{
	public static void main(String args[])
	{
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		int n = cin.nextInt(), i, j, k;
		int[] Hash = new int[105];
		int[][] a = new int[105][105];
		for (i = 1; i <= n; i++)
		{
			a[i][0] = cin.nextInt();
			for (j = 1; j <= a[i][0]; j++)
				a[i][j] = cin.nextInt();
		}
		
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= a[i][0]; j++)
				Hash[a[i][j]] = i;
			for (j = 1; j <= n; j++)
			{
				if (j == i)
					continue;
				for (k = 1; k <= a[j][0]; k++)
					if (Hash[a[j][k]] != i)
						break;
				if (k > a[j][0])
					break;
			}
			
			if (j <= n)
				System.out.println("NO");
			else
				System.out.println("YES");
		}
	}
}