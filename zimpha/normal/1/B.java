import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Xi Lin
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

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            for (; n > 0; --n) {
                String s = in.next();
                int i = 0, r = 0, c = 0;
                if (check(s)) {
                    for (++i; s.charAt(i) != 'C'; ++i) {
                        r = r * 10 + s.charAt(i) - '0';
                    }
                    for (++i; i < s.length(); ++i) {
                        c = c * 10 + s.charAt(i) - '0';
                    }
                    String ret = "";
                    for (; c > 0; c = (c - 1) / 26) {
                        ret = (char) ((c - 1) % 26 + 'A') + ret;
                    }
                    out.println(ret + r);
                } else {
                    for (; i < s.length(); ++i) {
                        if (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z') c = c * 26 + s.charAt(i) - 'A' + 1;
                        else break;
                    }
                    for (; i < s.length(); ++i) {
                        r = r * 10 + s.charAt(i) - '0';
                    }
                    out.println("R" + r + "C" + c);
                }
            }
        }

        boolean check(String s) {
            if (s.charAt(0) == 'R' && s.charAt(1) >= '0' && s.charAt(1) <= '9') {
                for (int i = 2; i < s.length(); ++i) {
                    if (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z') return true;
                }
            }
            return false;
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
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
}