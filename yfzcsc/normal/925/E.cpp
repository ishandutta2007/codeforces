#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
vector<int>G[maxn];
int vis[maxn],c[700][700],tp,tp2,tg[maxn],f[maxn];
int d[maxn],ans,fa2[maxn],ti[maxn],a[maxn],e[maxn],n,fa[maxn];
int top[maxn],dfn[maxn],tim,dep[maxn],b[maxn],son[maxn],m,q[maxn];
int pre(int u){
	int s,mxsize=0,sz=1;
	for(auto p:G[u]){
		s=pre(p),sz+=s;
		if(mxsize<s)mxsize=s,son[u]=p;
	}
	return sz;
}
void pre2(int u,int tp){
	dep[u]=dep[fa[u]]+1;
	top[u]=tp,dfn[u]=++tim;
	if(son[u])pre2(son[u],tp);
	for(auto p:G[u])if(p!=son[u])pre2(p,p);
}
int lca(int u,int v){
	while(top[u]!=top[v])
		dep[top[u]]<dep[top[v]]?v=fa[top[v]]:u=fa[top[u]];
	return dep[u]<dep[v]?u:v;
}
void build(){
	n=1e5,m=1e5;
	freopen("out.txt","w",stdout);
	for(int i=1;i<=n;++i){
		if(i>1)fa[i]=rand()%(i-1)+1;
		ti[i]=rand()%5;
		G[fa[i]].push_back(i);
	}
	for(int i=1;i<=m;++i)a[i]=rand()%n+1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;++i)
		scanf("%d",&fa[i]),G[fa[i]].push_back(i);
	for(int i=1;i<=n;++i)
		scanf("%d",&ti[i]);
	for(int i=1;i<=m;++i)
		scanf("%d",&a[i]);
//	build();
	pre(1),pre2(1,1);
	int blk=(int)sqrt(m)+1,l=0,r=0;
	q[r++]=1;
	while(l<r){
		int u=q[l++];
		for(auto p:G[u])q[r++]=p;
	}
	for(int i=0;i<=m/blk;++i){
		int L=i*blk+1,R=min(m,(i+1)*blk);
		for(int j=1;j<=n;++j)f[j]=tg[j]=vis[j]=0;
		ans=tp=tp2=0;
		for(int j=1;j<L;++j){
			vis[abs(a[j])]^=1;
			f[abs(a[j])]+=(a[j]>0?1:-1);
		}
		for(int i=n-1;i>=0;--i){
			int u=q[i];
			ans+=vis[u]==0&&f[u]>ti[u];
			f[fa[u]]+=f[u];
		}
		for(int j=L;j<=R;++j)
			b[++tp]=abs(a[j]);
		sort(b+1,b+tp+1,[](int x,int y){return dfn[x]<dfn[y];});
		for(int j=1,k=tp;j<k;++j)b[++tp]=lca(b[j],b[j+1]);
		sort(b+1,b+tp+1,[](int x,int y){return dfn[x]<dfn[y];});
		static int sta[maxn];
		int id=0;
		for(int j=1,lst=0;j<=tp;++j)if(lst!=b[j]||j==1){
			while(tp2&&lca(sta[tp2],b[j])!=sta[tp2])tp2--;
			if(tp2)fa2[b[j]]=sta[tp2];
			else fa2[b[j]]=0;
			sta[++tp2]=b[j],tg[b[j]]=1,d[lst=b[j]]=++id,b[id]=lst;
		}
		for(int j=1;j<=id;++j){
			e[j]=0;
			for(int k=-blk;k<=blk;++k)
				c[j][k+blk]=0;
			for(int k=fa[b[j]];k&&!tg[k];k=fa[k])
				if(abs(f[k]-ti[k]-1)<=blk&&!vis[k])c[j][f[k]-ti[k]-1+blk]++;
			for(int k=blk-1;k>=-blk;--k)
				c[j][k+blk]+=c[j][k+blk+1];
		}
		for(int j=L;j<=R;++j){
			int x=abs(a[j]),dta=a[j]>0?1:-1;
			for(;x;x=fa2[x]){
				ans-=vis[x]==0&&f[x]>ti[x];
				f[x]+=dta,vis[x]^=x==abs(a[j])?1:0;
				ans+=vis[x]==0&&f[x]>ti[x];
			//	printf("<%d,%d,%d>",x,vis[x],f[x]>ti[x]);
				ans-=c[d[x]][-e[d[x]]+blk];
				e[d[x]]+=dta;
				ans+=c[d[x]][-e[d[x]]+blk];
			}
			printf("%d ",ans);
		}
	}
}