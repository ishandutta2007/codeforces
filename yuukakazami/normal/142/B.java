/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 12-1-12
 * Time: 10:52
 * To change this template use File | Settings | File Templates.
 */

import java.io.*;
import java.util.*;

public class b {

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

    boolean[][] mark;
    int n, m;

    void dfs(int r, int c, int col, int[] cnt) {
        if (r < 0 || c < 0 || r >= n || c >= m)
            return;
        if (mark[r][c])
            return;
        mark[r][c] = true;
        cnt[col]++;

        for (int dr = -2; dr <= 2; dr++) {
            for (int dc = -2; dc <= 2; dc++) {
                if (dr * dr + dc * dc == 5)
                    dfs(r + dr, c + dc, 1 - col, cnt);
            }
        }
    }

    void solve() throws IOException {
        n = nextInt();
        m = nextInt();
        mark = new boolean[n][m];

        int ans = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (!mark[r][c]) {
                    int[] cnt = new int[2];
                    dfs(r, c, 0, cnt);
                    ans += Math.max(cnt[0], cnt[1]);
                }
            }
        }

        System.out.println(ans);
    }

    static public void main(String[] args) {
        new b().run();
    }
}