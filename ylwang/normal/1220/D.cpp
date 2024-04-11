#include <iostream>
#include <cstdio>
#include <algorithm>

#define int long long

template <typename Tp>
inline void read(Tp &x) {
    x = 0;
    bool f = true; char ch = getchar();
    for ( ; ch < '0' || ch > '9'; ch = getchar()) f ^= ch == '-';
    for ( ; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + (ch ^ 48);
    x = f ? x : -x;
}

const int M = 105, N = 2e5 + 7;

int tot[N], a[N], c[M];

signed main() {
    int n;
    read(n);
    int maxx = 0, pos = 0;
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        int x = a[i], cnt = 0;
        for ( ; !(x & 1); x >>= 1, ++cnt);
        tot[i] = cnt;
        ++c[cnt];
        if (c[cnt] > maxx) maxx = c[cnt], pos = cnt;
    }
    printf("%lld\n", n - maxx);
    for (int i = 1; i <= n; ++i) if (tot[i] != pos) printf("%lld ", a[i]);
    return 0;
}