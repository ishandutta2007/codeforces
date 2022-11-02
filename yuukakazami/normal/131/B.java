/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 11-11-25
 * Time: 10:58
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
        int[] cnt = new int[21];
        for (int i = 0; i < n; i++) {
            cnt[nextInt() + 10]++;
        }
        long ans = 0;
        for (int i = 1; i <= 10; i++) {
            ans += (long) cnt[i + 10] * cnt[10 - i];
        }

        ans += (long) cnt[10] * (cnt[10] - 1) / 2;
        writer.println(ans);
    }

    static public void main(String[] args) {
        new B().run();
    }
}