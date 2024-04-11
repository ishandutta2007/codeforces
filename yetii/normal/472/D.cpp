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
#include <numeric>
using namespace std;
typedef long long ll;

const int N=2002;
int n, d[N][N], u[N], pr[N];
ll t[N];
vector<int> g[N];
void ex()
{
    puts("NO");
    exit(0);
}
vector<pair<int, ll>> go(int v)
{
    vector<pair<int, ll>> rs, t;
    rs.push_back({v, 0});
    if (d[v][v]!=0) ex();
    for (int i=0;i<g[v].size();++i)
    {
        t=go(g[v][i]);
        ll h=-1;
        for (int p1=0;p1<rs.size();++p1) for (int p2=0;p2<t.size();++p2)
        {
            int u=rs[p1].first, v=t[p2].first;
            if (d[u][v]!=d[v][u]) ex();
            ll e=d[u][v]-rs[p1].second-t[p2].second;
            if (e<=0) ex();
            if (h==-1) h=e;
            if (e!=h) ex();
        }
        if (h==-1) throw;
        for (int j=0;j<t.size();++j) rs.push_back({t[j].first, t[j].second+h});
    }
    return rs;
}
vector<int> h[N], tt[N];
int gd(int v, int pr, int t)
{
    if (v==t) return 0;
    int rs=1e9;
    for (int i=0;i<h[v].size();++i)
    {
        int z=h[v][i];
        if (z==pr) continue;
        rs=min(rs, tt[v][i]+gd(z, v, t));
    }
    return rs;
}
int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i=0;i<n;++i) for (int j=0;j<n;++j) scanf("%d", &d[i][j]);
    for (int i=0;i<n;++i) t[i]=1e18;
    t[0]=0; pr[0]=N-1;
    for (int i=0;i<n;++i)
    {
        int m=-1; for (int j=0;j<n;++j) if (!u[j]&&(m==-1||t[j]<t[m])) m=j;
        if (m==-1) throw;
        u[m]=1; g[pr[m]].push_back(m);
        for (int j=0;j<n;++j) if (t[j]>=t[m]+d[m][j])
        {
            t[j]=t[m]+d[m][j];
            pr[j]=m;
        }
    }
    if (go(0).size()!=n) throw;
    puts("YES");
    return 0;
}