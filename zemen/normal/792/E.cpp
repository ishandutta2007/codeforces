#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

#define int ll

const int maxn = 505;
const int B = 50000;
int n;
int a[maxn];

int ans(int k) {
    int res = 0;
    forn (i, n) {
        res += (a[i] + k) / (k + 1);
    }
    cout << res << '\n';
    exit(0);
}

signed main() {
    #ifdef LOCAL
    assert(freopen("e.in", "r", stdin));
    #else
    #endif
    cin >> n;
    forn (i, n)
        cin >> a[i];

    vector<int> si;
    forn (i, n) {
        vector<int> cur;
        for (int b = B; b >= 1; --b) {
            int x = a[i] / b;
            if (x == 0)
                continue;
            if (x * b == a[i]) {
                if (cur.empty() || cur.back() != x - 1)
                    cur.push_back(x - 1);
            }
            if (cur.empty() || cur.back() != x)
                cur.push_back(x);
        }
        assert(is_sorted(cur.begin(), cur.end()));
        vector<int> nsi;
        if (i == 0)
            nsi = cur;
        else {
            set_intersection(si.begin(), si.end(), cur.begin(), cur.end(), back_inserter(nsi));
        }
        si = nsi;
    }
    int res1 = -1, res2 = -1;
    if (!si.empty()) {
        //ans(si.back());
        res1 = si.back();
    }

    for (int k = B; k >= 1; --k) {
        bool ok = true;
        forn (i, n) {
            int b = (a[i] + k) / (k + 1);
            int r = b * (k + 1) - a[i];
            if (r > b) {
                ok = false;
                break;
            }
        }
        if (ok) {
            //ans(k);
            res2 = k;
            break;
        }
    }
    ans(max(res1, res2));
    //cerr << res1 << ' ' << res2 << '\n';
    //assert(false);
}