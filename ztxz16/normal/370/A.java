import java.io.*;
import java.util.*;
import java.math.*;

public class a
{
	public static void main(String args[])
	{
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		int r1 = cin.nextInt(), c1 = cin.nextInt(), r2 = cin.nextInt(), c2 = cin.nextInt();
		if (r1 == r2 && c1 == c2)
		{
			System.out.printf("0 0 0\n");
			return;
		}
		
		if (r1 == r2 || c1 == c2)
			System.out.printf("1 ");
		else
			System.out.printf("2 ");
		if (((r1 + c1) & 1) != ((r2 + c2) & 1))
			System.out.printf("0 ");
		else if (r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2)
			System.out.printf("1 ");
		else
			System.out.printf("2 ");
		System.out.printf("%d\n", Math.max(Math.abs(r1 - r2), Math.abs(c1 - c2)));
	}
}