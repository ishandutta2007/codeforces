#include <cstdio>
using namespace std;

#ifdef LOCAL
    #define LLD "%lld"
#else
    #define LLD "%I64d"
#endif

typedef long long llong;

const int N = 55;
llong A[N];
llong Q[N];
llong P[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf(LLD, &P[i]);
    for (int i = 0; i < 5; i++)
        scanf(LLD, &A[i]);
    llong cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur += P[i];
        for (int j = 4; j >= 0; j--)
            Q[j] += cur / A[j], cur %= A[j];
    }
    for (int i = 0; i < 5; i++)
        printf(LLD"%c", Q[i], " \n"[i == 4]);
    printf(LLD"\n", cur);
}