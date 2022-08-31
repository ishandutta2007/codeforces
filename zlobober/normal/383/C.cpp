#include <cstdio>
#include <vector>
using namespace std;

const int N = 1 << 18;

vector<int> E[N];

int A[2 * N];

int init[N];

void push(int v)
{
    if (v < N)
    {
        A[2 * v] += A[v];
        A[2 * v + 1] += A[v];
        A[v] = 0;
    }
}

void add(int l, int r, int x, int L = 1, int R = N, int v = 1)
{
    if (r < L || l > R)
        return;
    else if (l <= L && R <= r)
        A[v] += x;
    else
    {
        push(v);
        add(l, r, x, L, (L + R) / 2, 2 * v);
        add(l, r, x, (L + R) / 2 + 1, R, 2 * v + 1);
    }
}

inline int get(int x)
{
    int L = 1, R = N, v = 1;
    while (v < N)
    {
        push(v);
        if (x <= (L + R) / 2)
            R = (L + R) / 2, v = 2 * v;
        else
            L = (L + R) / 2 + 1, v = 2 * v + 1;
    }
    return A[v];
}

int D[N];

int in[N], out[N];
int curt = 1;

void DFS(int x, int p = -1)
{
    in[x] = curt++;
    D[x] = (p == -1) ? 0 : D[p] + 1;
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
    }
    out[x] = curt;
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &init[i]);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    DFS(1);
    for (int i = 0; i < q; i++)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int x, v;
            scanf("%d %d", &x, &v);
            if (D[x] & 1)
                v *= -1;
            add(in[x], out[x] - 1, v);
        }
        else
        {
            int x;
            scanf("%d", &x);
            int v = get(in[x]);
            if (D[x] & 1)
                v *= -1;
            printf("%d\n", v + init[x]);
        }
    }
    return 0;
}