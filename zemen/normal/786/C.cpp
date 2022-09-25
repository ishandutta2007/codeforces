#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);
#define all(x) x.begin(), x.end()

const int maxn = 200100;
int a[maxn];
int VER;
vector<int> pos[maxn];

const int base = 1 << 17;
int t[base * 2];
vector<int> qs[maxn];
int ans[maxn];

int get(int x, int v = 1, int cl = 0, int cr = base) {
    if (x >= t[v])
        return cr;
    if (cl + 1 == cr)
        return cl;
    int cc = (cl + cr) / 2;
    if (x >= t[v * 2])
        return get(x - t[v * 2], v * 2 + 1, cc, cr);
    else
        return get(x, v * 2, cl, cc);
}

void put(int v, int val) {
    v += base;
    t[v] = val;
    while (v > 1) {
        v >>= 1;
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    forn (i, n) {
        scanf("%d", a + i);
        --a[i];
        pos[a[i]].push_back(i);
    }
    forn (i, n) {
        reverse(all(pos[i]));
        if (!pos[i].empty())
            t[pos[i].back() + base]++;
    }
    for (int i = base - 1; i > 0; --i)
        t[i] = t[i * 2] + t[i * 2 + 1];
    forn (i, n)
        qs[0].push_back(i + 1);
    forn (i, n) {
        for (auto k: qs[i]) {
            int to = get(k);
            ++ans[k];
            if (to < n)
                qs[to].push_back(k);
        }
        qs[i].clear();

        put(i, 0);
        int x = a[i];
        pos[x].pop_back();
        if (!pos[x].empty())
            put(pos[x].back(), 1);
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << '\n';
}