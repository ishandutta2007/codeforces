/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 11-12-24
 * Time: 7:56
 * To change this template use File | Settings | File Templates.
 */

import java.io.*;
import java.util.*;

public class b {

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
        String a = nextToken();
        int[] cnt = new int[10];
        for (char c : a.toCharArray()) {
            cnt[c - '0']++;
        }

        //justzero
        int maxLast = -1;
        int maxZero = cnt[0];

        for (int lastA = 1; lastA < 10; lastA++) {
            int lastB = 10 - lastA;
            int[] haveA = cnt.clone();
            int[] haveB = cnt.clone();
            if (haveA[lastA] == 0 || haveB[lastB] == 0)
                continue;
            --haveA[lastA];
            --haveB[lastB];
            int zero = 1;

            for (int i = 0; i < 10; i++) {
                int min = Math.min(haveA[i], haveB[9 - i]);
                zero += min;
                haveA[i] -= min;
                haveB[9 - i] -= min;
            }

            int min = Math.min(haveA[0], haveB[0]);
            haveA[0] -= min;
            haveB[0] -= min;
            zero += min;

            if (zero > maxZero) {
                maxZero = zero;
                maxLast = lastA;
            }
        }

        if (maxLast == -1) {
            StringBuilder sb = new StringBuilder();
            for (int i = 10 - 1; i >= 0; i--) {
                for (int j = 0; j < cnt[i]; j++) {
                    sb.append((char) ('0' + i));
                }
            }
            String ret = sb.toString();
            writer.println(ret);
            writer.println(ret);
            return;
        }

        {
            int lastA = maxLast;
            int lastB = 10 - lastA;
            int[] haveA = cnt.clone();
            int[] haveB = cnt.clone();
            StringBuilder sba = new StringBuilder(), sbb = new StringBuilder();

            --haveA[lastA];
            --haveB[lastB];
            sba.append((char) ('0' + lastA));
            sbb.append((char) ('0' + lastB));
            int zero = 1;

            for (int i = 0; i < 10; i++) {
                int min = Math.min(haveA[i], haveB[9 - i]);
                zero += min;
                for (int j = 0; j < min; j++) {
                    sba.append((char) ('0' + i));
                    sbb.append((char) ('0' + 9 - i));
                }
                haveA[i] -= min;
                haveB[9 - i] -= min;
            }


            int min = Math.min(haveA[0], haveB[0]);
            haveA[0] -= min;
            haveB[0] -= min;
            zero += min;

            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < haveA[i]; j++) {
                    sba.append((char) ('0' + i));
                }
                for (int j = 0; j < haveB[i]; j++) {
                    sbb.append((char) ('0' + i));
                }
            }

            sba = sba.reverse();
            sbb = sbb.reverse();

            for (int j = 0; j < min; j++) {
                sba.append('0');
                sbb.append('0');
            }

            writer.println(sba);
            writer.println(sbb);
        }
    }

    static public void main(String[] args) {
        new b().run();
    }
}