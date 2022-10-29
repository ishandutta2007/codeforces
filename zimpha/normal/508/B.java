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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        char s[] = in.next().toCharArray();
        String ans = new String("-1");
        int n = s.length, last = -1;
        for (int i = 0; i < n; i++) {
            if ((s[i] - '0') % 2 == 0) {
                if (s[n - 1] > s[i]) {
                    char t = s[i]; s[i] = s[n - 1]; s[n - 1] = t;
                    ans = new String(s);
                    break;
                }
                last = i;
            }
        }
        if (ans.equals("-1") && last != -1) {
            char t = s[last]; s[last] = s[n - 1]; s[n - 1] = t;
            ans = new String(s);
        }
        out.println(ans);
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
}