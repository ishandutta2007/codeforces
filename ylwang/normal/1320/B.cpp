# include <iostream>
# include <cstdio>
# include <cmath>
# include <cstdlib>
# include <cstring>
# include <string>
# include <algorithm>

#define LL long long
#define maxn int(4e5+5)
#define is(a) (a>='0'&&a<='9')

using namespace std;

int N,M,K,ans,Ans,a[maxn],f[maxn],cnt[maxn];
int ver[2][maxn],nt[2][maxn],hd[2][maxn],tot[2];
int tail,que[maxn],vis[maxn],q[maxn];

inline void read(int &x)
{
  x=0;bool f=0;char ch=getchar();
  for (;!is(ch);ch=getchar()) f|=ch=='-';
  for (;is(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
  x=f?-x:x;
}

inline void addedge(int x,int y,int v)
{
    ++tot[v]; nt[v][tot[v]] = hd[v][x]; ver[v][tot[v]] = y; hd[v][x] = tot[v];
}

inline void Bfs1(int x,int v)
{
    que[++tail] = x; vis[x] = 1; q[1] = x;
    int h=1,t=1;
    while (h<=t)
    {
        int x = q[h];
        for (int i = hd[v][x]; i ;  i = nt[v][i])
        {
            int y = ver[v][i];
            if (vis[y]) continue;
            vis[y]=1;
            que[++tail] = y;
            q[++t] = y;
        }
        ++h;
    }
}

inline void Dfs2(int x,int v)
{
    vis[x] = 1;
    for (int i = hd[v][x]; i ; i = nt[v][i])
    {
        int y = ver[v][i];
        if (f[y]!=1e9)
        {
            if (f[x]>f[y]+1) f[x]=f[y]+1,cnt[x]=1;
            else if (f[x]==f[y]+1) ++cnt[x];
        }
    }
}

int main()
{
//  freopen("a.in","r",stdin);
    read(N); read(M);
    for (int i = 1; i <= M; ++i)
    {
        int x,y;
        read(x); read(y);
        addedge(x,y,0);
        addedge(y,x,1);
    }
    read(K);
    for (int i = 1; i <= K; ++i) read(a[i]);
    Bfs1(a[K],1);
    for (int i = 1; i <= N; ++i) f[i]=1e9,cnt[i]=1,vis[i]=0;
    f[a[K]]=0;
    for (int i = 1; i <= N; ++i)
    {
        Dfs2(que[i],0);
    }
    for (int i = 2; i <= K; ++i)
    {
        if (f[a[i]]!=f[a[i-1]]-1) ++ans;
        else
        {
            if (cnt[a[i-1]]>1) ++Ans;
        }
    }
    printf("%d %d\n",ans,ans+Ans);
    return 0;
}