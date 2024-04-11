import std.stdio, std.string, std.conv, std.conv, std.array;

int main() {
    int n, k;
    readf("%d %d\n", &n, &k);
    if (k<n/2) {
        writeln(-1);
        return 0;
    }
    if (n == 1) {
        if (k == 0) {
            writeln(1);
        } else {
            writeln(-1);
        }
        return 0;
    }
    string[] s;
    int m = k-(n/2-1);
    s ~= to!string(m);
    s ~= to!string(2*m);
    foreach (i;0..n-2) {
        s ~= to!string(2*m+i+10);
    }
    writeln(join(s, " "));
    return 0;
}