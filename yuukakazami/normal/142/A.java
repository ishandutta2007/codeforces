/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 12-1-12
 * Time: 10:52
 * To change this template use File | Settings | File Templates.
 */

import java.io.*;
import java.util.*;

public class a {

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens())
            tokenizer = new StringTokenizer(reader.readLine());
        return tokenizer.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    void solve() throws IOException {
        int n = nextInt();

        long min = Long.MAX_VALUE, max = -1;

        for (int a = 1; a * a <= n; a++) {
            if (n % a == 0) {
                int m = n / a;
                for (int b = 1; b * b <= m; b++) {
                    if (m % b == 0) {
                        int c = m / b;
                        long ret = (long) (a + 1) * (b + 2) * (c + 2) - n;
                        min = Math.min(min, ret);
                        max = Math.max(max, ret);
                    }
                }

                int t = a;
                a = n / a;

                m = n / a;
                for (int b = 1; b * b <= m; b++) {
                    if (m % b == 0) {
                        int c = m / b;
                        long ret = (long) (a + 1) * (b + 2) * (c + 2) - n;
                        min = Math.min(min, ret);
                        max = Math.max(max, ret);
                    }
                }

                a = t;
            }
        }

        System.out.println(min + " " + max);
    }

    static public void main(String[] args) {
        new a().run();
    }
}