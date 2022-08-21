import std.stdio, std.string, std.conv, std.algorithm, std.functional;

immutable int MN = 2010;
immutable int MK = 2010;
immutable long MD = 10^^9+7;

int main() {
    int n, k;
    string s;
    long[MK][] dp = new long[MK][](MN);
    long[] sum = new long[](MK);
    readf("%d %d\n", &n, &k);
    s = chomp(readln());
    s ~= 'a';
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = n; i >= 0; i--) {
        for (int u = 0; u <= k; u++) {
            sum[u] += dp[i+1][u]*(s[i]-'a');
            sum[u] %= MD;
            dp[i][u] += sum[u];
            dp[i][u] %= MD;
            for (int j = i-1; j >= 0; j--) {
                int d = u+(i-j)*(n-i+1);
                if (d > k) break;
                dp[j][d] += dp[i][u] * ('z'-s[i-1]);
                dp[j][d] %= MD;
            }
        }
    }
    writeln(dp[0][k]%MD);
    return 0;
}