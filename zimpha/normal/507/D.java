import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Xi Lin (zimpha@gmail.com)
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    int dp[][][];
    int pm[], pk[], n, m, k;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        n = in.nextInt();
        k = in.nextInt();
        m = in.nextInt();
        pm = new int[n + 1]; pk = new int[n + 1];
        dp = new int[n][k][2]; pm[0] = pk[0] = 1;
        for (int i = 0; i < n; i++) {
            ArrayUtils.fill(dp[i], -1);
            pm[i + 1] = (int)((long)pm[i] * 10 % m);
            pk[i + 1] = pk[i] * 10 % k;
        }
        out.println(solve(0, 0, 0));
    }
    int solve(int i, int j, int e) {
        if (j == 0 && e == 1) return i != n ? (int)((long)pm[n - i - 1] * 9l % m) : 1;
        if (i == n) return 0;
        if (dp[i][j][e] != -1) return dp[i][j][e];
        int ret = 0;
        for (int d = 0; d < 10; ++ d) {
            int ne = e; if (d != 0) ne = 1;
            ret += solve(i + 1, (j + d * pk[i]) % k, ne);
            ret %= m;
        }
        return dp[i][j][e] = ret;
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;
    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }
    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }
}

class ArrayUtils {
    static void fill(int[][] A, int v) {
        for (int i = 0; i < A.length; i++) {
            Arrays.fill(A[i], v);
        }
    }
}