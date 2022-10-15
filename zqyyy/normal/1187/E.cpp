#include <cstdio>
#include <cctype>
#define re register
using namespace std;
#define ll long long
#define max(x,y) ((x)>(y)?(x):(y))
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int MAXN=2e5+1;
struct Edge{
	int to,nxt;
}e[MAXN<<1];
int s_e,head[MAXN];
inline void add_e(int from,int to){
	e[++s_e].to=to,e[s_e].nxt=head[from];
	head[from]=s_e;
}
int n,sz[MAXN];
ll f[MAXN],g[MAXN];
void dfs1(int x,int fa){
	sz[x]=1;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y==fa) continue;
		dfs1(y,x);
		sz[x]+=sz[y],f[x]+=f[y];
	}
	f[x]+=sz[x];
}
void dfs2(int x,int fa,int dep){
	if(x^1){
		g[x]=g[fa]-2*sz[x]+n;
	}
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y^fa)dfs2(y,x,dep+1);
	}
}
int main(){
	n=read();
	for(re int i=1;i<n;i++){
		int x=read(),y=read();
		add_e(x,y),add_e(y,x);
	}
	dfs1(1,0);g[1]=f[1];
	dfs2(1,0,0);
	ll ans=0;
	for(re int i=1;i<=n;i++)ans=max(ans,g[i]);
	printf("%lld\n",ans);
	return 0;
}