#include <cstdio>
#include <algorithm>
using namespace std;

const int K = 21;

typedef long long llong;
llong I1[K], I2[K];
const int N = 1 << 21;

#ifdef LOCAL42
    #define LLD "%lld"
#else
    #define LLD "%I64d"
#endif

int tmp[N];

int A[N];

void mer(int l, int r, int d)
{
    if (!d)
        return;
    int m = (l + r) / 2;
    mer(l, m, d - 1);
    mer(m, r, d - 1);
    int a = l, b = m;
    int c = 0;
    int aa = a, bb = b;
    while (a != m && b != r)
    {
        if (aa == a)
            while (aa != m && A[a] == A[aa])
               aa++;
        if (bb == b)
            while (bb != r && A[bb] == A[b])
                bb++;
        if (A[a] < A[b])
        {
            I1[d] += (b - m) * 1LL * (aa - a);
            while (a != aa)
                tmp[c++] = A[a++];
        }
        else if (A[a] > A[b])
        {
            I2[d] += (a - l) * 1LL * (bb - b);
            while (b != bb)
                tmp[c++] = A[b++];
        }
        else
        {
            I1[d] += (b - m) * 1LL * (aa - a);
            I2[d] += (a - l) * 1LL * (bb - b);
            while (a != aa)
                tmp[c++] = A[a++];
            while (b != bb)
                tmp[c++] = A[b++];
        }
    }
    while (a != m)
        tmp[c++] = A[a++], I1[d] += b - m;
    while (b != r)
        tmp[c++] = A[b++], I2[d] += a - l;
    for (int i = 0; i < r - l; i++)
        A[l + i] = tmp[i];
}

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

int main()
{
    int k;
    scanf("%d", &k);
    int n = (1 << k);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    mer(0, n, k);
    for (int i = 0; i <= k; i++)
        eprintf(LLD " " LLD "\n", I1[i], I2[i]);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int q;
        scanf("%d", &q);
        for (int j = 0; j <= q; j++)
            swap(I1[j], I2[j]);
        llong sum = 0;
        for (int j = 0; j <= k; j++)
            sum += I1[j];
        printf(LLD "\n", sum);
    }
}