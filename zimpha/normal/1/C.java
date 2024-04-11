import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Xi Lin
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            double x[] = new double[3];
            double y[] = new double[3];
            for (int i = 0; i < 3; i++) {
                x[i] = in.nextDouble();
                y[i] = in.nextDouble();
            }
            double d[] = new double[3];
            for (int i = 0; i < 3; ++i) {
                d[i] = dis(x[i], y[i], x[(i + 1) % 3], y[(i + 1) % 3]);
            }
            Arrays.sort(d);
            double p = (d[0] + d[1] + d[2]) / 2;
            double s = Math.sqrt(p * (p - d[0]) * (p - d[1]) * (p - d[2]));
            double r = d[0] * d[1] * d[2] / s * 0.25;
            double pi = Math.acos(-1.0);
            double A = Math.acos(1 - 0.5 * d[0] * d[0] / (r * r)) * 180 / pi;
            double B = Math.acos(1 - 0.5 * d[1] * d[1] / (r * r)) * 180 / pi;
            double C = 360 - A - B;
            double n = 360 / fgcd(A, fgcd(B, C));
            out.printf("%.10f\n", 0.5 * n * r * r * Math.sin(2 * pi / n));
        }

        private double fgcd(double a, double b) {
            if (Math.abs(a) < 1e-2) return b;
            if (Math.abs(b) < 1e-2) return a;
            return fgcd(b, a - b * Math.floor(a / b));
        }

        double dis(double x1, double y1, double x2, double y2) {
            return Math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
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

        public double nextDouble() {
            return Double.parseDouble(next());
        }

    }
}