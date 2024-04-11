/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 11-12-24
 * Time: 7:37
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

    String makePalindrome(String s) {
        char[] c = s.toCharArray();
        for (int l = 0, r = c.length - 1; l < r; ++l, --r)
            if (c[l] != c[r]) {
                c[l] = c[r];
            }
        return new String(c);
    }

    void solve() throws IOException {
        String input = nextToken();
        char[] s = input.toCharArray();
        int k = nextInt();
        int n = s.length;

        int[][] minCost = new int[n][n];
        for (int l = n - 1; l >= 0; l--) {
            for (int r = l; r < n; r++) {
                if (l == r)
                    minCost[l][r] = 0;
                else {
                    minCost[l][r] = minCost[l + 1][r - 1] + (s[l] == s[r] ? 0 : 1);
                }
            }
        }

        int[][] dp = new int[n + 1][k + 1];
        int[][] prev = new int[n + 1][k + 1];
        for (int[] a : dp) {
            Arrays.fill(a, Integer.MAX_VALUE);
        }
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                int c = dp[i][j];
                if (c == Integer.MAX_VALUE)
                    continue;
                for (int ni = i + 1; ni <= n; ni++) {
                    int nc = c + minCost[i][ni - 1];
                    if (nc < dp[ni][j + 1]) {
                        dp[ni][j + 1] = nc;
                        prev[ni][j + 1] = i;
                    }
                }
            }
        }

        int ans = Integer.MAX_VALUE;
        int cur = 0;
        for (int i = 0; i <= k; i++) {
            if (dp[n][i] < ans) {
                ans = dp[n][i];
                cur = i;
            }
        }
        List<String> stringList = new ArrayList<String>();
        writer.println(ans);
        int at = n;
        while (cur > 0) {
            int pre = prev[at][cur];
            stringList.add(makePalindrome(input.substring(pre, at)));
            --cur;
            at = pre;
        }
        Collections.reverse(stringList);
        boolean first = true;
        for (String a : stringList) {
            if (!first)
                writer.print("+");
            first = false;
            writer.print(a);
        }
        writer.println();
    }

    static public void main(String[] args) {
        new a().run();
    }
}