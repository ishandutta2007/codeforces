#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
const ll inf=1ll<<60;
inline void upi(ll&a,const ll&b){a>b?a=b:0;}
char ibuf[1<<25],*ih=ibuf,obuf[1<<25],*oh=obuf;
inline void read(int&x){
	for(;!isdigit(*ih);++ih);
	for(x=0;isdigit(*ih);x=x*10+*ih++-48);
}
inline void out(ll x){
	if(!x){*oh++='0';return;}
	static int buf[30];int xb=0;
	for(;x;x/=10)buf[++xb]=x%10;
	for(;xb;)*oh++=buf[xb--]|48;
}
int n,q,p[N],w[N],i,u,l,r,sz[N],M;
ll dep[N],ans[N],t[N<<2],ad[N<<2];
struct query{int l,r,id;};
vector<query>qu[N];
vector<int>e[N];
inline void maintain(int i){t[i]=min(t[i<<1],t[i<<1|1])+ad[i];}
void mdy(int l,int r,int v){
	for(l+=M-1,r+=M+1;l^r^1;maintain(l>>=1),maintain(r>>=1)){
		if(!(l&1))ad[l^1]+=v,t[l^1]+=v;
		if(r&1)ad[r^1]+=v,t[r^1]+=v;
	}
	for(;l>>=1;maintain(l));
}
ll ask(int l,int r){
	ll sl=inf,sr=inf,ans;
	for(l+=M-1,r+=M+1;l^r^1;sl+=ad[l>>=1],sr+=ad[r>>=1]){
		if(!(l&1))upi(sl,t[l^1]);
		if(r&1)upi(sr,t[r^1]);
	}
	for(ans=min(sl,sr);l>>=1;ans+=ad[l]);
	return ans;
}
void dfs(int u){
	for(query i:qu[u])
		ans[i.id]=ask(i.l,i.r);
	for(int i:e[u]){
		if(i>1)mdy(1,i-1,w[i]);
		if(i+sz[i]<=n)mdy(i+sz[i],n,w[i]);
		mdy(i,i+sz[i]-1,-w[i]);
		dfs(i);
		if(i>1)mdy(1,i-1,-w[i]);
		if(i+sz[i]<=n)mdy(i+sz[i],n,-w[i]);
		mdy(i,i+sz[i]-1,w[i]);
	}
}
int main(){
//	freopen("1","r",stdin);
	cin>>n>>q;for(M=1;M<n+2;M<<=1);
	fread(ibuf,1,1<<25,stdin);
	for(i=2;i<=n;++i)read(p[i]),read(w[i]),dep[i]=dep[p[i]]+w[i],e[p[i]].push_back(i);
	for(i=n;i;--i)sz[p[i]]+=++sz[i];
	for(i=1;i<=n;++i)t[i+M]=sz[i]==1?dep[i]:inf;
	for(i=M-1;i;--i)maintain(i);
	for(i=1;i<=q;++i){
		read(u);read(l);read(r);
		qu[u].push_back((query){l,r,i});
	}
	dfs(1);
	for(i=1;i<=q;++i)out(ans[i]),*oh++='\n';
	fwrite(obuf,1,oh-obuf,stdout);
	return 0;
}