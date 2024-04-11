import std.stdio, std.getopt, std.random, std.range, std.string, std.conv;
import std.algorithm, std.container, std.datetime, std.typecons;

const MD = 10^^9+7;

alias Tl = Tuple!(long, long);

long powMod(long x, long n, long md) {
    long r = 1;
    while (n) {
        if (n & 1) r *= x; r %= md;
        x *= x; x %= md;
        n >>= 1;
    }
    return r;
}

//-------------------------------------------------------//

int n;
int[] d;
string[] t;

Tl[][] dp;
bool[][] used;
Tl calc(int ad, int c) {
	if (ad == n) return Tl(c, 1);
	if (d[ad] != c) return calc(ad+1, c);
	if (used[ad][c]) return dp[ad][c];
	used[ad][c] = true;
	Tl res = [0,0];
	foreach_reverse (u; t[ad]) {
		auto r = calc(ad+1, u-'0');
		res[0] += r[0]*powMod(10, res[1], MD) % MD;
		res[1] += r[1];
		res[0] %= MD;
		res[1] %= MD-1;
	}
	dp[ad][c] = res;
	return res;
}

long solve() {
	auto s = readln().strip();
	readf("%d\n", &n); n++;
	d = new int[n]; t = new string[n];
	d[0] = 0; t[0] = s;
	foreach (i; 1..n) {
//		readf("%d", &d[i]);
		readf("%d->%s\n", &d[i], &t[i]);
	}

	dp = new Tl[][](n, 10);
	used = new bool[][](n, 10);
	return calc(0, 0)[0]%MD;
}

int main() {
    writeln(solve());
    return 0;
}