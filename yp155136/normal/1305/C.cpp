#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1006;
int cnt[N];
ll mod;

ll ppow(ll a, ll n) {
    ll ret = 1, now = a;
    while (n) {
        if (n & 1) {
            ret *= now;
            ret %= mod;
        }
        now *= now;
        now %= mod;
        n >>= 1;
    }
    return ret;
}

vector<ll> v[N];

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n >> mod;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        cnt[x % mod]++;
        v[x % mod].push_back(x);
    }
    ll ans = 1;
    for (int i = 0; i < mod; ++i) {
        if (v[i].size() > 1) {
            cout << 0 << endl;
            return 0;
        }
        if (v[i].size() == 0) continue;
        for (int j = i + 1; j < mod; ++j) {
            if (v[j].size() == 0) continue;
            ans *= abs(v[i][0] - v[j][0]);
            ans %= mod;
        }
    }
    cout << ans << endl;
}