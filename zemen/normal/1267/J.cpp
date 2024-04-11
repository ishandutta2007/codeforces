#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;

const int maxn = 2000500;

int n;
int cnt[maxn];
int have[maxn];

bool can(i64 k, i64 s) {
    if (s <= 2) return true;
    return (k % (s-1)) * (s-1) <= k;
}

int getNumberOfScreens(i64 k, i64 s) {
    int res = 0;
    if (s == 1) return k;
    while (k%s) ++res, k -= s-1;
    return res + k/s;
}

void solve() {
    vi a;

    cin >> n;
    forn(i, n+1) cnt[i] = 0, have[i] = 0;
    forn(i, n) {
        int c;
        cin >> c;
        ++cnt[c-1];
    }
    forn(i, n+1) if (cnt[i]) {
        if (!have[cnt[i]]) {
            have[cnt[i]] = 1;
            a.push_back(cnt[i]);
        }
    }
    sort(all(a));
    // cerr << "counts: ";
    // for (auto x : a) {
        // cerr << x << " ";
    // }
    // cerr << "\n";

    int mxs = 2;
    for (int s = 3; s <= a[0] + 1; ++s) {
        bool ok = true;
        for (auto x : a) {
            if (!can(x, s)) {
                ok = false;
                break;
            }
        }
        if (ok) mxs = s;
    }
    int m = 0;
    forn(i, n+1) {
        m += getNumberOfScreens(cnt[i], mxs);
    }
    cout << m << "\n";
}

int main() {
#ifdef LOCAL
    freopen("j.in", "r", stdin);
#endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    forn(i, t) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}