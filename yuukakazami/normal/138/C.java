/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 11-12-24
 * Time: 7:56
 * To change this template use File | Settings | File Templates.
 */

import java.io.*;
import java.util.*;

public class c {

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
        int n = nextInt(), m = nextInt();
        int[] a = new int[n], h = new int[n], l = new int[n], r = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
            h[i] = nextInt();
            l[i] = nextInt();
            r[i] = nextInt();
        }

        final int[] b = new int[m], j = new int[m];
        for (int i = 0; i < m; i++) {
            b[i] = nextInt();
            j[i] = nextInt();
        }

        Integer[] perm = new Integer[m];
        for (int i = 0; i < m; i++) {
            perm[i] = i;
        }
        Arrays.sort(perm, new Comparator<Integer>() {
            public int compare(Integer o1, Integer o2) {
                return b[o1] - b[o2];  //To change body of implemented methods use File | Settings | File Templates.
            }
        });

        int[] tmp = b.clone();
        for (int i = 0; i < m; i++) {
            b[i] = tmp[perm[i]];
        }

        tmp = j.clone();
        for (int i = 0; i < m; i++) {
            j[i] = tmp[perm[i]];
        }

        int[] cntBad = new int[m + 1];
        double[] sumExp = new double[m + 1];

        for (int i = 0; i < n; i++) {
            //left
            {
                int prob = 100 - l[i];
                int left = a[i] - h[i], right = a[i] - 1;
                int atL = Algorithms.lowerBound(b, left);
                int atR = Algorithms.upperBound(b, right) - 1;
                if (prob == 0) {
                    cntBad[atL]++;
                    cntBad[atR + 1]--;
                } else {
                    double exp = Math.log(prob / 100.0);
                    sumExp[atL] += exp;
                    sumExp[atR + 1] -= exp;
                }
            }

            //right
            {
                int prob = 100 - r[i];
                int left = a[i] + 1, right = a[i] + h[i];
                int atL = Algorithms.lowerBound(b, left);
                int atR = Algorithms.upperBound(b, right) - 1;
                if (prob == 0) {
                    cntBad[atL]++;
                    cntBad[atR + 1]--;
                } else {
                    double exp = Math.log(prob / 100.0);
                    sumExp[atL] += exp;
                    sumExp[atR + 1] -= exp;
                }
            }
        }

        for (int i = 1; i < cntBad.length; i++) {
            cntBad[i] += cntBad[i - 1];
        }

        for (int i = 1; i < sumExp.length; i++) {
            sumExp[i] += sumExp[i - 1];
        }

        double ans = 0;

        for (int i = 0; i < m; i++) {
            if (cntBad[i] > 0) {
                continue;
            }
            double exp = sumExp[i];
            ans += Math.exp(exp) * j[i];
        }

        writer.println(ans);
    }

    static public void main(String[] args) {
        new c().run();
    }
}


class Algorithms {
    static int lowerBound(int[] arr, int x) {//first index >= x
        int l = -1, r = arr.length;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (arr[m] >= x)
                r = m;
            else
                l = m;
        }
        return r;
    }

    static int upperBound(int[] arr, int x) {//first index > x
        int l = -1, r = arr.length;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (arr[m] > x)
                r = m;
            else
                l = m;
        }
        return r;
    }

    static int[] equalRange(int[] arr, int x) {
        return new int[]{lowerBound(arr, x), upperBound(arr, x)};
    }

    static int sortedCount(int[] arr, int x) {
        return upperBound(arr, x) - lowerBound(arr, x);
    }

    static int count(int[] arr, int x) {
        int cnt = 0;
        for (int i : arr) {
            if (x == i)
                ++cnt;
        }
        return cnt;
    }

    static int[] merge(int[] a, int[] b) {
        int ia = 0, ib = 0;
        int[] ret = new int[a.length + b.length];
        int cur = 0;

        while (ia < a.length || ib < b.length) {
            if (ia == a.length)
                ret[cur++] = b[ib++];
            else if (ib == b.length)
                ret[cur++] = a[ia++];
            else if (a[ia] < b[ib])
                ret[cur++] = a[ia++];
            else
                ret[cur++] = b[ib++];
        }

        return ret;
    }

    static int[] unique(int[] arr) {
        int[] tmp = new int[arr.length];
        int cur = 0;
        for (int i : arr) {
            if (cur == 0 || tmp[cur - 1] != i)
                tmp[cur++] = i;
        }
        int[] ret = new int[cur];
        System.arraycopy(tmp, 0, ret, 0, cur);
        return ret;
    }

    static int lowerBound(long[] arr, long x) {//first index >= x
        int l = -1, r = arr.length;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (arr[m] >= x)
                r = m;
            else
                l = m;
        }
        return r;
    }

    static int upperBound(long[] arr, long x) {//first index > x
        int l = -1, r = arr.length;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (arr[m] > x)
                r = m;
            else
                l = m;
        }
        return r;
    }

    static int[] equalRange(long[] arr, long x) {
        return new int[]{lowerBound(arr, x), upperBound(arr, x)};
    }

    static int sortedCount(long[] arr, long x) {
        return upperBound(arr, x) - lowerBound(arr, x);
    }

    static int count(long[] arr, long x) {
        int cnt = 0;
        for (long i : arr) {
            if (x == i)
                ++cnt;
        }
        return cnt;
    }

    static long[] merge(long[] a, long[] b) {
        int ia = 0, ib = 0;
        long[] ret = new long[a.length + b.length];
        int cur = 0;

        while (ia < a.length || ib < b.length) {
            if (ia == a.length)
                ret[cur++] = b[ib++];
            else if (ib == b.length)
                ret[cur++] = a[ia++];
            else if (a[ia] < b[ib])
                ret[cur++] = a[ia++];
            else
                ret[cur++] = b[ib++];
        }

        return ret;
    }

    static long[] unique(long[] arr) {
        long[] tmp = new long[arr.length];
        int cur = 0;
        for (long i : arr) {
            if (cur == 0 || tmp[cur - 1] != i)
                tmp[cur++] = i;
        }
        long[] ret = new long[cur];
        System.arraycopy(tmp, 0, ret, 0, cur);
        return ret;
    }
}