    import java.util.*;
    import java.math.*;
    import java.io.*;

    public class Equation {
        private void solve() throws IOException {

            double a = nextInt();
            double b = nextInt();
            double c = nextInt();

            if (a == 0) {
                double r = -c / b;
                if (Double.isNaN(r)) {
                    System.out.println(-1);
                    return;
                }
                if (Double.isInfinite(r)) {
                    System.out.println(0);
                    return;
                }
                System.out.println(1);
                System.out.printf("%.5f\n", Double.isNaN(r) ? -1 : r);
                return;
            }
            double momaiaz, root1, root2;

            momaiaz = (b * b) - (4 * a * c);

            if (Double.isNaN(momaiaz)) {
                System.out.println(0);
                return;
            }

            if (momaiaz > 0) {
                root1 = (-b + Math.sqrt(momaiaz)) / (2 * a);
                root2 = (-b - Math.sqrt(momaiaz)) / (2 * a);
                System.out.println(2);
                System.out.printf("%.5f\n", Math.min(root1, root2));
                System.out.printf("%.5f\n", Math.max(root1, root2));
                return;
            }

            if (momaiaz == 0) {
                root1 = (-b) / (2 * a);
                System.out.println(1);
                System.out.printf("%.5f\n", root1);
                return;
            }
           
            System.out.println(0);
        }

        public static void main(String[] args) {
            new Equation().run();
        }

        BufferedReader reader;
        StringTokenizer tokenizer;
        PrintWriter writer;

        public void run() {
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

        int[] readIntArray(int size) throws IOException {
            int[] res = new int[size];
            for (int i = 0; i < size; i++) {
                res[i] = nextInt();
            }
            return res;
        }

        long[] readLongArray(int size) throws IOException {
            long[] res = new long[size];
            for (int i = 0; i < size; i++) {
                res[i] = nextLong();
            }
            return res;
        }

        double[] readDoubleArray(int size) throws IOException {
            double[] res = new double[size];
            for (int i = 0; i < size; i++) {
                res[i] = nextDouble();
            }
            return res;
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

        BigInteger nextBigInteger() throws IOException {
            return new BigInteger(nextToken());
        }

        String nextToken() throws IOException {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }
    }