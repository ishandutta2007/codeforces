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

int n, m, r[1000*1000], d[1000*1000], s, u[1000*1000], x[1000*1000];
vector<int> g[1000*1000];
void go(int v)
{
    u[v]=1; r[s++]=v; d[v]^=1;
    for (int i=0;i<g[v].size();++i)
    {
        int to=g[v][i];
        if (u[to]) continue;
        go(to); d[v]^=1; r[s++]=v;
        if (x[to]!=d[to]) { d[v]^=1; d[to]^=1; r[s++]=to; r[s++]=v; }
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i=0;i<m;++i)
    {
        int a, b; scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=0;i<n;++i) scanf("%d", &x[i+1]);
    for (int i=1;i<=n;++i) if (x[i])
    {
        go(i);
        if (x[i]!=d[i]) --s, d[i]^=1;
        for (int j=1;j<=n;++j) if (d[j]!=x[j]) {puts("-1"); return 0; }
        printf("%d\n", s);
        for (int j=0;j<s;++j) printf("%d ", r[j]);
        return 0;
    }
    puts("0");
    return 0;
}