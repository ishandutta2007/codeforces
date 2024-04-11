/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 11-12-24
 * Time: 7:56
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

    String get(String a, int k) {
        for (int i = a.length() - 1; i >= 0; i--) {
            if ("aoieu".indexOf(a.charAt(i)) >= 0) {
                --k;
                if (k == 0)
                    return a.substring(i);
            }
        }
        return null;
    }

    boolean check(String a, String b, int k) {
        a = get(a, k);
        b = get(b, k);
        if (a == null || b == null)
            return false;
        return a.equals(b);
    }

    String get(String[] lines, int k) {
        int[] mark = new int[4];
        for (int i = 0; i < 4; i++) {
            mark[i] = i;
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < i; j++) {
                if (check(lines[i], lines[j], k)) {
                    int mi = mark[i], mj = mark[j];
                    for (int l = 0; l < 4; l++) {
                        if (mark[l] == mi)
                            mark[l] = mj;
                    }
                }
            }
        }
        char[] which = new char[4];
        Arrays.fill(which, '?');
        char cur = 'a';
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < 4; i++) {
            if (which[mark[i]] == '?')
                which[mark[i]] = cur++;
            sb.append(which[mark[i]]);
        }

        String a = sb.toString();
        if (a.equals("aaaa") || a.equals("abba") || a.equals("aabb") || a.equals("abab"))
            return a;
        else
            return "NO";
    }

    void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        String[] lines = new String[4];
        Set<String> set = new HashSet<String>();

        for (int it = 0; it < n; it++) {
            for (int i = 0; i < 4; i++) {
                lines[i] = nextToken();
            }
            String me = get(lines, k);
            if (me.equals("NO")) {
                writer.println("NO");
                return;
            }
            set.add(me);
        }
        if (set.size() == 1) {
            writer.println(set.iterator().next());
            return;
        }
        if (set.size() > 2) {
            writer.println("NO");
            return;
        }

        boolean has = false;
        for (String s : set) {
            if (s.equals("aaaa"))
                has = true;
        }
        if (!has) {
            writer.println("NO");
            return;
        }
        for (String s : set) {
            if (!s.equals("aaaa"))
                writer.println(s);
        }
    }

    static public void main(String[] args) {
        new a().run();
    }
}