#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

ll x[100];
int cc[100];
int k;

int res = inf;
ll a[2], h[2];

void go(int i, int q, int cur = 0, int bad = 0) {
    if (i == k) {
        //cerr << a[0] << ' ' << h[0] << ' ' << a[1] << ' ' << h[1] << '\n';
        if (a[0] >= h[0] && a[1] >= h[1])
            res = min(res, cur);
        return;
    }
    int iters = 0;
    forn (ii, cc[i] - bad + 1) {
        if (q)
            go(i + 1, 0, cur + iters, 0);
        else
            go(i, 1, cur + iters, ii);
        if (a[q] >= h[q])
            break;
        a[q] *= x[i];
        ++iters;
    }
    forn (ii, iters)
        a[q] /= x[i];
}

int main() {
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> h[0] >> h[1] >> a[0] >> a[1] >> n;
    vector<int> vs;
    map<int, int> vv;
    forn (i, n) {
        int x;
        scanf("%d", &x);
        vs.push_back(x);
    }
    sort(all(vs));
    forn (q, 2) {
        ll ca = a[q];
        while (ca < h[q] && !vs.empty()) {
            ca *= vs.back();
            vv[vs.back()]++;
            vs.pop_back();
        }
    }
    for (auto p: vv) {
        x[k] = p.first;
        cc[k] = p.second;
        ++k;
    }
    go(0, 0);
    swap(h[0], h[1]);
    go(0, 0);

    if (res == inf)
        res = -1;
    cout << res << '\n';
}