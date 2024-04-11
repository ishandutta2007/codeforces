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
import java.util.*;

public class E {

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

    Vertex vs, vt, S, T;
    Vertex[] in, out;

    int n, m;
    int[] a;

    void dfs(Vertex at, char cur, int last, List<String>[] before, char[] which) {
        int id = at.id;
        if (at == T)
            return;

        if (at == in[id]) {
            which[id] = cur;
            if (last == -1 || a[id] != a[last]) {
                before[id].add(cur + "=" + a[id]);
            }
            dfs(out[id], cur, last, before, which);
        } else {
            for (Edge e : at) {
                if (e.t.id > id && e.cap == 0) {
                    dfs(e.t, cur, id, before, which);
                    return;
                }
            }
        }
    }

    void print(List<String>[] before, char[] which) {
        char cur = 'a';
        for (Edge e : S) {
            if (e.t.id != -1 && e.cap == 0) {
                dfs(e.t, cur, -1, before, which);
                ++cur;
            }
        }
    }

    void solve() throws IOException {
        n = nextInt();
        m = nextInt();
        a = new int[n];
        for (int i = 0; i < a.length; i++) {
            a[i] = nextInt();
        }

        vs = new Vertex();
        vt = new Vertex();
        S = new Vertex();
        T = new Vertex();
        in = new Vertex[n];
        out = new Vertex[n];

        for (int i = 0; i < n; i++) {
            in[i] = new Vertex(i);
            out[i] = new Vertex(i);
        }
        vs.addEdge(S, m, 0);
        T.addEdge(vt, m, 0);
        S.addEdge(T, m, 0);

        final int BIG = 100000;

        for (int i = 0; i < n; i++) {
            S.addEdge(in[i], 1, Integer.bitCount(a[i]));

            in[i].addEdge(out[i], 1, -BIG);

            for (int j = i + 1; j < n; j++) {
                if (a[i] == a[j])
                    out[i].addEdge(in[j], 1, 0);
                else
                    out[i].addEdge(in[j], 1, Integer.bitCount(a[j]));
            }

            out[i].addEdge(T, 1, 0);
        }

        Vertex[] all = Vertex.vertexList.toArray(new Vertex[0]);

        Result result = MinCostFlowUtils.minCostFlow(all, vs, vt);

        @SuppressWarnings({"unchecked"})
        List<String>[] before = new List[n];
        for (int i = 0; i < before.length; i++) {
            before[i] = new ArrayList<String>();
        }
        char[] which = new char[n];
        print(before, which);
        int nLines = n;
        for (List<String> strings : before) {
            nLines += strings.size();
        }

        int ans = result.cost + BIG * n;
        writer.println(nLines + " " + ans);
        for (int i = 0; i < n; i++) {
            for (String s : before[i]) {
                writer.println(s);
            }
            writer.println("print(" + which[i] + ")");
        }
    }

    static public void main(String[] args) {
        new E().run();
    }
}

class Edge {
    Vertex t;
    int cap, cost;
    Edge rev;

    Edge(Vertex t, int cap, int cost) {
        this.t = t;
        this.cap = cap;
        this.cost = cost;
    }
}

class Vertex extends ArrayList<Edge> {
    boolean inQueue = false;
    int dist;
    int am;
    Edge prev;
    int id;//in a

    void addEdge(Vertex t, int cap, int cost) {
        Edge ab = new Edge(t, cap, cost);
        Edge ba = new Edge(this, 0, -cost);
        ab.rev = ba;
        ba.rev = ab;
        add(ab);
        t.add(ba);
    }

    static List<Vertex> vertexList = new ArrayList<Vertex>();

    Vertex() {
        this.id = -1;
        vertexList.add(this);
    }

    Vertex(int id) {
        this.id = id;
        vertexList.add(this);
    }
}

class Result {
    int cost, flow;

    Result(int cost, int flow) {
        this.cost = cost;
        this.flow = flow;
    }
}

class MinCostFlowUtils {

    static Result minCostFlow(Vertex[] vs, Vertex s, Vertex t) {
        int flow = 0, cost = 0;

        for (; ; ) {
            for (Vertex v : vs) {
                v.inQueue = false;
                v.dist = Integer.MAX_VALUE;
            }
            LinkedList<Vertex> queue = new LinkedList<Vertex>();
            s.dist = 0;
            s.inQueue = true;
            s.am = Integer.MAX_VALUE;
            queue.add(s);
            while (!queue.isEmpty()) {
                Vertex u = queue.poll();
                u.inQueue = false;
                for (Edge e : u)
                    if (e.cap > 0) {
                        Vertex v = e.t;
                        int nc = u.dist + e.cost;
                        if (nc < v.dist) {
                            v.dist = nc;
                            v.prev = e;
                            v.am = Math.min(u.am, e.cap);
                            if (!v.inQueue) {
                                v.inQueue = true;
                                if (queue.isEmpty() || v.dist < queue.peek().dist)
                                    queue.addFirst(v);
                                else
                                    queue.addLast(v);
                            }
                        }
                    }
            }

            if (t.dist == Integer.MAX_VALUE)
                break;

            int by = t.am;
            flow += by;
            cost += by * t.dist;

            Vertex u = t;
            while (u != s) {
                Edge e = u.prev;
                e.cap -= by;
                e.rev.cap += by;
                u = e.rev.t;
            }
        }

        return new Result(cost, flow);
    }
}