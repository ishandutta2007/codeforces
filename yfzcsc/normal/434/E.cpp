#include<bits/stdc++.h>
#include<tr1/unordered_map>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define maxn 200100
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
struct edge{
	int r,nxt;
}e[maxn<<1];
gp_hash_table<int,int>st,_st;
//tr1::unordered_map<int,int>st,_st;
int val[maxn],num,k,X,mod,vis[maxn],mn,rt;
int invk,ik[maxn],pk[maxn],head[maxn],esz,in[maxn],A[maxn],sz,out[maxn],n;
int qpow(int a,int b){
	int ans=1,tmp=a;
	for(;b;b>>=1,tmp=1ll*tmp*tmp%mod)
		if(b&1)ans=1ll*ans*tmp%mod;
	return ans;
}
void addedge(int u,int v){
	e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;
	e[++esz].r=u;e[esz].nxt=head[v];head[v]=esz;
}
void init(int u,int f){
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f&&!vis[e[t].r])
		init(e[t].r,u);
	num++;
}
int findrt(int u,int f){
	int sz=1,mxsize=0,s;
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f&&!vis[e[t].r])
		s=findrt(e[t].r,u),sz+=s,mxsize=max(mxsize,s);
//	printf("{%d,%d}",u,sz);
	mxsize=max(mxsize,num-sz);
	if(mxsize<mn)mn=mxsize,rt=u;
	return sz;
}
void cal(int u,int f,int d,int _d,int l){
	d=(d+1ll*pk[l]*val[u])%mod;
	_d=(_d+1ll*ik[l]*val[u])%mod;
	in[u]+=st[d],out[u]+=_st[(1ll*X*ik[l]%mod-_d+mod)%mod];
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f&&!vis[e[t].r])
		cal(e[t].r,u,d,_d,l+1);
}
void join(int u,int f,int d,int _d,int l){
	d=(d+1ll*pk[l]*val[u])%mod;
	_d=(_d+1ll*ik[l]*val[u])%mod;
	_st[d]++,st[(1ll*X*ik[l]%mod-_d+mod)%mod]++;
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f&&!vis[e[t].r])
		join(e[t].r,u,d,_d,l+1);
}
void solve(int u){
	num=0,mn=1<<30,rt=0;
	init(u,0),findrt(u,0);
	vis[u=rt]=1;
	st.clear(),_st.clear();
	st[(X-val[u]+mod)%mod]++,_st[val[u]]++,sz=0;
	for(int t=head[u];t;t=e[t].nxt)if(!vis[e[t].r])
		cal(e[t].r,u,0,0,1),join(e[t].r,u,val[u],val[u],1),A[++sz]=e[t].r;
	st.clear(),_st.clear();
	for(int i=sz;i>=1;--i)cal(A[i],u,val[u],val[u],1),join(A[i],u,0,0,1);
	in[u]+=st[val[u]],out[u]+=_st[(X-val[u]+mod)%mod];
	if(val[u]==X)in[u]++,out[u]++;
	for(int t=head[u];t;t=e[t].nxt)if(!vis[e[t].r])solve(e[t].r);
}
int main(){
	scanf("%d%d%d%d",&n,&mod,&k,&X);
	for(int i=1;i<=n;++i)scanf("%d",&val[i]),val[i]%=mod;
	for(int i=2,u,v;i<=n;++i)scanf("%d%d",&u,&v),addedge(u,v);
	invk=qpow(k,mod-2),pk[0]=ik[0]=1;
	for(int i=1;i<=n;++i)pk[i]=1ll*pk[i-1]*k%mod,ik[i]=1ll*ik[i-1]*invk%mod;
	solve(1);
	ll ans=0;
	for(int i=1;i<=n;++i)
		ans=(ans+2ll*in[i]*(n-in[i])+2ll*out[i]*(n-out[i])+1ll*in[i]*(n-out[i])+1ll*(n-in[i])*out[i]);
//		ans=(ans+1ll*in[i]*(n-in[i])+1ll*out[i]*(n-out[i])-1ll*in[i]*out[i]-1ll*(n-in[i])*(n-out[i]));
	printf("%lld",(1ll*n*n*n-ans/2));
}