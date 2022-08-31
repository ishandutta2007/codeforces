#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 20;
const int MSK = 1 << N;
int D[N + 1][MSK];

const int NN = 150;
int S[NN];

char V[N];
int T[N];

inline int mymax(int a, int b)
{
    return (a > b) ? a : b;
}
inline int mymin(int a, int b)
{
    return (a < b) ? a : b;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &S[i]);
    sort(S, S + n);
    reverse(S, S + n);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf(" %c %d", &V[i], &T[i]);
    for (int i = 1; i <= n; i++)
    {
        for (int msk = 0; msk < (1 << n); msk++)
        {
            if (__builtin_popcount(msk) < i - 1)
                continue;
            int tm = (T[n - i] == 1) ? 1 : -1;
            int tp = (V[n - i] == 'p');
            if (tm == 1)
                D[i][msk] = -1e9;
            else
                D[i][msk] = 1e9;
            if (tp)
            {
                for (int j = 0; j < n; j++)
                {
                    if ((msk >> j) & 1)
                        D[i][msk] = ((tm == 1) ? mymax : mymin)(D[i][msk], tm * S[j] + D[i - 1][msk ^ (1 << j)]);
                }
            }
            else
            {
                D[i][msk] = D[i - 1][msk];
                for (int j = 0; j < n; j++)
                {
                    if ((msk >> j) & 1)
                        D[i][msk] = ((tm == 1) ? mymax : mymin)(D[i][msk], D[i - 1][msk ^ (1 << j)]);
                }
            }
        }
    }
    int ans = D[n][(1 << n) - 1];
    printf("%d\n", ans);
}