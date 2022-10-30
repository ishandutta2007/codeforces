#include<bits/stdc++.h>
#define maxh 20
#define maxn 300050
using namespace std;

namespace IO {
	char In[1<<20],*p1=In,*p2=In,c,Out[1<<23],*Op=Out,St[10],*Tp=St;
	#define Getc (p1==p2&&(p2=(p1=In)+fread(In,1,1<<20,stdin),p1==p2)?EOF:*p1++)
	inline void Flush(){fwrite(Out,1,Op-Out,stdout);}
	inline int read(int x=0)   {
        int s=1;
        while(!isdigit(c=Getc)&&c!='-');
        if (c=='-') s=-1,c=Getc;
        for(;isdigit(c);c=Getc)x=(x<<3)+(x<<1)+(c^48);
        return s*x;
    }
	inline void write(int x)    {
        do *Tp++=x%10^48; while(x/=10);
        do *Op++=*--Tp; while(Tp!=St);
        *Op++='\n';
    }
}

int n,m;
int a[maxn];

vector<int> G[maxn];
int T,st[maxn],ed[maxn];
int seq[maxn<<1];

int dep[maxn];
int F[maxh][maxn],* const fa=F[0];

void dfs(int i) {
    dep[i]=dep[fa[i]]+1;
    for (int j=1;j<maxh;++j)
        F[j][i]=F[j-1][F[j-1][i]];
    seq[st[i]=++T]=i;
    for (int j:G[i])    {
        if (fa[i]==j) continue;
        fa[j]=i;
        dfs(j);
    }
    seq[ed[i]=++T]=i;
}

int lca(int u,int v)    {
    if (dep[u]<dep[v]) swap(u,v);
    for (int d=dep[u]-dep[v],i=0;i<maxh;++i)
        if (d>>i&1)
            u=F[i][u];
    if (u==v) return u;
    
    for (int i=maxh-1;i>=0;--i) {
        if (F[i][u]==F[i][v]) continue;
        u=F[i][u],v=F[i][v];
    }
    return fa[u];
}

const int lim=1300;
int bel[maxn<<1];

struct qry  {
    int l,r,d,u,x,id;
    bool operator < (const qry& Q) const    {
        return bel[l]!=bel[Q.l]?l<Q.l:((bel[l]&1)?r<Q.r:r>Q.r);
    }
};

vector<qry> Q;

int ans[maxn];

namespace BL    {
    int B[maxn],b[maxn];
    inline void change(int p,int d)    {
        if (b[p]&1) --B[bel[p]];
        b[p]+=d;
        if (b[p]&1) ++B[bel[p]];
    }

    inline int ask(int l,int r)    {
        // for (int i=1;i<=n;++i) cout<<b[i]<<" "; cout<<endl;
        if (bel[l]==bel[r]) {
            // cout<<"???"<<endl;
            for (int i=l;i<=r;++i)
                if (b[i]&1) {
                    return i;
                }
        } else    {
            for (int t=bel[l]+1;t<bel[r];++t)
                if (B[t])   {
                    for (int i=t*lim;i<t*lim+lim;++i)
                        if (b[i]&1)
                            return i;
                    assert(0);
                }
            for (int i=l;i<bel[l]*lim+lim;++i)
                if (b[i]&1)
                    return i;
            for (int i=r;i>=bel[r]*lim;--i)
                if (b[i]&1)
                    return i;
        }
        // cout<<"return -1"<<endl;
        return -1;
    }
}

int vis[maxn];

int CNT=0;

inline void change(int x)  {
    if (!x) return ;
    ++CNT;
    // cout<<"change:"<<x<<endl;
    if (vis[x]^=1)
        BL::change(a[x],1);
    else
        BL::change(a[x],-1);
}

int main()  {
    for (int i=0;i<maxn*2;++i) bel[i]=i/lim;

    // scanf("%d%d",&n,&m);
    n=IO::read(),m=IO::read();
    // for (int i=1;i<=n;++i) scanf("%d",a+i);
    for (int i=1;i<=n;++i) a[i]=IO::read();
    for (int i=1;i<n;++i)   {
        int u=IO::read(),v=IO::read();
        // scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1);

    // cout<<"???"<<endl;
    for (int i=0;i<m;++i)   {
        int u=IO::read(),v=IO::read(),l=IO::read(),r=IO::read();
        // scanf("%d%d%d%d",&u,&v,&l,&r);
        if (dep[u]>dep[v]) swap(u,v);
        int t=lca(u,v);
        if (u==t)
            Q.push_back(qry{st[u],st[v],l,r,0,i});
        else
            Q.push_back(qry{ed[u],st[v],l,r,t,i});
    }
    cerr<<clock()<<endl;

    sort(Q.begin(),Q.end());

    int L=1,R=0;
    for (auto q:Q)  {
        while (R<q.r) change(seq[++R]);
        while (L>q.l) change(seq[--L]);
        while (R>q.r) change(seq[R--]);
        while (L<q.l) change(seq[L++]);

        change(q.x);
        ans[q.id]=BL::ask(q.d,q.u);
        change(q.x);
    }

    for (int i=0;i<m;++i)
        printf("%d\n",ans[i]);
    cerr<<clock()<<" ~ "<<CNT<<endl;
    return 0;
}