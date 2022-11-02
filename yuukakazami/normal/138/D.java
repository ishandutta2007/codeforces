/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 11-12-24
 * Time: 7:56
 * To change this template use File | Settings | File Templates.
 */

import java.io.*;
import java.util.*;

public class d {

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

    int n, m;
    int[][][][] dp;
    int rem;

    int calc(int subL, int subR, int addL, int addR) {
        if ((subL & 1) != rem)
            ++subL;
        if ((subR & 1) != rem)
            --subR;
        if ((addL & 1) != rem)
            ++addL;
        if ((addR & 1) != rem)
            --addR;

        if (subL > subR || addL > addR)
            return 0;

        int ret = dp[subL + m][subR + m][addL][addR];
        if (ret != -1)
            return ret;
        boolean[] have = new boolean[(subR - subL + 1) * (addR - addL + 1) + 1];
        for (int sub = subL; sub <= subR; sub += 2) {
            for (int add = addL; add <= addR; add += 2) {
                int r = (add + sub) / 2;
                int c = add - r;
                if (r >= 0 && r < n && c >= 0 && c < m) {
                    char ch = grid[r][c];
                    if (ch == 'L') {//add
                        int tmp = calc(subL, subR, addL, add - 1) ^ calc(subL, subR, add + 1, addR);
                        if (tmp < have.length)
                            have[tmp] = true;
                    } else if (ch == 'R') {
                        int tmp = calc(subL, sub - 1, addL, addR) ^ calc(sub + 1, subR, addL, addR);
                        if (tmp < have.length)
                            have[tmp] = true;
                    } else {
                        int tmp = calc(subL, sub - 1, addL, add - 1) ^ calc(sub + 1, subR, addL, add - 1) ^
                                calc(subL, sub - 1, add + 1, addR) ^ calc(sub + 1, subR, add + 1, addR);
                        if (tmp < have.length)
                            have[tmp] = true;
                    }
                }
            }
        }

        for (int i = 0; i < have.length; i++) {
            if (!have[i])
                return dp[subL + m][subR + m][addL][addR] = i;
        }

        return -1;
    }

    char[][] grid;

    void solve() throws IOException {
        n = nextInt();
        m = nextInt();

        dp = new int[n + m + 3][n + m + 3][n + m + 3][n + m + 3];
        grid = new char[n][];
        for (int r = 0; r < n; r++) {
            grid[r] = nextToken().toCharArray();
        }

        int xor = 0;
        for (rem = 0; rem < 2; ++rem) {
            for (int[][][] a : dp) {
                for (int[][] b : a) {
                    for (int[] c : b) {
                        Arrays.fill(c, -1);
                    }
                }
            }
            xor ^= calc(0 - (m - 1), n - 1 - 0, 0, n + m - 2);
        }

        if (xor == 0)
            writer.println("LOSE");
        else
            writer.println("WIN");
    }

    static public void main(String[] args) {
        new d().run();
    }
}