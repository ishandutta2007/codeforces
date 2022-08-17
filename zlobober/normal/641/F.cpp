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

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = 1010;

struct func {
    
    int n;
    pii a[N * N];
    
    inline void read(int _n) {
        n = _n;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &a[i].fs, &a[i].sc);
        }
    }
    
};

int n, sz;
func f, g;
vi topsort;
bool used[2 * N];
int col[2 * N], xs[N];
bool can[2 * N][2 * N];
bitset<2 * N> go[2 * N];

inline void add(int xnum, int x, int ynum, int y) {
    can[xnum * 2 + x][ynum * 2 + y] = true;
}

void dfs1(int v) {
    used[v] = true;
    for (int i = 0; i < 2 * n; ++i) {
        if (can[v][i] && !used[i]) {
            dfs1(i);
        }
    }
    topsort.pb(v);
}

void dfs2(int v) {
    col[v] = sz;
    for (int i = 0; i < 2 * n; ++i) {
        if (can[i][v] && col[i] == -1) {
            dfs2(i);
        }
    }
}

inline bool check(int x, int y) {
    return go[col[x]].test(col[y]);
}

inline void build() {
    memset(used, 0, sizeof(used));
    topsort.clear();
    for (int i = 0; i < 2 * n; ++i) {
        if (!used[i]) {
            dfs1(i);
        }
    }
    reverse(all(topsort));
    memset(col, -1, sizeof(col));
    sz = 0;
    for (int v : topsort) {
        if (col[v] == -1) {
            dfs2(v);
            ++sz;
        }
    }
    for (int i = 0; i < n; ++i) {
        xs[i] = (col[2 * i] < col[2 * i + 1] ? 1 : 0);
    }
}

inline bool check(const func& f) {
    for (int i = 0; i < f.n; ++i) {
        pii p = f.a[i];
        int xnum = abs(p.fs) - 1, ynum = abs(p.sc) - 1;
        int xval = (p.fs < 0 ? (1 - xs[xnum]) : xs[xnum]);
        int yval = (p.sc < 0 ? (1 - xs[ynum]) : xs[ynum]);
        if ((xval | yval) == 0) {
            return false;
        }
    }
    return true;
}

inline void solve(const func& f, const func& g) {
    memset(can, 0, sizeof(can));
    for (int i = 0; i < g.n; ++i) {
        int x = 1, y = 1, xnum = abs(g.a[i].fs) - 1, ynum = abs(g.a[i].sc) - 1;
        if (g.a[i].fs < 0) {
            x = 0;
        }
        if (g.a[i].sc < 0) {
            y = 0;
        }
        add(xnum, 1 - x, ynum, y);
        add(ynum, 1 - y, xnum, x);
    }
    build();
    for (int i = 0; i < n; ++i) {
        if (col[2 * i] == col[2 * i + 1]) {
            return;
        }
    }
    for (int i = 0; i < 2 * n; ++i) {
        go[i].reset();
        go[i].set(i);
    }
    for (int i = sz(topsort) - 1; i >= 0; --i) {
        int v = topsort[i];
        for (int j = i + 1; j < sz(topsort); ++j) {
            int u = topsort[j];
            if (can[v][u] && col[v] != col[u]) {
                go[col[v]] |= go[col[u]];
            }
        }
    }
    for (int i = 0; i < f.n; ++i) {
        int x = 0, y = 0, xnum = abs(f.a[i].fs) - 1, ynum = abs(f.a[i].sc) - 1;
        if (f.a[i].fs < 0) {
            x = 1;
        }
        if (f.a[i].sc < 0) {
            y = 1;
        }
        if (xnum == ynum) {
            if (x != y) {
                continue;
            }
            if (!check(2 * xnum + x, 2 * xnum + (1 - x))) {
                add(xnum, 1 - x, xnum, x);
                build();
                for (int j = 0; j < n; ++j) {
                    printf("%d ", xs[j]);
                }
                puts("");
                //assert(check(f) != check(g));
                exit(0);
            }
            continue;
        }
        if (check(2 * xnum + x, 2 * xnum + (1 - x))) {
            continue;
        }
        if (check(2 * xnum + x, 2 * ynum + (1 - y)) && check(2 * ynum + y, 2 * xnum + (1 - x))) {
            continue;
        }
        if (check(2 * ynum + y, 2 * ynum + (1 - y))) {
            continue;
        }
        if (check(2 * ynum + y, 2 * xnum + (1 - x)) && check(2 * xnum + x, 2 * ynum + (1 - y))) {
            continue;
        }
        add(xnum, 1 - x, xnum, x);
        add(ynum, 1 - y, ynum, y);
        build();
        for (int j = 0; j < n; ++j) {
            printf("%d ", xs[j]);
        }
        puts("");
        //assert(check(f) != check(g));
        exit(0);
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int m1, m2;
    scanf("%d %d %d", &n, &m1, &m2);
    f.read(m1);
    g.read(m2);
    solve(f, g);
    solve(g, f);
    puts("SIMILAR");
    return 0;
}