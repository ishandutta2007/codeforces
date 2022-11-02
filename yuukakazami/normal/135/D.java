/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 11-12-9
 * Time: 10:36
 * To change this template use File | Settings | File Templates.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
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

    final int dx4[] = {0, -1, 0, 1}, dy4[] = {-1, 0, 1, 0};

    void solve() throws IOException {
        int n = nextInt(), m = nextInt();
        char[][] map = new char[n][];
        for (int i = 0; i < n; i++) {
            map[i] = nextToken().toCharArray();
        }

        int[][] oneId = new int[n][m];
        for (int[] v : oneId) {
            Arrays.fill(v, -1);
        }

        int[] que = new int[n * m * 2];
        int qh = 0, qt = 0;

        int nOneId = 0;

        DisJointSet djs = new DisJointSet(n * m);

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (map[r][c] == '1' && oneId[r][c] == -1) {
                    qh = qt = 0;
                    que[qt++] = r;
                    que[qt++] = c;
                    oneId[r][c] = nOneId;

                    while (qh < qt) {
                        int cr = que[qh++], cc = que[qh++];
                        for (int d = 0; d < 4; d++) {
                            int nr = cr + dx4[d], nc = cc + dy4[d];
                            if (nr >= 0 && nr < n && nc >= 0 && nc < m && map[nr][nc] == '1' && oneId[nr][nc] == -1) {
                                oneId[nr][nc] = nOneId;
                                que[qt++] = nr;
                                que[qt++] = nc;
                            }
                        }
                    }
                    ++nOneId;
                }
            }
        }

//        for (int r = 0; r < n; r++) {
//            for (int c = 0; c < m; c++) {
//                writer.print(oneId[r][c] + " ");
//            }
//            writer.println();
//        }

        boolean[][] markZero = new boolean[n][m];

        int[][] markTouched = new int[n][m];
        int markTouchedCur = 1;

        int ans = 0;

        for (int r = 0; r < n - 1; r++) {
            for (int c = 0; c < m - 1; c++) {
                if (map[r][c] == '1' && map[r + 1][c] == '1' && map[r][c + 1] == '1' && map[r + 1][c + 1] == '1') {
                    ans = 4;
                }
            }
        }

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (map[r][c] == '0' && !markZero[r][c]) {
                    qh = qt = 0;
                    int touchOneComponent = -1;
                    boolean touchBorder = false;

                    que[qt++] = r;
                    que[qt++] = c;
                    markZero[r][c] = true;

                    List<Integer> rs = new ArrayList<Integer>(), cs = new ArrayList<Integer>();
                    ++markTouchedCur;

                    while (qh < qt) {
                        int cr = que[qh++], cc = que[qh++];
                        for (int nr = cr - 1; nr <= cr + 1; nr++) {
                            for (int nc = cc - 1; nc <= cc + 1; nc++) {
                                if (nr != cr || nc != cc) {
                                    if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                                        if (map[nr][nc] == '0') {
                                            if (!markZero[nr][nc]) {
                                                markZero[nr][nc] = true;
                                                que[qt++] = nr;
                                                que[qt++] = nc;
                                            }
                                        } else {
                                            int id = oneId[nr][nc];
                                            if (touchOneComponent == -1) {
                                                touchOneComponent = id;
                                            } else if (touchOneComponent != id) {
                                                touchOneComponent = -2;
                                            }

                                            if (markTouched[nr][nc] != markTouchedCur) {
                                                markTouched[nr][nc] = markTouchedCur;
                                                rs.add(nr);
                                                cs.add(nc);
                                            }
                                        }
                                    } else {
                                        touchBorder = true;
                                    }
                                }
                            }
                        }
                    }

                    if (touchBorder)
                        continue;
                    if (touchOneComponent < 0)
                        continue;


                    for (int i = 0; i < rs.size(); i++) {
                        int cr = rs.get(i), cc = cs.get(i);
                        djs.father[cr * m + cc] = cr * m + cc;
                    }

                    //check degree

                    boolean check = true;
                    for (int i = 0; i < rs.size(); i++) {
                        int cr = rs.get(i), cc = cs.get(i);

                        int deg = 0;
                        for (int d = 0; d < 4; d++) {
                            int nr = cr + dx4[d], nc = cc + dy4[d];
                            if (nr >= 0 && nr < n && nc >= 0 && nc < m && markTouched[nr][nc] == markTouchedCur) {
                                ++deg;
                                djs.unite(nr * m + nc, cr * m + cc);
                            }
                        }
                        if (deg != 2) {
                            check = false;
                            break;
                        }
                    }

                    if (!check)
                        continue;

                    int mustBe = djs.find(rs.get(0) * m + cs.get(0));

                    for (int i = 0; i < rs.size(); i++) {
                        int cr = rs.get(i), cc = cs.get(i);
                        if (djs.find(cr * m + cc) != mustBe) {
                            check = false;
                            break;
                        }
                    }

                    if (!check)
                        continue;

                    ans = Math.max(ans, rs.size());
                }
            }
        }
        writer.println(ans);
    }

    static public void main(String[] args) {
        new D().run();
    }
}


class DisJointSet {
    int[] father, rank;

    DisJointSet(int n) {
        father = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }

    int find(int x) {
        if (x == father[x])
            return x;
        return father[x] = find(father[x]);
    }

    boolean unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (rank[a] < rank[b]) {
            father[a] = b;
        } else {
            father[b] = a;
            rank[a] += rank[a] == rank[b] ? 1 : 0;
        }
        return true;
    }
}