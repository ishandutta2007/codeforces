/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 11-11-25
 * Time: 10:58
 * To change this template use File | Settings | File Templates.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

import java.util.*;

public class E {

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

    class Queen implements Comparable<Queen> {
        int r, c;
        int cnt = 0;

        Queen(int r, int c) {
            this.r = r;
            this.c = c;
        }

        public int compareTo(Queen o) {
            if (r != o.r)
                return r - o.r;
            return c - o.c;
        }
    }

    void solve() throws IOException {
        int n = nextInt(), nQ = nextInt();
        Queen[] queens = new Queen[nQ];
        for (int i = 0; i < queens.length; i++) {
            queens[i] = new Queen(nextInt() - 1, nextInt() - 1);
        }
        //row
        List<List<Queen>> byRow = new ArrayList<List<Queen>>();
        List<List<Queen>> byCol = new ArrayList<List<Queen>>();
        List<List<Queen>> byAdd = new ArrayList<List<Queen>>();
        List<List<Queen>> bySub = new ArrayList<List<Queen>>();
        for (int i = 0; i < n * 2 + 2; i++) {
            byRow.add(new ArrayList<Queen>());
            byCol.add(new ArrayList<Queen>());
            byAdd.add(new ArrayList<Queen>());
            bySub.add(new ArrayList<Queen>());
        }
        for (Queen q : queens) {
            byRow.get(q.r).add(q);
            byCol.get(q.c).add(q);
            byAdd.get(q.r + q.c).add(q);
            bySub.get(q.r - q.c + n).add(q);
        }

        for (List<Queen> qs : byRow) {
            if (qs.size() <= 1)
                continue;
            Collections.sort(qs);
            for (int i = 0; i < qs.size(); i++) {
                qs.get(i).cnt += (i == 0 || i == qs.size() - 1) ? 1 : 2;
            }
        }

        for (List<Queen> qs : byCol) {
            if (qs.size() <= 1)
                continue;
            Collections.sort(qs);
            for (int i = 0; i < qs.size(); i++) {
                qs.get(i).cnt += (i == 0 || i == qs.size() - 1) ? 1 : 2;
            }
        }

        for (List<Queen> qs : byAdd) {
            if (qs.size() <= 1)
                continue;
            Collections.sort(qs);
            for (int i = 0; i < qs.size(); i++) {
                qs.get(i).cnt += (i == 0 || i == qs.size() - 1) ? 1 : 2;
            }
        }

        for (List<Queen> qs : bySub) {
            if (qs.size() <= 1)
                continue;
            Collections.sort(qs);
            for (int i = 0; i < qs.size(); i++) {
                qs.get(i).cnt += (i == 0 || i == qs.size() - 1) ? 1 : 2;
            }
        }

        int[] ans = new int[9];

        for (Queen q : queens) {
            ans[q.cnt]++;
        }

        for (int i : ans) {
            writer.print(i + " ");
        }
        writer.println();
    }

    static public void main(String[] args) {
        new E().run();
    }
}