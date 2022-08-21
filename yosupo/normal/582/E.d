import std.stdio, std.conv;
import std.algorithm, std.range, std.random;
import std.string, std.array, std.container, std.bigint;


immutable S = 4;
immutable N = 1<<S;
alias P = long[1<<N];
immutable MD = 10^^9+7;
P[4][2] p;
P pq;

struct Parser {
	string s;
	int co;
	this(string ss) {
		s = ss; co = 0;
	}
	char front() {
		return s[co];
	}
	char pop() {
		return s[co++];
	}
}

P val(ref Parser s) {
	char c = s.pop();
	if ('a' <= c && c <= 'd') {
		return p[0][cast(int)(c-'a')];
	} else if ('A' <= c && c <= 'D') {
		return p[1][cast(int)(c-'A')];
	}
	return pq;
}

P zeta(P d) {
	foreach (i; 0..N) {
		foreach (j; 0..(1<<N)) {
			if (j & (1<<i)) {
				d[j] += d[j ^ (1<<i)];
				d[j] %= MD;
			}
		}
	}
	return d;
}

P numor(P p1, P p2) {
	p1 = zeta(p1); p2 = zeta(p2);
	P r;
	foreach (i; 0..(1<<N)) {
		r[i] = p1[i]*p2[i] % MD;
	}

	foreach (i; 0..N) {
		foreach (j; 0..(1<<N)) {
			if (j & (1<<i)) {
				r[j] -= r[j ^ (1<<i)];
				r[j] %= MD;
			}
		}
	}
	return r;
}

P nummul(P p1, P p2) {
	foreach (i; 0..(1<<(N-1))) {
		swap(p1[i], p1[((1<<N)-1) ^ i]);
		swap(p2[i], p2[((1<<N)-1) ^ i]);
	}
	P r = numor(p1, p2);
	foreach (i; 0..(1<<(N-1))) {
		swap(r[i], r[((1<<N)-1) ^ i]);
	}
	return r;
}

P expr(ref Parser s) {
	char c = s.front();
	if (c == '(') {
		s.pop();
		P p1 = expr(s);
		s.pop();
		char op = s.pop();
		s.pop();
		P p2 = expr(s);
		s.pop();
		P or = numor(p1, p2);
		P mul = nummul(p1, p2);
		if (op == '|') return or;
		if (op == '&') return mul;
		P r;
		foreach (i; 0..(1<<N)) {
			r[i] = or[i]+mul[i];
			r[i] %= MD;
		}
		return r;
	} else {
		return val(s);
	}
}

int main() {
	string s = readln.strip;

	foreach (i; 0..2) {
		foreach (j; 0..S) {
			int m = 0;
			foreach (k; 0..(1<<S)) {
				if (((k >> j) & 1) == i) {
					m |= (1<<k);
				}
			}
			p[i][j][m] = 1;
			pq[m] += 1;
		}
	}

	int n = readln.strip.to!int;
	int[2][] l = new int[2][](n);
	foreach (i; 0..n) {
		auto inp = readln.split.map!(to!int).array;
		int m = 0;
		foreach (k; 0..4) {
			if (inp[k]) {
				m |= (1<<k);
			}
		}
		l[i] = [m, inp[4]];
	}
	Parser pr = Parser(s);
	P p = expr(pr);
	long sm = 0;
	foreach (i; 0..(1<<N)) {
		bool f = true;
		foreach (j; 0..n) {
			if (((i>>l[j][0]) & 1) != l[j][1]) {
				f = false;
				break;
			}
		}
		if (!f) continue;
		sm += p[i];
		sm %= MD;
	}
	sm = (sm + MD) % MD;
	writeln(sm);
	return 0;
}