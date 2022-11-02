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

import java.util.StringTokenizer;

public class C {

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
        String com = nextToken();
        int nChange = nextInt();

        int maxDist = com.length() + 3;
        boolean[][][] am = new boolean[maxDist * 2][nChange + 1][2];
        am[maxDist][0][0] = true;

        for (int i = 0; i < com.length(); i++) {
            boolean[][][] nam = new boolean[maxDist * 2][nChange + 1][2];
            for (int j = 0; j < am.length; j++) {
                for (int k = 0; k <= nChange; k++) {
                    for (int l = 0; l < 2; l++) {
                        if (am[j][k][l]) {
                            if (com.charAt(i) == 'F') {
                                nam[j + (l == 0 ? 1 : -1)][k][l] = true;
                                if (k < nChange)
                                    nam[j][k + 1][1 - l] = true;
                            } else {
                                nam[j][k][1 - l] = true;
                                if (k < nChange)
                                    nam[j + (l == 0 ? 1 : -1)][k + 1][l] = true;
                            }
                        }
                    }
                }
            }
            am = nam;
        }

        int ans = 0;
        for (int j = 0; j < am.length; j++) {
            for (int k = 0; k <= nChange; k++) {
                for (int l = 0; l < 2; l++) {
                    if (am[j][k][l] && (k % 2 == nChange % 2)) {
                        ans = Math.max(ans, Math.abs(j - maxDist));
                    }
                }
            }
        }

        writer.println(ans);
    }

    static public void main(String[] args) {
        new C().run();
    }
}