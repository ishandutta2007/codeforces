/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 11-12-3
 * Time: 9:30
 * To change this template use File | Settings | File Templates.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

import java.util.StringTokenizer;

public class B {

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
        int ans = Integer.MAX_VALUE;
        for (int i = 1; i <= n * 2 + 1; i++) {
            int a = n, b = i;
            int ret = 0;
            for (; ; ) {
                if (a < b) {
                    int t = a;
                    a = b;
                    b = t;
                }
                if (a == b) {
                    if (a == 1) {
                        ans = Math.min(ans, ret);
                    }
                    break;
                }
                if (b == 1) {
                    ret += a - b;
                    a = 1;
                } else {
                    ret += a / b;
                    a %= b;
                    if (a == 0)
                        break;
                }
            }
        }
        writer.println(ans);
    }

    static public void main(String[] args) {
        new B().run();
    }
}