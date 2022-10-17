#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 300500, inf = 1e9, mod = 998244353;

int sum(int a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

int mult(int a, int b) {
    return 1ll * a * b % mod;
}

int bp(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int x) {
    return bp(x, mod - 2);
}

int n, a[N], dp[N];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        a[i] ^= a[i - 1];
    dp[0] = 0;
    int ans = 0;
    map<int, int> mt;
    mt[0] = 1;
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i - 1];
        dp[i] = max(dp[i], mt[a[i]]);
        mt[a[i]] = max(mt[a[i]], dp[i] + 1);
        ans = max(ans, dp[i]);
    }
    cout << n - ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}