#include<bits/stdc++.h>
#define maxc 10
#define maxh 22
#define maxl 900050
#define maxn 100050
#define maxm 100050
#define modu 1000000007
using namespace std;
typedef long long LL;

int n,m;
int len[maxn];

int tot;
int cost[maxm<<1],id[maxm<<1];
int head[maxn],edge[maxm<<1],nxt[maxm<<1];

int dis[maxn];
bool inq[maxn];
queue<int> q;

int pos[maxn];

int sz;
int rt[maxn];
int dep[maxl];
int fa[maxl][maxh];
int ch[maxl][maxc];

int judge(int k1,int k2)   {
    if (!~k1||!~k2) return k1&k2;
    assert(dep[k1]==dep[k2]);
    int c1=k1,c2=k2;
    for (int d=maxh-1;~d;--d)   {
        if (fa[k1][d]==fa[k2][d])   continue;
        k1=fa[k1][d];
        k2=fa[k2][d];
    }
    int f=fa[k1][0];
    // cout<<"lca "<<f<<" "<<k1<<" "<<fa[k1][0]<<" "<<k2<<" "<<c1<<" "<<c2<<":"<<f<<endl;
    for (int c=0;c<maxc;++c)    {
        if (ch[f][c]==k1)   return c1;
        if (ch[f][c]==k2)   return c2;
    }
    assert(0);
}

int N,C[maxn];
LL ans[maxn],pw[maxn]={1};

int add(int k,int x)   {
    for (N=0;x;x/=10)
        C[++N]=x%10;
    for (int i=N;i;--i) {
        int c=C[i];
        if (!ch[k][c])  {
            ch[k][c]=++sz;
            dep[sz]=dep[ch[k][c]]+1;
            fa[sz][0]=k;
            for (int j=1;j<maxh;++j)
                fa[sz][j]=fa[fa[sz][j-1]][j-1];
        }
        k=ch[k][c];
    }
    return k;
}

void join(int u,int v,int k)  {
    cost[tot]=len[k]; id[tot]=k; nxt[tot]=head[u]; edge[tot]=v; head[u]=tot++;
    cost[tot]=len[k]; id[tot]=k; nxt[tot]=head[v]; edge[tot]=u; head[v]=tot++;
}

int main()  {
    for (int i=1;i<maxn;++i)    pw[i]=pw[i-1]*10%modu;
    scanf("%d%d",&n,&m);
    memset(head,-1,sizeof(head));
    for (int i=1;i<=m;++i)  {
        for (int t=i;t;t/=10)   ++len[i];
    }
    for (int t=1;t<=m;++t)  {
        int u,v;
        scanf("%d%d",&u,&v);
        join(u,v,t);
    }
    memset(dis,0x3f,sizeof(dis));
    dis[1]=1,inq[1],q.push(1);
    while (!q.empty())  {
        int i=q.front();    q.pop();
        for (int k=head[i];~k;k=nxt[k]) {
            int j=edge[k];
            if (dis[j]<=dis[i]+cost[k])  continue;
            dis[j]=dis[i]+cost[k];
            inq[j]=1;
            q.push(j);
        }
        inq[i]=0;
    }
    for (int i=1;i<=n;++i)  pos[i]=i;
    sort(pos+1,pos+n+1,[&](const int& i,const int& j){
        return dis[i]<dis[j];
    });
    ans[1]=0;
    for (int k=2;k<=n;++k)  {
        int i=pos[k],rt0=-1;
        for (int k=head[i];~k;k=nxt[k]) {
            int j=edge[k];
            // cout<<j<<"->"<<i<<" "<<dis[j]<<" "<<dis[i]<<endl;
            if (dis[j]+cost[k]>dis[i])   continue;
            int t=add(rt[j],id[k]);
            rt0=judge(rt0,t);
            // cout<<i<<" "<<j<<":"<<rt0<<" "<<rt[j]<<" "<<t<<" "<<id[k]<<endl;
            if (rt0==t)
                // cout<<i<<":"<<rt0<<" "<<j<<endl,
                ans[i]=(ans[j]*pw[cost[k]]+id[k])%modu;
        }
        rt[i]=rt0;
        // cout<<"i:"<<i<<" "<<rt[i]<<" "<<rt0<<" "<<ans[i]<<endl;
    }
    for (int i=2;i<=n;++i)
        printf("%lld\n",ans[i]);
    return 0;
}