/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 11-11-25
 * Time: 8:20
 * To change this template use File | Settings | File Templates.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

import java.util.ArrayList;
import java.util.StringTokenizer;

public class C {

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

    int nV, nE;

    class V extends ArrayList<V> {
        boolean visited = false;

        void dfs() {
            if (visited)
                return;
            visited = true;
            nV++;
            for (V v : this) {
                nE++;
                v.dfs();
            }
        }
    }

    void solve() throws IOException {
        int n = nextInt(), m = nextInt();
        V[] vs = new V[n];
        for (int i = 0; i < vs.length; i++) {
            vs[i] = new V();
        }

        for (int i = 0; i < m; i++) {
            int a = nextInt() - 1, b = nextInt() - 1;
            vs[a].add(vs[b]);
            vs[b].add(vs[a]);
        }

        nV = 0;
        nE = 0;
        vs[0].dfs();
        nE /= 2;
        if (nV != nE || nV != n) {
            writer.println("NO");
            return;
        }

        writer.println("FHTAGN!");
    }

    static public void main(String[] args) {
        new C().run();
    }
}