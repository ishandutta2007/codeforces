/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 11-12-9
 * Time: 10:48
 * To change this template use File | Settings | File Templates.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class B {

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

    boolean checkRec(Point[] qs) {
        qs = Geometry.convexHull(qs);
        if (qs.length != 4)
            return false;
        for (int i = 0; i < 4; i++) {
            if (Geometry.sign(qs[(i + 1) % 4].sub(qs[i]).dot(qs[(i + 2) % 4].sub(qs[(i + 1) % 4]))) != 0)
                return false;
        }
        if (Geometry.sign(Geometry.area(qs)) == 0)
            return false;
        return true;
    }

    boolean checkSquare(Point[] qs) {
        if (!checkRec(qs))
            return false;
        qs = Geometry.convexHull(qs);
        double d1 = qs[0].sub(qs[1]).abs();
        double d2 = qs[2].sub(qs[1]).abs();
//        writer.println(d1 + " " + d2);
        if (Geometry.sign(d1 - d2) == 0)
            return true;
        return false;
    }

    void solve() throws IOException {
        Point[] ps = new Point[8];
        for (int i = 0; i < 8; i++) {
            ps[i] = new Point(nextInt(), nextInt());
        }

        for (int squareSet = 0; squareSet < (1 << 8); squareSet++) {
            if (Integer.bitCount(squareSet) != 4)
                continue;
            int recSet = (1 << 8) - 1 - squareSet;

            Point[] qs = new Point[4];
            int cur = 0;
            for (int i = 0; i < 8; i++) {
                if ((squareSet >> i & 1) > 0)
                    qs[cur++] = ps[i];
            }
            Point[] rs = new Point[4];
            cur = 0;
            for (int i = 0; i < 8; i++) {
                if ((recSet >> i & 1) > 0)
                    rs[cur++] = ps[i];
            }

            if (checkSquare(qs) && checkRec(rs)) {
                writer.println("YES");
                for (int i = 0; i < 8; i++) {
                    if ((squareSet >> i & 1) > 0)
                        writer.print((i + 1) + " ");
                }
                writer.println();
                for (int i = 0; i < 8; i++) {
                    if ((recSet >> i & 1) > 0)
                        writer.print((i + 1) + " ");
                }
                writer.println();
                return;
            }
        }
        writer.println("NO");
    }

    static public void main(String[] args) {
        new B().run();
    }
}


class Geometry {
    static final double EPS = 1e-6;

    static int sign(double x) {
        return x < -EPS ? -1 : x > EPS ? 1 : 0;
    }

    static double cross(Point p1, Point p2, Point p3) {
        return p2.sub(p1).det(p3.sub(p2));
    }

    static int crossOp(Point p1, Point p2, Point p3) {
        return sign(cross(p1, p2, p3));
    }

    static boolean isII(double l, double r, double L, double R) {
        if (l > r) {
            double t = l;
            l = r;
            r = t;
        }
        if (L > R) {
            double t = L;
            L = R;
            R = t;
        }
        return !(l > R + EPS || L > r + EPS);
    }

    static boolean crsSS(Point p1, Point p2, Point q1, Point q2) {
        return isII(p1.x, p2.x, q1.x, q2.x) && isII(p1.y, p2.y, q1.y, q2.y) &&
                crossOp(p1, p2, q1) * crossOp(p1, p2, q2) <= 0 && crossOp(q1, q2, p1) * crossOp(q1, q2, p2) <= 0;
    }

    static boolean crsSSS(Point p1, Point p2, Point q1, Point q2) {//strict
        return crossOp(p1, p2, q1) * crossOp(p1, p2, q2) < 0 && crossOp(q1, q2, p1) * crossOp(q1, q2, p2) < 0;
    }

    static Point[] isCL(Point c, double r, Point p1, Point p2) {
        double x = p1.sub(c).dot(p2.sub(p1));
        double y = p2.sub(p1).abs2();
        double d = x * x - y * (p1.sub(c).abs2() - r * r);
        if (d < -EPS) return new Point[0];
        if (d < 0) d = 0;
        Point q1 = p1.sub(p2.sub(p1).mul(x / y));
        Point q2 = p2.sub(p1).mul(Math.sqrt(d) / y);
        return new Point[]{q1.sub(q2), q1.add(q2)};
    }

