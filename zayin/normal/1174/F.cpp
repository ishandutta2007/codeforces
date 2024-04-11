#include<bits/stdc++.h>
#define maxh 20
#define maxn 200050
#define F(i)    fa[i][0]
using namespace std;

int n;
vector<int> G[maxn];

int sz[maxn],dep[maxn];
int fa[maxn][maxh];
int son[maxn],leaf[maxn];

void init() {
    scanf("%d",&n);
    for (int k=1;k<n;++k)   {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

int dfs1(int i)  {
    for (int j=1;fa[i][j-1];++j)
        fa[i][j]=fa[fa[i][j-1]][j-1];
    for (int j:G[i])    {
        if (F(i)==j)  continue;
        dep[j]=dep[F(j)=i]+1;
        sz[i]+=dfs1(j);
        if (sz[son[i]]<sz[j])
            son[i]=j;
    }
    return ++sz[i];
}

int dfs2(int i) {
    leaf[i]=son[i]?dfs2(son[i]):i;
    for (int j:G[i])    {
        if (F(i)==j||son[i]==j)   continue;
        dfs2(j);
    }
    return leaf[i];
}

int kth(int u,int d)    {
    // cout<<"kth:"<<u<<" "<<d<<endl;
    for (int i=0;i<maxh;++i)
        if (d>>i&1)
            u=fa[u][i];
    return u;
}

int D(int u)    {
    printf("d %d\n",u);
    fflush(stdout);
    scanf("%d",&u);
    return u;
}

int S(int u)    {
    printf("s %d\n",u);
    fflush(stdout);
    scanf("%d",&u);
    return u;
}

void solve()    {
    dfs1(1);
    dfs2(1);
    int dx=D(1),u=1;
    while (dx)   {
        int d=D(leaf[u]);
        if (d+dx==dep[leaf[u]]) {
            u=kth(leaf[u],d);
            break;
        } else  {
            int dp=(dep[leaf[u]]+dx-d)/2;
            u=kth(leaf[u],dep[leaf[u]]-dp);
            u=S(u);
        }
    }
    printf("! %d\n",u);
    fflush(stdout);
}

int main()  {
    init();
    solve();
    return 0;
}