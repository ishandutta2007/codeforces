#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 210;
int n, K;
ll x[maxn], y[maxn];
pair<int, ll> f[maxn][maxn];

int main() {
    scanf("%d %d", &n, &K), K++;
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &x[i], &y[i]);
    }
    auto cross = [&](int i, int j, int k) {
        ll x1 = x[j] - x[i], y1 = y[j] - y[i];
        ll x2 = x[k] - x[i], y2 = y[k] - y[i];
        return x1 * y2 - x2 * y1;
    };
    auto chk = [&](ll x) {
        for (int len = 3; len <= n; len++) {
            for (int l = 1, r = len; r <= n; l++, r++) {
                f[l][r] = {-1e9, 0};
                for (int k = l + 1; k < r; k++) {
                    int a = f[l][k].first + f[k][r].first;
                    ll b = f[l][k].second + f[k][r].second + cross(l, k, r);
                    if (b >= x) a++, b = 0;
                    f[l][r] = max(f[l][r], make_pair(a, b));
                }
            }
        }
        return f[1][n].first >= K;
    };
    ll l = 0, r = 1e17, ans;
    while (l <= r) {
        ll mid = (l + r) / 2;
        chk(mid) ? l = (ans = mid) + 1 : r = mid - 1;
    }
    printf("%lld\n", ans);
    return 0;
}