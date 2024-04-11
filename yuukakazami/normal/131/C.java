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

public class C {

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
        int n = nextInt(), m = nextInt();
        int t = nextInt();
        int num = n + m;
        long[][] comb = new long[num + 1][num + 1];
        for (int i = 0; i <= num; i++) {
            for (int j = 0; j <= i; j++) {
                if (i == 0 || j == 0)
                    comb[i][j] = 1;
                else
                    comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
            }
        }

        long ans = 0;
        for (int nb = 4; nb <= n; nb++) {
            for (int ng = 1; ng <= m; ng++) {
                if (nb + ng == t)
                    ans += comb[n][nb] * comb[m][ng];
            }
        }

        writer.println(ans);
    }

    static public void main(String[] args) {
        new C().run();
    }
}