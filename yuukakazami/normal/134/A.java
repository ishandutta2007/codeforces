/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 11-12-3
 * Time: 9:30
 * To change this template use File | Settings | File Templates.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class A {

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
        int n = nextInt();
        long[] a = new long[n];
        long sum = 0;
        for (int i = 0; i < n; i++) {
            a[i] = nextLong();
            sum += a[i];
        }

        List<Integer> idx = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            long other = sum - a[i];
            if (a[i] * (n - 1) == other) {
                idx.add(i + 1);
            }
        }

        writer.println(idx.size());
        for (Integer i : idx) {
            writer.print(i + " ");
        }
        writer.println();
    }

    static public void main(String[] args) {
        new A().run();
    }
}