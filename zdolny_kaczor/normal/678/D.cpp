# include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int MOD = 1e9 + 7;
#define PLL pair <long long, long long>
PLL operator * (PLL a, PLL b) {
    return make_pair(a.f * b.f % MOD, (a.f * b.s + a.s) % MOD);
}
PLL power(PLL a, long long e) {
    if (e == 1)
        return a;
    if (e % 2)
        return a * power(a, e - 1);
    return power(a * a, e / 2);
}
int main() {
    long long a, b, x, n;
    scanf("%lld%lld%lld%lld", &a, &b, &n, &x);
    PLL lin = power(make_pair(a, b), n);
    printf("%lld\n", (lin.first * x + lin.second) % MOD);
}