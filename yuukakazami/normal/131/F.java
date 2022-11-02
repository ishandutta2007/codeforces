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

public class F {

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
        int n = nextInt(), m = nextInt(), k = nextInt();
        char[][] map = new char[n][m];
        for (int i = 0; i < n; i++) {
            map[i] = nextToken().toCharArray();
        }
//        for (int r = 0; r < n; r++) {
//            for (int c = 0; c < m; c++) {
//                map[r][c] = '1';
//            }
//        }
        boolean[][] is = new boolean[n][m];
        for (int r = 1; r + 1 < n; r++) {
            for (int c = 1; c + 1 < m; c++) {
                if (map[r][c] == '1' && map[r - 1][c] == '1' && map[r][c - 1] == '1' && map[r + 1][c] == '1' && map[r][c + 1] == '1')
                    is[r][c] = true;
            }
        }
//
//        for (int r = 0; r < n; r++) {
//            for (int c = 0; c < m; c++) {
//                writer.print((is[r][c] ? 1 : 0) + " ");
//            }
//            writer.println();
//        }

        long ans = 0;
        for (int r1 = 0; r1 < n; r1++) {
            int[] cnt = new int[m];
            for (int r2 = r1 + 2; r2 < n; r2++) {
                for (int c = 0; c < m; c++) {
                    cnt[c] += is[r2 - 1][c] ? 1 : 0;
                }
                int left = 0, sum = 0;
                for (int right = 0; right < m; right++) {
                    while (sum >= k) {
                        sum -= cnt[left + 1];
                        ++left;
                    }
                    ans += left;
                    sum += cnt[right];
                }
            }
        }

        writer.println(ans);
    }

    static public void main(String[] args) {
        new F().run();
    }
}