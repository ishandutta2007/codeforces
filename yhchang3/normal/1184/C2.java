//package com.company;
// Always comment out package when submitting.

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static class Task {

        int[] mapCoord(int[] original) {
            int x = original[0], y = original[1];
            return new int[]{x - y, x + y + 2_000_000};
        }

        class SegmentTree {
            int n;
            int[] nodes;
            int[] lazy;
            public SegmentTree(int n) {
                this.n = n;
                int y = 1;
                while (y < n) y *= 2;
                y *= 2;
                nodes = new int[y];
                lazy = new int[y];
            }
            public void push(int l, int r, int idx) {
                if (lazy[idx] != 0) {
                    int mid = (l + r) / 2;
                    lazy[idx << 1] += lazy[idx];
                    nodes[idx << 1] += lazy[idx];
                    lazy[idx << 1 | 1] += lazy[idx];
                    nodes[idx << 1 | 1] += lazy[idx];
                    lazy[idx] = 0;
                }
            }
            public void add(int L, int R, int v) {
                add(0, n, 1 , L, R, v);
            }

            public void add(int l, int r, int idx, int L, int R, int v) {
                if (L <= l && r <= R) {
                    lazy[idx] += v;
                    nodes[idx] += v;
                    return;
                }
                if (L >= r || l >= R) return;
                push(l, r, idx);
                int mid = (l + r) / 2;
                add(l, mid, idx << 1, L, R, v);
                add(mid, r, idx << 1 | 1, L ,R, v);
                nodes[idx] = Math.max(nodes[idx << 1], nodes[idx << 1 | 1]);
            }

            public int query(int L, int R) {
                return query(0, n, 1, L, R);
            }

            public int query(int l, int r, int idx, int L, int R) {
                if (L <= 1 && r <= R) {
                    return nodes[idx];
                }
                if (L >= r || l >= R) return 0;
                push(l, r, idx);
                int mid = (l + r) / 2;
                return Math.max(query(l, mid, idx << 1, L, R), query(mid, R, idx << 1 | 1, L, R));
            }

        }

        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            int n = sc.nextInt();
            int r = sc.nextInt();
            int[][] points = new int[n][2];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 2; j++) {
                    points[i][j] = sc.nextInt();
                }
            }
            for (int i = 0; i < n; i++) {
                points[i] = mapCoord(points[i]);
            }
            Arrays.sort(points, new Comparator<int[]>() {
                @Override
                public int compare(int[] o1, int[] o2) {
                    return o1[0] - o2[0];
                }
            });
            int s = 1 << 22;
            SegmentTree st = new SegmentTree(s);
            int lastIdx = 0;
            int best = 0;
            for (int i = 0; i < n; i++) {
                while (lastIdx < i && points[i][0] > points[lastIdx][0] + 2 * r) {
                    // delete
                    st.add(Math.max(0, points[lastIdx][1] - 2 * r), points[lastIdx][1] + 1, -1);
                    lastIdx++;
                }
                //add
                st.add(Math.max(0, points[i][1] - 2 * r), points[i][1] + 1, 1);
                int mm = st.query(0, s);
                best = Math.max(best, mm);
            }
            pw.println(best);
        }
    }

    // template, actual code is in class Task.
    static long TIME_START, TIME_END;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
//        Scanner sc = new Scanner(new FileInputStream("class_treasurer.txt"));
        PrintWriter pw = new PrintWriter(new BufferedOutputStream(System.out));
//        PrintWriter pw = new PrintWriter(new FileOutputStream("Test.out"));

        Runtime runtime = Runtime.getRuntime();
        long usedMemoryBefore = runtime.totalMemory() - runtime.freeMemory();
        TIME_START = System.currentTimeMillis();
        Task t = new Task();
        t.solve(sc, pw);
        TIME_END = System.currentTimeMillis();
        long usedMemoryAfter = runtime.totalMemory() - runtime.freeMemory();
        pw.close();
//        System.err.println("Memory increased: " + (usedMemoryAfter - usedMemoryBefore) / 1000000);
//        System.err.println("Time used: " + (TIME_END - TIME_START) + ".");
    }

    // Faster IO with BufferedReader wrapped with Scanner
    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public Scanner(FileReader s) throws FileNotFoundException {
            br = new BufferedReader(s);
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public String nextLine() throws IOException {
            return br.readLine();
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        public boolean ready() throws IOException {
            return br.ready();
        }
    }
}