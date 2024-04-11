#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cassert>
using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const int N = 200500;
const int logN = 19;
int up[N][logN];

vector<int> E[N];
vector<int> V[N];
int D[N];
int ans[N];

void DFS1(int x, int p)
{
    D[x] = D[p] + 1;
    up[x][0] = p;
    for (int i = 1; i < logN; i++)
        up[x][i] = up[up[x][i - 1]][i - 1];
    for (int i = 0; i < E[x].size(); i++)
    {
        int y = E[x][i];
        if (y == p)
            continue;
        DFS1(y, x);
    }
}

inline int lca(int a, int b)
{
    if (D[a] > D[b])
        swap(a, b);
    for (int i = logN - 1; i >= 0; i--)
    {
        if (D[up[b][i]] >= D[a])
            b = up[b][i];
    }
    if (a == b)
        return a;
    for (int i = logN - 1; i >= 0; i--)
    {
        if (up[b][i] != up[a][i])
            a = up[a][i], b = up[b][i];
    }
    assert(up[a][0] == up[b][0]);
    return up[a][0];
}

multiset<int> DFS2(int x, int p)
{
    multiset<int> our(V[x].begin(), V[x].end());
    for (int i = 0; i < E[x].size(); i++)
    {
        int y = E[x][i];
        if (p == y)
            continue;
        multiset<int> m = DFS2(y, x);
        if (our.size() < m.size())
            our.swap(m);
        for (multiset<int>::iterator it = m.begin(); it != m.end(); it++)
            our.insert(*it);
    }
    our.erase(D[x]);
    ans[x] = our.size();
    return our;
}

vector<pair<int, int> > edges;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        edges.push_back(make_pair(a, b));
        E[a].push_back(b);
        E[b].push_back(a);
    }
    DFS1(1, 1);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        int l = lca(a, b);
        if (a != l)
        {
            //eprintf("adding %d %d\n", a, l);
            V[a].push_back(D[l]);
        }
        if (b != l)
        {
            //eprintf("adding %d %d\n", b, l);
            V[b].push_back(D[l]);
        }
    }
    DFS2(1, 1);
    for (int i = 0; i < edges.size(); i++)
    {
        int a = edges[i].first;
        int b = edges[i].second;
        int q = (D[a] > D[b]) ? ans[a] : ans[b];
        printf("%d ", q);
    }
    return 0;
}