#include <cstdio>
using namespace std;

const int N = 5050;

int D[N][N];

int A[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int q;
    double x;
    for (int i = 0; i < n; i++)
        scanf("%d %lf", &A[i], &x);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            D[i][j] = -5050;
    D[0][0] = 0;

    D[1][0] = 0;
    for (int j = 1; j <= n; j++)
        D[1][j] = D[1][j - 1] + (A[j - 1] == 1);

    for (int i = 2; i <= m; i++)
    {
        D[i][0] = 0;
        int cur = 0;
        for (int j = 1; j <= n; j++)
        {
            if (A[j - 1] == i)
                cur++;
            if (cur < D[i - 1][j])
                cur = D[i - 1][j];
            D[i][j] = cur;
        }
    }
    printf("%d\n", n - D[m][n]);
    return 0;
}