#include<bits/stdc++.h>
const int N=200005,mo=1000000007;
inline void upa(int&a,const int&b){a<b?a=b:0;}
char ibuf[1<<25],*ih=ibuf,obuf[1<<25],*oh=obuf;
inline void read(int&x){
	for(;!isdigit(*ih);++ih);
	for(x=0;isdigit(*ih);x=x*10+*ih++-48);
}
int n,v[N],i,j,x,y,ans;
std::vector<int>e[N];
struct arr{
	int a[70],sz;
	inline void ins(int x){
		for(int i=0;i<sz;++i)a[i+sz]=a[i]*x;
		sz<<=1;
	}
}a[N];
int sz[N],f[N],rt,sum,dfn[N];
int bel[N],p[N],xb,g[N],inv[N],ph[N];
bool b[N],vi[N];
void dfs(int x,int fa){
	f[x]=sz[x]=1;
	for(int i=0;i<e[x].size();++i)if(e[x][i]!=fa && !vi[e[x][i]]){
		dfs(e[x][i],x);sz[x]+=sz[e[x][i]];
		upa(f[x],sz[e[x][i]]);
	}
	upa(f[x],sum-sz[x]);
	if(f[x]<f[rt])rt=x;
}
int de[N];
void getdep(int x,int fa,int dep){
	dfn[++xb]=x;de[x]=dep;
	for(int i=0;i<e[x].size();++i)if(e[x][i]!=fa && !vi[e[x][i]]){
		getdep(e[x][i],x,dep+1);
	}
}
int g1[N],g2[N];
inline int calc(int*g,int v){
	int ans=0,i=0;
	for(;i<a[v].sz;++i)ans=(ans+g[a[v].a[i]])%mo;
	return ans;
}
inline void add(int*gg,int v,int z){
	for(int i=0;i<a[v].sz;++i)gg[a[v].a[i]]=(gg[a[v].a[i]]+1ll*z*g[a[v].a[i]])%mo;
}
inline void cle(int*g,int v){
	for(int i=0;i<a[v].sz;++i)g[a[v].a[i]]=0;
}
void solve(int x){
	vi[x]=1;
	int i,cnt=0,j;xb=0;
	add(g2,bel[v[x]],1ll*v[x]*ph[bel[v[x]]]%mo);
	for(i=0;i<e[x].size();++i)if(!vi[e[x][i]]){
		if(sz[e[x][i]]>x)sz[e[x][i]]=sum-x;
		getdep(e[x][i],x,1);
		for(j=cnt+1;j<=xb;++j){
			int y=dfn[j];
	ans=(ans+1ll*v[y]*ph[bel[v[y]]]%mo*(calc(g1,bel[v[y]])+1ll*de[y]*calc(g2,bel[v[y]])%mo))%mo;
		}
		for(j=cnt+1;j<=xb;++j){
			int y=dfn[j];
			add(g1,bel[v[y]],1ll*v[y]*ph[bel[v[y]]]%mo*de[y]%mo);
			add(g2,bel[v[y]],1ll*v[y]*ph[bel[v[y]]]%mo);
		}
		cnt=xb;
	}
	cle(g2,bel[v[x]]);
	for(i=1;i<=cnt;++i){
		int y=dfn[i];
		cle(g1,bel[v[y]]),cle(g2,bel[v[y]]);
	}
	for(i=0;i<e[x].size();++i)if(!vi[e[x][i]]){
		rt=0;sum=sz[e[x][i]];dfs(e[x][i],0);
		solve(rt);
	}
}
int main(){
	fread(ibuf,1,1<<25,stdin);
	read(n);
	for(i=1;i<=n;++i)read(v[i]);
	for(i=1;i<n;++i){
		read(x),read(y);
		e[x].push_back(y),e[y].push_back(x);
	}
	g[1]=inv[1]=ph[1]=bel[1]=1;
	a[1].a[0]=a[1].sz=1;
	for(i=2;i<=n;++i){
		inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
		if(!b[i]){
			p[++xb]=i,ph[i]=1ll*inv[i]*(i-1)%mo,g[i]=1ll*inv[i-1]*i%mo-1;
			a[i]=a[1];a[i].ins(i);bel[i]=i;
		}
		for(j=1;j<=xb;++j){
			x=i*p[j];if(x>n)break;
			b[x]=1;
			if(i%p[j]==0){
				bel[x]=bel[i];break;
			}
			bel[x]=bel[i]*p[j];a[x]=a[i];a[x].ins(p[j]);
			g[x]=1ll*g[i]*g[p[j]]%mo;ph[x]=1ll*ph[i]*ph[p[j]]%mo;
		}
	}
	f[0]=1<<30;sum=n;dfs(1,0);
	solve(rt);
	if(n&1)ans=1ll*inv[n]*inv[(n-1)>>1]%mo*ans%mo;
		else ans=1ll*inv[n>>1]*inv[n-1]%mo*ans%mo;
	return printf("%d\n",ans),0;
}