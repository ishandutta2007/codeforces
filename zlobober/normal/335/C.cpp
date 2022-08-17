#include <cstdio>
#include <algorithm>
#include <cstring>
#include <memory.h>
using namespace std;

const int N = 105;
int D[3][3][N];
int mex[2 * N];

int ver = 0;

int str[N];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int l = 0; l < 3; l++)
        for (int r = 0; r < 3; r++)
            D[l][r][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int l = 0; l < 3; l++)
            for (int r = 0; r < 3; r++)
            {
                ++ver;
                for (int j = 0; j < i; j++)
                    for (int q = 1; q < 3; q++)
                    {
                        if (j == 0 && q + l == 3)
                            continue;
                        if (j == i - 1 && q + r == 3)
                            continue;
                        int val = D[l][q][j] ^ D[q][r][i - j - 1];
                        mex[min(val, 2 * i)] = ver;
                    }
                for (D[l][r][i] = 0; mex[D[l][r][i]] == ver; D[l][r][i]++);
            }
    }
    memset(str, -1, sizeof(str));
    for (int i = 0; i < k; i++)
    {
        int x, v;
        scanf("%d %d", &x, &v);
        str[x] = v;
    }
    int pos = 0, val = 0;
    int ans = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        if (str[i] != -1 || i == n + 1)
        {
            int cur = (i == n + 1) ? 0 : str[i];
            ans ^= D[val][cur][i - pos - 1];
            pos = i, val = cur;
        }
    }
    puts(ans ? "WIN" : "LOSE");
}