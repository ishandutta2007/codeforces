#include <cstdio>
#include <cstring>
using namespace std;

const int N = 105;

char A[N], B[N];
char buf[N];

const int E = 26;
int go[N][E];

typedef long long llong;

const llong P = 4243;
llong PP[N];
llong H[N];

inline llong get(int i, int j)
{
    return H[j] - H[i] * PP[j - i];
}

char D[N][N][N];
int prv[N][N][N];
bool add[N][N][N];

int a, b, n;

inline void relax(int i1, int j1, int v1, int i2, int j2, int v2, int q)
{
    if (D[i1][j1][v1] < D[i2][j2][v2] + q)
        D[i1][j1][v1] = D[i2][j2][v2] + q, prv[i1][j1][v1] = i2 * N * N + j2 * N + v2, add[i1][j1][v1] = q;
}

char str[N];

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

int main()
{
    gets(A);
    gets(B);
    gets(buf);
    a = strlen(A);
    b = strlen(B);
    n = strlen(buf);
    PP[0] = 1;
    for (int i = 0; i < n; i++)
        PP[i + 1] = PP[i] * P, H[i + 1] = H[i] * P + buf[i] - 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            go[i][j] = 0;
            for (int l = i + 1; l >= 1; l--)
            {
                llong h2 = get(i - l + 1, i) * P + j;
                llong h1 = get(0, l);
                if (h1 == h2)
                {
                    go[i][j] = l;
                    break;
                }
            }
        }
    }
    memset(D, -1, sizeof(D));
    D[0][0][0] = 0;
    for (int i = 0; i <= a; i++)
        for (int j = 0; j <= b; j++)
            for (int v = 0; v < n; v++)
            {
                if (D[i][j][v] == -1)
                    continue;
                //eprintf("%d %d %d %d\n", i, j, v, D[i][j][v]);
                if (i != a && j != b && A[i] == B[j])
                    relax(i + 1, j + 1, go[v][A[i] - 'A'], i, j, v, 1);
                if (i != a)
                    relax(i + 1, j, v, i, j, v, 0);
                if (j != b)
                    relax(i, j + 1, v, i, j, v, 0);
           }
    int ans = -1;
    int ansp = -1;
    for (int v = 0; v < n; v++)
        if (ans < D[a][b][v])
            ans = D[a][b][v], ansp = v;
    eprintf("%d %d\n", ans, ansp);
    int cur = a * N * N + b * N + ansp;
    int pt = 0;
    while (true)
    {
        int v = cur % N;
        cur /= N;
        int j = cur % N;
        cur /= N;
        int i = cur;
        if (i == 0 && j == 0)
            break;
        if (add[i][j][v])
            str[ans - (++pt)] = A[i - 1];
        int pcur = prv[i][j][v];
        cur = pcur;
    }
    if (!ans)
        puts("0");
    else
        puts(str);
    
    return 0;
}