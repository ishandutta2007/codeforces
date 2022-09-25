#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 200200;
int col[maxn];
int rk[maxn];
int a[maxn];
int b[maxn];

int get(int u) {
    if (col[u] == u)
        return u;
    return col[u] = get(col[u]);
}

void join(int u, int v) {
    u = get(u), v = get(v);
    if (rk[u] > rk[v])
        swap(u, v);
    if (rk[u] == rk[v])
        rk[v]++;
    col[u] = v;
}

bool used[maxn];

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    int res = 0;
    forn (i, n)
        col[i] = i;
    int rt = -1;
    forn (i, n) {
        int u;
        cin >> u;
        --u;
        a[i] = b[i] = u;
        if (u == i)
            res = -1, rt = u;
        join(u, i);
    }
    //cerr << "RT " << rt << '\n';
    if (rt == -1) {
        int u = 0;
        forn (i, n)
            u = a[u];
        rt = u;
        b[u] = u;
    }
    forn (i, n)
        if (get(i) == i) {
            //cerr << "comp " << i << '\n';
            ++res;
            int u = i;
            while (!used[u]) {
                used[u] = true;
                u = b[u];
            }
            if (u != rt)
                b[u] = rt;
        }
    cout << res << '\n';
    int realRes = 0;
    forn (i, n) {
        cout << b[i] + 1 << ' ';
        realRes += (b[i] != a[i]);
    }
    cout << '\n';
    //cerr << res << ' ' << realRes << '\n';
    assert(realRes == res);
}