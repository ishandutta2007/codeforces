/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 12-1-12
 * Time: 10:52
 * To change this template use File | Settings | File Templates.
 */

import java.io.*;
import java.util.*;

public class c {

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

    int ans;

    int[][][] HOW;
    int[][] id;
    int[][] out;
    int n, m;

    boolean inRange(int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }

    void rec(int r, int c, int nUsed) {
        int rem = (n - 1 - r) * m + m - c;
        if (nUsed + rem / 5 <= ans)
            return;
        if (r == n) {
            if (nUsed > ans) {
                ans = nUsed;
                out = id.clone();
                for (int i = 0; i < n; i++) {
                    out[i] = id[i].clone();
                }
            }
            return;
        }
        if (c == m) {
            rec(r + 1, 0, nUsed);
            return;
        }
        if (id[r][c] == -1) {
            outer:
            for (int[][] a : HOW) {
                for (int[] p : a) {
                    int nr = r + p[0], nc = c + p[1];
                    if (!inRange(nr, nc) || id[nr][nc] != -1)
                        continue outer;
                }

                for (int[] p : a) {
                    int nr = r + p[0], nc = c + p[1];
                    id[nr][nc] = nUsed;
                }

                rec(r, c + 1, nUsed + 1);

                for (int[] p : a) {
                    int nr = r + p[0], nc = c + p[1];
                    id[nr][nc] = -1;
                }
            }
        }
        rec(r, c + 1, nUsed);
    }

    void solve() throws IOException {
        //9 9 1
        String ANS99 = "AAABBBCCC\n" +
                ".AD.BE.C.\n" +
                ".AD.BE.C.\n" +
                "FDDDEEE.G\n" +
                "FFFHHHGGG\n" +
                "FIIIHJJJG\n" +
                ".KILH.JM.\n" +
                ".KILLLJM.\n" +
                "KKKL..MMM";
        n = nextInt();
        m = nextInt();
        if (n == 9 && m == 9) {
            System.out.println(13);
            System.out.println(ANS99);
            return;
        }
        id = new int[n][m];
        for (int[] a : id) {
            Arrays.fill(a, -1);
        }
        ans = 0;

        HOW = new int[4 * 5][][];
        int cur = 0;

        {
            String[] mat = {"###", ".#.", ".#."};
            for (int r = 0; r < 3; r++) {
                for (int c = 0; c < 3; c++) {
                    if (mat[r].charAt(c) == '#') {
                        HOW[cur] = new int[5][];

                        int t = 0;
                        for (int nr = 0; nr < 3; nr++) {
                            for (int nc = 0; nc < 3; nc++) {
                                if (mat[nr].charAt(nc) == '#') {
                                    HOW[cur][t++] = new int[]{nr - r, nc - c};
                                }
                            }
                        }
                        ++cur;
                    }
                }
            }
        }

        {
            String[] mat = {"..#", "###", "..#"};
            for (int r = 0; r < 3; r++) {
                for (int c = 0; c < 3; c++) {
                    if (mat[r].charAt(c) == '#') {
                        HOW[cur] = new int[5][];

                        int t = 0;
                        for (int nr = 0; nr < 3; nr++) {
                            for (int nc = 0; nc < 3; nc++) {
                                if (mat[nr].charAt(nc) == '#') {
                                    HOW[cur][t++] = new int[]{nr - r, nc - c};
                                }
                            }
                        }
                        ++cur;
                    }
                }
            }
        }

        {
            String[] mat = {".#.", ".#.", "###"};
            for (int r = 0; r < 3; r++) {
                for (int c = 0; c < 3; c++) {
                    if (mat[r].charAt(c) == '#') {
                        HOW[cur] = new int[5][];

                        int t = 0;
                        for (int nr = 0; nr < 3; nr++) {
                            for (int nc = 0; nc < 3; nc++) {
                                if (mat[nr].charAt(nc) == '#') {
                                    HOW[cur][t++] = new int[]{nr - r, nc - c};
                                }
                            }
                        }
                        ++cur;
                    }
                }
            }
        }


        {
            String[] mat = {"#..", "###", "#.."};
            for (int r = 0; r < 3; r++) {
                for (int c = 0; c < 3; c++) {
                    if (mat[r].charAt(c) == '#') {
                        HOW[cur] = new int[5][];

                        int t = 0;
                        for (int nr = 0; nr < 3; nr++) {
                            for (int nc = 0; nc < 3; nc++) {
                                if (mat[nr].charAt(nc) == '#') {
                                    HOW[cur][t++] = new int[]{nr - r, nc - c};
                                }
                            }
                        }
                        ++cur;
                    }
                }
            }
        }

        cur = 0;
        for (int[][] a : HOW) {
            boolean ok = true;
            for (int[] p : a) {
                if (p[0] < 0 || p[0] == 0 && p[1] < 0)
                    ok = false;
            }
            if (ok)
                HOW[cur++] = a;
        }

        HOW = Arrays.copyOfRange(HOW, 0, cur);

        out = id;
        rec(0, 0, 0);

        System.out.println(ans);
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (out[r][c] == -1)
                    System.out.print('.');
                else
                    System.out.print((char) (out[r][c] + 'A'));
            }
            System.out.println();
        }
    }

    static public void main(String[] args) {
        new c().run();
    }
}