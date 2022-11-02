/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 11-12-24
 * Time: 7:56
 * To change this template use File | Settings | File Templates.
 */

import java.io.*;
import java.util.*;

public class e {

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
        String input = nextToken();
        int n = input.length();
        int[] what = new int[n];
        for (int i = 0; i < n; i++) {
            what[i] = input.charAt(i) - 'a';
        }

        int k = nextInt(), L = nextInt(), R = nextInt();
        int[] id = new int[k], l = new int[k], r = new int[k];

        int[] cnt = new int[n];

        for (int i = 0; i < k; i++) {
            id[i] = nextToken().charAt(0) - 'a';
            l[i] = nextInt();
            r[i] = nextInt();
        }

        int[] atL = new int[k], atR = new int[k];//[l,r)
        long ans = 0;

        @SuppressWarnings({"unchecked"})
        List<Integer>[] by = new List[26];
        for (int i = 0; i < 26; i++) {
            by[i] = new ArrayList<Integer>();
        }

        for (int i = 0; i < n; i++) {
            by[what[i]].add(i);
        }

        for (int i = 0; i < k; i++) {
            if (by[id[i]].size() < l[i]) {
                atL[i] = atR[i] = n;
            } else {
                if (l[i] == 0) {
                    atL[i] = 0;
                } else {
                    atL[i] = by[id[i]].get(l[i] - 1);
                }
                if (by[id[i]].size() <= r[i]) {
                    atR[i] = n;
                } else {
                    atR[i] = by[id[i]].get(r[i]);
                }
            }
        }

        for (int i = 0; i < k; i++) {
            for (int j = atL[i]; j < atR[i]; j++) {
                cnt[j]++;
            }
        }
        int curCount = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[i] >= L && cnt[i] <= R)
                ++curCount;
        }

        for (int i = 0; i < n; i++) {
            int me = what[i];
            ans += curCount;

            for (int j = 0; j < k; j++) {
                if (id[j] == me) {
                    int x = atL[j];
                    while (x < n) {
                        if (x >= i) {
                            if (cnt[x] >= L && cnt[x] <= R) {
                                --curCount;
                            }
                            cnt[x]--;
                            if (cnt[x] >= L && cnt[x] <= R) {
                                ++curCount;
                            }
                        }
                        ++x;
                        if (x == n || what[x] == me)
                            break;
                    }
                    atL[j] = x;

                    x = atR[j];
                    while (x < n) {
                        if (x >= i) {
                            if (cnt[x] >= L && cnt[x] <= R) {
                                --curCount;
                            }
                            cnt[x]++;
                            if (cnt[x] >= L && cnt[x] <= R) {
                                ++curCount;
                            }
                            ++x;
                        }
                        if (x == n || what[x] == me)
                            break;
                    }
                    atR[j] = x;
                }
            }

            if (cnt[i] >= L && cnt[i] <= R)
                --curCount;
        }

        writer.println(ans);
    }

    static public void main(String[] args) {
        new e().run();
    }
}