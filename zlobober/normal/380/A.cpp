#include <cstdio>
#include <cassert>
using namespace std;

const int N = 300500;

typedef long long llong;

#ifdef LOCAL42
    #define LLD "%lld"
#else
    #define LLD "%I64d"
#endif

int T[N], L[N], C[N];
int m;
int len = 0;
const int inf = 100500;

int A[N];

int fs = -1, pos = -1;

void apply()
{
    for (int i = 0; i < m; i++)
    {
        if (i == m - 1)
        {
            pos = len;
            fs = m - 1;
            goto end;
        }
        if (T[i] == 1)
        {
            A[len++] = L[i];
            if (len >= inf)
            {
                fs = i + 1;
                pos = len;
                goto end;
            }
        }
        else
        {
            assert(L[i] <= len);
            for (int q = 0; q < C[i]; q++)
            {
                for (int j = 0; j < L[i]; j++)
                {
                    A[len++] = A[j];
                }
                if (len >= inf)
                {
                    for (int u = m - 1; u >= i; u--)
                        T[u + 1] = T[u], L[u + 1] = L[u], C[u + 1] = C[u];
                    ++m;
                    C[i + 1] = C[i] - q - 1;
                    C[i] = q + 1;
                    fs = i + 1;
                    pos = len;
                    goto end;
                }
            }
        }
    }
end:;
}

inline int blen(int o)
{
    if (T[o] == 1)
        return 1;
    else
        return L[o] * C[o];
}

int main()
{
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &T[i]);
        if (T[i] == 1)
            scanf("%d", &L[i]);
        else
            scanf("%d %d", &L[i], &C[i]);
    }
    T[m] = 0;
    L[m] = -42;
    m++;
    apply();
    int n;
    scanf("%d", &n);
    int curg = fs;
    llong l = pos, r = pos + blen(fs);
    for (int i = 0; i < n; i++)
    {
        llong x;
        scanf(LLD, &x);
        --x;
        int ans = -1;
        if (x < len)
            ans = A[(int)x];
        else
        {
            while (r <= x && curg < m - 1)
                l = r, r += blen(++curg);
            assert(l <= x && x < r);
            if (T[curg] == 1)
                ans = L[curg];
            else
                ans = A[(x - l) % L[curg]];
        }
        printf("%d%c", ans, " \n"[i + 1 == n]);
    }
}