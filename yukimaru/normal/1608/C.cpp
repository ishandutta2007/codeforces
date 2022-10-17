#include<bits/stdc++.h>
using namespace std;
const int N=100005;
vector<int> e[N];
int dfn[N], low[N], dfncnt, s[N], in_stack[N], tp;
int scc[N], sc;  //  i  SCC 
int sz[N];       //  i 
void tarjan(int u)
{
    low[u] = dfn[u] = ++dfncnt, s[++tp] = u, in_stack[u] = 1;
    for(auto v : e[u])
    {
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (in_stack[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        ++sc;
        while (s[tp] != u)
        {
            scc[s[tp]] = sc;
            sz[sc]++;
            in_stack[s[tp]] = 0;
            --tp;
        }
        scc[s[tp]] = sc;
        sz[sc]++;
        in_stack[s[tp]] = 0;
        --tp;
    }
}
void init(int n)
{
    sc=0;
    for(int i=1;i<=n;i++)
        e[i].clear(),dfn[i]=low[i]=0;
}
int a[N],b[N],ord_a[N],ord_b[N];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        init(n);
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        for(int i=1; i<=n; i++)
            scanf("%d",&b[i]);
        iota(ord_a+1,ord_a+n+1,1);
        sort(ord_a+1,ord_a+n+1,[](int x,int y){
            return a[x]>a[y];
        });
        for(int i=1;i<n;i++)
            e[ord_a[i]].push_back(ord_a[i+1]);
        iota(ord_b+1,ord_b+n+1,1);
        sort(ord_b+1,ord_b+n+1,[](int x,int y){
            return b[x]>b[y];
        });
        for(int i=1;i<n;i++)
            e[ord_b[i]].push_back(ord_b[i+1]);
        tarjan(ord_a[1]);
        string res(n,'0');
        for(int i=1;i<=n;i++)
            res[i-1]+=(scc[i]==scc[ord_a[1]]);
        printf("%s\n",res.c_str());
    }
    return 0;
}