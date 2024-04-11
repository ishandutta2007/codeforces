#pragma GCC optimize("Ofast","inline")
#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=a;i<=b;i++)
#define Fod(i,b,a) for (int i=b;i>=a;i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define real __zzd001
#define _SEED_ ('C'+'L'+'Y'+'A'+'K'+'I'+'O'+'I')
#define outval(x) printf(#x" = %d\n",x)
#define outvec(x) printf("vec "#x" = ");for (auto _v : x)printf("%d ",_v);puts("")
#define outtag(x) puts("----------"#x"----------")
#define outarr(a,L,R) printf(#a"[%d...%d] = ",L,R);\
						For(_v2,L,R)printf("%d ",a[_v2]);puts("");
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> vi;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=200005;
int n,m;
vector <int> e[N],id[N];
struct Edge{
	int x,y,z;
}a[N];
int depth[N],size[N],son[N],fa[N],top[N],I[N],aI[N],Time=0;
void dfs1(int x,int pre,int d){
	depth[x]=d,fa[x]=pre,size[x]=1,son[x]=0;
	for (int i=0;i<e[x].size();i++){
		int y=e[x][i];
		if (y!=pre){
			dfs1(y,x,d+1);
			size[x]+=size[y];
			if (!son[x]||size[y]>size[son[x]])
				son[x]=y;
		}
	}
}
void dfs2(int x,int Top){
	top[x]=Top;
	I[x]=++Time;
	aI[Time]=x;
	if (son[x])
		dfs2(son[x],Top);
	for (int i=0;i<e[x].size();i++){
		int y=e[x][i];
		if (y!=fa[x]&&y!=son[x])
			dfs2(y,y);
	}
}
LL c[N];
void Add(int x,LL v){
	for (;x<=n;x+=x&-x)
		c[x]+=v;
}
LL Ask(int x){
	LL ans=0;
	for (;x;x-=x&-x)
		ans+=c[x];
	return ans;
}
int LCA(int x,int y){
	while (top[x]!=top[y]){
		if (depth[top[x]]<depth[top[y]])
			swap(x,y);
		x=fa[top[x]];
	}
	return depth[x]<depth[y]?x:y;
}
int Goup(int x,int y){
	// depth[x] > depth[y];
	while (top[x]!=top[y]){
		x=top[x];
		if (fa[x]==y)
			return x;
		x=fa[x];
	}
	return son[y];
}
LL dp[N],val[N];
LL Query(int x,int y){
	LL ans=dp[son[x]];
	while (top[x]!=top[y]){
		ans+=Ask(I[x])-Ask(I[top[x]]-1);
		ans-=dp[top[x]];
		x=fa[top[x]];
		ans+=dp[son[x]];
	}
	ans+=Ask(I[x])-Ask(I[y]-1);
	return ans;
}
void dfs3(int x){
	dp[x]=0;
	for (int i=0;i<e[x].size();i++){
		int y=e[x][i];
		if (y!=fa[x]){
			dfs3(y);
			dp[x]+=dp[y];
			if (y!=son[x])
				val[x]+=dp[y];
		}
	}
	Add(I[x],val[x]);
	for (int cly=0;cly<id[x].size();cly++){
		int i=id[x][cly];
		dp[x]=max(dp[x],Query(a[i].x,x)+Query(a[i].y,x)
						-val[x]-dp[son[x]]+a[i].z);
	}
}
int main(){
	n=read(),m=read();
	For(i,1,n-1){
		int f=read();
		e[i+1].pb(f),e[f].pb(i+1);
	}
	dfs1(1,0,0);
	dfs2(1,1);
	For(i,1,m){
		int x=read(),y=read(),z=read();
		a[i].x=x,a[i].y=y,a[i].z=z;
		id[LCA(x,y)].pb(i);
	}
	dfs3(1);
	cout<<dp[1]<<endl;
	return 0;
}