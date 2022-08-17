#include <iostream>
#include <cstdio>
#include <memory.h>
#include <cassert>
#include <map>
using namespace std;

const int N = 502;
int A[N][N];

int sx[N][N];
int sy[N][N];

inline int get(int y1, int x1, int y2, int x2)
{
    if (x1 > x2)
        swap(x1, x2);
    if (y1 > y2)
        swap(y1, y2);
    if (x1 == x2)
        return sy[y2 + 1][x2] - sy[y1][x1];
    else
        return sx[y2][x2 + 1] - sx[y1][x1];
}

int cans[N][N][N / 2];

inline int spiral(int y, int x, int k)
{
    if (cans[y][x][k / 2] != -1)
        return cans[y][x][k / 2];

    assert(k % 2 == 1);
    if (k == 1)
        return get(y, x, y, x);
    if (k == 3)
        return get(y, x, y, x + 2) + get(y + 1, x + 2, y + 2, x + 2) + get(y + 2, x + 1, y + 2, x);
    int ans = get(y, x, y, x + k - 1) + get(y + 1, x + k - 1, y + k - 1, x + k - 1) + get(y + k - 1, x + k - 2, y + k - 1, x)
            + get(y + k - 2, x, y + 2, x) + get(y + 2, x + 1, y + 2, x + 1);
    return cans[y][x][k / 2] = (ans + spiral(y + 2, x + 2, k - 4));
}

int main()
{
    cerr << sizeof(cans) << endl;
    memset(cans, -1, sizeof(cans));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            sx[i][j + 1] = sx[i][j] + A[i][j], sy[i + 1][j] = sy[i][j] + A[i][j];
    int ans = -1e9;
    for (int k = 3; k < N; k += 2)
    {
        for (int y = 0; y + k <= n; y++)
            for (int x = 0; x + k <= m; x++)
                ans = max(ans, spiral(y, x, k));
    }
    cout << ans << endl;
}