#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 100100;
int a[maxn];
ll p[maxn];

multiset<ll> S;
set<int> del;

ll get(int l, int r) {
    if (l == r)
        return 0;
    return p[r] - p[l + 1];
}

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    forn (i, n)
        scanf("%d", &a[i]);
    forn (i, n)
        p[i + 1] = p[i] + a[i];
    del.insert(-1);
    del.insert(n);
    S.insert(get(-1, n));
    S.insert(0);
    forn (i, n) {
        int x;
        scanf("%d", &x);
        --x;
        auto it = del.lower_bound(x);
        int r = *it;
        int l = *prev(it);
        del.insert(x);
        S.erase(S.find(get(l, r)));
        if (l + 1 < x)
            S.insert(get(l, x));
        if (x + 1 < r)
            S.insert(get(x, r));
        cout << *S.rbegin() << '\n';
    }
}