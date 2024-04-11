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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    int A[][], n, m, k;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        n = in.nextInt();
        m = in.nextInt();
        k = in.nextInt();
        A = new int[n][m];
        out.println(gao(in));
    }
    int gao(InputReader in) {
        for (int i = 0; i < n; ++ i) Arrays.fill(A[i], 0);
        for (int i = 1; i <= k; ++ i) {
            int x = in.nextInt() - 1, y = in.nextInt() - 1;
            A[x][y] = 1;
            if (check(x, y)) return i;
        }
        return 0;
    }
    boolean check(int x, int y) {
        if (x >= 1 && y >= 1 && A[x][y - 1] == 1 && A[x - 1][y] == 1 && A[x - 1][y - 1] == 1) return true;
        if (x >= 1 && y + 1 < m && A[x][y + 1] == 1 && A[x - 1][y] == 1 && A[x - 1][y + 1] == 1) return true;
        if (x + 1 < n && y >= 1 && A[x][y - 1] == 1 && A[x + 1][y] == 1 && A[x + 1][y - 1] == 1) return true;
        if (x + 1 < n && y + 1 < m && A[x][y + 1] == 1 && A[x + 1][y] == 1 && A[x + 1][y + 1] == 1) return true;
        return false;
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