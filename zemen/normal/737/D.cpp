#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 4005;
const int maxk = 100;
const int maxd = 70;

int n;
int d[maxn][maxk][maxd * 2][2];
int a[maxn];
int pr[maxn];

int cost(int p, int s) {
    return pr[p] - (pr[n] - pr[n - s]);
}

int calc(int p, int k, int diff, int who) {
    assert(p < maxn && k < maxk && abs(diff) < maxd);
    int &res = d[p][k][diff + maxd][who];
    if (res != inf)
        return res;
    int s = p - diff;
    if (p + s + k > n)
        return res = cost(p, s);
    if (who == 0) {
        res = calc(p + k, k, diff + k, who ^ 1);
        if (p + s + k < n)
            res = max(res, calc(p + k + 1, k + 1, diff + k + 1, who ^ 1));
    } else {
        res = calc(p, k, diff - k, who ^ 1);
        if (p + s + k < n)
            res = min(res, calc(p, k + 1, diff - k - 1, who ^ 1));
    }
    return res;
}

int main() {
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    //cerr << sizeof(d) << '\n';
    forn (i, maxn)
        forn (j, maxk)
            forn (k, maxd * 2)
                forn (q, 2)
                    d[i][j][k][q] = inf;
    cin >> n;
    forn (i, n)
        cin >> a[i];
    forn (i, n)
        pr[i + 1] = pr[i] + a[i];
    cout << calc(0, 1, 0, 0) << '\n';
}