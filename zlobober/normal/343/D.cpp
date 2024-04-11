#include <cstdio>
#include <vector>
#include <cassert>
using namespace std;

const int N = 1 << 19;

int T[2 * N];
int S[2 * N];
int SZ[2 * N];

void push(int v)
{
    if (v >= N)
    {
        if (S[v] == -1)
            return;
        else
            T[v] = S[v], S[v] = -1;
    }
    else
    {
        if (S[v] == -1)
            return;
        else
            S[2 * v] = S[v], S[2 * v + 1] = S[v], T[v] = S[v] * SZ[v], S[v] = -1;
    }
}

int get(int l, int r, int L, int R, int v)
{
    if (r < L || l > R)
        return 0;
    push(v);
    if (l <= L && R <= r)
        return T[v];
    else
        return get(l, r, L, (L + R) / 2, 2 * v) + get(l, r, (L + R) / 2 + 1, R, 2 * v + 1);
}

int set(int l, int r, int L, int R, int v, int x)
{
    push(v);
    if (r < L || l > R)
        return T[v];
    if (l <= L && R <= r)
    {
        S[v] = x;
        push(v);
        return T[v];
    }
    return T[v] = set(l, r, L, (L + R) / 2, 2 * v, x) + set(l, r, (L + R) / 2 + 1, R, 2 * v + 1, x);
}

vector<int> E[N];
int par[N];
int tin[N], tout[N];
int pt = 1;
int sz[N];

void DFS(int x, int p = -1)
{
    tin[x] = pt++;
    sz[x] = 1;
    for (int i = 0; i < E[x].size(); i++)
    {
        int y = E[x][i];
        if (y == p)
        {
            E[x].erase(E[x].begin() + i);
            --i;
            continue;
        }
        DFS(y, x);
        sz[x] += sz[y];
    }
    par[x] = p;
    tout[x] = pt;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    DFS(1);
    for (int i = 2 * N - 1; i >= N; i--)
    {
        S[i] = -1;
        SZ[i] = 1;
        T[i] = 0;
    }
    for (int i = N - 1; i > 0; i--)
    {
        SZ[i] = SZ[2 * i] + SZ[2 * i + 1];
        S[i] = -1;
        assert(SZ[2 * i] == SZ[2 * i + 1]);
    }
    int q = 0;
    scanf("%d", &q);
    //q = 500000;
    for (int i = 0; i < q; i++)
    {
        int c, v;
        scanf("%d %d", &c, &v);
        if (c == 1)
        {
            int ans = get(tin[v], tout[v] - 1, 1, N, 1);
            int p = par[v];
            if (p != -1 && ans != sz[v])
                set(tin[p], tin[p], 1, N, 1, 0);
            set(tin[v], tout[v] - 1, 1, N, 1, 1);
        }
        else if (c == 2)
        {
            set(tin[v], tin[v], 1, N, 1, 0);
        }
        else
        {
            int ans = get(tin[v], tout[v] - 1, 1, N, 1);
            if (ans != sz[v])
                printf("0\n");
            else
                printf("1\n");
        }
    }
    return 0;
}