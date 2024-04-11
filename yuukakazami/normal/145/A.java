/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 12-1-26
 * Time: 2:03
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
        String a = nextToken(), b = nextToken();
        int[][] cnt = new int[8][8];
        for (int i = 0; i < a.length(); i++) {
            cnt[a.charAt(i) - '0'][b.charAt(i) - '0']++;
        }
        int ans = cnt[4][7] + cnt[7][4] - Math.min(cnt[4][7], cnt[7][4]);
        System.out.println(ans);
    }

    static public void main(String[] args) {
        new a().run();
    }
}