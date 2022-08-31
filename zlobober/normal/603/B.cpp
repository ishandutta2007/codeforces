#include <cstdio>
#include <cassert>
using namespace std;

int MOD = 1000 * 1000 * 1000 + 7;

inline int mul(int a, int b) {
    return a * 1ll * b % MOD;
}

int powmod(int a, int k) {
    int res = 1;
    while (k) {
        if (k & 1)
            res = mul(res, a);
        k >>= 1;
        a = mul(a, a);
    }
    return res;
}

int main() {
    int p, k;
    scanf("%d %d", &p, &k);
    int ans = 0;
    if (k == 0) {
        ans = powmod(p, p - 1);
    } else {
        int cyc = 0;
        int cur = 1;
        while (cyc == 0 || cur != 1)
            cur = 1ll * cur * k % p, cyc++;
        assert((p - 1) % cyc == 0);
        ans = powmod(p, (p - 1) / cyc);
        if (k == 1) {
            ans = mul(ans, p);
        }
    }
    printf("%d\n", ans);
}