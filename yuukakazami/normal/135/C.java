/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 11-12-9
 * Time: 10:36
 * To change this template use File | Settings | File Templates.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

import java.util.StringTokenizer;
import java.util.TreeSet;

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

    String evaluate(String s) {
        int n = s.length();

        int atL = 0, atR = 0;
        boolean[] mark = new boolean[n];

        for (int i = 0; i < n - 2; i++) {
            if (i % 2 == 0) {
                while (atL < n && s.charAt(atL) == '0')
                    ++atL;
                if (atL == n)
                    return "00";
                mark[atL] = true;
                ++atL;
            } else {
                while (atR < n && s.charAt(atR) == '1')
                    ++atR;
                if (atR == n)
                    return "11";
                mark[atR] = true;
                ++atR;
            }
        }

        String res = "";
        for (int i = 0; i < n; i++) {
            if (!mark[i])
                res = res + s.charAt(i);
        }

        return res;
    }

    int[] prepareSum(String s, char ch) {
        int n = s.length();
        int[] sum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + (s.charAt(i) == ch ? 1 : 0);
        }
        return sum;
    }

    int[] getAll(String s, char ch) {
        int cnt = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == ch)
                ++cnt;
        }

        int[] my = new int[cnt];
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == ch)
                my[cur++] = i;
        }

        return my;
    }

    int calc(int[] sum, int l, int r) {//[l,r]
        return sum[r + 1] - sum[l];
    }

    void solve() throws IOException {
        TreeSet<String> results = new TreeSet<String>();
        String s = nextToken();

//        int[] sumUnKnow = prepareSum(input, '?');
//        int[] sumOne = prepareSum(input, '1');
//        int[] sumZero = prepareSum(input, '0');
//
//        int[] myUnKnow = getAll(input, '?');
//        int[] myOne = getAll(input, '1');
//        int[] myZero = getAll(input, '0');
//
//        int n = input.length();
//
//        int minMove = 0, maxMove = 0;
//        for (int i = 0; i < n - 2; i++) {
//            if (i % 2 == 0)
//                minMove++;
//            else
//                maxMove
//        }

        results.add(evaluate(s.replace('?', '0')));
        results.add(evaluate(s.replace('?', '1')));

        //10
        int left = 0, right = s.length();
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            String t = evaluate(s.substring(0, mid).replace('?', '1') + s.substring(mid).replace('?', '0'));
            if (t.equals("10")) {
                results.add(t);
                break;
            } else {
                if (t.equals("00")) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
        }

        //01
        left = 0;
        right = s.length();
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            String t = evaluate(s.substring(0, mid).replace('?', '0') + s.substring(mid).replace('?', '1'));
            if (t.equals("01")) {
                results.add(t);
                break;
            } else {
                if (t.equals("00")) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
        }

        for (String result : results) {
            writer.println(result);
        }
    }

    static public void main(String[] args) {
        new C().run();
    }
}