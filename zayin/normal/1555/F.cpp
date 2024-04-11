#include<bits/stdc++.h>
#define maxn 1000050
using namespace std;
typedef pair<int,int> pii;

int n,m;
namespace LCT   {
    #define ls(x) ch[x][0]
    #define rs(x) ch[x][1]

    int ch[maxn][2],fa[maxn],rev[maxn];

    void info() {
        for (int i=1;i<=n;++i) cout<<i<<":"<<fa[i]<<" ("<<ls(i)<<","<<rs(i)<<")"<<endl;
    }

    void init(int x) {
        fa[x]=ls(x)=rs(x)=rev[x]=0;
    }

    int get(int x)  {   return ch[fa[x]][1]==x; }
    int isroot(int x)   {   return !(ch[fa[x]][0]==x||ch[fa[x]][1]==x); }

    void makerev(int x) {
        if (!x) return ;
        swap(ls(x),rs(x));
        rev[x]^=1;
    }

    void godown(int x)  {
        if (rev[x])
            makerev(ls(x)),makerev(rs(x)),rev[x]=0;
    }

    void update(int x)  {
    }

    void rotate(int x)  {
        int y=fa[x],z=fa[y],c=get(x);
        ch[y][c]=ch[x][c^1];
        if (ch[x][c^1]) fa[ch[x][c^1]]=y;
        if (!isroot(y)) ch[z][get(y)]=x;
        ch[x][c^1]=y,fa[x]=z,fa[y]=x;
        update(y),update(x);
    }

    void refresh(int x)    {
        if (!isroot(x)) refresh(fa[x]);
        godown(x);
    }
    void splay(int x)   {
        refresh(x);
        for (;!isroot(x);rotate(x))
            if (!isroot(fa[x]))
                rotate(get(fa[x])==get(x)?fa[x]:x);
    }
    
    void travel(int x)  {
        if (!x) return ;
        godown(x);
        travel(ls(x));
        cout<<x<<"("<<ls(x)<<","<<rs(x)<<") ";
        travel(rs(x));
    }

    void print(int x)   {
        while (!isroot(x)) x=fa[x];
        cout<<"travel:"; travel(x); cout<<endl;
    }

    void access(int x)  {
        for (int t=0;x;t=x,x=fa[x]) 
            splay(x),rs(x)=t,update(x);
    }

    int findroot(int x)    {
        access(x),splay(x);
        while (ls(x)) x=ls(x);
        splay(x);//can not be deleted
        return x;
    }

    void makeroot(int x)    {
        access(x),splay(x),makerev(x);
    }
    void link(int x,int y)  {
        makeroot(x);
        if (findroot(y)!=x) 
            fa[x]=y;
    }

    void cutf(int x)    {
        access(x),splay(x);
        ls(x)=fa[ls(x)]=0;
        update(x);
    }
    void cut(int x,int y)   {
        makeroot(x);
        if (findroot(y)==x&&fa[y]==x&&!ls(y))
            cutf(y);
    }

    void split(int x,int y) {
        makeroot(x),access(y),splay(y);
    }

    bool connected(int x,int y) {
        makeroot(x);
        return findroot(y)==x;
    }
}

int u[maxn],v[maxn],w[maxn];

int fa[maxn];
vector<pii> G[maxn];

int f[maxn];
int find(int i) {
    return !f[i]?i:f[i]=find(f[i]);
}

int dep[maxn];
int res[maxn],sum[maxn];

void dfs(int i)    {
    // cout<<i<<" "<<fa[i]<<":"<<sum[i]<<endl;
    for (pii pr:G[i])   {
        int j=pr.first;
        if (fa[i]!=j)    {
            // cout<<i<<" "<<j<<endl;
            LCT::link(i,j);
            fa[j]=i;
            dep[j]=dep[i]+1;
            sum[j]=sum[i]^pr.second;
            dfs(j);
        }
    }
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for (int i=1;i<=m;++i)  {
        cin>>u[i]>>v[i]>>w[i];
        if (find(u[i])==find(v[i])) continue;
        f[find(u[i])]=find(v[i]);
        res[i]=1;
        G[u[i]].emplace_back(v[i],w[i]);
        G[v[i]].emplace_back(u[i],w[i]);
    }


    for (int i=1;i<=n;++i)
        LCT::init(i);
    for (int i=1;i<=n;++i)
        if (!fa[i])
            dfs(i);

        
    // cout<<"???"<<endl;

    for (int i=1;i<=m;++i)  {
        if (res[i]) {
            cout<<"YES"<<endl;
            continue;
        }

        // cout<<i<<":"<<(sum[u[i]]^sum[v[i]])<<" "<<LCT::connected(u[i],v[i])<<endl;

        if ((sum[u[i]]^sum[v[i]]^w[i])==1&&LCT::connected(u[i],v[i]))    {
            cout<<"YES"<<endl;
            int x=u[i],y=v[i];
            while (x!=y)    {
                if (dep[x]<dep[y]) swap(x,y);
                LCT::cut(x,fa[x]);
                x=fa[x];
            }
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}