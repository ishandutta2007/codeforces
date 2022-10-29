#include<bits/stdc++.h>
#define maxn 301000
using namespace std;
typedef long long ll;
typedef pair<ll,int> par;
const ll inf=1ll<<60;
const int _inf=1<<30;
//pi=suffi-costi=suf[i]
//mxs=max suffi
//val -> his brother *=min (maxsuff + pi)
//atg=add tag
struct WXHAKIOI{
	ll mxs,val,mnp,mxc,atg;
}s[maxn<<2];
struct edge{int r,nxt;}e[maxn];
ll pre[maxn],suf[maxn],g[maxn],w[maxn];
int fa[maxn],A,K,head[maxn],ret,tp,sta[maxn],esz,n,ans;
void addedge(int u,int v){
	e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;
}
void pd(int o){
	int ls=o<<1,rs=o<<1|1;
	if(!s[o].atg)return ;
	s[ls].atg+=s[o].atg,s[ls].mxs+=s[o].atg;
	s[ls].val+=s[o].atg,s[ls].mxc+=s[o].atg;
	s[rs].atg+=s[o].atg,s[rs].mxs+=s[o].atg;
	s[rs].val+=s[o].atg,s[rs].mxc+=s[o].atg;
	s[o].atg=0;
}
ll qmax(int o,int l,int r,int ql,int qr){
	if(ql>r||qr<l)return -inf;
	if(ql<=l&&r<=qr)return s[o].mxs;
	int mid=l+r>>1;
	pd(o);
	if(qr<=mid)return qmax(o<<1,l,mid,ql,qr);
	else if(ql>mid)return qmax(o<<1|1,mid+1,r,ql,qr);
	else return max(qmax(o<<1,l,mid,ql,qr),qmax(o<<1|1,mid+1,r,ql,qr));
}
ll qval(int o,int l,int r,ll mx){
	if(l==r)return s[o].mnp+mx;
	if(s[o].mxs<=mx)return s[o].mnp+mx;
	int mid=l+r>>1,ls=o<<1,rs=o<<1|1;
	pd(o);
	if(s[ls].mxs>=mx)return min(qval(ls,l,mid,mx),s[rs].val);
	else return min(mx+s[ls].mnp,qval(rs,mid+1,r,mx));
}
void upd(int o,int l,int r){
	int mid=l+r>>1;
	s[o].mxs=max(s[o<<1].mxs,s[o<<1|1].mxs);
	s[o].mxc=min(s[o<<1].mxc,s[o<<1|1].mxc);
	s[o<<1|1].val=qval(o<<1|1,mid+1,r,s[o<<1].mxs);
}
void mdy(int o,int l,int r,int ql,int qr,ll t){
	if(ql<=l&&r<=qr){
		s[o].mxc+=t,s[o].atg+=t;
		s[o].val+=t,s[o].mxs+=t;
		return ;
	}
	int mid=l+r>>1;
	pd(o);
	if(ql<=mid)mdy(o<<1,l,mid,ql,qr,t);
	if(qr>mid)mdy(o<<1|1,mid+1,r,ql,qr,t);
	upd(o,l,r);
}
void qry(int o,int l,int r,int ql,int qr,ll mx){
	if(ql>qr)return ;
	if(r-A+1<=ans)return ;
	if(ql<=l&&r<=qr){
		ll x=qval(o,l,r,mx);
		if(x>K)return ;
		ret=max(ret,l);
		if(l==r)return ;
	}
	int mid=l+r>>1;
	pd(o);
	if(qr>mid)qry(o<<1|1,mid+1,r,ql,qr,max(mx,qmax(o<<1,l,mid,ql,qr)));
	if(ql<=mid&&ret<=mid)qry(o<<1,l,mid,ql,qr,mx);
}
void build(int o,int l,int r){
	if(l==r){
		s[o].mnp=-suf[l];
		s[o].mxs=suf[l];
		return ;
	}
	int mid=l+r>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	s[o].mnp=min(s[o<<1].mnp,s[o<<1|1].mnp);
	upd(o,l,r);
}
int find(int o,int l,int r){
	if(l==r)return l+1;
	int mid=l+r>>1;
	pd(o);
	if(s[o<<1|1].mxc<=K)return find(o<<1|1,mid+1,r);
	else return find(o<<1,l,mid);
}
void dfs(int u){
	if(fa[u])mdy(1,1,n,fa[u]-1,n,pre[u-1]-pre[fa[u]-1]);
	ret=u;
	A=u;
	int d=find(1,1,n);
	qry(1,1,n,u,d,-inf);
	ans=max(ans,ret-u+1);
	for(int t=head[u];t;t=e[t].nxt)dfs(e[t].r);
	if(fa[u])mdy(1,1,n,fa[u]-1,n,-pre[u-1]+pre[fa[u]-1]);
}
int main(){
	ans=1;
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n-1;++i)scanf("%d",&w[i]);
	for(int i=1;i<=n;++i)scanf("%d",&g[i]);
	for(int i=1;i<=n;++i)pre[i]=pre[i-1]+g[i]-w[i],suf[i]=suf[i-1]+g[i]-w[i-1];
	for(int i=n-1;i>=1;--i){
		while(tp&&pre[sta[tp]]>=pre[i-1])tp--;
		if(g[i]<w[i])fa[i]=i+1;
		else if(!tp)fa[i]=0;
		else fa[i]=sta[tp]+1>n?0:sta[tp]+1;
		sta[++tp]=i;
		if(fa[i])addedge(fa[i],i);
	}
	build(1,1,n);
	for(int i=1;i<=n;++i)if(!fa[i])dfs(i);
	printf("%d",ans);
}