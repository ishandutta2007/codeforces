#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 1000100;
struct Fw {
    int t[maxn];

    void put(int pos, int delta) {
        for (int i = pos; i < maxn; i |= i + 1)
            t[i] += delta;
    }

    int get(int r) {
        int res = 0;
        for (int i = r - 1; i >= 0; i = (i & (i + 1)) - 1)
            res += t[i];
        return res;
    }

    int get(int l, int r) {
        return get(r) - get(l);
    }
} fw;

int main() {
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    int n, k;
    cin >> n >> k;
    if (2 * k > n)
        k = n - k;
    int x = 0;
    ll ans = 1;
    forn (iter, n) {
        int y = x + k;
        int q = 0;
        if (y < n) {
            q = fw.get(x + 1, y);
        } else {
            y -= n;
            q = fw.get(x + 1, n) + fw.get(y);
        }
        ans += 1 + q;
        cout << ans << ' ';
        fw.put(x, 1);
        fw.put(y, 1);
        x = y;
    }
    cout << '\n';
}