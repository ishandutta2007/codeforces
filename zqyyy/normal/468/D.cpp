#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define max(x,y) ((x)>(y)?(x):(y))
#define pii pair<int,int>
#define fi first
#define se second
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1e5+5;
struct Edge{
	int to,nxt,dat;
}e[N<<1];
int cnt,head[N];
inline void add_e(int from,int to,int dat){
	e[++cnt].to=to,e[cnt].nxt=head[from];
	e[cnt].dat=dat,head[from]=cnt;
}
int n,zx,zxsz;
int sz[N],bel[N],sum[N];
ll ans=0;
set<int>in[N],mn;
set<pii>s;
void dfs1(int x,int fa){
	sz[x]=1;int mxsz=0;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y==fa)continue;
		dfs1(y,x);sz[x]+=sz[y];
		mxsz=max(mxsz,sz[y]);
	}
	mxsz=max(mxsz,n-sz[x]);
	if(mxsz<zxsz)zx=x,zxsz=mxsz;
}
void dfs2(int x,int fa,ll dep){
	ans+=(dep<<1);
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y^fa)dfs2(y,x,dep+e[i].dat);
	}
}
void dfs(int x,int fa,int rt){
	bel[x]=rt;in[rt].insert(x);
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y^fa)dfs(y,x,rt);
	}
}
inline int solve(int x){
	int ans=0;auto res=*s.rbegin();
	if(res.fi==n-x+1 && res.se!=bel[x])ans=*in[res.se].begin();
	else{
		if(bel[*mn.begin()]==bel[x] && x!=zx)ans=*next(mn.begin());
		else ans=*mn.begin();
	}
	int p=bel[x],q=bel[ans];
	mn.erase(ans);
	if(p)s.erase(pii(sum[p],p)),s.insert(pii(--sum[p],p));
	if(q){
		in[q].erase(ans);if(!in[q].empty())mn.insert(*in[q].begin());
		s.erase(pii(sum[q],q)),s.insert(pii(--sum[q],q));
	}
	return ans;
}
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read(),dat=read();
		add_e(x,y,dat),add_e(y,x,dat);
	}
	zxsz=1e9;dfs1(1,0);dfs2(zx,0,0);
	printf("%lld\n",ans);
	if(n==1)puts("1"),exit(0);
	mn.insert(zx);
	for(int i=head[zx];i;i=e[i].nxt){
		int x=e[i].to;
		dfs(x,zx,x);mn.insert(*in[x].begin());
		s.insert(pii(sum[x]=(in[x].size()<<1),x));
	}
	for(int i=1;i<=n;i++)printf("%d ",solve(i));
	return 0;
}