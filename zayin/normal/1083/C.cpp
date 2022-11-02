#include<bits/stdc++.h>
#define u(i)    T[i].u
#define v(i)    T[i].v
#define maxh 20
#define maxn 200050
using namespace std;

int dep[maxn];

int pos[maxn];
int N,Log2[maxn<<1]={-1};
int ST[maxh][maxn<<1];

int Min(int i,int j)
{
    return dep[i]<dep[j]?i:j;
}

int LCA(int i,int j)
{
    i=pos[i],j=pos[j];
    if (i>j)    swap(i,j);
    int t=Log2[j-i+1];
    return Min(ST[t][i],ST[t][j-(1<<t)+1]);
}

bool in(int u,int v,int p)  {
    return (LCA(u,p)==p||LCA(v,p)==p)&&dep[p]>=dep[LCA(u,v)];
}

struct node
{
    int u,v;
    node (int _u=0,int _v=0)  {
        u=_u,v=_v;
    }


    node operator * (const node& N) const {
        if (!u)   return N;
        if (!N.u) return *this;
        if (!~u||!~N.u)  return node(-1,-1);
        // cout<<"merge: ("<<u<<","<<v<<") ("<<N.u<<","<<N.v<<")"<<endl;
        vector<int> V={u,v,N.u,N.v};
        for (int i=0;i<4;++i)
            for (int j=i+1;j<4;++j)
            {
                bool flag=1;
                // cout<<V[i]<<" "<<V[j]<<endl;
                for (int k=0;k<4;++k)  flag&=in(V[i],V[j],V[k]);
                if (flag)
                    return node(V[i],V[j]);
            }
        return node(-1,-1);
    }

    operator bool() const   {
        return ~u;
    }
}   T[maxn<<2];

int n,q;

int vert[maxn],val[maxn];
vector<int> G[maxn];

void init()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",&val[i]),vert[++val[i]]=i;
    for (int v,u=2;u<=n;++u)
    {
        scanf("%d",&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void dfs(int i,int fa=0)
{
    pos[i]=N;
    ST[0][N++]=i;
    dep[i]=dep[fa]+1;
    for (int j:G[i])
    {
        if (fa==j)  continue;
        dfs(j,i);
        ST[0][N++]=i;
    }
}

void build(int k,int l,int r)
{
    if (l==r)
        T[k]=node(vert[l],vert[l]);
    else
    {
        int mid=(l+r)>>1;
        build(k<<1,l,mid);
        build(k<<1|1,mid+1,r);
        T[k]=T[k<<1]*T[k<<1|1];
    }
    // cout<<"build:"<<k<<" "<<l<<" "<<r<<" ("<<u(k)<<","<<v(k)<<")"<<endl;
}

void predo()
{
    dfs(1);
    for (int i=1;i<=N;++i)  Log2[i]=Log2[i>>1]+1;
    for (int j=1;(1<<j)<=N;++j)
        for (int i=0;i+(1<<j)<=N;++i)
            ST[j][i]=Min(ST[j-1][i],ST[j-1][i+(1<<(j-1))]);
    build(1,1,n);
}

void change(int k,int l,int r,int p)
{
    if (l==r)
        T[k]=node(vert[p],vert[p]);
    else
    {
        int mid=(l+r)>>1;
        if (p<=mid)
            change(k<<1,l,mid,p);
        else
            change(k<<1|1,mid+1,r,p);
        T[k]=T[k<<1]*T[k<<1|1];
    }
}

int ans;
node path;

bool query(int k,int l,int r)
{
    // cout<<"query:"<<k<<" "<<l<<" "<<r<<" ("<<path.u<<","<<path.v<<") "<<ans<<endl;
    if (path*T[k]) return path=path*T[k],ans=r;
    if (l==r)   return 0;
    int mid=(l+r)>>1;
    if (query(k<<1,l,mid))
        query(k<<1|1,mid+1,r);
    return 0;
}

void solve()
{
    scanf("%d",&q);
    while (q--)
    {
        int op,x,y;
        scanf("%d",&op);
        if (op==1)
        {
            scanf("%d%d",&x,&y);
            swap(vert[val[x]],vert[val[y]]);
            change(1,1,n,val[x]);
            change(1,1,n,val[y]);
            swap(val[x],val[y]);
        } else
        {
            ans=0;
            path=node();
            query(1,1,n);
            printf("%d\n",ans);
        }
    }
}

int main()
{
    init();
    predo();
    solve();
    return 0;
}