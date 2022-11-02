#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> pii;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int N=200005;
int n,m,k,q;
struct Graph{
	static const int M=N*2;
	int cnt,y[M],nxt[M],fst[N];
	void clear(){
		cnt=1,clr(fst);
	}
	void add(int a,int b){
		y[++cnt]=b,nxt[cnt]=fst[a],fst[a]=cnt;
	}
}g;
vector <int> e[N];
int bh[N];
namespace TJ{
	int dfn[N],low[N],st[N],inst[N];
	int vise[N];
	int Time=0,cnt=0,top=0;
	void Tarjan(int x){
		inst[x]=1;
		dfn[x]=low[x]=++Time;
		st[++top]=x;
		for (int i=g.fst[x];i;i=g.nxt[i]){
			if (vise[i>>1])
				continue;
			vise[i>>1]=1;
			int y=g.y[i];
//			printf("%d: %d -> %d\n",i,x,y);
			if (!dfn[y]){
				Tarjan(y);
				low[x]=min(low[x],low[y]);
			}
			else if (inst[y])
				low[x]=min(low[x],low[y]);
		}
		if (low[x]==dfn[x]){
			bh[st[top]]=++cnt;
			inst[st[top]]=0;
			while (st[top--]!=x){
				bh[st[top]]=cnt;
				inst[st[top]]=0;
			}
		}
	}
}
map <int,int> Map[N];
int vis[N];
int fa[N][20],depth[N];
void dfs(int x,int pre,int d){
	fa[x][0]=pre,depth[x]=d,vis[x]=1;
	For(i,1,19)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for (auto y : e[x])
		if (!vis[y])
			dfs(y,x,d+1);
}
int LCA(int x,int y){
	if (depth[y]>depth[x])
		swap(x,y);
	Fod(i,19,0)
		if (depth[x]-(1<<i)>=depth[y])
			x=fa[x][i];
	if (x==y)
		return x;
	Fod(i,19,0)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int up[N],dn[N];
int flag=0;
void check(int x){
	vis[x]=1;
	for (auto y : e[x])
		if (!vis[y]){
			check(y);
			up[x]=min(up[x],up[y]);
			dn[x]=min(dn[x],dn[y]);
		}
	flag|=up[x]<depth[x]&&dn[x]<depth[x];
}
int main(){
	n=read(),m=read(),q=read();
	g.clear();
	For(i,1,m){
		int x=read(),y=read();
		g.add(x,y),g.add(y,x);
	}
	For(i,1,n)
		if (!TJ::dfn[i])
			TJ::Tarjan(i);
//	outarr(bh,1,n);
//	outarr(TJ::dfn,1,n);
//	outarr(TJ::low,1,n);
	k=TJ::cnt;
	For(i,2,g.cnt){
		int x=g.y[i^1],y=g.y[i];
		x=bh[x],y=bh[y];
		if (x==y||Map[x][y])
			continue;
		e[x].pb(y);
		Map[x][y]=1;
	}
	clr(vis);
	For(i,1,k)
		if (!vis[i])
			dfs(i,0,0);
	For(i,1,k)
		up[i]=dn[i]=depth[i];
	while (q--){
		int x=bh[read()],y=bh[read()];
		int lca=LCA(x,y);
		if (!lca)
			return puts("No"),0;
		up[x]=min(up[x],depth[lca]);
		dn[y]=min(dn[y],depth[lca]);
	}
	clr(vis);
	For(i,1,k)
		if (!vis[i])
			check(i);
	puts(flag?"No":"Yes");
	return 0;
}