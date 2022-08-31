#include <cstdio>
#include <memory.h>
#include <vector>
using namespace std;

const int N = 100500;
int A[N];
int S[N];
int n, m, d;

vector<char> prof()
{
    int k;
    scanf("%d", &k);
    memset(A, 0, sizeof(A));
    for (int i = 0; i < k; i++)
    {
        int t;
        scanf("%d", &t);
        A[t] = 1;
    }
    for (int i = 0; i <= n; i++)
        S[i + 1] = S[i] + A[i];
    vector<char> ret(n - d + 1);
    for (int i = 1; i <= n - d + 1; i++)
        ret[i - 1] = (S[i + d] - S[i]) > 0;
    return ret;
}

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const int M = 20;
const int MSK = 1 << M;

bool bad[MSK];

char* bin(int msk, int m)
{
    char* ret = new char[m + 1];
    ret[m] = 0;
    for (int i = 0; i < m; i++)
        ret[i] = '0' + ((msk >> i) & 1);
    return ret;
}

int main()
{
    scanf("%d %d %d", &n, &m, &d);
    vector<vector<char> > P;
    for (int i = 0; i < m; i++)
        P.push_back(prof());
    /*for (int i = 0; i < m; i++)
        for (int j = 0; j < P[i].size(); j++)
            eprintf("%d%c", (int)P[i][j], " \n"[j + 1 == P[i].size()]);*/
    for (int i = 0; i < n - d + 1; i++)
    {
        int msk = 0;
        for (int j = 0; j < m; j++)
            msk |= P[j][i] * (1 << j);
        //eprintf("msk %d -> %s\n", i, bin(msk, m));
        bad[((1 << m) - 1) ^ msk] = true;
    }
    for (int msk = (1 << m) - 1; msk >= 0; msk--)
    {
        for (int t = 0; t < m; t++)
            if (bad[msk | (1 << t)])
                bad[msk] = true;
    }
    int mn = 1e9;
    for (int msk = 0; msk < (1 << m); msk++)
    {
        //eprintf("%s -> %d\n", bin(msk, m), bad[msk]);
        if (!bad[msk])
            mn = min(mn, __builtin_popcount(msk));
    }
    printf("%d\n", mn);
}