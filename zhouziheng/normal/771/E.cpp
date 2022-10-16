#pragma GCC optimize("Ofast")

#include<cstdio>
#include<vector>
#include<map>

using namespace std;

namespace IO
{
char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read() {
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*f;
}
}

int type,n,m;
long long a[3][1100000],sum[3][1100000];int fa[3][1100000];
vector<int> sons[3][1100000];

namespace bru
{
    int dp[1100][1100];
    void main()
    {
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i>0)dp[i][j]=max(dp[i][j],dp[i-1][j]);
                if(j>0)dp[i][j]=max(dp[i][j],dp[i][j-1]);
                if(fa[0][i]>=0)dp[i][j]=max(dp[i][j],dp[fa[0][i]][j]+1);
                if(fa[1][j]>=0)dp[i][j]=max(dp[i][j],dp[i][fa[1][j]]+1);
                if(i==j&&fa[2][i]>=0)dp[i][i]=max(dp[i][i],dp[fa[2][i]][fa[2][i]]+1);
            }
        }
        //for(int i=0;i<=n;i++){for(int j=0;j<=n;j++)printf("%d ",dp[i][j]);puts("");}
        if(type==1){int ans=0;for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)ans+=dp[i][j];printf("%d\n",ans);}
        while(m--)
        {
            int x=0,y=0;scanf("%d%d",&x,&y);printf("%d\n",dp[x][y]);
        }
    }
}



const int INF=1e9;
int dp[1100000];

struct func
{
    int val,pnt;func(int _val=-INF,int _pnt=0):val(_val),pnt(_pnt){}
    // f(x) = val (x < pnt) / val + 1 (x >= pnt)
    int operator()(int x){return val+(x>=pnt);}
};
func merge(func A,func B)
{
    if(A.val!=B.val)return A.val>B.val?A:B;
    return A.pnt<B.pnt?A:B;
}

struct SegmentTree
{
    struct nd
    {
        func dat;int l,r;
    }t[4000000];
    void build(int l,int r,int k=1)
    {
        t[k].l=l,t[k].r=r;if(l==r)return;
        int mid=(l+r)>>1;build(l,mid,k<<1);build(mid+1,r,k<<1|1);
    }
    void modify(int l,int r,func F,int k=1)
    {
        if(l>t[k].r||r<t[k].l)return;
        if(l<=t[k].l&&t[k].r<=r){t[k].dat=merge(t[k].dat,F);return;}
        modify(l,r,F,k<<1);modify(l,r,F,k<<1|1);
    }
    int query(int pos,int x,int k=1)
    {
        if(t[k].l==t[k].r)return t[k].dat(x);
        int mid=(t[k].l+t[k].r)>>1;
        if(pos<=mid)return max(t[k].dat(x),query(pos,x,k<<1));
        return max(t[k].dat(x),query(pos,x,k<<1|1));
    }
    func queryF(int pos,int k=1)
    {
        if(t[k].l==t[k].r)return t[k].dat;
        int mid=(t[k].l+t[k].r)>>1;
        if(pos<=mid)return merge(t[k].dat,queryF(pos,k<<1));
        return merge(t[k].dat,queryF(pos,k<<1|1));
    }
}T[1];

int dep[3][1100000],dfn[3][1100000];

void dfs_bas(int id,int u,int &x)
{
    dfn[id][u]=++x;dep[id][u]=fa[id][u]==-1?1:(dep[id][fa[id][u]]+1);
    for(int i=0;i<sons[id][u].size();i++)dfs_bas(id,sons[id][u][i],x);
}

namespace Sub3
{
    void main()
    {
        while(m--)
        {
            int x=0,y=0;scanf("%d%d",&x,&y);
            printf("%d\n",dp[x]);
        }
    }
}

int lowbit(int x){return x&-x;}
struct BIT
{
    int c[1100000];int n;
    void build(int _n){n=_n;for(int i=1;i<=n;i++)c[i]=0;}
    void add(int x,int y){while(x<=n){c[x]+=y;x+=lowbit(x);}}
    int query(int x){int ans=0;while(x){ans+=c[x];x-=lowbit(x);}return ans;}
}B[2];


int ans[1100000];

int main()
{
    //freopen("zero.in","r",stdin);
    //freopen("zero.out","w",stdout);
    n=IO::read();
    for(int i=0;i<2;i++)
    {
        for(int j=1;j<=n;j++){a[i][j]=IO::read();sum[i][j]=sum[i][j-1]+a[i][j];}
    }
    for(int j=1;j<=n;j++){a[2][j]=a[0][j]+a[1][j];sum[2][j]=sum[2][j-1]+a[2][j];}
    for(int i=0;i<3;i++)
    {
        map<long long,int> mp;
        mp[0]=0;fa[i][0]=-1;
        for(int j=1;j<=n;j++)
        {
            if(mp.find(sum[i][j])==mp.end())fa[i][j]=-1;else fa[i][j]=mp[sum[i][j]];
            mp[sum[i][j]]=j;
            fa[i][j]=max(fa[i][j],fa[i][j-1]);
        }
        for(int j=0;j<=n;j++)if(fa[i][j]!=-1)sons[i][fa[i][j]].push_back(j);
    }
    //for(int i=0;i<3;i++){for(int j=0;j<=n;j++)printf("%d ",fa[i][j]);puts("");}
    /*if(n<=1000)
    {
        bru::main();return 0;
    }*/

    for(int i=0;i<2;i++)
    {
        int cnt=0;
        for(int u=0;u<=n;u++)if(fa[i][u]==-1)dfs_bas(i,u,cnt);
    }

    //for(int i=0;i<2;i++){for(int j=0;j<=n;j++)printf("%d ",dep[i][j]);puts("");}
    //for(int i=0;i<2;i++){for(int j=0;j<=n;j++)printf("%d ",dfn[i][j]);puts("");}
    T[0].build(1,n+1);
    for(int i=0;i<2;i++){for(int j=1;j<=n+1;j++)B[i].add(j,1);}
    for(int u=0;u<=n;u++)
    {
        if(fa[2][u]!=-1)dp[u]=max(dp[u],dp[fa[2][u]]+1);
        dp[u]=max(dp[u],dep[0][u]+dep[1][u]+T[0].query(dfn[0][u],dfn[1][u]));
        T[0].modify(1,dfn[0][u],func(dp[u]-dep[0][u]-dep[1][u]-2,dfn[1][u]));
        T[0].modify(dfn[0][u],n+1,func(dp[u]-dep[0][u]-dep[1][u]-1,dfn[1][u]));
    }

    printf("%d\n",dp[n]);
}