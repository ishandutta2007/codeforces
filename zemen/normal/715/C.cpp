#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

int n, mod, modphi;
int r10;

void calcphi() {
    int x = mod;
    modphi = 1;
    for (int i = 2; i * i <= x; ++i) {
        int deg = 0;
        while (x % i == 0) {
            x /= i;
            if (!deg)
                modphi *= i - 1;
            else
                modphi *= i;
            ++deg;
        }
    }
    if (x > 1)
        modphi *= x - 1;
}

int add(int a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int mul(ll a, ll b) {
    return (a * b) % mod;
}

int binpow(int a, int deg) {
    int res = 1;
    while (deg) {
        if (deg & 1) {
            res = mul(res, a);
        }
        deg /= 2;
        a = mul(a, a);
    }
    return res;
}

int rev(int x) {
    if (mod == 1)
        return 0;
    return binpow(x, modphi - 1);
}

const int maxn = 100100;
vector<pair<int, int>> g[maxn];
int p10[2][maxn];

int cnt[maxn];
int worst[maxn];
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

int CENTER, ALL;
void findCenter(int u, int up = 0, int prev = -1) {
    int worst = up;
    for (auto p: g[u]) {
        int v = p.first;
        if (v == prev)
            continue;
        worst = max(worst, cnt[v]);
        findCenter(v, up + cnt[u] - cnt[v], u);
    }
    if (worst <= ALL / 2)
        CENTER = u;
}

map<int, int> C[2];
vector<int> A, B;
ll ANS;

void dfs2(int u, int a, int b, int h, int prev = -1) {
    A.push_back(a);
    B.push_back(b);
    int delta = C[0][(mod - b) % mod] + C[1][(mod - a) % mod];
    ANS += delta;
    for (auto p: g[u]) {
        int v = p.first;
        if (v == prev)
            continue;
        int dig = p.second % mod;
        dfs2(v, add(a, mul(p10[0][h], dig)), add(b, mul(p10[1][h + 1], dig)), h + 1, u);
    }
}

void dfs(int u) {
    pre(u);
    CENTER = -1, ALL = cnt[u];
    findCenter(u);
    assert(CENTER != -1);
    u = CENTER;

    C[0].clear();
    C[1].clear();
    C[0][0] = 1;
    C[1][0] = 1;
    for (auto p: g[u]) {
        int v = p.first;
        int dig = p.second % mod;
        dfs2(v, dig, mul(dig, r10), 1, u);
        for (int x: A)
            C[0][x]++;
        for (int x: B)
            C[1][x]++;
        A.clear();
        B.clear();

        int j = 0;
        while (g[v][j].first != u)
            ++j;
        g[v].erase(g[v].begin() + j);
    }
    for (auto p: g[u])
        dfs(p.first);
}

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    cin >> n >> mod;
    calcphi();
    r10 = rev(10);
    p10[0][0] = p10[1][0] = 1;
    for (int i = 1; i < maxn; ++i) {
        p10[0][i] = mul(p10[0][i - 1], 10 % mod);
        p10[1][i] = mul(p10[1][i - 1], r10);
    }
    forn (i, n - 1) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    dfs(0);
    cout << ANS << '\n';
    cerr << "Time " << clock() / 1000 << '\n';
}