#include<bits/stdc++.h>
#define maxn 300100
#define maxm 1001000
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef pair<ll,ll> pii;
typedef vector<pii> owo;
const ldb eps=1e-9;
struct data1{int r,a,b;};
vector<data1>G[maxn],_G[maxn];
int fr[maxn],to[maxn],ai[maxn],bi[maxn];
int vis[maxn],num,rtu,rtv,rta,rtb,mn,n,m,tim,ptr,lst[maxn],dfn[maxn];
void addedge(int u,int v,int a,int b,vector<data1>G[]){
//	printf("[%d->%d(%d,%d)]\n",u,v,a,b);
	G[u].push_back(data1{v,a,b});
	G[v].push_back(data1{u,a,b});
}
pii operator+(pii a,pii b){
	return pii(a.xx+b.xx,a.yy+b.yy);
}
int chk(pii ax,pii ay,pii bx,pii by){
	ldb da=(ay.yy-ax.yy)/(ldb)(ax.xx-ay.xx);
	ldb db=(by.yy-bx.yy)/(ldb)(bx.xx-by.xx);
	return fabs(da-db)<eps?0:(da<db?-1:1);
}
owo oadd(owo a,owo b,ll sa=0,ll sb=0){
	owo ret;
	for(int i=0,j=0;i<a.size()||j<b.size();){
		if(i==a.size()-1&&j==b.size()-1)ret.push_back(a[i++]+b[j++]);
		else if(i==a.size()-1)ret.push_back(a[i]+b[j++]);
		else if(j==b.size()-1)ret.push_back(a[i++]+b[j]);
		else {
			int tg=chk(a[i],a[i+1],b[j],b[j+1]);
			if(tg<0)ret.push_back(a[i++]+b[j]);
			else if(tg>0)ret.push_back(a[i]+b[j++]);
			else  ret.push_back(a[i++]+b[j++]);
		}
	}
	for(auto& c:ret)c.xx+=sa,c.yy+=sb;
	return ret;
}
owo deal(owo ret){
	owo _ret;
	for(auto c:ret){
		if(_ret.size()&&_ret.back().xx==c.xx)continue;
		while(_ret.size()>1&&chk(_ret[_ret.size()-2],_ret.back(),_ret.back(),c)>=0)_ret.pop_back();
		_ret.push_back(c);
	}
	return _ret;
}
owo omerge(owo a,owo b){
	owo ret;
	if(!a.size())return b;
	else if(!b.size())return a;
	for(int i=0,j=0;i<a.size()||j<b.size();){
		if(i==a.size())ret.push_back(b[j++]);
		else if(j==b.size())ret.push_back(a[i++]);
		else if(a[i].xx<b[j].xx)ret.push_back(a[i++]);
		else if(a[i].xx>b[j].xx)ret.push_back(b[j++]);
		else if(a[i].yy>b[j].yy)ret.push_back(a[i++]);
		else ret.push_back(b[j++]);
	}
	return deal(ret);
}
void init(int u,int f){
	num++;
	for(auto v:G[u])if(v.r!=f&&!vis[v.r])
		init(v.r,u);
}
int findrt(int u,int f){
	int sz=1,s=0;
	for(auto v:G[u])if(v.r!=f&&!vis[v.r]){
		s=findrt(v.r,u),sz+=s;
		int mx=max(s,num-s);
		if(mx<mn)mn=mx,rtu=u,rtv=v.r,rta=v.a,rtb=v.b;
	}
	return sz;
}
void dfs(int u,int f,owo& fk,ll ai,ll bi,int flg=1){
	if(flg)fk.push_back(pii(ai,bi));
	for(auto v:G[u])if(v.r!=f&&!vis[v.r])
		dfs(v.r,u,fk,ai+v.a,bi+v.b,v.a||v.b?1:0);
}
int cmp(pii a,pii b){
	return a.xx==b.xx?a.yy>b.yy:a.xx<b.xx;
}
owo all,lef,rig;
void solve(int u){
//	printf("[u=%d]",u);
	mn=1<<30,num=0,rtu=rtv=0;
	init(u,0),findrt(u,0);
	if(num==1)return ;
	lef.clear(),rig.clear();
//	printf("[YES,(%d-%d{%d})]\n",rtu,rtv,num);
	dfs(rtu,rtv,lef,0,0);
	dfs(rtv,rtu,rig,0,0);
	sort(lef.begin(),lef.end(),cmp);
	sort(rig.begin(),rig.end(),cmp);
//	puts("OK");
	lef=oadd(deal(lef),deal(rig),rta,rtb);
	for(auto c:lef)all.push_back(c);
	int ru=rtu,rv=rtv;
	vis[rv]=1,vis[ru]=0,solve(ru);
	vis[ru]=1,vis[rv]=0,solve(rv);
}
int _fa[maxn];
void predfs(int u,int f){
	_fa[u]=f;
	for(auto c:_G[u])if(c.r!=f)
		predfs(c.r,u);
}
int main(){
//	n=1e5,m=0;
	scanf("%d%d",&n,&m);
	ptr=n;
	for(int i=1;i<=n;++i)lst[i]=i;
	for(int i=1;i<=2*n;++i)dfn[i]=i;
	for(int i=2,u,v,a,b;i<=n;++i){
		scanf("%d%d%d%d",&u,&v,&a,&b);
//		u=rand()%(i-1)+1,v=i,a=rand(),b=rand();
		fr[i]=u,to[i]=v,ai[i]=a,bi[i]=b;
		addedge(u,v,a,b,_G);
//		addedge(v,u,a,b,_G);
	}
	predfs(1,0);
	for(int i=1;i<=n;++i){
		int lst=i;
		for(auto c:_G[i])if(c.r!=_fa[i]){
			addedge(lst,++ptr,0,0,G),lst=ptr,
			addedge(ptr,c.r,c.a,c.b,G);
		}
	}
	solve(1);
	sort(all.begin(),all.end(),cmp);
	owo g=deal(all);
	for(int i=0,t=0;i<m;++i){
		auto cal=[&](pii p){
			return (ll)p.xx*i+p.yy;	
		};
		while(t+1<g.size()&&cal(g[t])<cal(g[t+1]))t++;
		printf("%lld ",g.size()?cal(g[t]):0ll);
	}
}