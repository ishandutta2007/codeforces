#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxk = 505;
const int maxn = maxk * maxk;

namespace dsu {
int col[maxn];
int ssz[maxn];

int get(int u) {
    if (u == col[u])
        return u;
    return col[u] = get(col[u]);
}

void join(int u, int v) {
    u = get(u), v = get(v);
    if (u != v) {
        ssz[v] += ssz[u];
        col[u] = v;
    }
}

void init(int n) {
    forn (i, n) {
        col[i] = i;
        ssz[i] = 1;
    }
}

};

char a[maxk][maxk];
int pr[maxk][maxk];
int n, k;

int cnt[maxn];
int sum = 0;

void add(int x, int y) {
    if (!a[x][y])
        return;
    x = dsu::col[x * n + y];
    if (cnt[x]++ == 0)
        sum += dsu::ssz[x];
}

void del(int x, int y) {
    if (!a[x][y])
        return;
    x = dsu::col[x * n + y];
    if (--cnt[x] == 0)
        sum -= dsu::ssz[x];
}

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    cin >> n >> k;
    forn (i, n) {
        scanf("%s", a[i]);
        forn (j, n)
            a[i][j] = (a[i][j] == '.');
    }
    forn (i, n)
        forn (j, n)
            pr[i + 1][j + 1] = a[i][j] + pr[i][j + 1] + pr[i + 1][j] - pr[i][j];
    dsu::init(n * n);
    forn (i, n)
        forn (j, n) {
            if (!a[i][j])
                continue;
            if (i && a[i - 1][j])
                dsu::join(i * n + j, (i - 1) * n + j);
            if (j && a[i][j - 1])
                dsu::join(i * n + j, i * n + (j - 1));
        }
    forn (i, n * n)
        dsu::get(i);

    int res = 0;
    forn (i, n - k + 1) {
        forn (u, n * n)
            cnt[u] = 0;
        sum = 0;

        for (int x = max(0, i - 1); x < min(n, i + k + 1); ++x)
            for (int y = 0; y < min(n, k + 1); ++y)
                add(x, y);
        forn (j, n - k + 1) {
            if (i && j)
                del(i - 1, j - 1);
            if (i && j + k < n)
                del(i - 1, j + k);
            if (i + k < n && j + k < n)
                del(i + k, j + k);
            if (i + k < n && j)
                del(i + k, j - 1);

            int cres = sum + k * k - (pr[i + k][j + k] + pr[i][j] - pr[i + k][j] - pr[i][j + k]);
            res = max(res, cres);

            if (i && j)
                add(i - 1, j - 1);
            if (i && j + k < n)
                add(i - 1, j + k);
            if (i + k < n && j + k < n)
                add(i + k, j + k);
            if (i + k < n && j)
                add(i + k, j - 1);

            if (j == n - k)
                break;

            if (j)
                for (int x = max(0, i - 1); x < min(n, i + k + 1); ++x)
                    del(x, j - 1);
            if (j + k + 1 < n)
                for (int x = max(0, i - 1); x < min(n, i + k + 1); ++x)
                    add(x, j + k + 1);
        }
    }
    cout << res << '\n';
}