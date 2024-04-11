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

int n, d[1000*1000], f[1000*1000], x[1000*1000];
vector<int> g[1000*1000];
const int mod=1000000007;
int add(int a, int b)
{
    a+=b; if (a>=mod) a-=mod; return a;
}
int mul(int a, int b)
{
    return (a*1LL*b)%mod;
}
void go(int v, int pr)
{
    if (x[v]) d[v]=1; else f[v]=1;
    for (int i=0;i<g[v].size();++i)
    {
        int t=g[v][i];
        if (t==pr) continue;
        go(t, v);
        d[v]=add(mul(d[v], add(f[t], d[t])), mul(f[v], d[t]));
        f[v]=mul(f[v], add(f[t], d[t]));
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i=0;i<n-1;++i)
    {
        int a;
        scanf("%d", &a);
        g[a].push_back(i+1);
        g[i+1].push_back(a);
    }
    for (int i=0;i<n;++i) scanf("%d", &x[i]);
    go(0, -1);
    printf("%d\n", d[0]);
    return 0;
}