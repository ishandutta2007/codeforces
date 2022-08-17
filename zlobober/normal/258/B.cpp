#include <cstdio>
#include <memory.h>
using namespace std;

const int L = 11;

char buf[L + 2];

int Q[L][L][2];
int C[L];

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

bool H[10];

typedef long long llong;
const llong MOD = 1000*1000*1000 + 7;

const int N = 6;
//llong D[N + 1][L][N + 1][L];

int cnt[N];
int E[10];

int main()
{
    H[4] = H[7] = true;
    int m;
    scanf("%d", &m);
    sprintf(buf, "%011d", m);
    Q[0][0][0] = 1;
    for (int i = 0; i < L - 1; i++)
    {
        for (int j = 0; j < L - 1; j++)
        {
            for (int ot = 0; ot < 2; ot++)
            {
                for (int k = 0; k <= ((ot) ? 9 : (buf[i + 1] - '0')); k++)
                {
                    Q[i + 1][j + H[k]][ot || (k < (buf[i + 1] - '0'))] += Q[i][j][ot];
                }
            }
        }
    }
    for (int i = 0; i < L; i++)
    {
        C[i] = Q[L - 1][i][0] + Q[L - 1][i][1] - !i;
        eprintf("%d%c", C[i], " \n"[i == L - 1]);
    }
    /*D[0][0][0][0] = 1;
    for (int i = 0; i < N; i++)
    {
        for (int p = 0; p < L; p++)
            for (int g = 0; g < N; g++)
                for (int s = 0; s < L; s++)
                {
                    int v;
                    // v == p
                    v = p;
                    if (s + v < L)
                        D[i + 1][p][g + 1][s + v] = (D[i + 1][p][g + 1][s + v] + D[i][p][g][s] * (C[v] - g)) % MOD;

                    for (v = p + 1; v < L; v++)
                    {
                        if (s + v < L)
                            D[i + 1][v][1][s + v] = (D[i + 1][v][1][s + v] + D[i][p][g][s] * (C[v] - 1 + 1))) % MOD;
                    }
                }
    }*/

    llong ans = 0;

    for (int msk = 0; msk < 1000000; msk++)
    {
        int _msk = msk;
        memset(E, 0, sizeof(E));
        int sum = 0;
        for (int i = 0; i < N; i++)
            E[(cnt[i] = _msk % 10)]++, _msk /= 10, sum += cnt[i];
        llong hh = 0;
        for (int i = sum + 1; i < L; i++)
            hh += C[i];
        llong cur = 1;
        for (int i = 0; i < 10; i++)
        {
            llong val = 1;
            for (int j = 0; j < E[i]; j++)
                val = (val * (C[i] - j)) % MOD;
            cur = (cur * val) % MOD;
        }
        ans = (ans + cur * hh) % MOD;
    }

    /*for (int i = 1; i < L; i++)
    {
        llong cur = 0;
        for (int s = 0; s < i; s++)
            for (int p = 0; p < L; p++)
                for (int g = 0; g <= N; g++)
                    cur = (cur + D[N][p][g][s]) % MOD;
        ans = ans + (cur * C[i]) % MOD;
    }*/
    printf("%d\n", (int)ans);
    return 0;
}