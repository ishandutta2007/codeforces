//#pragma GCC optimize("O2")
#include<bits/stdc++.h>
typedef long long ll;
inline void read(int&x){
	char c=getchar();
	for(x=0;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())x=x*10+c-48;
}
inline void up(int&a,const int&b){a<b?a=b:0;}
const int N=200005,S=1050000;
int n,u,v,i,h[N],xb,cnt[S],sz[N],f[N],rt,sum,de[N],dfn[N],tc[S];
char c[N];
bool vi[N];
ll ans[N],su[N];
struct edge{
	int to,next;
}e[N<<1];
inline void addedge(int u,int v){
	e[++xb]=(edge){v,h[u]};h[u]=xb;
	e[++xb]=(edge){u,h[v]};h[v]=xb;
}
void getrt(int x,int fa){
	sz[x]=f[x]=1;
	for(int i=h[x];i;i=e[i].next)
		if(e[i].to!=fa && !vi[e[i].to]){
			getrt(e[i].to,x),sz[x]+=sz[e[i].to];up(f[x],sz[e[i].to]);
		}
	up(f[x],sum-sz[x]);if(f[x]<f[rt])rt=x;
}
void getdep(int x,int fa){
	dfn[++xb]=x;++tc[de[x]];++cnt[de[x]];
	for(int i=h[x];i;i=e[i].next)
		if(e[i].to!=fa && !vi[e[i].to]){
			de[e[i].to]=de[x]^(1<<c[e[i].to]);
			getdep(e[i].to,x);
		}
}
void dfs(int x,int fa){
	for(int i=h[x];i;i=e[i].next)
		if(e[i].to!=fa && !vi[e[i].to]){
			dfs(e[i].to,x);su[x]+=su[e[i].to];
		}
	ans[x]+=su[x];
}
void solve(int x){
	vi[x]=1;int i,u,j,lxb,k,v;
	for(i=h[x];i;i=e[i].next)
		if(sz[e[i].to]>sz[x])sz[e[i].to]=sum-sz[x];
	xb=0;
	for(i=h[x];i;i=e[i].next){
		u=e[i].to;if(vi[u])continue;
		de[u]=1<<c[u];lxb=xb;
		getdep(u,x);
		for(j=lxb+1;j<=xb;++j){
			u=dfn[j];v=de[u]^(1<<c[x]);
			su[u]=-tc[v];
			for(k=0;k<20;++k)su[u]-=tc[v^(1<<k)];
		}
		for(j=lxb+1;j<=xb;++j)tc[de[dfn[j]]]=0;
	}
	for(j=1;j<=xb;++j){
		u=dfn[j];v=de[u]^(1<<c[x]);
		su[u]+=cnt[v]+((v&-v)==v);
		for(k=0;k<20;++k)su[u]+=cnt[v^(1<<k)];
	}
	ll res=0;
	for(i=h[x];i;i=e[i].next)if(!vi[e[i].to]){
		dfs(e[i].to,x);
		res+=su[e[i].to];
	}
	res+=cnt[1<<c[x]];
	for(k=0;k<20;++k)res+=cnt[(1<<c[x])^(1<<k)];
	ans[x]+=res>>1;
	for(j=1;j<=xb;++j)cnt[de[dfn[j]]]=0;
	for(j=h[x];j;j=e[j].next)
		if(!vi[e[j].to]){
			sum=sz[e[j].to];rt=0;
			getrt(e[j].to,x);
			solve(rt);
		}
}
inline void putl(ll x){
	if(x){
		static int buf[30],xb;
		for(xb=0;x;x/=10)buf[++xb]=x%10;
		for(;xb;)putchar(buf[xb--]|48);
	}else putchar('0');
}
int main(){
	//freopen("e.txt","r",stdin);freopen("1.txt","w",stdout);
	read(n);
	for(i=1;i<n;++i)read(u),read(v),addedge(u,v);scanf("%s",c+1);
	for(i=1;i<=n;++i)c[i]-='a';
	sum=n,f[rt=0]=S;getrt(1,0);solve(rt);
	for(i=1;i<=n;++i)putl(ans[i]+1),putchar(' ');
	return 0;
}