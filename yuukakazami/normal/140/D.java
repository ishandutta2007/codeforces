/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 12-1-4
 * Time: 10:57
 * To change this template use File | Settings | File Templates.
 */

import java.io.*;
import java.util.*;

public class d {

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

        int cur = 10;
        int num = 0, time = 0;
        for (int i : a) {
            if (cur + i <= 360) {
                cur += i;
                ++num;
            } else if (cur + i <= 720) {
                cur += i;
                ++num;
                time += Math.abs(cur - 360);
            }
        }

        System.out.println(num + " " + time);
    }

    static public void main(String[] args) {
        new d().run();
    }
}