#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int C=1e6;
int n, m, k, ty[C], c[555], d[555][555], u[C], uc[555], lo[555], ls;
vector<int> t[C];
void go(int v)
{
    if (!uc[ty[v]]) lo[ls++]=ty[v];
    ++uc[ty[v]];
    u[v]=1;
    for (int i=0;i<t[v].size();++i) if (!u[t[v][i]]) go(t[v][i]);
}
void sm(int &a, int x)
{
    if (a==-1||a>x) a=x;
}
int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i=0;i<k;++i) scanf("%d", &c[i]);
    for (int i=0, s=0;i<k;s+=c[i], ++i) for (int j=s;j<s+c[i];++j) ty[j]=i;
    for (int i=0;i<k;++i) for (int j=0;j<k;++j) if (i!=j) d[i][j]=-1;
    for (int i=0;i<m;++i)
    {
        int a, b, x;
        scanf("%d %d %d", &a, &b, &x);
        --a; --b;
        if (x==0)
        {
            t[a].push_back(b);
            t[b].push_back(a);
        }
        a=ty[a];
        b=ty[b];
        sm(d[a][b], x);
        sm(d[b][a], x);
    }
    for (int i=0;i<n;++i)
    {
        if (uc[ty[i]]) continue;
        int pp=ls;
        go(i);
        for (int j=pp;j<ls;++j) if (uc[lo[j]]!=c[lo[j]]) { puts("No"); return 0; }
    }
    for (int l=0;l<k;++l) for (int i=0;i<k;++i) for (int j=0;j<k;++j)
    {
        if (d[i][l]!=-1&&d[l][j]!=-1) sm(d[i][j], d[i][l]+d[l][j]);
    }
    puts("Yes");
    for (int i=0;i<k;++i) for (int j=0;j<k;++j) printf("%d%c", d[i][j], j+1==k?'\n':' ');
    return 0;
}