#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <iomanip>
#include <string.h>
using namespace std;
typedef long long ll;
const int MAX=1000000;
int n, m, q, id[MAX], sz[MAX], rs[MAX], d[MAX], h[MAX];
vector<int> g[MAX];
void go(int v0, int v, int p)
{
    id[v]=v0; sz[v]=1;
    int m1=0, m2=0;
    for (int i=0;i<g[v].size();++i)
    {
        int t=g[v][i]; if (p==t) continue;
        go(v0, t, v);
        int e=h[t]+1;
        h[v]=max(h[v], e);
        if (e>m1) m2=m1, m1=e;
        else if (e>m2) m2=e;
        d[v]=max(d[v], d[t]);
    }
    d[v]=max(d[v], m1+m2);
}
int ID(int v)
{
    return id[v]==v?v:id[v]=ID(id[v]);
}
void MER(int a, int b)
{
    if (sz[a]>sz[b]) swap(a, b);
    id[a]=b;
    sz[b]+=sz[a];
}
int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d %d %d", &n, &m, &q);
    for (int i=0;i<m;++i)
    {
        int a, b; scanf("%d %d", &a, &b); g[a].push_back(b); g[b].push_back(a);
    }
    for (int i=1;i<=n;++i) if (id[i]==0)
    {
        go(i, i, 0);
        rs[ID(i)]=d[i];
    }
    for (int i=0;i<q;++i)
    {
        int t, a, b;
        scanf("%d %d", &t, &a);
        if (t==1) printf("%d\n", rs[ID(a)]);
        else
        {
            scanf("%d", &b);
            a=ID(a); b=ID(b);
            if (a!=b)
            {
                t=max(1+(rs[a]+1)/2+(rs[b]+1)/2, max(rs[a], rs[b]));
                MER(a, b);
                rs[ID(a)]=t;
            }
        }
    }
    return 0;
}