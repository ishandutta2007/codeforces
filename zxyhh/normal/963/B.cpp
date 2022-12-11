#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<ctime>
#include<string>
#include<queue>
#include<cmath>
#include<vector>
#define rep(x,a,b) for (int x=int(a);x<=(int)(b);x++)
#define drp(x,a,b) for (int x=int(a);x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];x;x=nx[x])
#define ll long long
#define ldb long double
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define maxn 200005
using namespace std;
inline ll rd(){
    ll x=0;int ch=getchar(); bool f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=0;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return f?x:-x;
}
void write(ll x){ if (x>=10) write(x/10),putchar(x%10+'0'); else putchar(x+'0'); }
inline void wrt(ll x,int p){if (x<0) putchar('-'),x=-x; write(x); if (p) putchar(p);}
int dep[maxn],fa[maxn],n,root,mx;
int to[maxn],nx[maxn],hd[maxn],cnt;
int d[maxn];
bool vis[maxn];
inline void add(int u,int v) {to[++cnt]=v,nx[cnt]=hd[u],hd[u]=cnt;}
vector <int> a[maxn];
void dfs1(int u)
{
    dep[u]=dep[fa[u]]+1;
    if (dep[u]>mx) mx=dep[u];
    a[dep[u]].push_back(u);
    cross(i,u)
    fa[to[i]]=u,dfs1(to[i]),d[u]++,d[to[i]]++;
}
void dfs(int u)
{
    wrt(u,'\n');vis[u]=1;
    cross(i,u)
    if (!vis[to[i]]) dfs(to[i]);
}
int main()
{
    n=rd();
    if (!(n&1)) {printf("NO\n"); return 0;}
    printf("YES\n");
    int x;
    rep(i,1,n) if (x=rd()) add(x,i);
    else root=i;
    dfs1(root);
    vector<int>::iterator it;
    drp(i,mx,2) for(it=a[i].begin();it!=a[i].end();it++)
    if ((d[*it]&1)==0) dfs(*it),d[fa[*it]]--;
    dfs(root);
}