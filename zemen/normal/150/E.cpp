#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
typedef pair<int, int> pii;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 100100;
int L, R;
int u1, v1;
vector<pii> _g[maxn];
vector<pii> g[maxn];

int cnt[maxn];
void pre(int u, int prev = -1) {
    cnt[u] = 1;
    for (auto p: g[u]) {
        int v = p.first;
        if (v == prev)
            continue;
        pre(v, u);
        cnt[u] += cnt[v];
    }
}

int CENTER, CCNT;
void findCenter(int u, int prev = -1, int up = 0) {
    int worst = up;
    for (auto p: g[u]) {
        int v = p.first;
        if (v == prev)
            continue;
        findCenter(v, u, up + cnt[u] - cnt[v]);
        worst = max(worst, cnt[v]);
    }
    if (worst < CCNT) {
        CCNT = worst;
        CENTER = u;
    }
}

const int cbase = 1 << 17;
pii t[cbase * 2];
int ver[cbase * 2];
int VER, base;

pii &getT(int v) {
    if (ver[v] != VER) {
        ver[v] = VER;
        t[v] = {-inf, -1};
    }
    return t[v];
}

pii tmx(int l, int r) {
    l = max(l, 0);
    r = min(r, base);
    pii res = {-inf, -1};
    for (l += base, r += base; l < r; l >>= 1, r >>= 1) {
        if (l & 1)
            res = max(res, getT(l++));
        if (r & 1)
            res = max(res, getT(--r));
    }
    return res;
}

void put(int v, pii val) {
    v += base;
    t[v] = max(getT(v), val);
    while (v > 1) {
        v /= 2;
        getT(v) = max(getT(v * 2), getT(v * 2 + 1));
    }
}

vector<pair<int, pii>> qs;
void dfs2(int u, int prev, int a, int b) {
    //cerr << "ask " << u+1 << ' ' << L-b << ' ' << R-b << '\n';
    pii cur = tmx(L - b, R - b + 1);
    qs.emplace_back(b, pii{2 * a - b, u});
    if (cur.first + 2 * a - b >= 0) {
        u1 = u, v1 = cur.second;
        return;
        //cerr << "FOUND!\n";
    }

    for (auto p: g[u]) {
        int v = p.first;
        if (v == prev)
            continue;
        dfs2(v, u, a + p.second, b + 1);
    }
}

void dfs(int u) {
    CENTER = -1, CCNT = inf;
    pre(u);

    ++VER;
    base = cnt[u];

    findCenter(u);
    assert(CCNT <= cnt[u] / 2);
    u = CENTER;
    //cerr << "dec " << u+1 << '\n';

    //cerr << "put " << u+1 << '\n';
    put(0, pii{0, u});
    for (auto p: g[u]) {
        qs.clear();
        dfs2(p.first, u, p.second, 1);
        if (u1 != -1)
            return;
        for (auto q: qs)
            put(q.first, q.second);
    }

    for (auto p: g[u]) {
        int v = p.first;
        g[v].erase(find(g[v].begin(), g[v].end(), pii{u, p.second}));
    }
    for (auto p: g[u]) {
        dfs(p.first);
        if (u1 != -1)
            return;
    }
}

int main() {
    #ifdef LOCAL
    assert(freopen("e.in", "r", stdin));
    #else
    #endif
    forn (i, 2 * base)
        t[i] = {-inf, -1};

    int n;
    cin >> n >> L >> R;
    vector<int> allc;
    forn (i, n - 1) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        --u, --v;
        _g[u].emplace_back(v, c);
        _g[v].emplace_back(u, c);
        allc.push_back(c);
    }
    sort(allc.begin(), allc.end());
    allc.erase(unique(allc.begin(), allc.end()), allc.end());

    int L = -1, R = sz(allc);
    while (L + 1 < R) {
        int C = (L + R) / 2;
        forn (i, n) {
            g[i] = _g[i];
            for (auto &p: g[i])
                p.second = (p.second >= allc[C]);
        }
        u1 = v1 = -1;
        dfs(0);

        if (u1 != -1)
            L = C;
        else
            R = C;
    }

    forn (i, n) {
        g[i] = _g[i];
        for (auto &p: g[i])
            p.second = (p.second >= allc[L]);
    }
    u1 = v1 = -1;
    dfs(0);

    cout << u1 + 1 << ' ' << v1 + 1 << '\n';
}