#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;
const ll rev_2 = 1000000007 / 2 + 1;
const int N = 500006;

ll a[N];
ll cnt[62];

int main () {
    // cerr << 2 * rev_2 % mod << endl;
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &a[i]);
            for (int j = 0; j < 62; ++j) {
                if ((a[i] & (1ll << j)) != 0) cnt[j]++;
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ll A = 0, B = 0;
            for (int j = 0; j < 62; ++j) {
                if (((1ll << j) & a[i]) == 0) {
                    B += (cnt[j]) * ((1ll << j) % mod) % mod;
                }
                else {
                    A += (cnt[j]) * ((1ll << j) % mod) % mod;
                    B += (n) * ((1ll << j) % mod) % mod;
                }
                A %= mod, B %= mod;
            }
            ans += ((A + B) * (A + B) % mod - A * A - B * B) % mod;
            ans = (ans % mod + mod) % mod;
        }
        memset(cnt, 0, sizeof(cnt));
        printf("%lld\n", ans * rev_2 % mod);
    }
}