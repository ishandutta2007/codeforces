/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 11-12-3
 * Time: 9:56
 * To change this template use File | Settings | File Templates.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class D {

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
        String input = "0" + nextToken();
        int L = input.length();
        int[][] dp = new int[L + 1][5];//-2 to 2
        int[][] how = new int[L + 1][5];
        int[][] prev = new int[L + 1][5];
        for (int[] d : dp) {
            Arrays.fill(d, Integer.MAX_VALUE);
        }
        dp[0][2] = 0;
        for (int i = 0; i < input.length(); i++) {
            for (int j = 0; j < 5; j++) {
                int v = j - 2;
                int c = dp[i][j];
                if (c == Integer.MAX_VALUE)
                    continue;
                for (int cur = -1; cur <= 1; cur++) {
                    int nc = c + (cur == 0 ? 0 : 1);
                    int nv = v * 2 + cur + input.charAt(i) - '0';
                    if (nv >= -2 && nv <= 2) {
                        int nj = nv + 2;
                        if (nc < dp[i + 1][nj]) {
                            dp[i + 1][nj] = nc;
                            how[i + 1][nj] = cur;
                            prev[i + 1][nj] = j;
                        }
                    }
                }
            }
        }

        int m = dp[L][2];
        writer.println(m);
        int j = 2;
        for (int i = L; i >= 1; i--) {
            int v = how[i][j];
            if (v != 0) {
                writer.println((v == -1 ? "+" : "-") + "2^" + (L - i));
            }
            j = prev[i][j];
        }
    }

    static public void main(String[] args) {
        new D().run();
    }
}