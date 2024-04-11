import java.io.InputStreamReader;
import java.io.IOException;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    final int MAXN = 40000;
    int ret[], sz;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        String[] words = new String[n];
        for (int i = 0; i < n; i++) {
            words[i] = in.next();
        }
        int[] from = new int[n], to = new int[n];
        int[] deg = new int[MAXN];
        for (int i = 0; i < n; i++) {
            String s = words[i];
            int u = hash(s.charAt(0), s.charAt(1));
            int v = hash(s.charAt(1), s.charAt(2));
            from[i] = u; to[i] = v;
            deg[u] ++; deg[v] --;
        }
        int[][] G = GraphUtils.buildGraph(MAXN, from, to);
        int rt = hash(words[0].charAt(0), words[0].charAt(1));
        int cnt = 0;
        for (int i = 0; i < MAXN; i++) {
            if (deg[i] != 0) {
                if (Math.abs(deg[i]) != 1) {
                    out.println("NO");
                    return;
                }
                if (deg[i] == 1) rt = i;
                ++ cnt;
            }
        }
        if (cnt != 0 && cnt != 2) {
            out.println("NO");
            return;
        }
        ret = new int[n + 1]; sz = 0;
        dfs(rt, G, new int[MAXN]);
        if (sz < n) {
            out.println("NO");
            return;
        }
        out.println("YES");
        for (int i = sz - 1; i >= 0; i--) {
            if (i == sz - 1) out.print((char)(ret[i] >> 8));
            out.print((char)(ret[i] & 0xff));
        }
        out.println();
    }
    void dfs(int u, int[][] G, int[] cur) {
        for (; cur[u] < G[u].length; ) {
            cur[u] ++;
            dfs(G[u][cur[u] - 1], G, cur);
        }
        ret[sz ++] = u;
    }
    int hash(char a, char b) {
        return (a << 8) | b;
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

class GraphUtils {
    public static int[][] buildGraph(int vertexCount, int[] from, int[] to) {
        int edgeCount = from.length;
        int[] deg = new int[vertexCount];
        for (int i = 0; i < edgeCount; i++) deg[from[i]] ++;
        int[][] graph = new int[vertexCount][];
        for (int i = 0; i < vertexCount; i++) graph[i] = new int[deg[i]];
        for (int i = 0; i < edgeCount; i++) {
            graph[from[i]][-- deg[from[i]]] = to[i];
        }
        return graph;
    }
}