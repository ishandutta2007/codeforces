#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

const int C = 66;

int vy[] = {1, 0, -1, 0};
int vx[] = {0, 1, 0, -1};

int A[2 * C + 1][2 * C + 1];

bool isin[2 * C + 1][2 * C + 1];

const int MXQ = C * C * C;
int Q[MXQ];

int bpt = 0, ept = 0;
int cnt = 0;

void go()
{
}

int main()
{
    int n, t;
    scanf("%d %d", &n, &t);
    //scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        A[C][C]++;
        if (A[C][C] >= 4)
        {
            Q[ept] = C * 1024 + C;
            ept = (ept + 1) % (MXQ);
            cnt++;
            isin[C][C] = true;
        }
        while (bpt != ept)
        {
            int y = Q[bpt] / 1024 - C;
            int x = Q[bpt] % 1024 - C;
            if (A[y + C][x + C] >= 4)
            {
                int vv = A[y + C][x + C] / 4;
                A[y + C][x + C] %= 4;
                for (int v = 0; v < 4; v++)
                {
                    int ty = y + vy[v];
                    int tx = x + vx[v];
                    assert(abs(ty) <= C && abs(tx) <= C);
                    A[ty + C][tx + C] += vv;
                    if (A[ty + C][tx + C] >= 4 && !isin[ty + C][tx + C])
                    {
                        isin[ty + C][tx + C] = true;
                        Q[ept] = (ty + C) * 1024 + tx + C;
                        ept = (ept + 1) % MXQ;
                        cnt++;
                    }
                }
            }
            isin[y + C][x + C] = false;
            assert(cnt <= 5000);
            bpt = (bpt + 1) % (MXQ);
            cnt--;
        }
        /*for (int y = -3; y <= 3; y++)
        {
            for (int x = -3; x <= 3; x++)
                printf("%d", A[y + C][x + C]);
            printf("\n");
        }*/
        //printf("%d\n", i);
    }
    for (int i = 0; i < t; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        int ans;
        if (abs(x) > C || abs(y) > C)
            ans = 0;
        else
            ans = A[y + C][x + C];
        printf("%d\n", ans);
    }
    return 0;
}