#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 500006;
ll c[N];
ull hh[N];

ull get_val() {
    return ((ull)rand() << 48) ^ ((ull)rand() << 32) ^ ((ull)rand() << 16) ^ rand();
}

ull val[N];

void go() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &c[i]);
        hh[i] = get_val();
        val[i] = 0;
    }
    map<ull, ll> mp;
    for (int i = 1; i <= m; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        val[y] ^= hh[x];
    }
    vector< pair<ull, ll> > v;
    for (int i = 1; i <= n; ++i) {
        if (val[i] != 0) v.push_back({val[i], c[i]});
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    ll pre = 0;
    for (int i = 0; i <= (int)v.size(); ++i) {
        if (i == (int)v.size()) {
            ans = __gcd(ans, pre);
        }
        else if (i > 0 && v[i].first != v[i - 1].first) {
            ans = __gcd(ans, pre);
            pre = v[i].second;
        }
        else {
            pre += v[i].second;
        }
    }
    printf("%lld\n", ans);
}

int main () {
    srand(time(0));
    int T; scanf("%d", &T);
    while (T--) {
        go();
    }
}