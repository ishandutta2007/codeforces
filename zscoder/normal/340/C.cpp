#include <stdio.h>
#include <algorithm>
#define ll long long

using namespace std;

int x[100010];

ll gcd(ll A, ll B) {
    if (B == 0)
        return A;
    return gcd(B, A % B);
}

int main() {
    int n;
    ll sum1 = 0, sum2 = 0, sumBefore = 0, sumtot = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x[i]);
        sum1 += x[i];
    }
    sort(x + 1, x + n + 1);
    for (int i = 1; i <= n; ++i) {
        sum2 += 1LL * x[i] * (i - 1) - sumBefore;
        sumBefore += x[i];
    }
    sumtot = sum1 + 2 * sum2;
    ll _gcd = gcd(sumtot, n);
    printf("%I64d %I64d", sumtot / _gcd, n / _gcd);
    return 0;
}