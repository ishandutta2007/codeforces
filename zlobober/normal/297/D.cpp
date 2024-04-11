#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1050;
int R[N][N], C[N][N];
int A[N][N];
int n, m, k;

char buf[N];

inline void fill(int i)
{
    int cur = 0;
    for (int j = 0; j < m; j++)
    {
        A[i][j] = cur;
        cur ^= !R[i][j];
    }
}

void solve()
{
    for (int i = 0; i < 2 * n - 1; i++)
    {
        gets(buf);
        if (!(i & 1))
        {
            for (int j = 0; j < m - 1; j++)
                R[i / 2][j] = buf[j] == 'E';
        }
        else
        {
            for (int j = 0; j < m; j++)
                C[j][i / 2] = buf[j] == 'E';
        }
    }
    bool sw = false;
    if (n > m)
    {
        sw = true;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                swap(R[i][j], C[i][j]);
        swap(n, m);
    }

    fill(0);
    for (int i = 0; i < n - 1; i++)
    {
        fill(i + 1);
        int b = 0;
        for (int j = 0; j < m; j++)
            b += (A[i][j] != A[i + 1][j]) ^ C[j][i];
        if (b < (m + 1) / 2)
            for (int j = 0; j < m; j++)
                A[i + 1][j] ^= 1;
    }

    if (sw)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < i; j++)
                swap(A[i][j], A[j][i]);
        swap(n, m);
    }
    printf("YES\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          printf("%d%c", 1 + A[i][j], " \n"[j + 1 == m]);
}

void solve1()
{
    int eq = 0;
    char c;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        gets(buf);
        for (int j = 0; j < m - 1 + (i & 1); j++)
            eq += buf[j] == 'E';
    }
    if (eq * 4 >= 3 * (2 * n * m - n - m))
    {
        printf("YES\n");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                printf("1%c", " \n"[j == m - 1]);
    }
    else
        printf("NO\n");
}

int main()
{
    scanf("%d %d %d ", &n, &m, &k);
    if (k == 1)
        solve1();
    else
        solve();
}