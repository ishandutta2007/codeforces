#include <cstdio>
#include <vector>
using namespace std;

const int N = 1050;

const int M = 12;
char A[N][M][M];

int n, m, k, ww;
int U[N][N];
bool was[N];

inline int diff(int i, int j)
{
    int ans = 0;
    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
            ans += A[i][y][x] != A[j][y][x];
    return ans;
}

vector<pair<int, int> > G[M * M];

int par[N], rnk[N];

int get(int x)
{
    return (x == par[x]) ? x : par[x] = get(par[x]);
}


bool merge(int a, int b)
{
    a = get(a), b = get(b);
    if (a == b)
        return false;
    if (rnk[a] < rnk[b])
        swap(a, b);
    if (rnk[a] == rnk[b])
        rnk[a]++;
    par[b] = a;
    return true;
}

vector<int> E[N];
void DFS(int x, int p = -1)
{
    if (p != -1)
        printf("%d %d\n", x, p);
    for (int i = 0; i < E[x].size(); i++)
    {
        int y = E[x][i];
        if (y == p)
            continue;
        DFS(y, x);
    }
}

int main()
{
    scanf("%d %d %d %d ", &n, &m, &k, &ww);
    for (int i = 1; i <= k; i++)
        for (int y = 0; y < n; y++)
            gets(A[i][y]);
    for (int i = 1; i <= k; i++)
        par[i] = i, rnk[i] = 0;
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= k; j++)
        {
            if (i == j)
                continue;
            U[i][j] = diff(i, j);
            if (U[i][j] <= n * m)
                G[U[i][j]].push_back(make_pair(i, j));
        }
    int cnt = 0;
    int sum = 0;
    for (int w = 0; w * ww <= n * m; w++)
    {
        for (int i = 0; i < G[w].size(); i++)
        {
            int a = G[w][i].first;
            int b = G[w][i].second;
            if (merge(a, b))
                sum += w * ww, cnt++, E[a].push_back(b), E[b].push_back(a);
        }
    } 
    printf("%d\n", sum + (k - cnt) * (n * m));
    for (int i = 1; i <= k; i++)
    {
        if (!was[get(i)])
        {
            was[get(i)] = true;
            printf("%d %d\n", i, 0);
            DFS(i);
        }
    }
}