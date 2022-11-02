/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 11-12-9
 * Time: 10:48
 * To change this template use File | Settings | File Templates.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
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
        int[] a = new int[n];
        for (int i = 0; i < a.length; i++) {
            a[i] = nextInt();
        }
        Arrays.sort(a);
        if (a[a.length - 1] == 1) {
            for (int i = 0; i < a.length - 1; i++) {
                writer.print(1 + " ");
            }
            writer.println(2 + "");
            return;
        }
        for (int i = 0; i < a.length; i++) {
            if (i == 0)
                writer.print(1 + " ");
            else
                writer.print(a[i - 1] + " ");
        }
        writer.println();
    }

    static public void main(String[] args) {
        new A().run();
    }
}