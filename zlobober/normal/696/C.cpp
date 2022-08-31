#include <cstdio>
using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;

typedef long long llong;

int powmod(int x, llong b) {
    x %= MOD;
    int ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = 1ll * ans * x % MOD;
        }
        x = 1ll * x * x % MOD;
        b >>= 1;
    }
    return ans;
}

int inv(int x) {
    return powmod(x, MOD - 2);
}

const int N = 100500;

llong A[N];

int main() {
    int k;
    scanf("%d", &k);
    bool even = false;
    for (int i = 0; i < k; i++) {
        scanf("%lld", &A[i]);
        even |= (A[i] % 2 == 0);
    }
    llong den = 2;
    for (int i = 0; i < k; i++) {
        den = powmod(den, A[i]);
    }
    llong num;
    if (even) {
        num = (den + 2) % MOD;
        num = (num * inv(3)) % MOD;
    } else {
        num = (den + MOD - 2) % MOD;
        num = (num * inv(3)) % MOD;
    }
    num = (num * inv(2)) % MOD;
    den = (den * inv(2)) % MOD;
    printf("%lld/%lld\n", num, den);
}