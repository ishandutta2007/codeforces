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

int fact[N], invfact[N], inv[N], dp[N], dp2[N];

int cnk(int n, int k) {
    if (n < k || k < 0) return 0;
    return mult(fact[n], mult(invfact[k], invfact[n - k]));
}

void solve() {
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i <= n; i += 2){
        int a = i / 2;
        int b = n - i;
        int cur = cnk(a + b, a);
        cur = mult(cur, dp2[a]);
        cur = mult(cur, dp[b]);
        cur = mult(cur, bp(2, a / 2));
//        cerr << a << " " << b << " " << dp2[a] << " " << dp[b] <<  " " << cur << endl;
        ans = sum(ans, cur);
    }
    cout << ans << endl;
}

int main() {
    fact[0] = invfact[0] = invfact[1] = inv[1] = fact[1] = 1;
    for (int i = 2; i < N; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    dp[0] = 1;
    for (int i = 1; i < N; i++) {
        dp[i] = dp[i - 1];
        if (i >= 2)
            dp[i] = sum(dp[i], mult(i - 1, dp[i - 2]));
    }
    dp2[0] = 1;
    for (int i = 1; i < N; i++) {
        if (i >= 2)
            dp2[i] = sum(dp2[i], mult(i - 1, dp2[i - 2]));
    }
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}