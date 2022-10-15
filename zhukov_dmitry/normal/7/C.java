import java.io.*;
import java.util.*;
import java.math.*;

public class Main311 implements Runnable
{
	static Scanner scanner;
	static BufferedReader input;
	static PrintWriter pw;

	public static void main(String[] args) throws Exception
	{
		new Thread(new Main311()).start();
	}

	public void run()
	{
		try
		{
			boolean room311 = System.getProperty("ROOM_311") != null;
			input = new BufferedReader(room311 ? new FileReader("input.txt") : new InputStreamReader(System.in));
			scanner = new Scanner(input);
			pw = new PrintWriter(room311 ? new FileWriter("output.txt") : new OutputStreamWriter(System.out));

			solve();

			pw.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
			System.exit(1);
		}
	}

	class xyd { BigInteger x, y, d; }

	xyd gcd(BigInteger a, BigInteger b) { // a * x + b * y = d = gcd(a, b)
		xyd z, z1;
		z = new xyd();
		if (b.compareTo(BigInteger.ZERO) == 0) {
			z.x = BigInteger.ONE;
			z.y = BigInteger.ZERO;
			z.d = a;
			return z;
		}
		z1 = gcd(b, a.mod(b));
		z.x = z1.y;                                             // x = y1
		z.y = z1.x.subtract((a.divide(b)).multiply(z1.y));      // y = x1 - (a / b) * y1
		z.d = z1.d;
		return z;
	}

	public void solve() throws Exception
	{
		BigInteger a = scanner.nextBigInteger();
		BigInteger b = scanner.nextBigInteger();
		BigInteger c = scanner.nextBigInteger();

		BigInteger t = a.abs().gcd(b.abs());
		a = a.divide(t);
		b = b.divide(t);
		BigInteger aa = BigInteger.ONE;
		if (a.compareTo(BigInteger.ZERO) < 0)
		{
			a = a.negate();
			aa = aa.negate();
		}
		BigInteger bb = BigInteger.ONE;
		if (b.compareTo(BigInteger.ZERO) < 0)
		{
			b = b.negate();
			bb = bb.negate();
		}
		if (c.mod(t).intValue() != 0)
		{
			pw.println("-1");
			return;
		}
		c = c.divide(t);
		c = c.negate();

		xyd z = gcd(a, b);
		pw.println(z.x.multiply(c).multiply(aa) + " " + z.y.multiply(c).multiply(bb));
	}
}