    static Point[] isCC(Point c1, double r1, Point c2, double r2) {
        double x = c1.sub(c2).abs2();
        if (x < EPS)
            return new Point[0];
        double y = ((r1 * r1 - r2 * r2) / x + 1) / 2;
        double d = r1 * r1 / x - y * y;
        if (d < -EPS) return new Point[0];
        if (d < 0) d = 0;
        Point q1 = c1.add(c2.sub(c1).mul(y));
        Point q2 = c2.sub(c1).mul(Math.sqrt(d)).rot90();
        return new Point[]{q1.sub(q2), q1.add(q2)};
    }

    static double disLP(Point p1, Point p2, Point q) {
        return Math.abs(p2.sub(p1).det(q.sub(p1))) / p2.sub(p1).abs();
    }

    static double disSP(Point p1, Point p2, Point q) {
        if (p2.sub(p1).dot(q.sub(p1)) < EPS)
            return p1.sub(q).abs();
        if (p1.sub(p2).dot(q.sub(p2)) < EPS)
            return p2.sub(q).abs();
        return disLP(p1, p2, q);
    }

    static int conPS(Point[] ps, Point q) {
        int n = ps.length;
        int res = -1;
        for (int i = 0; i < n; i++) {
            Point a = ps[i].sub(q), b = ps[(i + 1) % n].sub(q);
            if (a.y > b.y) {
                Point t = a;
                a = b;
                b = t;
            }
            if (a.y < EPS && b.y > EPS && a.det(b) > EPS)
                res = -res;
            if (Math.abs(a.det(b)) < EPS && a.dot(b) < EPS) return 0;
        }
        return res;
    }

    static Point[] convexHull(Point[] ps) {
        int n = ps.length, k = 0;
        if (n <= 1)
            return ps;
        Arrays.sort(ps);
        Point[] qs = new Point[n * 2];
        for (int i = 0; i < n; qs[k++] = ps[i++]) {
            while (k > 1 && crossOp(qs[k - 2], qs[k - 1], ps[i]) <= 0)
                --k;
        }

        for (int i = n - 2, t = k; i >= 0; qs[k++] = ps[i--]) {
            while (k > t && crossOp(qs[k - 2], qs[k - 1], ps[i]) <= 0)
                --k;
        }
        Point[] res = new Point[k - 1];
        System.arraycopy(qs, 0, res, 0, k - 1);
        return res;
    }

    static Point isLL(Point p1, Point p2, Point q1, Point q2) {
        double a1 = cross(p1, p2, q1), a2 = -cross(p1, p2, q2);
        if (Math.abs(a1 + a2) < EPS)
            return null;
        return q1.mul(a2).add(q2.mul(a1)).div(a1 + a2);
    }

    static double area(Point[] ps) {
        double ret = 0;
        for (int i = 0; i < ps.length; i++) {
            ret += ps[i].det(ps[(i + 1) % 4]);
        }
        return Math.abs(ret / 2);
    }
}

class Point implements Comparable<Point> {
    double x, y;

    public int compareTo(Point o) {
        int t = Geometry.sign(x - o.x);
        if (t != 0)
            return t;
        return Geometry.sign(y - o.y);
    }

    @Override
    public String toString() {
        return "Point{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }

    Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    Point add(Point o) {
        return new Point(x + o.x, y + o.y);
    }

    Point sub(Point o) {
        return new Point(x - o.x, y - o.y);
    }

    Point mul(double o) {
        return new Point(x * o, y * o);
    }

    Point div(double o) {
        return new Point(x / o, y / o);
    }

    Point unit() {
        return div(abs());
    }

    double dot(Point o) {
        return x * o.x + y * o.y;
    }

    double det(Point o) {
        return x * o.y - y * o.x;
    }

    double alpha() {
        return Math.atan2(y, x);
    }

    double abs2() {
        return x * x + y * y;
    }

    double abs() {
        return Math.hypot(x, y);
    }

    Point rot90() {
        return new Point(-y, x);
    }

    static Point alphaUnit(double a) {
        return new Point(Math.cos(a), Math.sin(a));
    }
}