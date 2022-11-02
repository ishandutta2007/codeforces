/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 11-11-25
 * Time: 10:58
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

    void solve() throws IOException {
        char[] a = nextToken().toCharArray();
        boolean changed = true;
        for (int i = 1; i < a.length; i++) {
            if (!Character.isUpperCase(a[i]))
                changed = false;
        }
        if (changed) {
            StringBuilder b = new StringBuilder();
            for (int i = 0; i < a.length; i++) {
                if (Character.isLowerCase(a[i]))
                    b.append(Character.toUpperCase(a[i]));
                else
                    b.append(Character.toLowerCase(a[i]));
            }
            a = b.toString().toCharArray();
        }
        writer.println(new String(a));
    }

    static public void main(String[] args) {
        new A().run();
    }
}