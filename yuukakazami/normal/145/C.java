/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 12-1-26
 * Time: 2:03
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

    boolean is(int x) {
        while (x > 0) {
            int d = x % 10;
            if (d != 4 && d != 7)
                return false;
            x /= 10;
        }
        return true;
    }

    public static final int MOD = 1000000007;

    void solve() throws IOException {
        int n = nextInt(), k = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < a.length; i++) {
            a[i] = nextInt();
        }
        boolean[] luck = new boolean[n];
        int nUnLucky = 0;
        Map<Integer, Integer> cnt = new HashMap<Integer, Integer>();
        for (int i = 0; i < n; i++) {
            luck[i] = is(a[i]);
            if (!luck[i])
                ++nUnLucky;
            else if (cnt.containsKey(a[i]))
                cnt.put(a[i], cnt.get(a[i]) + 1);
            else
                cnt.put(a[i], 1);
        }
        //all unlucky
        fact = LongUtils.buildFactorials(n + 1, MOD);
        rfact = LongUtils.buildInverses(fact, MOD);

        long[] am = new long[cnt.size() + 1];
        am[0] = 1;
        for (Integer i : cnt.values()) {
            long[] nam = new long[cnt.size() + 1];
            for (int j = 0; j < am.length; j++) {
                nam[j] += am[j];
                nam[j] %= MOD;
                if (j + 1 < am.length) {
                    nam[j + 1] += am[j] * i % MOD;
                    nam[j + 1] %= MOD;
                }
            }
            am = nam;
        }

        long ans = 0;
        for (int i = 0; i <= cnt.size() && i <= k; i++) {
            ans += am[i] * comb(nUnLucky, k - i) % MOD;
            ans %= MOD;
        }
        System.out.println(ans);
    }

    long[] fact, rfact;

    long comb(int n, int m) {
        if (m > n) return 0;
        return fact[n] * rfact[m] % MOD * rfact[n - m] % MOD;
    }

    static public void main(String[] args) {
        new c().run();
    }
}


class LongUtils {
    static int sign(long x) {
        return x < 0 ? -1 : x > 0 ? 1 : 0;
    }

    static int compare(long a, long b) {
        return a < b ? -1 : a > b ? 1 : 0;
    }

    static long gcd(long a, long b) {
        while (b != 0) {
            long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    static long[][] generateBinomialCoefficients(int n) {
        long[][] c = new long[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            c[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            }
        }
        return c;
    }

    static long[][] generateBinomialCoefficients(int n, long module) {
        long[][] c = new long[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            c[i][0] = 1 % module;
            for (int j = 1; j <= i; j++) {
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
                if (c[i][j] >= module)
                    c[i][j] -= module;
            }
        }
        return c;
    }

    static boolean isPrime(long x) {
        if (x == 1)
            return false;
        for (long i = 2; i * i <= x; i++)
            if (x % i == 0)
                return false;
        return true;
    }


    static long[] toLongArr(Long[] longs) {
        long[] arr = new long[longs.length];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = longs[i];
        }
        return arr;
    }

    static Long[] toLongArr(long[] a) {
        Long[] arr = new Long[a.length];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = a[i];
        }
        return arr;
    }

    static long factorial(int n) {
        long ret = 1;
        for (int i = 2; i <= n; i++) {
            ret *= i;
        }
        return ret;
    }

    static long factorial(int n, long module) {
        long ret = 1;
        for (int i = 2; i <= n; i++) {
            ret = ret * i % module;
        }
        return ret;
    }

    static long pow(long x, long e, long module) {
        if (e == 0)
            return 1 % module;
        return e % 2 == 0 ? pow(x * x % module, e >> 1, module) : pow(x, e - 1, module) * x % module;
    }

    static long inverse(long x, long module) {
        return pow(x, module - 2, module);
    }

    static long[] buildInverses(int n, long module) {//1..n
        long[] a = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            a[i] = inverse(i, module);
        }
        return a;
    }

    static long[] buildFactorials(int n, long module) {//1..n
        long[] a = new long[n + 1];
        a[0] = 1;

        for (int i = 1; i <= n; i++) {
            a[i] = a[i - 1] * i % module;
        }

        return a;
    }

    static long[] buildInverses(long[] a, long module) {
        long[] ret = new long[a.length];
        for (int i = 0; i < ret.length; i++) {
            ret[i] = inverse(a[i], module);
        }
        return ret;
    }

    static void swap(long[] arr, int a, int b) {
        long t = arr[a];
        arr[a] = arr[b];
        arr[b] = t;
    }

    static void reverse(long[] arr) {
        for (int l = 0, r = arr.length - 1; l < r; l++, r--)
            swap(arr, l, r);
    }

    static long max(Object obj) {
        long ret = Long.MIN_VALUE;
        if (obj instanceof long[]) {
            long[] a = (long[]) obj;
            for (long i : a) {
                if (i > ret)
                    ret = i;
            }
        } else if (obj instanceof Object[]) {
            Object[] a = (Object[]) obj;
            for (Object o : a) {
                ret = Math.max(ret, max(o));
            }
        } else throw new IllegalArgumentException();

        return ret;
    }

    static long min(Object obj) {
        long ret = Long.MAX_VALUE;
        if (obj instanceof long[]) {
            long[] a = (long[]) obj;
            for (long i : a) {
                if (i < ret)
                    ret = i;
            }
        } else if (obj instanceof Object[]) {
            Object[] a = (Object[]) obj;
            for (Object o : a) {
                ret = Math.min(ret, min(o));
            }
        } else throw new IllegalArgumentException();
        return ret;
    }

    static void fill(Object obj, long x) {
        if (obj instanceof long[]) {
            long[] a = (long[]) obj;
            for (int i = 0; i < a.length; i++) {
                a[i] = x;
            }
        } else if (obj instanceof Object[]) {
            Object[] a = (Object[]) obj;
            for (Object o : a) {
                fill(o, x);
            }
        } else throw new IllegalArgumentException();
    }

    static long sum(Object obj) {
        long ret = 0;
        if (obj instanceof long[]) {
            long[] a = (long[]) obj;
            for (long i : a) {
                ret += i;
            }
        } else if (obj instanceof Object[]) {
            Object[] a = (Object[]) obj;
            for (Object o : a) {
                ret += sum(o);
            }
        } else throw new IllegalArgumentException();
        return ret;
    }


    static long sum(Object obj, long module) {
        long ret = 0;
        if (obj instanceof long[]) {
            long[] a = (long[]) obj;
            for (long i : a) {
                ret += i;
                ret %= module;
                if (ret < 0)
                    ret += module;
            }
        } else if (obj instanceof Object[]) {
            Object[] a = (Object[]) obj;
            for (Object o : a) {
                ret += sum(o, module);
                ret %= module;
                if (ret < 0)
                    ret += module;
            }
        } else throw new IllegalArgumentException();
        return ret;
    }
}