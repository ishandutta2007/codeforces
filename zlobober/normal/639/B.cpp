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

vector<pii> ans;

inline void fail() {
    puts("-1");
    exit(0);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, d, h;
    cin >> n >> d >> h;
    if (d > 2 * h) {
        fail();
    }
    if (h == d && h == 1) {
        if (n == 2) {
            puts("1 2");
            return 0;
        } else {
            fail();
        }
    }
    int sz = 1, last = 1;
    for (int i = 0; i < h; ++i) {
        int v = ++sz;
        ans.pb(mp(last, v));
        last = v;
    }
    int leaf_par = ans.back().fs;
    last = 1;
    for (int i = 0; i < d - h; ++i) {
        int v = ++sz;
        ans.pb(mp(last, v));
        last = v;
    }
    if (sz > n) {
        fail();
    }
    while (sz < n) {
        ans.pb(mp(leaf_par, ++sz));
    }
    assert(sz(ans) == n - 1);
    for (pii e : ans) {
        printf("%d %d\n", e.fs, e.sc);
    }
    return 0;
}