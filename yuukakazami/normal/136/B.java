/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 11-12-12
 * Time: 5:58
 * To change this template use File | Settings | File Templates.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

import java.util.StringTokenizer;

public class Main {

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
        String a = Integer.toString(nextInt(), 3), b = Integer.toString(nextInt(), 3);
        while (a.length() < b.length())
            a = "0" + a;
        while (b.length() < a.length())
            b = "0" + b;
        int pow = 1;
        int ret = 0;
        for (int i = a.length() - 1; i >= 0; i--) {
            int me = (b.charAt(i) - '0') - (a.charAt(i) - '0') + 3;
            me %= 3;
            ret += me * pow;
            pow *= 3;
        }
        writer.println(ret);
    }

    static public void main(String[] args) {
        new Main().run();
    }
}