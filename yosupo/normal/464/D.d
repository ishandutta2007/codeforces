import std.stdio, std.getopt, std.random, std.range, std.string, std.conv;
import std.algorithm, std.container;

const ML = 700;
double[][] dp;
bool[][] used;
int k;
double solve(int l, int n) {
    if (n < 0) return 0;
    if (l >= ML) return 0;
    if (used[l][n]) return dp[l][n];
    used[l][n] = true;
    double res = 0;
    double hp = 1.0/(l+1);
    res += hp*(l + solve(l+1, n-1));
    res += (1-hp)*((l+1.0)/2 + solve(l, n-1));
    res /= k;
    res += (1-1.0/k)*solve(l, n-1);
    return (dp[l][n] = res);
}

int main() {
    int n;
    readf("%d %d\n", &n, &k);
    auto dp = new double[ML+1];
    dp[] = 0;
    foreach (i; 1..n+1) {
        foreach (j; 1..ML) {
            double res = 0;
            double hp = 1.0/(j+1);
            res += hp*(j + dp[j+1]);
            res += (1-hp)*((j+1.0)/2 + dp[j]);
            res /= k;
            res += (1-1.0/k)*dp[j];
            dp[j] = res;
        }
    }
    writef("%.20f\n", dp[1]*k);
	return 0;
}