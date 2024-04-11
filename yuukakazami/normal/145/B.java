/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 12-1-26
 * Time: 2:03
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

    boolean check(int p, int a4, int a7, int a47, int a74) {
        if (a4 < 0 || a7 < 0 || a47 < 0 || a74 < 0)
            return false;
        if (p == 4) {
            //4747474747 4:a 7:a 47:a 74:a-1

            if (a47 == a74 + 1) {
                if (a47 == 0 && a7 > 0)
                    return false;
                if (a4 >= a47 - 1 && a7 >= a47)
                    return true;
            }
            //4747474 4:a 47:a-1 74:a-1
            if (a47 == a74) {
                int a = a47 + 1;
                if (a - 1 == 0 && (a4 > 0 || a7 > 0)) return false;
                if (a4 >= a - 1 && a7 >= a - 1)
                    return true;
            }
            return false;
        }
        return check(4, a7, a4, a74, a47);
    }

    void solve() throws IOException {
        int a4 = nextInt(), a7 = nextInt(), a47 = nextInt(), a74 = nextInt();
        StringBuilder sb = new StringBuilder();
        int p;
        if (check(4, a4 - 1, a7, a47, a74)) {
            sb.append('4');
            a4 -= 1;
            p = 4;
        } else if (check(7, a4, a7 - 1, a47, a74)) {
            sb.append('7');
            a7 -= 1;
            p = 7;
        } else {
            System.out.println("-1");
            return;
        }
        int n = a4 + a7;
        for (int i = 0; i < n; i++) {
            if (check(4, a4 - 1, a7, a47, a74 - (p == 7 ? 1 : 0))) {
                sb.append('4');
                a4 -= 1;
                a74 -= (p == 7 ? 1 : 0);
                p = 4;
            } else {
                sb.append('7');
                a7 -= 1;
                a47 -= p == 4 ? 1 : 0;
                p = 7;
            }
        }
        System.out.println(sb);
    }

    static public void main(String[] args) {
        new b().run();
    }
}