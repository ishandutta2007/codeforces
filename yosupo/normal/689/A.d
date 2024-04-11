import std.stdio, std.conv;
import std.algorithm, std.range, std.random;
import std.string, std.array, std.container, std.bigint;
import std.exception;


bool solve(int f, int ok) {
    import std.conv : octal;
    if ((f & std.conv.octal!2500) == 0) return true;
    if ((f & std.conv.octal!7) == 0) return true;
    if ((f & std.conv.octal!2111) == 0) return true;
    if ((f & std.conv.octal!2444) == 0) return true;
    return false;
}   
int main() {
    readln;
    string s = readln.strip;
    int f = 0;
    foreach (c; s) {
        if (c == '0') {
            f |= 1<<10;
            continue;
        }
        f |= 1<<(c-'1');
    }

    int ok = ((1<<9)-1) + (1<<10);

    if (solve(f, ok)) {
        writeln("NO");
    } else {
        writeln("YES");
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