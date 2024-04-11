#include <cstdio>
#include <cstring>
const int N=2e6+10;
int n,dnt,mx[N],mxp[N],len[N],ans[N],dep[N],heavy[N],head[N],to[N],next[N];
int *dp[N];bool vis[N];
namespace basic{
	int lt,nw,res,dig[30];
	char cdc;
	inline int read(){
		res=0;
		for(;cdc<'0'||cdc>'9';cdc=getchar());
		for(;!(cdc<'0'||cdc>'9');cdc=getchar())res=(res<<1)+(res<<3)+(cdc^48);
		return res;
	}
	inline void write(int x){
		if(!x)putchar('0');
		for(;x;x=nw)nw=x/10,dig[++lt]=x-(nw<<1)-(nw<<3);
		for(;lt;--lt)putchar(dig[lt]^48);
		putchar('\n');
	}
}using basic::read;using basic::write;
inline void addedge(int u,int v){next[++dnt]=head[u],head[u]=dnt,to[dnt]=v;}
inline void ins(int u,int p,int d){int w=(dp[u][p]+=d);if(w>mx[u]||(w==mx[u]&&p<mxp[u]))mx[u]=w,mxp[u]=p;}
void dfs1(int u){
	vis[u]=true;
	for(int i=head[u];i;i=next[i]){
		if(vis[to[i]])continue;
		dep[to[i]]=dep[u]+1,dfs1(to[i]);if(len[to[i]]>len[u])len[u]=len[to[i]],heavy[u]=to[i];
	}
	++len[u];
}
void dfs2(int u){
	if(!len[u])len[u]=1;
	if(heavy[u])len[heavy[u]]=len[u]+1,dfs2(heavy[u]),mx[u]=mx[heavy[u]],mxp[u]=mxp[heavy[u]]+1,dp[u]=dp[heavy[u]]-1;
	else{
		dp[u]=new int[len[u]+5]+len[u]-1;
		for(int i=-1;i<len[u];++i)dp[u][-i]=0;
	}
	for(int i=head[u];i;i=next[i]){
		if(len[to[i]])continue;dfs2(to[i]);
		for(int j=0;dp[to[i]][j]>0;++j)ins(u,j+1,dp[to[i]][j]);delete[] dp[to[i]];
	}
	ins(u,0,1),ans[u]=mxp[u];
}
int main(){
	n=read();
	for(int u,v,i=1;i<n;++i)u=read(),v=read(),addedge(u,v),addedge(v,u);
	dfs1(1),memset(len,0,sizeof(len)),dfs2(1),delete[] dp[1];
	for(int i=1;i<=n;++i)write(ans[i]);return 0;
}