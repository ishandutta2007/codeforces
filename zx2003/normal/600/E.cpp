#include<cstdio>
#include<cctype>
inline int getint(){
	int x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x;
}
int buf[100];
inline void putl(long long x){
	if(!x)putchar('0');
		else{
			int xb=0;
			for(;x;x/=10)buf[++xb]=x%10;
			for(;xb;--xb)putchar(buf[xb]+48);
		}
}
const int N=100005;
struct edge{
	int to,next;
}e[N<<1];
int h[N],xb,id[N],dfn[N],right[N],sz[N],ma[N],n,c[N],i,u,v,cnt[N];
long long s[N],ans[N]; 
inline void addedge(int u,int v){
	e[++xb]=(edge){v,h[u]};
	h[u]=xb;
	e[++xb]=(edge){u,h[v]};
	h[v]=xb;
}
void dfs1(int x,int fa){
	dfn[id[x]=++xb]=x;
	sz[x]=1;
	for(int i=h[x];i;i=e[i].next)
		if(e[i].to!=fa){
			dfs1(e[i].to,x);
			sz[x]+=sz[e[i].to];
			if(!ma[x] || sz[ma[x]]<sz[e[i].to])ma[x]=e[i].to;
		}
	right[x]=xb;
}
inline void in(int x){
	for(register int i=id[x];i<=right[x];++i){
		s[cnt[c[dfn[i]]]]-=c[dfn[i]];
		s[++cnt[c[dfn[i]]]]+=c[dfn[i]];
		if(cnt[c[dfn[i]]]>v)v=cnt[c[dfn[i]]];
	}
}
inline void out(int x){
	for(register int i=id[x];i<=right[x];++i){
		s[cnt[c[dfn[i]]]--]-=c[dfn[i]];
		s[cnt[c[dfn[i]]]]+=c[dfn[i]];
		if(!s[v])--v;
	}
}
void dfs(int x,int fa,bool keep){
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=fa && e[i].to!=ma[x])dfs(e[i].to,x,0);
	if(ma[x])dfs(ma[x],x,1);
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=fa && e[i].to!=ma[x])in(e[i].to);
	s[cnt[c[x]]]-=c[x];
	s[++cnt[c[x]]]+=c[x];
	if(cnt[c[x]]>v)v=cnt[c[x]];
	ans[x]=s[v];
	if(!keep)out(x);
}
int main(){
	n=getint();
	for(i=1;i<=n;++i)*s+=c[i]=getint();
	for(i=1;i<n;++i){
		u=getint();
		v=getint();
		addedge(u,v);
	}
	dfs1(1,xb=0);
	dfs(1,v=0,1);
	for(i=1;i<=n;++i)putl(ans[i]),putchar(' ');
	return 0;
}