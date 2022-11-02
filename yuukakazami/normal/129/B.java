/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 11-12-3
 * Time: 10:40
 * To change this template use File | Settings | File Templates.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class T {

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
        boolean[][] e = new boolean[n][n];
        int nE = nextInt();
        for (int i = 0; i < nE; i++) {
            int a = nextInt() - 1, b = nextInt() - 1;
            e[a][b] = e[b][a] = true;
        }

        int cnt = 0;
        List<Integer> cur = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            cur.add(i);
        }
        for (; ; ) {
            List<Integer> ncur = new ArrayList<Integer>();
            for (Integer a : cur) {
                int d = 0;
                for (Integer b : cur) {
                    if (e[a][b])
                        ++d;
                }
                if (d != 1)
                    ncur.add(a);
            }
            if (cur.size() == ncur.size())
                break;
            ++cnt;
            cur = ncur;
        }

        writer.println(cnt);
    }

    static public void main(String[] args) {
        new T().run();
    }
}