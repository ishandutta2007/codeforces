import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Stack;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] l = new int[n], r = new int[n], p = new int[n];
        Stack<Integer> S = new Stack<Integer>();
        String ret = new String();
        for (int i = 0; i < n; i++) {
            l[i] = in.nextInt();
            r[i] = in.nextInt();
            p[i] = ret.length();
            ret = ret + "(";
            S.push(i);
            while (!S.empty() && p[S.peek()] + l[S.peek()] <= ret.length()) {
                if (p[S.peek()] + r[S.peek()] < ret.length()) {
                    out.println("IMPOSSIBLE");
                    return;
                }
                S.pop(); ret = ret + ")";
            }
        }
        if (!S.empty()) out.println("IMPOSSIBLE");
        else out.println(ret);
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