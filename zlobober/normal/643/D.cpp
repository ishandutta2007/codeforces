#pragma comment(linker, "/STACK:256000000")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#undef NDEBUG
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pbk pop_back
#define sz(s) ((int) (s).size())
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define prev huprev
#define next hunext
#define link hulink
#define hash huhash
#define rank hurank
#define y0 yy0
#define y1 yy1

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll inf = ll(1e18);
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(1e5) + 100;
const int K = 800;

int k[N], out[N], heavy[N], heavy_ver[N];
set<int> in[N];
ll val[N], t[N];
vector<ll> lst[N];
multiset<ll> heavy_val[N];
tuple<int, int, int> q[N];

int iters = 0;

inline void add(int v, ll add) {
    ++iters;
    int num = heavy[out[v]];
    heavy_val[num].erase(heavy_val[num].find(val[v]));
    val[v] += add;
    heavy_val[num].insert(val[v]);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", t + i);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", out + i);
        --out[i];
        in[out[i]].insert(i);
        ++k[out[i]];
    }
    for (int i = 0; i < m; ++i) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int x, y;
            scanf("%d %d", &x, &y);
            --x;
            --y;
            q[i] = mt(t, x, y);
            continue;
        }
        if (t == 2) {
            int x;
            scanf("%d", &x);
            --x;
            q[i] = mt(t, x, -1);
            continue;
        }
        assert(t == 3);
        q[i] = mt(t, -1, -1);
    }
    for (int i = 0; i < n; ++i) {
        val[i] = t[i] - (k[i] + 1) * (t[i] / (k[i] + 2)) + t[out[i]] / (k[out[i]] + 2);
        for (int j : in[i]) {
            val[i] += t[j] / (k[j] + 2);
        }
    }
    int ptr = 0, sz = 1;
    while (ptr < m) {
        int nptr = ptr, cnt1 = 0;
        while (nptr < m && cnt1 < K) {
            int tt, x, y;
            tie(tt, x, y) = q[nptr];
            if (tt == 1) {
                ++cnt1;
            }
            ++nptr;
        }
        for (int i = 0; i < sz; ++i) {
            heavy_val[i].clear();
        }
        for (int i = 0; i < n; ++i) {
            if (heavy[out[i]] > 0) {
                val[i] += t[out[i]] / (k[out[i]] + 2);
            }
        }
        for (int i = 0; i < n; ++i) {
            heavy[i] = 0;
        }
        sz = 1;
        for (int i = 0; i < n; ++i) {
            if (k[i] >= K) {
                heavy_ver[sz] = i;
                heavy[i] = sz++;
            }
        }
        for (int i = 0; i < sz; ++i) {
            lst[i].clear();
        }
        for (int i = 0; i < n; ++i) {
            ++iters;
            if (heavy[out[i]] > 0) {
                val[i] -= t[out[i]] / (k[out[i]] + 2);
            }
            lst[heavy[out[i]]].pb(val[i]);
        }
        for (int i = 0; i < sz; ++i) {
            sort(all(lst[i]));
            auto it = heavy_val[i].end();
            for (ll val : lst[i]) {
                it = heavy_val[i].insert(it, val);
            }
        }
        for (int i = ptr; i < nptr; ++i) {
            int tt, x, y;
            tie(tt, x, y) = q[i];
            if (tt == 1) {
                int z = out[x];
                // remove z
                in[z].erase(x);
                heavy_val[heavy[z]].erase(heavy_val[heavy[z]].find(val[x]));
                if (heavy[z] == 0) {
                    val[x] -= t[z] / (k[z] + 2);
                }
                add(z, -(t[x] / (k[x] + 2)));
                add(z, -(t[z] - (k[z] + 1) * (t[z] / (k[z] + 2))));
                add(out[z], -(t[z] / (k[z] + 2)));
                if (heavy[z] == 0) {
                    for (int v : in[z]) {
                        add(v, -(t[z] / (k[z] + 2)));
                    }
                }
                --k[z];
                add(z, t[z] - (k[z] + 1) * (t[z] / (k[z] + 2)));
                add(out[z], t[z] / (k[z] + 2));
                if (heavy[z] == 0) {
                    for (int v : in[z]) {
                        add(v, t[z] / (k[z] + 2));
                    }
                }
                // add y
                add(y, t[x] / (k[x] + 2));
                add(y, -(t[y] - (k[y] + 1) * (t[y] / (k[y] + 2))));
                add(out[y], -(t[y] / (k[y] + 2)));
                if (heavy[y] == 0) {
                    for (int v : in[y]) {
                        add(v, -(t[y] / (k[y] + 2)));
                    }
                }
                ++k[y];
                add(y, t[y] - (k[y] + 1) * (t[y] / (k[y] + 2)));
                add(out[y], t[y] / (k[y] + 2));
                if (heavy[y] == 0) {
                    for (int v : in[y]) {
                        add(v, t[y] / (k[y] + 2));
                    }
                }
                if (heavy[y] == 0) {
                    val[x] += t[y] / (k[y] + 2);
                }
                heavy_val[heavy[y]].insert(val[x]);
                in[y].insert(x);
                out[x] = y;
                continue;
            }
            if (tt == 2) {
                ll res = val[x];
                if (heavy[out[x]] > 0) {
                    res += t[out[x]] / (k[out[x]] + 2);
                }
                printf("%lld\n", res);
                continue;
            }
            assert(tt == 3);
            ll min_val = inf, max_val = -inf;
            for (int i = 0; i < sz; ++i) {
                ll add = (i == 0 ? 0 : t[heavy_ver[i]] / (k[heavy_ver[i]] + 2));
                if (sz(heavy_val[i]) > 0) {
                    min_val = min(min_val, *(heavy_val[i].begin()) + add);
                    max_val = max(max_val, *(heavy_val[i].rbegin()) + add);
                }
            }
            printf("%lld %lld\n", min_val, max_val);
        }
        ptr = nptr;
    }
    cerr << "iters = " << iters << endl;
    return 0;
}