import std.stdio, std.string, std.conv, std.algorithm;
immutable int MN = 100010;
immutable int MK = 105;
immutable int MD = cast(int)(1e9+7.1);

int main() {
    long[MK][] b = new long[MK][](MN);
    long[MK][] c = new long[MK][](MN+MK);

    c[0][0] = 1;
    foreach (i; 1..MN+MK) {
        c[i][0] = 1;
        c[i][1..MK] = (c[i-1][0..MK-1] + c[i-1][1..MK]) % MD;
    }

    int n, m;
    readf("%d %d\n", &n, &m);
    string[] input = split(readln());
    long[] a = new long[](n);
    foreach (i; 0..n) {
        a[i] = to!int(input[i]);
    }
    foreach (i; 0..m) {
        int l, r, k;
        readf("%d %d %d\n", &l, &r, &k); l--;
        int f = 1;
        foreach_reverse (j; 0..k+1) {
            b[l][j] += c[l][k-j]*f; b[l][j] %= MD;
            b[r][j] -= c[l][k-j]*f; b[r][j] %= MD;
            f = -f;
        }
    }
    long[] b1 = new long[](MK);
    foreach (i; 0..n) {
        b1[] += b[i][];
        b1[] %= MD;
        for (int k = 0; k < MK; k++) {
            a[i] += b1[k]*c[i+k][k]%MD; a[i] %= MD;
        }
        a[i] = (a[i]+MD)%MD;
    }
    writeln(join(map!(to!string)(a[0..n]), " "));
    return 0;
}