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

int n, a[N], ans;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        a[i] += a[i - 1];
    }
    ans = min(a[n], n - a[n]);
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        int y = (n - i) - (a[n] - a[i]);
        ans = min(ans, max(x, y));
    }
    cout << ans << endl;
}
int main() {
//#ifdef DEBUG
//    freopen("input.txt", "r", stdin);
//#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}