/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 12-1-4
 * Time: 10:56
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

    void solve() throws IOException {
        int n = nextInt(), R = nextInt(), r = nextInt();
        if (r > R) {
            System.out.println("NO");
            return;
        }
        if (n == 1) {
            System.out.println("YES");
            return;
        }
        if (2 * r > R) {
            System.out.println("NO");
            return;
        }
        double s = (double) r / (R - r);
        double a = Math.asin(s) * 2;
//        System.out.println(a);
        if (a * n <= Math.PI * 2 + 1e-10) {
            System.out.println("YES");
            return;
        }
        System.out.println("NO");
    }

    static public void main(String[] args) {
        new a().run();
    }
}