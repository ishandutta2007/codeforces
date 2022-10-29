#include<bits/stdc++.h>
#define maxn 200100
using namespace std;
typedef long long ll;
struct edge{ll r,nxt,w;}e[maxn<<1];
struct data{ll B,C,tag,ans;}s[maxn<<2];
ll head[maxn],esz,fa[maxn],vis[maxn],isin[maxn];
ll q[maxn],pre[maxn],tp,n,L[maxn],flag;
ll dp[maxn],lsmx,b,c,_L[maxn],mn=1ll<<60;
void addedge(ll u,ll v,ll w){
	e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;e[esz].w=w;
	e[++esz].r=u;e[esz].nxt=head[v];head[v]=esz;e[esz].w=w;
}
void dfs1(ll u){
	vis[u]=1;
	for(ll t=head[u];t;t=e[t].nxt)if(e[t].r!=fa[u]){
		if(vis[e[t].r]){
			if(flag)continue;flag=1;
			for(ll i=u;i!=fa[e[t].r];i=fa[i])
				isin[i]=1,q[++tp]=i,L[tp]=(i==e[t].r?e[t].w:pre[i]);
		} else pre[e[t].r]=e[t].w,fa[e[t].r]=u,dfs1(e[t].r);
	}
}
void dfs2(ll u){
//	printf("[%d]",u);
	ll mx1=0,mx2=0,s;
	for(ll t=head[u];t;t=e[t].nxt)if(e[t].r!=fa[u]&&!isin[e[t].r]){
		fa[e[t].r]=u,dfs2(e[t].r),s=dp[e[t].r]+e[t].w;
		if(mx1<s)mx2=mx1,mx1=s; else if(mx2<s)mx2=s;
	}
	lsmx=max(lsmx,mx1+mx2),dp[u]=mx1;
}
void pd(ll o){
	if(s[o].tag){
		s[o<<1].B-=s[o].tag;
		s[o<<1|1].B-=s[o].tag;
		s[o<<1].C+=s[o].tag;
		s[o<<1|1].C+=s[o].tag;
		s[o<<1].tag+=s[o].tag;
		s[o<<1|1].tag+=s[o].tag;
		s[o].tag=0;
	}
}
void modify(ll o,ll l,ll r,ll ql,ll qr,ll tg){
	if(ql<=l&&r<=qr){
	//	printf(">>>>[%lld,%lld,%d,%d]",s[o].B,s[o].C,l,r);
		s[o].B-=tg,s[o].C+=tg,s[o].tag+=tg;
		return ;
	}
	ll mid=l+r>>1;
	pd(o);
	if(ql<=mid)modify(o<<1,l,mid,ql,qr,tg);
	if(qr>mid)modify(o<<1|1,mid+1,r,ql,qr,tg);
	s[o].B=max(s[o<<1].B,s[o<<1|1].B);
	s[o].C=max(s[o<<1].C,s[o<<1|1].C);
//	printf(">>>[%lld,%lld,%d,%d,%d]\n",s[o].B,s[o].C,l,r,tg);
	s[o].ans=max(max(s[o<<1].ans,s[o<<1|1].ans),max(s[o<<1].B+s[o<<1|1].C,s[o<<1|1].B+s[o<<1].C));
}
void modify2(ll o,ll l,ll r,ll k,ll tg){
	if(l==r){
		s[o].B=dp[q[l]]+tg;
		s[o].C=dp[q[l]]-tg;
		s[o].ans=0;
		return ;
	}
	ll mid=l+r>>1;
	pd(o);
	if(k<=mid)modify2(o<<1,l,mid,k,tg);
	else modify2(o<<1|1,mid+1,r,k,tg);
	s[o].B=max(s[o<<1].B,s[o<<1|1].B);
	s[o].C=max(s[o<<1].C,s[o<<1|1].C);
//	printf("[%lld,%lld,%d,%d]\n",s[o].B,s[o].C,l,r);
	s[o].ans=max(max(s[o<<1].ans,s[o<<1|1].ans),max(s[o<<1].B+s[o<<1|1].C,s[o<<1|1].B+s[o<<1].C));
}
void build(ll o,ll l,ll r){
	if(l==r){
		s[o].B=dp[q[l]]+_L[l];
		s[o].C=dp[q[l]]-_L[l];
		s[o].ans=0;
	//	printf("[%lld,%lld,%d,%d]\n",s[o].B,s[o].C,l,r);
		return ;
	}
	ll mid=l+r>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	s[o].B=max(s[o<<1].B,s[o<<1|1].B);
	s[o].C=max(s[o<<1].C,s[o<<1|1].C);
	s[o].ans=max(max(s[o<<1].ans,s[o<<1|1].ans),max(s[o<<1].B+s[o<<1|1].C,s[o<<1|1].B+s[o<<1].C));
}
int main(){
//	freopen("in.txt","r",stdin);
	scanf("%lld",&n);
	for(ll i=1,u,v,w;i<=n;++i)
		scanf("%lld%lld%lld",&u,&v,&w),
		addedge(u,v,w);
	dfs1(1);
	ll sum=0;
	for(ll i=1;i<=tp;++i)fa[q[i]]=0,dfs2(q[i]),sum+=L[i];//,printf("[L=%lld,%lld]\n",_L[i],dp[q[i]]);
	for(ll i=tp+1;i>=1;--i)L[i]=L[i==1?tp+1:i-1];
	for(ll i=2;i<=tp;++i)_L[i]=_L[i-1]+L[i];
	build(1,1,tp);
	mn=min(mn,max(lsmx,s[1].ans));
//	printf("[%lld]",s[1].ans);
	for(ll i=1;i<tp;++i){
		if(i>1)modify(1,1,tp,1,i-1,L[i+1]);
		if(i<tp)modify(1,1,tp,i+1,tp,L[i+1]);
		modify2(1,1,tp,i,sum-L[i+1]);//printf("[%lld,%lld,%lld]",s[1].ans,L[i+1],sum-L[i+1]);
		mn=min(mn,max(lsmx,s[1].ans));
	}
	printf("%lld",mn);
}