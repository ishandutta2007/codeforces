/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 11-12-3
 * Time: 10:40
 * To change this template use File | Settings | File Templates.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class T {

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
        String input = nextToken();
        String[] parts = input.split("[<>]");
        int cnt = 0;
        for (String part : parts)
            if (part.length() > 0) {
                if (part.startsWith("/"))
                    --cnt;
                for (int j = 0; j < cnt * 2; j++) {
                    writer.print(" ");
                }
                writer.println("<" + part + ">");
                if (!part.startsWith("/"))
                    ++cnt;
            }
    }

    static public void main(String[] args) {
        new T().run();
    }
}