#include <bits/stdc++.h>
using namespace std;

void solve() {
    /*
    Let s[1..n] be the prefix sum of b
    Let x[1..k] be the positions that maybe differ from the original array
    Then:
        a[i] = b[i] for 1 <= i < x[1]
        a[x[1]] = b[x[1]] - s[x[1] - 1] = b[x[1]] - s[x[1] - 1] + s[0]
        a[i] = b[u] for x[1] < i < x[2]
        a[x[2]] = b[x[2]] - (s[x[2] - 1] - b[x[1]] + a[x[1]])
        a[x[2]] = b[x[2]] - (s[x[2] - 1] - b[x[1]] + b[x[1]] - s[x[1] - 1])
        a[x[2]] = b[x[2]] - s[x[2] - 1] + s[x[1] - 1]

        generalise to a[x[i]] = b[x[i]] - s[x[i] - 1] + s[x[i - 1] - 1]
        so we don't really need to care about the actual sequence, just the last x[i]

        f[i] -> last different element is i, how many sequence there are
        for j > i:
            f[j] += f[i] * 2 if (a[j] = b[j] - s[j-1] + s[i-1]) != b[j]
        ans = sum f[i]
     */
    constexpr int base = 1e9 + 7;
    int n;
    cin >> n;
    map<int64_t, int64_t> skip;
    int64_t sum = 1;
    skip[0] = 1;
    int64_t b;
    int64_t s = 0;
    int64_t f_i;
    for (int i = 1; i <= n; i++) {
        cin >> b;
        (f_i = sum - skip[s]) %= base;
        (sum += f_i) %= base;
        (skip[s] += f_i) %= base;
        s += b;
    }
    (sum += base) %= base;
    cout << sum << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}