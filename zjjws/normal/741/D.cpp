#include <vector>
#include <stdio.h>
#include <string.h>
#define LL long long
using namespace std;
inline LL rin()
{
    LL s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)return -s;
    return s;
}
inline int gc(){char c=getchar();for(;c>'v'||c<'a';c=getchar());return c-'a';}

const int N=5e5+3;
int n;
int f[N];
int c[N];
vector<int>nxt[N];

int son[N];
int lar[N];
int dep[N];
inline void find_son(int x)
{
    lar[x]=1;
    int maxl=0;
    for(vector<int>::iterator i=nxt[x].begin();i!=nxt[x].end();i++)
    {
        dep[*i]=dep[x]+1;find_son(*i);lar[x]+=lar[*i];
        if(lar[*i]>maxl)maxl=lar[*i],son[x]=*i;
    }
    return;
}

const int INF=0x3f3f3f3f;
int dp[1<<23];
inline void del(int x,int val)
{
    dp[val]=-INF;
    for(vector<int>::iterator i=nxt[x].begin();i!=nxt[x].end();i++)del(*i,val^(1<<c[*i]));
    return;
}
int Tp;
int ans[N];
inline void check(int x,int val)
{
    if(dp[val])ans[Tp]=max(ans[Tp],dp[val]+dep[x]-(dep[Tp]<<1));
    for(int i=0;i<22;i++)
    {
        int now=val^(1<<i);
        if(dp[now]>0)ans[Tp]=max(ans[Tp],dp[now]+dep[x]-(dep[Tp]<<1));
    }
    return;
}
inline void find_ans(int x,int val)
{
    check(x,val);
    for(vector<int>::iterator i=nxt[x].begin();i!=nxt[x].end();i++)find_ans(*i,val^(1<<c[*i]));
    return;
}
inline void add(int x,int val)
{
    dp[val]=max(dp[val],dep[x]);
    for(vector<int>::iterator i=nxt[x].begin();i!=nxt[x].end();i++)add(*i,val^(1<<c[*i]));
    return;
}
inline void dfs(int x,int val,int fa)
{
    for(vector<int>::iterator i=nxt[x].begin();i!=nxt[x].end();i++)if((*i)!=son[x])dfs(*i,val^(1<<c[*i]),x),del(*i,val^(1<<c[*i]));
    if(son[x])dfs(son[x],val^(1<<c[son[x]]),x);
    Tp=x;for(vector<int>::iterator i=nxt[x].begin();i!=nxt[x].end();i++)if((*i)!=son[x])find_ans(*i,val^(1<<c[*i])),add(*i,val^(1<<c[*i]));
    check(x,val);dp[val]=max(dp[val],dep[x]);
    ans[fa]=max(ans[fa],ans[x]);
    return;
}
//aba
int main()
{
    n=rin();
    for(int i=2;i<=n;i++)f[i]=rin(),c[i]=gc(),nxt[f[i]].push_back(i);
    find_son(1);dfs(1,0,0);
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);puts("");
    return 0;
}

//vjudge 