#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

int m;
V<int> freq;
int dp[TEN(6) + 10][3][3];
bool vis[TEN(6) + 10][3][3];
int solve(int p, int b1, int b2) {
    if (p == -1) {
        if (b1 == 0 && b2 == 0) return 0;
        return -TEN(9);
    }
    if (vis[p][b1][b2]) return dp[p][b1][b2];
    vis[p][b1][b2] = true;
    int ans = -TEN(9);
    for (int u = 0; u <= 2; u++) {
        int rem = freq[p] - b1 - b2 - u;
        if (rem < 0) continue;
        ans = max(ans, solve(p - 1, u, b1) + u + rem / 3);
    }
    return dp[p][b1][b2] = ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;

    int n;
    cin >> n >> m;
    freq = V<int>(m);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x; x--;
        freq[x]++;
    }
    cout << solve(m - 1, 0, 0) << endl;
    return 0;
}