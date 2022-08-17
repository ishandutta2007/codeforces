#include <cstdio>
using namespace std;

const int N = 2050;

char buf[N][N];
int n, m, k;

inline bool is(int y, int x, char v)
{
    return (y < n && y >= 0 && x < m && x >= 0 && buf[y][x] == v);
}

int main()
{
    scanf("%d %d %d ", &n, &m, &k);
    for (int i = 0; i < n; i++)
        gets(buf[i]);
    for (int j = 0; j < m; j++)
    {
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            ans += is(i, j + i, 'L');
            ans += is(i, j - i, 'R');
            ans += is(2 * i, j, 'U');
        }
        printf("%d ", ans);
    }
    printf("\n");
}