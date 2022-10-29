import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt(), k = in.nextInt();
        pair[] A = new pair[n];
        for (int i = 0; i < n; i++) {
            A[i] = new pair(in.nextInt(), i + 1);
        }
        Arrays.sort(A, new Comparator<pair>() {
            public int compare(final pair lhs, pair rhs) {
                return lhs.a - rhs.a;
            }
        });
        int ret[] = new int[n], m = 0;
        for (int i = 0, s = 0; i < n; i++) {
            s += A[i].a;
            if (s <= k) {
                ret[m ++] = A[i].id;
            }
            else break;
        }
        out.println(m);
        for (int i = 0; i < m; i++) {
            out.print(ret[i] + " ");
        }
    }
    class pair {
        public int a, id;
        public pair(int _a, int _i) {
            a = _a; id = _i;
        }
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