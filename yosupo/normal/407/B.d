import std.stdio, std.string, std.conv;

immutable long MD = 10^^9+7;
immutable int MN = 1010;

long[MN][MN] dp;
bool[MN][MN] used;
int n;
int[MN] p;

long solve(int a, int b) {
    if (a == b) return 0;
    if (used[a][b]) return dp[a][b];
    long r = (2 + solve(p[a], a) + solve(a+1, b)) % MD;
    used[a][b] = true;
    dp[a][b] = r;
    return r;
}

int main() {
    readf("%d\n", &n);
    string[] input = split(readln());
    foreach (i; 0..n) {
        p[i] = to!int(input[i]) - 1;
    }
    writeln(solve(0, n));
    return 0;
}