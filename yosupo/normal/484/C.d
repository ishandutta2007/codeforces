import std.stdio, std.getopt, std.random, std.range, std.string, std.conv;
import std.algorithm, std.container, std.datetime;

struct Permutation {
	int N;
	int[] d;
	alias d this;

	this(int _N) {
		N = _N;
		d = iota(N).array;
	}

	Permutation opBinary(string op) (Permutation r) {
		static if (op == "*") {
			assert(N == r.N);
			auto tmp = Permutation(N);
			foreach (i; 0..N) {
				tmp[i] = r[d[i]];
			}
			return tmp;
		} else {
			static assert(false);
		}
	}

	void opOpAssign(string op) (Permutation r) {
		static if (op == "*") {
			this = this*r;
		} else {
			static assert(false);
		}
	}

	Permutation opBinary(string op) (long n) {
		static if (op == "^^") {
			auto x = this;
			auto r = Permutation(N);
			while (n) {
				if (n & 1) r *= x;
				x *= x;
				n >>= 1;
			}
			return r;
		}
		assert(false);
	}
}

int main() {
	char[] s = readln.strip.dup;
	auto n = cast(int)s.length;
	char[] s2 = new char[](n);
	auto m = readln.strip.to!int;
	auto sh = Permutation(n);
	foreach (i; 0..n) {
		sh[i] = (i-1+n)%n;
	}
	foreach (_ ; 0..m) {
		auto ins = readln.split.map!(to!int).array;
		auto k = ins[0], d = ins[1];
		auto p = Permutation(n);
		int u = 0, b = 0;
		foreach (i; 0..k) {
			p[u] = i;
			u += d;
			if (u >= k) {
				b++;
				u = b;
			}
		}
		auto ps = (p*sh)^^(n-k) * p * sh^^k;
		foreach (i; 0..n) {
			s2[ps[i]] = s[i];
		}
		s[] = s2[];
		writeln(s);
	}
    return 0;
}