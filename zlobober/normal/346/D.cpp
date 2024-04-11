#include <cstdio>
#include <cassert>
#include <vector>
using namespace std;

const int N = 1000500;
vector<int> E[N], IE[N];

int D[N];
int deg[N];

int wh[N];
int pos[N];
vector<int> V[N];
int pt = 0;

inline void del(int v)
{
    pos[V[wh[v]].back()] = pos[v];
    swap(V[wh[v]][pos[v]], V[wh[v]].back());
    V[wh[v]].pop_back();
    wh[v] = pos[v] = -1;
}


inline void add(int d, int v)
{
    if (wh[v] != -1)
        del(v);
    wh[v] = d;
    pos[v] = V[d].size();
    V[d].push_back(v);
}

int mn[N], mx[N];

bool fin[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        E[a].push_back(b);
        IE[b].push_back(a);
    }
    int s, t;
    scanf("%d %d", &s, &t);
    for (int i = 1; i <= n; i++)
        mx[i] = -N, mn[i] = N, D[i] = N, wh[i] = pos[i] = -1;
    D[t] = 0;
    
    add(0, t);
    while (true)
    {
        while (pt < N && V[pt].empty())
            pt++;
        if (pt == N)
            break;
        int x = V[pt].back();
        del(x);
        assert(pt == D[x]);
        fin[x] = true;
        for (int i = 0; i < IE[x].size(); i++)
        {
            int y = IE[x][i];
            if (fin[y])
                continue;
            mn[y] = min(mn[y], D[x]);
            mx[y] = max(mx[y], D[x]);
            if (D[y] > mn[y] + 1)
                D[y] = mn[y] + 1, add(D[y], y);
            deg[y]++;
            if (deg[y] == E[y].size())
                if (D[y] > mx[y])
                    D[y] = mx[y], add(D[y], y);
        }
    }
    if (D[s] > N - 42)
        printf("%d\n", -1);
    else
        printf("%d\n", D[s]);
    return 0;
}