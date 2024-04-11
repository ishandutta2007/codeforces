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
ll ans[maxn];
int qx[maxn];
int qy[maxn];
vector<int> diag1[maxn * 2], diag2[maxn * 2];

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    forn (i, k) {
        int x, y;
        cin >> x >> y;
        ans[i] = infl;
        qx[i] = x, qy[i] = y;
        diag1[x + y].push_back(i);
        diag2[x - y + m].push_back(i);
    }
    int x = 0, y = 0;
    int dir = 0;
    ll T = 0;
    while (true) {
        int tx, ty, tdir, s;
        auto &v = (dir == 0 || dir == 2) ? diag2[x - y + m] : diag1[x + y];
        for (auto id: v) {
            ll ct = T + abs(qx[id] - x);
            ans[id] = min(ans[id], ct);
        }
        if (dir == 0) {
            s = min(n - x, m - y);
            tx = x + s, ty = y + s;
            if (tx == n && ty == m)
                break;
            else if (ty == m)
                tdir = 3;
            else {
                assert(tx == n);
                tdir = 1;
            }
        } else if (dir == 1) {
            s = min(x, m - y);
            tx = x - s, ty = y + s;
            if (tx == 0 && ty == m)
                break;
            else if (ty == m)
                tdir = 2;
            else {
                assert(tx == 0);
                tdir = 0;
            }
        } else if (dir == 2) {
            s = min(x, y);
            tx = x - s, ty = y - s;
            if (tx == 0 && ty == 0)
                break;
            else if (tx == 0)
                tdir = 3;
            else {
                assert(ty == 0);
                tdir = 1;
            }
        } else if (dir == 3) {
            s = min(n - x, y);
            tx = x + s, ty = y - s;
            if (tx == n && ty == 0)
                break;
            else if (tx == n)
                tdir = 2;
            else {
                assert(ty == 0);
                tdir = 0;
            }
        } else
            assert(false);
        T += s;
        x = tx, y = ty, dir = tdir;
    }
    forn (i, k) {
        if (ans[i] == infl)
            ans[i] = -1;
        cout << ans[i] << '\n';
    }
}