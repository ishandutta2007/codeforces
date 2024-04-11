#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 16;
map<int, int> d[1 << maxn];
char c[maxn];
int r[maxn];
int b[maxn];

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #endif
    int n;
    cin >> n;
    forn (i, n) {
        cin >> c[i] >> r[i] >> b[i];
    }
    d[0][0] = 0;
    forn (mask, 1 << n) {
        int R = 0, B = 0;
        forn (i, n) {
            if (mask & (1 << i)) {
                if (c[i] == 'R')
                    ++R;
                else
                    ++B;
            }
        }
        forn (i, n) {
            if (mask & (1 << i))
                continue;
            int to = mask | (1 << i);
            for (auto p: d[mask]) {
                int nr = p.first + max(0, r[i] - R);
                int nb = p.second + max(0, b[i] - B);
                //cerr << to << ' ' << nr << ' ' << nb << '\n';
                if (!d[to].count(nr))
                    d[to][nr] = inf;
                d[to][nr] = min(d[to][nr], nb);
            }
        }
    }
    int res = inf;
    for (auto p: d[(1 << n) - 1]) {
        res = min(res, max(p.first, p.second));
    }
    res += n;
    cout << res << '\n';
}