import std.stdio, std.conv;
import std.algorithm, std.range, std.random;
import std.string, std.array, std.container, std.bigint;
import std.exception;

long calc(long x) {
    long ans = 0;
    foreach (i; 2L..300000) {
        ans += x / (i*i*i);
    }
    return ans;
}

int main() {
    long m = readln.strip.to!long;
    long l = 0, r = 10L^^16;
    while (r-l > 1) {
        long md = (l+r)/2;
        if (calc(md) < m) {
            l = md;
        } else {
            r = md;
        }
    }
    if (calc(r) != m) {
        writeln(-1);
    } else {
        writeln(r);
    }
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