import java.io.*;
import java.util.*;
import java.math.*;

public class a {
  public static void main(String[] args) {
    try {
       new a();
    } catch (Exception e) {
      e.printStackTrace();
      System.exit(1);
    }
  }

  BufferedReader in;
  StringTokenizer toks;

  String next() throws Exception {
    while (toks == null || !toks.hasMoreTokens()) {
      toks = new StringTokenizer(in.readLine());
    }
    return toks.nextToken();
  }
  int readInt() throws Exception {
    return Integer.parseInt(next());
  }

  public a() throws Exception {
    in = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(System.out);

    int n = readInt();
    int k = readInt();

    int[] as = new int[n];
    for (int i = 0; i < n; i++)
      as[i] = readInt();

    BigInteger curSum = BigInteger.ZERO;
    int curN = n;
    int prevCnt = 0;

    for (int i = 0; i < n; i++) {
      BigInteger curChange = curSum.subtract(BigInteger.valueOf((long)prevCnt * as[i]).multiply(BigInteger.valueOf(curN - prevCnt - 1)));

      if (curChange.compareTo(BigInteger.valueOf(k)) < 0) {
        out.println(i + 1);
        curN--;
      } else {
        curSum = curSum.add(BigInteger.valueOf((long)as[i] * prevCnt));
        prevCnt++;
      }
    }

    out.close();
  }
};