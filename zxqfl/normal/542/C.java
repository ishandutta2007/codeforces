import java.math.*;
import java.util.*;

public class C
{
	int[] f;
	int N;

	void solve()
	{
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		f = new int[N];
		for (int i = 0; i < N; i++)
			f[i] = sc.nextInt() - 1;
		TreeSet<Integer> constraints = new TreeSet<Integer>();
		int minVal = 0;
		for (int i = 0; i < N; i++)
		{
			int[] dist = new int[N];
			Arrays.fill(dist, -1);
			int cnt = 0;
			int v = i;
			while (true)
			{
				if (dist[v] >= 0)
				{
					minVal = Math.max(minVal, dist[v]);
					constraints.add(cnt - dist[v]);
					break;
				}
				dist[v] = cnt++;
				v = f[v];
			}
		}
		BigInteger lo = BigInteger.valueOf(minVal);
		BigInteger ans = BigInteger.ONE;
		for (int x : constraints)
		{
			BigInteger o = BigInteger.valueOf(x);
			ans = ans.multiply(o).divide(ans.gcd(o));
		}
		BigInteger fans = ans;
		while (fans.compareTo(lo) < 0)
			fans = fans.add(ans);
		System.out.println(fans);
	}

	public static void main(String[] args)
	{
		new C().solve();
	}
}