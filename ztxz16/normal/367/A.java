import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
	public static void main(String args[])
	{
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		String str = cin.next();
		int s[][] = new int[100005][5];
		s[0][0] = s[0][1] = s[0][2] = 0;
		for (int i = 1; i <= str.length(); i++)
		{
			s[i][0] = s[i - 1][0];
			s[i][1] = s[i - 1][1];
			s[i][2] = s[i - 1][2];
			s[i][str.charAt(i - 1) - 'x']++;
		}
		
		int n = cin.nextInt();
		for (int i = 1; i <= n; i++)
		{
			int l = cin.nextInt(), r = cin.nextInt();
			int ss0 = s[r][0] - s[l - 1][0], ss1 = s[r][1] - s[l - 1][1], ss2 = s[r][2] - s[l - 1][2];
			if (r - l + 1 <= 2 || Math.max(ss0, Math.max(ss1, ss2)) - Math.min(ss0, Math.min(ss1, ss2)) <= 1)
				System.out.println("YES");
			else
				System.out.println("NO");
		}
	}
}