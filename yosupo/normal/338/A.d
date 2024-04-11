import std.stdio, std.getopt, std.random, std.range, std.string, std.conv;
import std.algorithm, std.container, std.datetime;

const MD = 10^^9+9;
long powMod(long x, long n, long md) {
    x %= md; n %= md-1;
    long r = 1;
    while (n) {
        if (n & 1) r *= x; r %= md;
        x *= x; x %= md;
        n >>= 1;
    }
    return r;
}
long solve() {
	long n, m, k;
	readf("%d %d %d\n", &n, &m, &k);
	long a = n/k, b = n%k;
	long c = a*(k-1)+b;
	if (m <= c) return m % MD;
	long d = m-c;
	long res = (powMod(2, d+1, MD)-2+MD)*k%MD;
/*	foreach (i; 0..d) {
		res += k;
		res *= 2;
		res %= MD;
	}//2 6 14 30 62 126..*/
	res += m-d*k;
    return res%MD;
}

int main() {
	writeln(solve());
	return 0;
}