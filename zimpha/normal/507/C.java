import java.io.InputStreamReader;
import java.io.IOException;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int h = in.nextInt();
        long n = in.nextLong() - 1, x = 0;
        for (int i = 0; i < h; i++) {
            if (i % 2 == 0) x <<= 1;
            else x = x << 1 | 1;
        }
        //System.out.println(x + " " + n);
        long ret = 0;
        int p = 0;
        while (x != n) {
            int d = get(x, n);
            ret += ((long)1 << d) - 1 + (h - d) - p + 1;
            long o = (n >> (d - 1)) & 1;
            p = h - d + 1; x >>= d;
            for (int i = 0; i < d; i++) {
                if (i % 2 == 0) x = x << 1 | o;
                else x = x << 1 | o;
                o ^= 1;
            }
        }
        out.println(ret + h - p);
    }
    int get(long a, long b) {
        int t = 0;
        while (a != b) {
            a >>= 1;
            b >>= 1;
            ++ t;
        }
        return t;
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
    public long nextLong() {
        return Long.parseLong(next());
    }
}