#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;

const int N = 1000500;
const int E = 26;

int cnt[N][E];

typedef long long llong;
#ifdef LOCAL42
    #define LLD "%lld"
#else
    #define LLD "%I64d"
#endif

char A[N], B[N];

llong gcd(llong a, llong b)
{
    while (b)
        a %= b, swap(a, b);
    return a;
}

int p, q;

llong get()
{
    llong g = gcd(p, q);
    for (int i = 0; i < q; i++)
    {
        cnt[i % g][B[i] - 'a']++;
    }
    llong ans = 0;
    for (int i = 0; i < p; i++)
    {
        ans += (q / g - cnt[i % g][A[i] - 'a']);
    }
    return ans;
}

int main()
{
    llong n, m;
    scanf(LLD " " LLD " ", &n, &m);
    gets(A);
    gets(B);
    p = strlen(A);
    q = strlen(B);
    assert(n * p == m * q);
    llong ps = p / gcd(p, q);
    llong qs = q / gcd(p, q);
    assert(n % qs == 0 && m % ps == 0);
    llong r = n / qs;
    assert(m / ps == r);
    llong v = get();
    llong ans = r * v;
    printf(LLD "\n", ans);
}