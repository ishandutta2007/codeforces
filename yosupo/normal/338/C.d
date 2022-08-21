import std.stdio, std.getopt, std.random, std.range, std.string, std.conv;
import std.algorithm, std.container, std.datetime;
import core.bitop;

class Primes {
    immutable bool[] isPrime;
    immutable int[] primes;
    this(int n) {
        auto used = new bool[n];
        int[] p;
        used[0] = used[1] = true;
        for (int i = 2; i < n; i++) {
            if (used[i]) continue;
            p ~= i;
            for (int j = i*2; j < n; j+= i) {
                used[j] = true;
            }
        }
        isPrime = used.idup.map!(i => !i).array;
        primes = p.idup;
    }

    int[] primeDecomp(long i) {
    	assert(n*n >= i);
    	int[] res;
    	foreach (d; primes) {
    		if (d*d > i) break;
    		while (!(i % d)) {
    			res ~= d;
    			i /= d;
    		}
    	}
    	if (i > 1) res ~= cast(int)i;
    	return res;
    }
};

int n;
long[] a;
int[] ps;

bool ok(int p, int d) {
	long aa = a[p];
	foreach (j; 0..n) {
		if (!(d & (1<<j))) continue;
		if (aa % a[j]) return false;
		aa /= a[j];
	}
	return true;
}

int count(int p, int d) {
	int res = ps[p];
	foreach (j; 0..n) {
		if (!(d & (1<<j))) continue;
		res -= ps[j];
	}
	return res;
}

int[][] dpcalc;
int calc(int p, int d) {
	if (p == n) {
		if (popcnt(d) == 1) return 0;
		return 1;
	}
	if (dpcalc[p][d] != -1) return dpcalc[p][d];
	int res = ((ps[p] == 1) ? 1 : ps[p]+1) + calc(p+1, d | (1<<p));
	foreach (i; 1..(1<<p)) {
		if ((i & d) != i) continue;
		if (!ok(p, i)) continue;
		res = min(res, count(p, i)+1+calc(p+1, (d & (~i)) | (1<<p)));
	}
	return res;
}

int solve() {
	auto p = new Primes(10^^6+100);
	readf("%d\n", &n);
	a = readln().split().map!(to!long).array.sort;
	ps.length = n;
	foreach (i; 0..n) {
		ps[i] = cast(int)p.primeDecomp(a[i]).length;
	}
	dpcalc = new int[][](n, 1<<n);
	foreach (dp; dpcalc) {
		dp[] = -1;
	}
	return calc(0, 0);
}

int main() {
	writeln(solve());
    return 0;
}