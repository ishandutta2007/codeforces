/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 11-11-26
 * Time: 1:31
 * To change this template use File | Settings | File Templates.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

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

    V dfs(V u, V parent) {
        if (u.visited)
            return u;
        u.visited = true;
        for (V v : u) {
            if (v != parent) {
                V t = dfs(v, u);
                if (t != null) {
                    u.inCycle = true;
                    if (t == u)
                        return null;
                    else
                        return t;
                }
            }
        }
        return null;
    }

    void solve() throws IOException {
        int n = nextInt();
        int[] a = new int[n], b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt() - 1;
            b[i] = nextInt() - 1;
        }

        V[] vs = GraphUtils.buildSimpleGraph(n, a, b);
        dfs(vs[0], null);
        Queue<V> queue = new LinkedList<V>();
        for (V v : vs) {
            if (v.inCycle) {
                v.dist = 0;
                queue.add(v);
            }
        }

        while (!queue.isEmpty()) {
            V u = queue.poll();
            for (V v : u) {
                if (v.dist == -1) {
                    v.dist = u.dist + 1;
                    queue.add(v);
                }
            }
        }

        for (V v : vs) {
            writer.print(v.dist + " ");
        }
        writer.println();
    }

    static public void main(String[] args) {
        new a().run();
    }
}

class V extends ArrayList<V> {
    boolean inCycle = false;
    boolean visited = false;
    int dist = -1;
}

class GraphUtils {
    static V[] buildSimpleGraph(int nV, int[] a, int[] b) {
        V[] vs = new V[nV];
        for (int i = 0; i < nV; i++) {
            vs[i] = new V();
        }
        for (int i = 0; i < a.length; i++) {
            vs[a[i]].add(vs[b[i]]);
            vs[b[i]].add(vs[a[i]]);
        }
        return vs;
    }
}