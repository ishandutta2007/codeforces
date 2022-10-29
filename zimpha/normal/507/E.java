import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Xi Lin (zimpha@gmail.com)
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    final int inf = 1000000000;
    int Q[];
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt(), m = in.nextInt();
        int x[] = new int[m], y[] = new int[m], z[] = new int[m];
        for (int i = 0; i < m; i++) {
            x[i] = in.nextInt() - 1;
            y[i] = in.nextInt() - 1;
            z[i] = in.nextInt();
        }
        int g[][] = buildGraph(x, y, n, m);
        Q = new int[n];
        int d1[] = spfa(g, 0, n);
        int d2[] = spfa(g, n - 1, n);
        int len = d2[0], t0 = 0, deg[] = new int[n];
        Vector G[] = new Vector[n];
        for (int i = 0; i < n; i++) {
            G[i] = new Vector();
        }
        for (int i = 0; i < m; i++) {
            if (z[i] == 0) t0 ++;
            if (d1[x[i]] + d2[y[i]] + 1 == len) {
                G[x[i]].add(i); deg[y[i]] ++;
            }
            else {
                int t = x[i];
                x[i] = y[i];
                y[i] = t;
                if (d1[x[i]] + d2[y[i]] + 1 == len) {
                    G[x[i]].add(i); deg[y[i]] ++;
                }
            }
        }
        int dp[] = new int[n], pre[] = new int[n];
        Arrays.fill(dp, inf); dp[0] = 0; Q[0] = 0;
        for (int h = 0, t = 1; h < t; ++ h) {
            int u = Q[h];
            for (int i : G[u]) {
                int v = y[i], w = z[i]; deg[v] --;
                if (dp[v] > dp[u] + 1 - w) {
                    dp[v] = dp[u] + 1 - w;
                    pre[v] = i;
                }
                if (deg[v] == 0) Q[t ++] = v;
            }
        }
        boolean mark[] = new boolean[m];
        for (int v = n - 1; v != 0; v = x[pre[v]]) {
            mark[pre[v]] = true;
        }
        //System.out.println(dp[n - 1]);
        out.println(2 * dp[n - 1] - len + m - t0);
        for (int i = 0; i < m; i++) {
            x[i] ++; y[i] ++;
            if (mark[i] && z[i] == 0) out.println(x[i] + " " + y[i] + " 1");
            if (!mark[i] && z[i] == 1) out.println(x[i] + " " + y[i] + " 0");
        }
    }
    int[] spfa(int[][] g, int s, int n) {
        int dis[] = new int[n];
        Arrays.fill(dis, -1);
        dis[s] = 0; Q[0] = s;
        for (int h = 0, t = 1; h < t; ++ h) {
            int u = Q[h];
            for (int v : g[u]) if (dis[v] == -1) {
                dis[v] = dis[u] + 1;
                Q[t ++] = v;
            }
        }
        return dis;
    }
    int[][] buildGraph(int[] from, int[] to, int n, int m) {
        int deg[] = new int[n];
        for (int i = 0; i < m; i++) {
            deg[from[i]] ++;
            deg[to[i]] ++;
        }
        int g[][] = new int[n][];
        for (int i = 0; i < n; i++) {
            g[i] = new int[deg[i]];
        }
        for (int i = 0; i < m; i++) {
            g[from[i]][-- deg[from[i]]] = to[i];
            g[to[i]][-- deg[to[i]]] = from[i];
        }
        return g;
    }
    class Vector extends ArrayList<Integer> {

    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;
    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }
    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }
}