#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <iostream>
using namespace std;

const int L = 20;
const int K = 6;
const int V = 50;
bool D[L][K][V + 1];
int pl[L][K][V + 1], pk[L][K][V + 1], pv[L][K][V + 1];
int ps[L][K][V + 1];

char ans[K][L + 1];

#ifdef LOCAL42
    #define LLD "%lld"
#else
    #define LLD "%I64d"
#endif

char buf[L];

void solve()
{
    memset(buf, '0', sizeof(buf));
    gets(buf);
    int len = strlen(buf);
    buf[len] = 0;
    reverse(buf, buf + len);
    memset(D, 0, sizeof(D));
    D[0][0][0] = D[0][0][4] = D[0][0][7] = true;
    ps[0][0][0] = 0;
    ps[0][0][4] = 4;
    ps[0][0][7] = 7;
    pl[0][0][0] = -1;
    pl[0][0][4] = -1;
    pl[0][0][7] = -1;
    
    for (int i = 0; i < L - 1; i++)
        for (int j = 0; j < K; j++)
            for (int v = 0; v <= V; v++)
            {
                if (!D[i][j][v])
                    continue;
                for (int r = 0; r != 8; r = (r == 0) ? 4 : ((r == 4) ? 7 : 8))
                {
                    if (j != K - 1)
                    {
                        D[i][j + 1][v + r] = true;
                        pl[i][j + 1][v + r] = i;
                        pk[i][j + 1][v + r] = j;
                        pv[i][j + 1][v + r] = v;
                        ps[i][j + 1][v + r] = r;
                    }
                    else
                    {
                        if (v % 10 != buf[i] - '0')
                            continue;
                        D[i + 1][0][v / 10 + r] = true;
                        pl[i + 1][0][v / 10 + r] = i;
                        pk[i + 1][0][v / 10 + r] = j;
                        pv[i + 1][0][v / 10 + r] = v;
                        ps[i + 1][0][v / 10 + r] = r;
                    }
                }
        }
    if (!D[len][0][0])
        printf("-1\n");
    else
    {
        int i = len;
        int j = 0;
        int v = 0;
        memset(ans, '0', sizeof(ans));
        while (i != -1)
        {
            int ni = pl[i][j][v], nj = pk[i][j][v], nv = pv[i][j][v];
            ans[j][i] = ps[i][j][v] + '0';
            i = ni, j = nj, v = nv;
        }
        for (int i = 0; i < 6; i++)
        {
            int j;
            for (j = L - 1; j >= 0; j--)
                if (ans[i][j] != '0')
                    break;
            if (j == -1)
                printf("0 ");
            else
            {
                for (; j >= 0; j--)
                    printf("%c", ans[i][j]);
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int T;
    scanf("%d ", &T);
    for (int i = 0; i < T; i++)
        solve();
}