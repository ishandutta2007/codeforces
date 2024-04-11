#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
const int N = 1000006;

#define F first
#define S second

ll f(ll x) {
    ll ret = 0;
    while (x) {
        ret = max(ret, x % 10);
        x /= 10;
    }
    return ret;
}

pii dp[10][N]; // (cnt, left)
ll ff[N];

int main () {
    for (int i = 0; i < N; ++i) {
        ff[i] = f(i);
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j == 0) {
                dp[i][j] = make_pair(0, 0);
                continue;
            }
            int _ = ff[j];
            int __ = max(_, i);
            if (j - __ < 0) {
                dp[i][j] = make_pair(0, j);
            }
            else {
                dp[i][j] = dp[i][j - __];
                dp[i][j].F++;
            }
        }
    }
    ll n; cin >> n;
    ll ans = 0;
    while (n != 0) {
        ll pre = n / 1000000;
        ll suf = n % 1000000;
        ll _ = ff[pre];
        pii val = dp[_][suf];
        ans += val.F;
        n = pre * 1000000 + val.S;
        if (n != 0) {
            ++ans;
            n -= f(n);
        }
    }
    cout << ans << endl;
}