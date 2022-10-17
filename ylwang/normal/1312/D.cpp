#include <bits/stdc++.h>
#define LL long long

const int mod = 998244353;

int n, m;
LL up = 1LL, down = 1LL;

LL qpow(LL base, LL power) {
    LL res = 1LL % mod;
    while(power) {
        if(power & 1)
            res = res * base % mod;
        base = base * base % mod;
        power >>= 1;
    }
    return res;
}

int main() {
    std::cin >> n >> m;
    //C(m, n - 1) Wrong!
    for(int i = m; i >= m - (n - 1) + 1; --i) up = 1LL * up * i % mod;
    for(int i = 1; i <= n - 1; ++i) down = 1LL * down * i % mod;
    if(n == 1 || n == 2)
        std::cout << 0;
    else
        std::cout << 1LL * up * qpow(down, mod - 2) % mod * qpow(2, n - 3) % mod * (n - 2) % mod;

    return 0;
}