/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 12-10-9
 * Time: 12:41
 * To change this template use File | Settings | File Templates.
 */

import java.io.*;
import java.util.*;

public class EJava {

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

    class Converter {
        int n, sq;
        int[] lst;

        public Converter(int n) {
            this.n = n;
            sq = 1;
            while (sq * sq <= n) ++sq;
            lst = new int[sq * 2 + 1];
            for (int i = 1; i <= sq * 2; i++) {
                lst[i] = i <= sq ? i : n / (i - sq);
            }
        }

        int encode(int x) {
            return x <= sq ? x : n / x + sq;
        }

        int decode(int x) {
            return lst[x];
        }

        int size() {
            return sq * 2;
        }
    }

    int calcTwo(int a, int b, int[] cnt) {
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        return cnt[a] * cnt[b] * 4 - cnt[a] * 4 + cnt[a] * 3;
    }

    void solve() throws IOException {
        int a = nextInt(), b = nextInt(), c = nextInt();
        Converter A = new Converter(a), B = new Converter(b), C = new Converter(c);
        int n = Math.max(a, Math.max(b, c));
        int[] cnt = new int[n + 1];
        boolean[] is = new boolean[n + 1];
        Arrays.fill(is, true);

        ArrayList<Integer> smallPrimes = new ArrayList<Integer>();

        for (int i = 2; i <= n; i++) {
            if (is[i]) {
                if (i * i <= n) {
                    smallPrimes.add(i);
                } else {
                    cnt[i]++;
                }
                for (int j = i + i; j <= n; j += i) {
                    is[j] = false;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            cnt[i] += cnt[i - 1];
        }

        int[][][] am = new int[A.size() + 1][B.size() + 1][C.size() + 1];
        int[][][] nam = new int[A.size() + 1][B.size() + 1][C.size() + 1];
        am[A.encode(a)][B.encode(b)][C.encode(c)] += 1;
        for (int p : smallPrimes) {
            for (int[][] x : nam) {
                for (int[] y : x) {
                    Arrays.fill(y, 0);
                }
            }
            for (int i = 1; i <= A.size(); i++) {
                for (int j = 1; j <= B.size(); j++) {
                    for (int k = 1; k <= C.size(); k++) {
                        int d = am[i][j][k];
                        if (d == 0)
                            continue;
                        int I = A.decode(i), J = B.decode(j), K = C.decode(k);
                        for (int pi = 1, ci = 0; pi <= I; pi *= p, ++ci) {
                            int x = A.encode(I / pi);
                            for (int pj = 1, cj = 0; pj <= J; pj *= p, ++cj) {
                                int y = B.encode(J / pj);
                                for (int pk = 1, ck = 0; pk <= K; pk *= p, ++ck) {
                                    int z = C.encode(K / pk);
                                    nam[x][y][z] += d * (ci + cj + ck + 1);
                                }
                            }
                        }
                    }
                }
            }
            int[][][] tmp = am;
            am = nam;
            nam = tmp;
        }


        int ans = 0;
        for (int i = 1; i <= A.size(); ++i) {
            for (int j = 1; j <= B.size(); ++j) {
                for (int k = 1; k <= C.size(); ++k) {
                    int d = am[i][j][k];
                    if (d == 0)
                        continue;
                    int I = A.decode(i), J = B.decode(j), K = C.decode(k);
                    int t[] = {I, J, K};
                    Arrays.sort(t);
                    I = t[0];
                    J = t[1];
                    K = t[2];
                    //there
                    int cur = cnt[I] * cnt[J] * cnt[K] * 8; //abc->8
                    cur += -cnt[I] * cnt[K] * 2; //aab->3*2->6
                    cur += -cnt[I] * cnt[J] * 2;
                    cur += -cnt[J] * cnt[I] * 2;
                    cur += cnt[I] * 2; //aaa->4
                    //two
                    cur += calcTwo(I, J, cnt) + calcTwo(J, K, cnt) + calcTwo(I, K, cnt);
                    //one
                    cur += (cnt[I] + cnt[J] + cnt[K]) * 2;
                    //zero
                    cur += 1;
                    ans += cur * d;
                }
            }
        }
        ans %= 1 << 30;
        if (ans < 0)
            ans += 1 << 30;
        System.out.println(ans);
    }

    static public void main(String[] args) {
        new EJava().run();
    }
}