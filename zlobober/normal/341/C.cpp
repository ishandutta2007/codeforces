#include <cstdio>
#include <memory.h>
using namespace std;

const int N = 2050;

int to[N];
int from[N];

/*int go(int x, int st, bool first = true)
{
    if (x == st && !first)
        return to[x] = -2;
    if (to[x] != -1)
    {
        return to[x] = go(to[x], st, false);
    }
    else
        return -1;
}*/

typedef long long llong;
int A[N];

const llong mod = 1000 * 1000 * 1000 + 7;
llong D[N][N];

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

int main()
{
    int n;
    memset(to, -1, sizeof(to));
    memset(from, -1, sizeof(from));
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
        if (A[i] != -1)
            A[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        to[i] = A[i];
        if (A[i] != -1)
            from[A[i]] = i;
    }
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == -1 && from[i] != -1)
            a++;
        if (from[i] == -1 && A[i] == -1)
            b++;
    }
    eprintf("a = %d, b = %d\n", a, b);
    D[0][0] = 1;
    for (int u = 0; u <= a; u++)
        for (int v = 0; v <= b; v++)
        {
            if (!u && !v)
                continue;
            D[u][v] = 0;
            #define add(x, y) x = (x + y) % mod
            if (u)
                add(D[u][v], (u * D[u - 1][v]) % mod);
            if (u && v)
                add(D[u][v], (v * D[u - 1][v - 1]) % mod);
            if (u)
                add(D[u][v], (v * D[u - 1][v]) % mod);
            if (!u && v)
                add(D[u][v], ((v - 1) * (D[u][v - 1])) % mod);
            if (!u && v > 1)
                add(D[u][v], ((v - 1) * (D[u][v - 2])) % mod);    
        }
    printf("%d\n", (int)D[a][b]);
}