import std.stdio, std.conv;
import std.algorithm, std.range, std.random;
import std.string, std.array, std.container, std.bigint;
import std.exception;

struct SparseRMQ(int S) {
    immutable int N = 1<<S;
    int[][] a, b;
    this(int[] _a, int[] _b) {
        a = new int[][](S, N);
         b = new int[][](S, N);
        _a.copy(a[0]);
        _b.copy(b[0]);
        int l = 1;
        for (int s = 1; s < S; s++) {
            for (int i = 0; i < N - l; i++) {
                a[s][i] = max(a[s-1][i], a[s-1][i + l]);
                b[s][i] = min(b[s-1][i], b[s-1][i + l]);
            }
            l <<= 1;
        }
    }
    int[2] query(int l, int r) {
        import core.bitop : bsr;
        if (l == r) return [-1, 10^^9+10^^8];
        int u = bsr(r-l);
        return [max(a[u][l], a[u][r-(1<<u)]), min(b[u][l], b[u][r-(1<<u)])];
    }
}

int main() {
    int n = readln.strip.to!int;
    int[] a = readln.split.map!(to!int).array;
    int[] b = readln.split.map!(to!int).array;

    SparseRMQ!(18) sp = SparseRMQ!(18)(a, b);

    long ans = 0;
    foreach (i; 0..n) {
        int X, Y, l, r;
        l = i; r = n+1;
        while (r-l > 1) {
            int md = (l+r)/2;
            int[2] q = sp.query(i, md);
            if (q[0] < q[1]) {
                l = md;
            } else {
                r = md;
            }
        }
        X = r;
        l = i; r = n+1;
        while (r-l > 1) {
            int md = (l+r)/2;
            int[2] q = sp.query(i, md);
            if (q[0] <= q[1]) {
                l = md;
            } else {
                r = md;
            }
        }
        Y = r;
        ans += cast(long)(Y-X);
    }
    writeln(ans);
	return 0;
}



string readToken() {
    import std.stdio : readln;
    import std.string : split;
    static size_t pos;
    static string[] tokens;
    while (!(pos < tokens.length)) {
        pos = 0;
        tokens = readln.split;
    }
    return tokens[pos++];
}
T read(T)() {
    import std.conv : to;
    return readToken.to!T;
}