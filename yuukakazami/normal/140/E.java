/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 12-1-4
 * Time: 10:57
 * To change this template use File | Settings | File Templates.
 */

import java.io.*;
import java.util.*;

public class e {

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
        int n = nextInt(), m = nextInt(), p = nextInt();
        final int MAX = 5000 + 10;
        int[] a = new int[n];

        for (int i = 0; i < a.length; i++) {
            a[i] = nextInt();
        }

        int[][] dp = new int[MAX][];
        for (int i = 0; i < MAX; i++) {
            dp[i] = new int[i + 1];
        }

        dp[1][1] = 1;
        for (int i = 1; i + 1 < MAX; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % p;
                dp[i + 1][j] = (int) ((dp[i + 1][j] + (long) dp[i][j] * (j - 1)) % p);
            }
        }

        long[] A = new long[MAX];
        A[1] = m;
        for (int i = 2; i < MAX; i++) {
            A[i] = A[i - 1] * (m - i + 1) % p;
        }

        long[] fact = new long[MAX];
        fact[0] = 1;
        for (int i = 1; i < MAX; i++) {
            fact[i] = fact[i - 1] * i % p;
        }

        long[] am = new long[a[0] + 1];
        for (int i = 1; i <= a[0]; i++) {
            am[i] = dp[a[0]][i];
            if (i > m)
                am[i] = 0;
        }

        for (int i = 1; i < n; i++) {

            int prev = a[i - 1], cur = a[i];
//            System.out.println("prev = " + prev);
//            for (int j = 0; j < am.length; j++) {
//                System.out.println(j + "=" + am[j]);
//            }

            long[] nam = new long[cur + 1];

            long sum = 0;
            for (int j = 1; j < am.length && j <= m; j++) {
                sum += am[j] * A[j] % p;
                sum %= p;
            }

            for (int j = 1; j <= cur; j++) {
                nam[j] = sum * dp[cur][j] % p;
                if (j <= prev) {
                    nam[j] -= am[j] * fact[j] % p * dp[cur][j] % p;
                    nam[j] %= p;
                    if (nam[j] < 0)
                        nam[j] += p;
                }
                if (j > m)
                    nam[j] = 0;
            }

            am = nam;
        }

        long ans = 0;
        for (int i = 1; i < am.length && i <= m; i++) {
            ans += am[i] * A[i] % p;
            ans %= p;
        }

        writer.println(ans);
    }

    static public void main(String[] args) {
        new e().run();
    }
}