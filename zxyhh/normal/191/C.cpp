/*
	Author: zxy_hhhh
	date: 2019/03/29
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#define rep(x,a,b) for (int x=int(a);x<=(int)(b);x++)
#define drp(x,a,b) for (int x=int(a);x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];x;x=nx[x])
#define ll long long
using namespace std;
inline ll rd()
{
	ll _x=0;int _ch=getchar(),_f=1;
	for(;!isdigit(_ch)&&(_ch!='-')&&(_ch!=EOF);_ch=getchar());
	if (_ch=='-'){_f=0;_ch=getchar();}
	for(;isdigit(_ch);_ch=getchar()) _x=_x*10+_ch-'0';
	return _f?_x:-_x;
}
void write(ll _x){if (_x>=10) write(_x/10),putchar(_x%10+'0'); else putchar(_x+'0'); }
inline void wrt(ll _x,char _p){if (_x<0) putchar('-'),_x=-_x; write(_x); if (_p) putchar(_p);}
#define maxn 200005
int nx[maxn],to[maxn],hd[maxn],id[maxn],cnt;
inline void add(int u,int v,int Id) {
	nx[++cnt]=hd[u],to[cnt]=v,id[cnt]=Id,hd[u]=cnt;
}
int n;
int ans[maxn],res[maxn];
int f[maxn][21],F[maxn],dep[maxn];
void dfs(int u,int fa) {
	f[u][0]=fa,dep[u]=dep[fa]+1;
	rep(i,1,19) f[u][i]=f[f[u][i-1]][i-1];
	cross(i,u) if (to[i]!=fa) {
		F[to[i]]=id[i];
		dfs(to[i],u);
	}
}
inline int lca(int u,int v) {
	if (dep[u]<dep[v]) swap(u,v);
	drp(i,19,0)
		if (dep[f[u][i]]>=dep[v]) u=f[u][i];
	if (u==v) return u;
	drp(i,19,0)
		if (f[u][i]!=f[v][i])
			u=f[u][i],v=f[v][i];
	return f[u][0];
}
void DFS(int u,int fa) {
	cross(i,u) if (to[i]!=fa) {
		DFS(to[i],u);
		ans[u]+=ans[to[i]];
	}
	res[F[u]]=ans[u];
}
int main()
{
	n=rd();
	rep(i,2,n) {
		int x=rd(),y=rd();
		add(x,y,i-1),add(y,x,i-1);
	}
	dfs(1,0);
	int m=rd();
	rep(i,1,m) {
		int x=rd(),y=rd();
		ans[x]++,ans[y]++,ans[lca(x,y)]-=2;
	}
	DFS(1,0);
	rep(i,1,n-1) wrt(res[i],' ');
	putchar('\n');
}