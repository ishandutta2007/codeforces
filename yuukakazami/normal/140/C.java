/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 12-1-4
 * Time: 10:57
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

    class Number implements Comparable<Number> {
        int value;
        int cnt;

        Number(int value, int cnt) {
            this.value = value;
            this.cnt = cnt;
        }

        public int compareTo(Number o) {
            return -cnt + o.cnt;
        }
    }

    void solve() throws IOException {
        int n = nextInt();

        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < n; i++) {
            int r = nextInt();
            if (map.containsKey(r))
                map.put(r, map.get(r) + 1);
            else
                map.put(r, 1);
        }

        PriorityQueue<Number> pq = new PriorityQueue<Number>();
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            pq.add(new Number(entry.getKey(), entry.getValue()));
        }

        List<int[]> ans = new ArrayList<int[]>();
        outer:
        for (; ; ) {
            if (pq.size() < 3)
                break;
            int[] me = new int[3];
            Number[] cur = new Number[3];

            for (int i = 0; i < 3; i++) {
                cur[i] = pq.poll();
                cur[i].cnt--;
                me[i] = cur[i].value;
            }

            ans.add(me);

            for (Number number : cur) {
                if (number.cnt > 0)
                    pq.add(number);
            }
        }

        writer.println(ans.size());

        for (int[] an : ans) {
            Arrays.sort(an);
            for (int i = an.length - 1; i >= 0; i--) {
                writer.print(an[i] + " ");
            }
            writer.println();
        }
    }

    static public void main(String[] args) {
        new c().run();
    }
}