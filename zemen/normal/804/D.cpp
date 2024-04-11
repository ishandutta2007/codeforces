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

const int maxn = 100100;
vector<int> g[maxn];
const int B = 300;

int r1[maxn];
int r2[maxn];
int w1[maxn];

int col[maxn];
int cc;

int diam[maxn];
int cnt[maxn];
vector<ll> rs[maxn];
vector<ll> pr[maxn];
vector<ll> prc[maxn];
int bigId[maxn];
int bigCol[maxn];

ld pre[maxn / B + 100][maxn / B + 100];
//ld pre[100][100];

int dfs1(int u, int prev = -1) {
    col[u] = cc;
    r1[u] = r2[u] = 0;
    int res = 0;

    for (int v: g[u]) {
        if (v == prev)
            continue;
        res = max(res, dfs1(v, u));
        int r = r1[v] + 1;
        if (r > r1[u]) {
            r2[u] = r1[u];
            w1[u] = v;
            r1[u] = r;
        } else if (r > r2[u]) {
            r2[u] = r;
        }
    }
    res = max(res, r1[u] + r2[u]);
    return res;
}

void dfs2(int u, int h = 0, int prev = -1) {
    cnt[cc]++;
    int cur = max(h, r1[u]);
    if (sz(rs[cc]) <= cur)
        rs[cc].resize(cur + 1);
    rs[cc][cur]++;

    for (int v: g[u]) {
        if (v == prev)
            continue;
        int nh = h + 1;
        if (v == w1[u])
            nh = max(nh, r2[u] + 1);
        else
            nh = max(nh, r1[u] + 1);
        dfs2(v, nh, u);
    }
}

ld calc(int c1, int c2) {
    if (c1 == c2)
        return -1;
    if (sz(rs[c1]) > sz(rs[c2]))
        return calc(c2, c1);
    int d = max(diam[c1], diam[c2]);

    ld cnt = ::cnt[c1] * ld(::cnt[c2]);
    ld sum = 0;

    forn (r1, sz(rs[c1])) {
        int b2 = max(0, d - r1 - 1);
        int cnt2 = 0;
        ll sum2 = 0;
        if (b2 < sz(pr[c2])) {
            cnt2 = prc[c2][b2];
            sum2 = pr[c2][b2];
        }
        ld cnt1 = rs[c1][r1];
        ld sum1 = cnt1 * r1;
        sum += cnt2 * sum1;
        sum += cnt1 * sum2;
        sum += cnt1 * cnt2;
        ld cntBad = ::cnt[c2] - cnt2;
        sum += cntBad * cnt1 * d;
    }
    //cerr << cnt << ' ' << sum << '\n';
    return sum / cnt;
}

int main() {
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    int n, m, q;
    cin >> n >> m >> q;
    forn (i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    forn (i, n)
        col[i] = -1;
    forn (i, n) {
        if (col[i] != -1)
            continue;
        diam[cc] = dfs1(i);
        dfs2(i);
        pr[cc] = rs[cc];
        prc[cc] = rs[cc];

        forn (i, sz(pr[cc]))
            pr[cc][i] *= ll(i);

        for (int i = sz(pr[cc]) - 2; i >= 0; --i) {
            pr[cc][i] += pr[cc][i + 1];
            prc[cc][i] += prc[cc][i + 1];
        }

        ++cc;
    }
    int big = 0;
    forn (i, cc) {
        if (cnt[i] > B) {
            bigId[i] = big++;
            bigCol[big - 1] = i;
        } else
            bigId[i] = -1;
    }
    forn (i, big)
        forn (j, big)
            pre[i][j] = calc(bigCol[i], bigCol[j]);

    cout << fixed;
    cout.precision(10);
    forn (i, q) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        int c1 = col[u], c2 = col[v];
        if (c1 == c2) {
            cout << -1 << '\n';
            continue;
        }
        int bc1 = bigId[c1];
        int bc2 = bigId[c2];
        ld res;
        if (bc1 != -1 && bc2 != -1)
            res = pre[bc1][bc2];
        else
            res = calc(c1, c2);
        cout << res << '\n';
    }
}