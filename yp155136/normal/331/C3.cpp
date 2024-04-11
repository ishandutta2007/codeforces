#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define F first
#define S second

map<pii, pii> dp;

// dp[i][j]: max digit = i, number = j
// (cnt, left)

ll f(ll n) {
    ll ret = 0;
    while (n) {
        ret = max(ret, n % 10);
        n /= 10;
    }
    return ret;
}

pii DP(pii val) {
    if (dp.find(val) != dp.end()) return dp[val];
    ll digit = val.F, n = val.S;
    // cerr << "digit = " << digit << " , n = " << n << endl;
    if (n == 0) {
        dp[val] = make_pair(0, 0);
        return dp[val];
    }
    if (n < 10) {
        if (digit > n) {
            dp[val] = make_pair(0, n);
            return dp[val];
        }
        else {
            dp[val] = make_pair(1, 0);
            return dp[val];
        }
    }
    ll nn = n, pp = 1;
    while (nn >= 10) {
        nn /= 10;
        pp *= 10;
    }
    // cerr << "pp = " << pp << endl;
    pii ret = DP(make_pair(max(digit, n / pp), n % pp));
    // cerr << "ret.F = " << ret.F << " , ret.S = " << ret.S << endl;
    ll newn = (n / pp) * pp + ret.S;
    ll cnt = ret.F;
    ++cnt, newn -= max(digit, f(newn));
    // cerr << "cnt = " << cnt << " , newn = " << newn << endl;
    // exit(0);
    pii ret2 = DP(make_pair(digit, newn));
    dp[val] = make_pair(ret2.F + cnt, ret2.S);
    return dp[val];
}

int main () {
    ll n; cin >> n;
    pii ret = DP(make_pair(0ll, n));
    cout << ret.F << endl;
}