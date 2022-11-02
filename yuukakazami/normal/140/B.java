/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 12-1-4
 * Time: 10:56
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

    int[] get(int[] a) {
        int[] ret = new int[a.length];
        for (int i = 0; i < a.length; i++) {
            ret[a[i]] = i;
        }
        return ret;
    }

    int get(int[] rank, int a, int b) {
        if (a == -1)
            return b;
        if (b == -1)
            return a;
        return rank[a] < rank[b] ? a : b;
    }

    void solve() throws IOException {
        int n = nextInt();
        int[][] they = new int[n][n];
        int[][] theyRank = new int[n][];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                they[i][j] = nextInt() - 1;
            }
            theyRank[i] = get(they[i]);
        }

        int[] me = new int[n];

        for (int i = 0; i < me.length; i++) {
            me[i] = nextInt() - 1;
        }
        int[] myRank = get(me);

        int[] best = new int[n];
        int[] when = new int[n];

        Arrays.fill(best, -1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                int what = -1;
                for (int k = 0; k <= i; k++) {
                    if (k != j) {
                        what = get(myRank, what, k);
                    }
                }

                best[j] = get(theyRank[j], best[j], what);
                if (best[j] == what) {
                    when[j] = i;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            System.out.print((when[i] + 1) + " ");
        }
    }

    static public void main(String[] args) {
        new b().run();
    }
}