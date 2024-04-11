import java.io.*;
import java.util.*;
import java.math.*;

public class d
{
	static int[] list1 = new int[10000005], list2 = new int[10000005];
	static int[][] dis = new int[3005][3005];
	
	public static void main(String args[])
	{
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		int n = cin.nextInt(), k = cin.nextInt(), i, j, h, t, x, y, xx, yy;
		int[] p = new int[3005], s = new int[3005];
		for (i = 1; i <= n; i++)
			p[i] = cin.nextInt();
		s[n + 1] = 0;
		for (i = n; i >= 1; i--)
		{
			s[i] = s[i + 1];
			if (p[i] == 100)
				s[i] = 100;
			if (p[i] > 0 && s[i] == 0)
				s[i] = 50;
		}
		
		for (i = 1; i <= n + 2; i++)
			for (j = 1; j <= n + 2; j++)
				dis[i][j] = k + 1;
		dis[1][2] = 0;
		list1[1] = 1; list2[1] = 2;
		for (h = t = 1; h <= t; h++)
		{
			x = list1[h];
			y = list2[h];
			//System.out.printf("%d %d\n", x, y);
			if (dis[x][y] == k)
				continue;
			if (y <= n && p[x] > 0 && s[y] > 0)
			{
				xx = y + 1; yy = y + 2;
				if (dis[x][y] + 1 < dis[xx][yy])
				{
					dis[xx][yy] = dis[x][y] + 1;
					list1[++t] = xx;
					list2[t] = yy;
				}
			}
			
			if (x <= n && p[x] < 100 && s[y] > 0)
			{
				xx = y; yy = y + 1;
				if (dis[x][y] + 1 < dis[xx][yy])
				{
					dis[xx][yy] = dis[x][y] + 1;
					list1[++t] = xx;
					list2[t] = yy;
				}
			}
			
			if (y <= n && p[x] > 0 && s[y] < 100)
			{
				xx = x; yy = y + 1;
				if (dis[x][y] + 1 < dis[xx][yy])
				{
					dis[xx][yy] = dis[x][y] + 1;
					list1[++t] = xx;
					list2[t] = yy;
				}
			}
		}
		
		System.out.println(t);
	}
}