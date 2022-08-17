#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

const int logN = 17;
const int N = 1 << logN;

int up[N][logN];
vector<int> E[N];

int D[N];

int L[N], R[N];
int curt = 0;

vector<int> T[2 * N];

void DFS(int x, int p)
{
    L[x] = curt++;
    D[x] = D[p] + 1;
    T[L[x] + N].push_back(D[x]);
    for (int i = 1; i < logN; i++)
        up[x][i] = up[up[x][i - 1]][i - 1];
    for (int y : E[x])
        DFS(y, x);
    R[x] = curt - 1;
}

int get(int l, int r, int L, int R, int v, int x)
{
    if (r < L || l > R)
        return 0;
    else if (l <= L && R <= r)
        return upper_bound(T[v].begin(), T[v].end(), x) - lower_bound(T[v].begin(), T[v].end(), x);
    else
        return get(l, r, L, (L + R) / 2, 2 * v, x) + get(l, r, (L + R) / 2 + 1, R, 2 * v + 1, x);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &up[i][0]);
        E[up[i][0]].push_back(i);
    }
    D[0] = -1;
    DFS(0, 0);
    for (int i = N - 1; i > 0; i--)
    {
        T[i].resize(T[2 * i].size() + T[2 * i + 1].size());
        merge(
            T[2 * i].begin(), T[2 * i].end(),
            T[2 * i + 1].begin(), T[2 * i + 1].end(),
            T[i].begin()
        );
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int x, d;
        scanf("%d %d", &x, &d);
        int q = D[x];
        for (int j = logN - 1; j >= 0; j--)
            if ((1 << j) <= d)
                x = up[x][j], d -= (1 << j);
        assert(d == 0);
        int ans = !!x * (get(L[x] + 1, R[x] + 1, 1, N, 1, q) - 1);
        printf("%d%c", ans, " \n"[i == m - 1]);
    }
    return 0;
}