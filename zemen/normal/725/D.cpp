#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

multiset<ll> s;
vector<pair<ll, ll>> v;
ll cur, best, pos;

void relax() {
    while (!v.empty() && v.back().first > cur) {
        s.insert(v.back().second);
        v.pop_back();
        ++pos;
    }
    best = min(best, pos);
}

int main() {
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    pos = 1, best = infl;
    ll tmp;
    cin >> cur >> tmp;
    forn (i, n - 1) {
        ll t, w;
        cin >> t >> w;
        v.emplace_back(t, w - t + 1);
    }
    sort(v.begin(), v.end());
    relax();
    while (!s.empty()) {
        ll x = *s.begin();
        s.erase(s.begin());
        if (cur < x)
            break;
        cur -= x;
        --pos;
        relax();
    }
    cout << best << '\n';
}