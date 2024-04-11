#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
#define all(x) x.begin(),x.end()
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=3e5+10;
struct edge{
	int x,y,w;
	edge(int _=0,int __=0,int ___=0){
		x=_; y=__; w=___; 
	}
}a[M];
int f[M],sz[M],ct;
int Fd(int x){
	if (f[x]==x) return x;
	return Fd(f[x]); 
}
edge s[M]; 
int tp; 
void merge(int u,int v){
	u=Fd(u),v=Fd(v); 
	if (u==v) return ;
	if (sz[u]<sz[v]) swap(u,v); 
	if (sz[u]&1 && sz[v]&1){
		ct-=2;
	}
	sz[u]+=sz[v];
	f[v]=u; 
	s[++tp]=edge(u,v,0);
}
void del(int u,int v){
	sz[u]-=sz[v]; 
	f[v]=v;
	if (sz[u]&1 && sz[v]&1){
		ct+=2;
	}
}
vector<edge> g[M];
int ans[M];
void solve(int l,int r,int ll,int rr){
	if (l>r || ll>rr) return ;
	if (l==r) {
		int old=tp; 
//		cout<<ct<<" "<<l<<" "<<r<<"   sb\n";
		F(i,0,SZ(g[l])){
			if (g[l][i].w>=ll) break;
			merge(g[l][i].x,g[l][i].y);
		}
		F(i,ll,rr) {
			if (a[i].w<=l) merge(a[i].x,a[i].y); 
			if (!ct) ans[i]=l; 
		}
		while (tp>old) del(s[tp].x,s[tp].y),tp--;
		return ;
	}
	int mid=(l+r>>1);
	int old=tp;
	F(i,l,mid){
		F(j,0,SZ(g[i])){
			if (g[i][j].w>=ll) break; 
			merge(g[i][j].x,g[i][j].y);
		}
	}
	int k=ll; 
	F(i,ll,rr){
		if (ct==0) break; 
		if (a[i].w<=mid) merge(a[i].x,a[i].y);
		k=i;
	}
	if (ct) k++; 
	while (tp>old) del(s[tp].x,s[tp].y),tp--;
	F(i,ll,min(k,rr)){
		if (a[i].w<l) merge(a[i].x,a[i].y); 
	}
	solve(l,mid,k,rr);
	while (tp>old) del(s[tp].x,s[tp].y),tp--;
	F(i,l,mid){
		F(j,0,SZ(g[i])){
			if (g[i][j].w>=ll) break; 
			merge(g[i][j].x,g[i][j].y);
		}
	}
	solve(mid+1,r,ll,k-1);
	while (tp>old) del(s[tp].x,s[tp].y),tp--;
}
int n,m,t[M];
int main(){
	n=read(); m=read();
	F(i,1,m){
		int x=read(),y=read(),w=read();
		a[i]=edge(x,y,w);
		t[i]=w; 
	}
	sort(t+1,t+m+1);
	
	int N=unique(t+1,t+m+1)-t-1;
	F(i,1,m){
		int rk=lower_bound(t+1,t+N+1,a[i].w)-t; 
		a[i].w=rk;
		edge tmp=a[i]; tmp.w=i; 
		g[rk].pb(tmp); 
	}
	F(i,1,n) f[i]=i,sz[i]=1; ct=n; 
	solve(1,N,1,m); 
	F(i,1,m) cout<<(ans[i] ? t[ans[i]] : -1)<<"\n";  
	return 0;
}