#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;

ll ppow(ll a, ll n) {
    ll ret = 1, now = a;
    while (n) {
        if (n & 1) {
            ret = (ret * now) % mod;
        }
        now = (now * now) % mod;
        n >>= 1;
    }
    return ret;
}

const int N = (1 << 20);
int a[N];

int count_bit(int x) {
    int ret = 0;
    while (x) {
        if (x & 1) ++ret;
        x >>= 1;
    }
    return ret;
}

int main () {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        a[x]++;
    }
    n = 20;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            if ( ((1 << i) & j) == 0) {
                a[j] += a[ (j ^ (1 << i)) ];
                a[j] %= mod;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < (1 << n); ++i) {
        ans += ppow(-1, count_bit(i)) * ppow(2, a[i]);
        ans %= mod;
    }
    printf("%lld\n", (ans + mod) % mod);
}