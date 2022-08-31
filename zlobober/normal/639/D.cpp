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

const ll inf = 1e18;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(2e5) + 100;

int a[N];
vector<pii> lst[5];
multiset<ll> top;

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, need, b, c;
    cin >> n >> need >> b >> c;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        a[i] += int(1e9);
    }
    sort(a, a + n);
    if (5 * c <= b) {
        ll ans = inf;
        ll sum = 0;
        for (int i = 0; i < need; ++i) {
            sum += a[i];
        }
        for (int i = need - 1; i < n; ++i) {
            ans = min(ans, (1LL * a[i] * need - sum) * c);
            if (i + 1 < n) {
                sum += a[i + 1];
                sum -= a[i - need + 1];
            }
        }
        cout << ans << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            lst[(a[i] + j) % 5].pb(mp((a[i] + j) / 5, j * c));
        }
    }
    ll ans = inf;
    for (int i = 0; i < 5; ++i) {
        sort(all(lst[i]));
        ll sum = 0;
        top.clear();
        for (int j = 0; j < sz(lst[i]); ++j) {
            sum += lst[i][j].sc - 1LL * lst[i][j].fs * b;
            top.insert(lst[i][j].sc - 1LL * lst[i][j].fs * b);
            while (sz(top) > need) {
                auto it = top.end();
                --it;
                sum -= *it;
                top.erase(it);
            }
            if (sz(top) == need) {
                ans = min(ans, 1LL * lst[i][j].fs * b * need + sum);
            }
        }
    }
    cout << ans << endl;
    return 0;
}