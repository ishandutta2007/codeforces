import std.stdio, std.conv, std.string, std.algorithm, std.range;
import std.datetime, std.numeric, std.random;

int main() {
    StopWatch sw;
    sw.start();
    auto gen = Random(unpredictableSeed);
    int n;
    readf("%d\n", &n);
    auto a = readln().split().map!(to!long).array;
    auto b = new long[20000];
    auto num = new int[20000];
    auto res = 0L;
    auto loop = 0L;
    while (sw.peek().msecs < 3000 && loop < 20) {
        loop += 1;
        auto k = a[uniform(0, n, gen)];
        b.length = 20000;
        //b.length = 0;
        auto id = 0;
        for (auto i = 1L; i*i <= k; i++) {
            if (!(k%i)) {
                b[id++] = i;
//                b ~= i;
                if (i*i != k) {
                    b[id++] = k/i;
//                    b ~= k/i;
                }
            }
        }
        b.length = id;

        b.sort;
        num.length = b.length;
        num[] = 0;
        foreach (int i, d; a) {
            auto dd = gcd(d, k);
            num[assumeSorted(b).lowerBound(dd).length]++;
        }
        foreach_reverse (i; 0..b.length) {
            if (b[i] <= res) break;
            auto count = 0;
            foreach (j; i..b.length) {
                if (!(b[j]%b[i])) {
                    count += num[j];
                }
            }
            if (count >= (n+1)/2) {
                res = max(res, b[i]);
            }
        }
    }
    writeln(res);
    return 0;
}