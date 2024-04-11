#include<bits/stdc++.h>
using namespace std;
inline void upa(int&a,const int&b){
	if(a<b)a=b;
}
inline int Max(const int&a,const int&b){
	return a<b?b:a;
}
const int N=2505;
int f[N][N],g[N][N],h[N][N];
int n,m,i,j,a,b;
struct edge{
	int to,next;
}e[N*10];
int he[N],xb=1;
vector<vector<int> >z[N];
inline void addedge(int x,int y){
	e[++xb]=(edge){y,he[x]};he[x]=xb;
	e[++xb]=(edge){x,he[y]};he[y]=xb;
}
//f->mine,g->others,h->nothing
int st[N],w,dep[N],sz[N];
set<int>cs[N];
bool bb[N];
void dfs(int x,int fe){
	st[++w]=x;sz[x]=1;
	f[x][0]=1;g[x][1]=h[x][0]=0;
	for(int i=he[x];i;i=e[i].next){
		if(i==fe)continue;
		if(!dep[e[i].to]){
			dep[e[i].to]=dep[x]+1;
			dfs(e[i].to,i^1);
			if(!cs[x].count(e[i].to)){
				int j,k,y=e[i].to;
				for(j=sz[x];j>=0;--j)
					for(k=sz[y];k>=0;--k){
						upa(f[x][j+k],f[x][j]+Max(f[y][k],h[y][k]));
						upa(g[x][j+k],g[x][j]+Max(g[y][k],h[y][k]));
						upa(h[x][j+k],h[x][j]+Max(Max(f[y][k],g[y][k]),h[y][k]));
					}
				sz[x]+=sz[y];
			}
		}else if(dep[e[i].to]<dep[x]){
			int j,k;
			for(j=w;st[j]!=e[i].to;--j);
			vector<int>a;a.clear();
			for(k=j;k<=w;++k)a.push_back(st[k]),cs[st[k]].insert(st[k+1]);
			z[e[i].to].push_back(a);
			cs[st[w]].erase(st[w+1]);
		}
	}
	--w;
	for(int l=0;l<z[x].size();++l){
		static int ff[N],gg[N],hh[N],of[N],og[N],oh[N],szi[N],sum[N];
		static int fn[N],gn[N],hn[N];
		int i,j,k,n=z[x][l].size(),y;
		for(i=0;i<n;++i)szi[i+1]=sz[z[x][l][i]],sum[i+1]=sum[i]+szi[i+1];
		memset(ff,240,(sum[n]+1)<<2);
		memset(gg,240,(sum[n]+1)<<2);
		memset(hh,240,(sum[n]+1)<<2);
		memcpy(of,f[x],(sz[x]+1)<<2);
		memcpy(og,g[x],(sz[x]+1)<<2);
		memcpy(oh,h[x],(sz[x]+1)<<2); 
		memcpy(ff,of,(sz[x]+1)<<2);
		memset(gg,240,(sz[x]+1)<<2);
		memset(hh,240,(sz[x]+1)<<2);
		for(i=2;i<=n;++i){
			memset(fn,240,(sum[i]+1)<<2);
			memset(gn,240,(sum[i]+1)<<2);
			memset(hn,240,(sum[i]+1)<<2);
			for(j=sum[i-1],y=z[x][l][i-1];j>=0;--j)
				for(k=szi[i];k>=0;--k){
					upa(fn[j+k],f[y][k]+Max(ff[j],hh[j]));
					upa(gn[j+k],g[y][k]+Max(gg[j],hh[j]));
					upa(hn[j+k],h[y][k]+Max(Max(ff[j],gg[j]),hh[j]));
				}
			memcpy(ff,fn,(sum[i]+1)<<2);
			memcpy(gg,gn,(sum[i]+1)<<2);
			memcpy(hh,hn,(sum[i]+1)<<2);
		}
		for(i=0;i<=sum[n];++i)upa(f[x][i],Max(ff[i],hh[i]));
		memset(ff,240,(sz[x]+1)<<2);
		memcpy(gg,og,(sz[x]+1)<<2);
		memset(hh,240,(sz[x]+1)<<2);
		for(i=2;i<=n;++i){
			memset(fn,240,(sum[i]+1)<<2);
			memset(gn,240,(sum[i]+1)<<2);
			memset(hn,240,(sum[i]+1)<<2);
			for(j=sum[i-1],y=z[x][l][i-1];j>=0;--j)
				for(k=szi[i];k>=0;--k){
					upa(fn[j+k],f[y][k]+Max(ff[j],hh[j]));
					upa(gn[j+k],g[y][k]+Max(gg[j],hh[j]));
					upa(hn[j+k],h[y][k]+Max(Max(ff[j],gg[j]),hh[j]));
				}
			memcpy(ff,fn,(sum[i]+1)<<2);
			memcpy(gg,gn,(sum[i]+1)<<2);
			memcpy(hh,hn,(sum[i]+1)<<2);
		}
		for(i=0;i<=sum[n];++i)upa(g[x][i],Max(gg[i],hh[i]));
		memset(ff,240,(sz[x]+1)<<2);
		memset(gg,240,(sz[x]+1)<<2);
		memcpy(hh,oh,(sz[x]+1)<<2);
		for(i=2;i<=n;++i){
			memset(fn,240,(sum[i]+1)<<2);
			memset(gn,240,(sum[i]+1)<<2);
			memset(hn,240,(sum[i]+1)<<2);
			for(j=sum[i-1],y=z[x][l][i-1];j>=0;--j)
				for(k=szi[i];k>=0;--k){
					upa(fn[j+k],f[y][k]+Max(ff[j],hh[j]));
					upa(gn[j+k],g[y][k]+Max(gg[j],hh[j]));
					upa(hn[j+k],h[y][k]+Max(Max(ff[j],gg[j]),hh[j]));
				}
			memcpy(ff,fn,(sum[i]+1)<<2);
			memcpy(gg,gn,(sum[i]+1)<<2);
			memcpy(hh,hn,(sum[i]+1)<<2);
		}
		for(i=0;i<=sum[n];++i)upa(h[x][i],Max(Max(ff[i],gg[i]),hh[i]));
		sz[x]=sum[n];
	}
}
int main(){
	memset(f,240,sizeof f);memset(g,240,sizeof g);memset(h,240,sizeof h);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(i=1;i<=m;++i){
		cin>>a>>b;
		addedge(a,b);
	}
	dep[1]=1;
	dfs(1,0);
	for(i=0;i<=n;++i)cout<<Max(Max(f[1][i],g[1][i]),h[1][i])<<' ';
	return 0;
}