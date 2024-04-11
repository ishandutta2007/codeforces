/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 12-1-12
 * Time: 10:52
 * To change this template use File | Settings | File Templates.
 */

import java.io.*;
import java.util.*;

public class d {

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

    void solve() throws IOException {
        int n = nextInt(), m = nextInt(), k = nextInt();
        String[] lines = new String[n];
        int nR = 0, nG = 0;
        for (int i = 0; i < n; i++) {
            lines[i] = nextToken();
            for (char c : lines[i].toCharArray()) {
                if (c == 'R')
                    ++nR;
                if (c == 'G')
                    ++nG;
            }
        }
        if (nG == 0) {
            System.out.println("Second");
            return;
        }
        boolean cantDieR = false, cantDieG = false;

        if (m == 1) {
            System.out.println("Second");
            return;
        }

        int[] xor = new int[10];

        for (String line : lines) {
            boolean hasR = line.indexOf('R') >= 0, hasG = line.indexOf('G') >= 0;
            if (!hasR && !hasG)
                continue;
            if (hasR && hasG) {
                if (line.indexOf("RG") >= 0 || line.indexOf("GR") >= 0)
                    continue;

                int a = line.indexOf('R'), b = line.indexOf('G');
                int num = Math.abs(a - b) - 1;
                for (int i = 0; i < 10; i++) {
                    xor[i] += num % 2;
                    num /= 2;
                }
                continue;
            }
            if (hasR && !line.equals("RR"))
                cantDieR = true;
            if (hasG && !line.equals("GG"))
                cantDieG = true;
        }

        if (cantDieR && cantDieG) {
            System.out.println("Draw");
            return;
        }

        if (cantDieG) {
            System.out.println("First");
            return;
        }

        if (cantDieR) {
            System.out.println("Second");
            return;
        }

        for (int i : xor) {
            if (i % (k + 1) != 0) {
                System.out.println("First");
                return;
            }
        }
        System.out.println("Second");
    }

    static public void main(String[] args) {
        new d().run();
    }
}