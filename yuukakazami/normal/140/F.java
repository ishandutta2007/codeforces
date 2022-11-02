/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 12-1-4
 * Time: 10:57
 * To change this template use File | Settings | File Templates.
 */

import java.io.*;
import java.util.*;

public class f {

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

    class Point implements Comparable<Point> {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int compareTo(Point o) {
            if (x != o.x)
                return x - o.x;
            return y - o.y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Point)) return false;

            Point point = (Point) o;

            if (x != point.x) return false;
            if (y != point.y) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = x;
            result = 31 * result + y;
            return result;
        }
    }

    void solve() throws IOException {
        int n = nextInt(), k = nextInt();
        if (k >= n) {
            System.out.println("-1");
            return;
        }
        Point[] ps = new Point[n];
        for (int i = 0; i < n; i++) {
            ps[i] = new Point(nextInt(), nextInt());
        }
        Arrays.sort(ps);

        Set<Point> ans = new HashSet<Point>();

        for (int a = 0; a <= k; a++) {
            for (int b = 0; a + b <= k; b++) {
                int l = a, r = n - b - 1;
                int rem = k - a - b;

                int mx = ps[l].x + ps[r].x, my = ps[l].y + ps[r].y;
                Point p = new Point(mx, my);

                if (ans.contains(p))
                    continue;

                boolean[] ok = new boolean[n];

                int j = r;

                for (int i = l; i <= r; i++) {
                    while (j >= l && (ps[i].x + ps[j].x > mx || (ps[i].x + ps[j].x == mx && ps[i].y + ps[j].y > my)))
                        --j;
                    if (j < l)
                        break;
                    if (ps[i].x + ps[j].x == mx && ps[i].y + ps[j].y == my)
                        ok[i] = ok[j] = true;
                }

                for (int i = l; i <= r; i++) {
                    if (!ok[i])
                        --rem;
                }

                if (rem >= 0)
                    ans.add(p);
            }
        }

        writer.println(ans.size());

        for (Point p : ans) {
            writer.format("%.3f %.3f\n", 0.5 * p.x, 0.5 * p.y);
        }
    }

    static public void main(String[] args) {
        new f().run();
    }
}