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

    int rev(int a) {
        int b = 0;
        for (int i = 0; i < 8; i++) {
            if ((a & (1 << i)) > 0)
                b += 1 << (8 - 1 - i);
        }
        return b;
    }

    void solve() throws IOException {
        String input = reader.readLine();
        int p = 0;
        for (char ch : input.toCharArray()) {
            int c = (int) ch;
            for (int i = 0; i < 256; i++) {
                int np = rev(p);
                int a = np - i;
                if (a < 0)
                    a += 256;
                if (rev(a) == c) {
                    writer.println(i);
                    break;
                }
            }
            p = c;
        }
    }

    static public void main(String[] args) {
        new A().run();
    }
}