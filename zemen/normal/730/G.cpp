#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);
typedef pair<ll, ll> pii;

set<pair<ll, ll>> s;

bool check(ll st, ll d) {
    auto it = s.lower_bound(pii(st, -1));
    bool ok = true;
    if (it->first < st + d)
        ok = false;
    --it;
    if (it->second > st)
        ok = false;
    return ok;
}

void ans(ll st, ll d) {
    cout << st << ' ' << st + d - 1 << '\n';
    s.emplace(st, st + d);
}

int main() {
    #ifdef LOCAL
    assert(freopen("g.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    s.emplace(1e18, 1e18);
    s.emplace(-1e18, -1e18);
    forn (i, n) {
        ll st, d;
        cin >> st >> d;
        if (check(st, d)) {
            ans(st, d);
            continue;
        }
        st = 1;
        if (check(st, d)) {
            ans(st, d);
            continue;
        }
        for (auto p: s) {
            if (p.second < 0)
                continue;
            st = p.second;
            if (check(st, d)) {
                ans(st, d);
                break;
            }
        }
    }
}