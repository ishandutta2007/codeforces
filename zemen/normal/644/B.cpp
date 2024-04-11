#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long long i64;
typedef long double ld;

const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 200200;
ll ans[maxn];
ll t[maxn], d[maxn];

int main() {
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int n, b;
    cin >> n >> b;
    ll T = 0;
    int id = 0;
    int s = 0;
    forn (i, n) {
        cin >> t[i] >> d[i];
        while (id < i && (ans[id] == -1 || d[id] + max(t[id], T) <= t[i])) {
            if (ans[id] == -1) {
                ++id;
                continue;
            }
            T = max(T, t[id]) + d[id];
            ans[id++] = T;
            --s;
        }
        if (s > b)
            ans[i] = -1;
        else
            ++s;
    }
    while (id < n) {
        if (ans[id] == -1) {
            ++id;
            continue;
        }
        T = max(T, t[id]) + d[id];
        ans[id++] = T;
        --s;
    }
    forn (i, n)
        cout << ans[i] << ' ';
    cout << '\n';

    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}