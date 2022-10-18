import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

public class A {
    boolean isblack(int x, int y) {
        int r = x * x + y * y;
//      System.out.println(r);
        for (int i = 0; i < 5000; i++) {
            if (i * i == r) return true;
            if (i * i > r) return (((x > 0) ? 1 : 0) + ((y > 0) ? 1 : 0) + i) % 2 == 1;
        }
        return false;
    }

    private void solve() throws IOException {
        int x = nextInt();
        int y = nextInt();
        if (isblack(x, y)) System.out.println("black");
        else System.out.println("white");
    }

    public static void main(String[] args) {
        new A().run();
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
        }
        catch (Exception e) {
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