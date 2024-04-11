/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 12-10-17
 * Time: 1:30
 * To change this template use File | Settings | File Templates.
 */

import java.io.*;
import java.util.*;

public class CJava {

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    List<Node> nodes = new ArrayList<Node>();

    class Node {
        Node[] go;
        Node suf, nxt = null;
        int val, cnt;

        Node(Node[] go, Node suf, int val) {
            this.go = go;
            this.suf = suf;
            this.val = val;
            this.cnt = 0;
            nodes.add(this);
        }

        Node(Node suf, int val) {
            this(new Node[26], suf, val);
        }

        Node() {
            this(null, 0);
        }
    }

    Node root, last;

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

    void extend(int w) {
        Node p = last;
        Node np = new Node();
        np.val = p.val + 1;
        np.cnt = 1;
        while (p != null && p.go[w] == null) {
            p.go[w] = np;
            p = p.suf;
        }
        if (p == null) {
            np.suf = root;
        } else {
            Node q = p.go[w];
            if (p.val + 1 == q.val)
                np.suf = q;
            else {
                Node nq = new Node(q.go.clone(), q.suf, p.val + 1);
                q.suf = nq;
                np.suf = nq;
                while (p != null && p.go[w] == q) {
                    p.go[w] = nq;
                    p = p.suf;
                }
            }
        }
        last = np;
    }

    int repetend(char[] s) {
        int n = s.length;
        int[] nxt = new int[n + 1];
        nxt[0] = -1;
        for (int i = 1; i <= n; i++) {
            int j = nxt[i - 1];
            while (j >= 0 && s[j] != s[i - 1])
                j = nxt[j];
            nxt[i] = j + 1;
        }
        int a = n - nxt[n];
        if (n % a == 0)
            return a;
        return n;
    }

    void solve() throws IOException {
        root = last = new Node();
        {
            char[] s = nextToken().toCharArray();
//            char[] s = new char[500000];
//            Random rnd = new Random();
//            for (int i = 0; i < s.length; i++) {
//                s[i] = (char)(rnd.nextInt(26) + 'a');
//            }
            int n = s.length;
            for (char c : s) {
                extend(c - 'a');
            }
            Node[] first = new Node[n + 1];
            for (Node node : nodes) {
                node.nxt = first[node.val];
                first[node.val] = node;
            }
            for (int i = n; i >= 0; i--) {
                for (Node u = first[i]; u != null; u = u.nxt)
                    if (u.suf != null)
                        u.suf.cnt += u.cnt;
            }
        }

        int nQ = nextInt();
        for (int i = 0; i < nQ; i++) {
            char[] buf = nextToken().toCharArray();
            int rep = repetend(buf);
            Node cur = root;
            int l = 0;
            int n = buf.length;

            for (int j = 0; j < n; j++) {
                int w = buf[j] - 'a';
                while (cur != null && cur.go[w] == null) {
                    cur = cur.suf;
                    if (cur != null)
                        l = cur.val;
                }
                if (cur != null && cur.go[w] != null) {
                    cur = cur.go[w];
                    ++l;
                } else {
                    cur = root;
                    l = 0;
                }
            }
            int ans = 0;
            if (l == n)
                ans += cur.cnt;
            for (int j = 1; j < rep; j++) {
                if (l == n) {
                    --l;
                    if (l <= cur.suf.val)
                        cur = cur.suf;
                }
                //add last
                int w = buf[j - 1] - 'a';
                while (cur != null && cur.go[w] == null) {
                    cur = cur.suf;
                    if (cur != null)
                        l = cur.val;
                }
                if (cur != null && cur.go[w] != null) {
                    cur = cur.go[w];
                    ++l;
                } else {
                    cur = root;
                    l = 0;
                }
                if (l == n)
                    ans += cur.cnt;
            }
            writer.println(ans);
        }
    }

    static public void main(String[] args) {
        new CJava().run();
    }
}