#include <cstdio>
#include <cassert>
#include <cstring>
#include <memory.h>
using namespace std;

const int N = 50500;
const int K = 105;
const int E = 26;
char S[N];
int left[E][N];
int pos[E];

int D[K][N];
bool T[K][N];

char ans[N];

int main()
{
    gets(S);
    int n = strlen(S);
    memset(pos, -1, sizeof(pos));
    for (int i = 0; i < n; i++)
    {
        pos[S[i] - 'a'] = i;
        for (int j = 0; j < E; j++)
            left[j][i] = pos[j];
    }
    D[0][0] = n - 1;
    D[1][0] = left[S[0] - 'a'][n - 1] - 1;
    T[1][0] = true;
    T[0][0] = false;
    for (int i = 2; i < K; i++)
        D[i][0] = -2;
    for (int i = 1; i < n; i++)
    {
        D[0][i] = n - 1;
        for (int l = 1; l < K; l++)
        {
            if (D[l][i - 1] > left[S[i] - 'a'][D[l - 1][i - 1]] - 1)
                D[l][i] = D[l][i - 1];
            else
                D[l][i] = left[S[i] - 'a'][D[l - 1][i - 1]] - 1, T[l][i] = true;
        }
    }
    int mx = -1, odd = 0, pos = -1;
    for (int l = 0; l <= 100; l++)
        for (int i = 0; i < n; i++)
        {
            if (D[l][i] < i - 1)
                continue;
            else if (D[l][i] == i - 1)
            {
                if (mx < 2 * l - 1 && 2 * l - 1 <= 100)
                   odd = true, mx = 2 * l - 1, pos = i;
            }
            else
            {
                if (mx < 2 * l && 2 * l <= 100)
                    odd = false, mx = 2 * l, pos = i;
            }
        }
    assert(mx != -1);
    int pt1 = (mx - 1) / 2, pt2 = mx / 2;
    while (pt1 >= 0)
    {
        assert(pos >= 0);
        if (T[pt1 + 1][pos])
            ans[pt1] = ans[pt2] = S[pos], --pt1, ++pt2;
        --pos;
    }
    puts(ans);
}