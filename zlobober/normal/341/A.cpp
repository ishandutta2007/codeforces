#include <cstdio>
#include <cassert>
#include <algorithm>
using namespace std;

typedef long long llong;

const int N = 100500;

llong A[N];

#ifdef LOCAL42
    #define LLD "%lld"
#else
    #define LLD "%I64d"
#endif

llong gcd(llong a, llong b)
{
    while (b)
        a %= b, swap(a, b);
    return a;
}

int main()
{
    int n;
    scanf("%d", &n);
    llong S1 = 0;
    for (int i = 0; i < n; i++)
        scanf(LLD, &A[i]);
    for (int i = 0; i < n; i++)
        S1 += A[i];
    llong S2 = 0;
    llong s = 0;
    sort(A, A + n);
    for (int i = 0; i < n; i++)
    {
        S2 += i * A[i] - s;
        s += A[i];
    }
    llong q2 = (llong)n * (n - 1) / 2;
    llong q1 = (llong)n;
    S2 *= 2;
    q2 *= 2;
    q2 /= (n - 1);
    assert(q1 == q2);
    llong S = S1 + S2;
    llong g = gcd(S, q1);
    S /= g;
    q1 /= g;
    printf(LLD " " LLD "\n", S, q1);
    return 0;
}