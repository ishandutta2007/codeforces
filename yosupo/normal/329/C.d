import std.datetime;
import std.stdio;
import std.range;
import std.random;
import std.algorithm;

int main() {
    StopWatch sw;
    sw.start();
    int n, m;
    scanf("%d %d", &n, &m);
    int[][] g = new int[][](n);
    foreach (i; 0..m) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        g[a] ~= b;
        g[b] ~= a;
    }
    foreach (i; 0..n) {
        sort(g[i]);
    }
    auto a = iota(n).array;
    auto rnd = Random(unpredictableSeed);
    while (true) {
        randomShuffle(a, rnd);
        int c = 0;
        foreach (i; 0..n) {
            int l = a[i], r = a[(i+1)%n];
            if (!assumeSorted(g[l]).canFind(r)) {
                c++;
            }
        }
        if (c >= m) {
            c = 0;
            foreach (i; 0..n) {
                int l = a[i], r = a[(i+1)%n];
                if (!assumeSorted(g[l]).canFind(r)) {
                    writef("%d %d\n", l+1, r+1);
                    c++;
                    if (c == m) break;
                }
            }
            return 0;
        }
        if (sw.peek().msecs > 1000) {
            break;
        }
    }
    writeln("-1");
    return 0;
}