/**
 * Created by IntelliJ IDEA.
 * User: mac
 * Date: 11-12-3
 * Time: 9:30
 * To change this template use File | Settings | File Templates.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

import java.util.ArrayList;
import java.util.List;
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

    class Person implements Comparable<Person> {
        int id, have;

        Person(int have, int id) {
            this.have = have;
            this.id = id;
        }

        public int compareTo(Person o) {
            if (have != o.have)
                return have - o.have;
            return id - o.id;
        }
    }

    void solve() throws IOException {
        int n = nextInt(), s = nextInt();
        int[] have = new int[n];
        for (int i = 0; i < have.length; i++) {
            have[i] = nextInt();
        }

        Person[] persons = new Person[n];
        for (int i = 0; i < persons.length; i++) {
            persons[i] = new Person(have[i], i + 1);
        }

        TreeSet<Person> byHave = new TreeSet<Person>();
        for (Person person : persons) {
            byHave.add(person);
        }

        List<int[]> pairs = new ArrayList<int[]>();

        while (!byHave.isEmpty()) {
            Person me = byHave.last();
            byHave.remove(me);

            List<Person> list = new ArrayList<Person>();
            while (me.have > 0) {
                if (byHave.isEmpty()) {
                    System.out.println("No");
                    return;
                }
                Person pair = byHave.last();
                byHave.remove(pair);
                me.have--;
                if (pair.have == 0) {
                    System.out.println("No");
                    return;
                }
                pair.have--;
                pairs.add(new int[]{me.id, pair.id});
                list.add(pair);
            }

            for (Person p : list) {
                byHave.add(p);
            }
        }

        writer.println("Yes");
        writer.println(pairs.size());
        for (int[] pair : pairs) {
            writer.println(pair[0] + " " + pair[1]);
        }
    }

    static public void main(String[] args) {
        new C().run();
    }
}