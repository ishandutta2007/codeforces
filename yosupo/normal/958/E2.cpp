#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

struct D {
    ll v; int cnt;
    bool operator<(const D &r) const {
        if (v != r.v) return v < r.v;
        return cnt < r.cnt;
    }
    D operator+(const D &r) const {
        D res;
        res.v = v + r.v;
        res.cnt = cnt + r.cnt;
        return res;
    }
};

void solve() {
    int n, m, k;
    cin >> k >> n;
    V<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(begin(a), end(a));
    m = 1;    
    VV<ll> gw_base(n, V<ll>(m-1)), gh_base(n-1, V<ll>(m));
    VV<ll> gw(n, V<ll>(m-1)), gh(n-1, V<ll>(m));
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m; j++) {
            gh_base[i][j] = a[i+1] - a[i];
//            cin >> gh_base[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m-1; j++) {
//            cin >> gw_base[i][j];
        }
    }
    
    auto check = [&](ll md) {
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < m; j++) {
                gh[i][j] = gh_base[i][j] - md;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m-1; j++) {
                gw[i][j] = gw_base[i][j] - md;
            }
        }

        V<D> dp(1<<m, D{TEN(18), 0}); dp[0] = D{0, 0};
        for (int i = 0; i < n; i++) {
            //gw send
            for (int j = 0; j < m-1; j++) {
                int msk = (3<<j);
                for (int f = 0; f < (1<<m); f++) {
                    if (f & msk) continue;
                    dp[f|msk] = min(dp[f|msk], dp[f] + D{gw[i][j], 1});
                }
            }
            if (i == n-1) break;
            //gh send
            V<D> ndp(1<<m, D{TEN(18), 0});
            for (int f = 0; f < (1<<m); f++) {
                for (int g = 0; g < (1<<m); g++) {
                    if (f & g) continue;                    
                    D d = D{0, 0};
                    for (int j = 0; j < m; j++) {
                        if (g & (1<<j)) {
                            d = d + D{gh[i][j], 1};
                        }
                    }
                    ndp[g] = min(ndp[g], dp[f] + d);
                }
            }
            dp = ndp;
        }

        D ans = D{TEN(18), 0};
        for (int f = 0; f < (1<<m); f++) {
            ans = min(ans, dp[f]);
        }

        return ans;
    };

    ll lw = 0, up = TEN(9) + TEN(6);
    while (up - lw > 1) {
        ll md = (up + lw) / 2;
        D ans = check(md);
        if (ans.cnt <= k) {
            lw = md;
        } else {
            up = md;
        }
    }

    D ans = check(lw);
//    cout << "ANS: " << lw << " " << ans.v << " " << ans.cnt << endl;
    cout << (lw*k + ans.v) << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    solve();
/*    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }*/
    return 0;
}