#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define M 660
using namespace std;
struct abcd{
    int to,next;
}table[100100];
int head[M],tot;
int n,m,k,p;
int degree[M],num[M];
int f[M][M];
bool v[M];
int q[M],g[M];
void Add(int x,int y)
{
    table[++tot].to=y;
    table[tot].next=head[x];
    head[x]=tot;
}
void Topology_Sort()
{
    int i,r=0,h=0;
    for(i=1;i<=n;i++)
        if(!degree[i])
            q[++r]=i;
    while(r!=h)
    {
        int x=q[++h];
        for(i=head[x];i;i=table[i].next)
            if(!--degree[table[i].to])
                q[++r]=table[i].to;
    }
}
void DP(int f[],int x)
{
    int i,j;
    memset(g,0,sizeof g);
    g[x]=1;
    for(j=1;j<=n;j++)
    {
        int x=q[j];
        for(i=head[x];i;i=table[i].next)
            (g[table[i].to]+=g[x])%=p;
    }
    for(i=1;i<=n;i++)
        if(num[i])
            f[num[i]]=g[i];
}
long long Quick_Power(long long x,int y)
{
    long long re=1;
    while(y)
    {
        if(y&1) (re*=x)%=p;
        (x*=x)%=p; y>>=1;
    }
    return re;
}
void Gauss_Elimination(int n)
{
    int i,j,k,mark=1;
    for(i=1;i<=n;i++)
    {
        for(k=i;k<=n;k++)
            if(f[k][i])
                break;
        if(k!=i) mark=-mark;
        for(j=1;j<=n;j++)
            swap(f[k][j],f[i][j]);
        for(k=i+1;k<=n;k++)
        {
            long long temp=p-f[k][i]*Quick_Power(f[i][i],p-2)%p;
            for(j=i;j<=n;j++)
                (f[k][j]+=f[i][j]*temp%p)%=p;
        }
    }
    long long ans=1;
    for(i=1;i<=n;i++)
        (ans*=f[i][i])%=p;
    if(mark==-1)
        ans=(p-ans)%p;
    cout<<ans<<endl;
}
int main()
{
    //freopen("energy.in","r",stdin);
    //freopen("energy.out","w",stdout);
    int i,x,y;
    cin>>n>>m>>p;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        degree[y]++;Add(x,y);
    }
    for(i=1;i<=n;i++)
        if(!degree[i])
            v[i]=true;
    for(i=1;i<=n;i++)
        if(!head[i])
            num[i]=++k;
    Topology_Sort();
    int temp=0;
    for(i=1;i<=n;i++)
        if(v[i])
            DP(f[++temp],i);
    Gauss_Elimination(k);
    return 0;
}