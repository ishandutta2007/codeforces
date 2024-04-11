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

    final int[][] DIR = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};//R,D,L,U
    int H, W, nSteps;

    boolean inRange(int r, int c) {
        return r >= 0 && r < H && c >= 0 && c < W;
    }

    int code(int r, int c, int dp, int cp) {
        return ((r * W + c) * 4 + dp) * 2 + cp;
    }

    void solve() throws IOException {
        H = nextInt();
        nSteps = nextInt();
        char[][] map = new char[H][];
        for (int i = 0; i < H; i++) {
            map[i] = nextToken().toCharArray();
        }
        W = map[0].length;

        int[][][][] go = new int[H][W][8][2];
        int[] nxt = new int[H * W * 8 * 2];

        for (int r = 0; r < H; r++) {
            for (int c = 0; c < W; c++) {
                for (int d = 0; d < 8; d++) {
                    int dp = d / 2;
                    int cp = d % 2;

                    int nr = r, nc = c;
                    char ch = map[r][c];
                    int[] dir = DIR[dp];
                    while (inRange(nr, nc) && map[nr][nc] == ch) {
                        nr += dir[0];
                        nc += dir[1];
                    }
                    nr -= dir[0];
                    nc -= dir[1];
                    if (cp == 0) {
                        dir = DIR[(dp + 3) % 4];
                    } else {
                        dir = DIR[(dp + 1) % 4];
                    }
                    while (inRange(nr, nc) && map[nr][nc] == ch) {
                        nr += dir[0];
                        nc += dir[1];
                    }
                    nr -= dir[0];
                    nc -= dir[1];

                    dir = DIR[dp];
                    nr += dir[0];
                    nc += dir[1];
                    go[r][c][d] = new int[]{nr, nc};
                }
            }
        }

        int cr = 0, cc = 0;

        for (int r = 0; r < H; r++) {
            for (int c = 0; c < W; c++) {
                for (int dp = 0; dp < 4; dp++) {
                    for (int cp = 0; cp < 2; cp++) {
                        int[] where = go[r][c][dp * 2 + cp];
                        int nr = where[0], nc = where[1];
                        if (!inRange(nr, nc) || map[nr][nc] == '0') {
                            if (cp == 0) {
                                nxt[code(r, c, dp, cp)] = code(r, c, dp, 1);
                            } else {
                                nxt[code(r, c, dp, cp)] = code(r, c, (dp + 1) % 4, 0);
                            }
                        } else {
                            nxt[code(r, c, dp, cp)] = code(nr, nc, dp, cp);
                        }
                    }
                }
            }
        }

        int at = code(0, 0, 0, 0);
        for (int i = 0; i < nSteps; i++) {
            at = nxt[at];
        }

        int r = (at / 8) / W;
        int c = (at / 8) % W;
        writer.println(map[r][c]);
    }

    static public void main(String[] args) {
        new B().run();
    }
}