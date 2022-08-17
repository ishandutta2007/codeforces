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
const int N = 111;

vector<pii> op;
int ans[N][N];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < q; ++i) {
        int t, x;
        scanf("%d %d", &t, &x);
        --x;
        if (t == 1) {
            op.pb(mp(0, x));
        } else if (t == 2) {
            op.pb(mp(1, x));
        } else {
            assert(t == 3);
            int y, val;
            scanf("%d %d", &y, &val);
            --y;
            for (int j = sz(op) - 1; j >= 0; --j) {
                if (op[j].fs == 0) {
                    if (x == op[j].sc) {
                        if (++y >= m) {
                            y = 0;
                        }
                    }
                } else {
                    if (y == op[j].sc) {
                        if (++x >= n) {
                            x = 0;
                        }
                    }
                }
            }
            ans[x][y] = val;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", ans[i][j]);
        }
        puts("");
    }
    return 0;
}