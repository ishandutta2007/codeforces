#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=3e5+10;
int n;
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
int tg[M<<3];
void build(int x,int l,int r){
	tg[x]=-1;
	if (l==r){
		
		return ;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
}
void pd(int x){
	if (tg[x]!=-1){
		tg[lc]=tg[rc]=tg[x];
		tg[x]=-1;
	}
}
void upd(int x,int l,int r,int ll,int rr,int d){
	if (l==ll && r==rr){
		tg[x]=d;
		return ;
	}
	pd(x);
	if (rr<=mid) upd(lc,l,mid,ll,rr,d);
	else if (ll>mid) upd(rc,mid+1,r,ll,rr,d);
	else upd(lc,l,mid,ll,mid,d),upd(rc,mid+1,r,mid+1,rr,d);
}
int qry(int x,int l,int r,int p){
	if (l==r) return tg[x];
	pd(x);
	if (p<=mid) return qry(lc,l,mid,p);
	return qry(rc,mid+1,r,p);
}
int sz[M];
int yjy,dfn[M],wn[M];
vector<int>  va[M],vb[M];
void dfs(int x,int fa){
	sz[x]=1;
	dfn[x]=++yjy; wn[yjy]=x;
	for (int y :vb[x]){
		if (y^fa){
			dfs(y,x);
			sz[x]+=sz[y];
		}
	}
}
int dp[M],ans;
void dfs1(int x,int fa){
	dp[x]=dp[fa];
	int tmp=qry(1,1,n,dfn[x]);
//	cout<<x<<" "<<tmp<<" "<<sz[x]<<"  dfs\n";
	if (tmp<=0){
		upd(1,1,n,dfn[x],dfn[x]+sz[x]-1,x);
		dp[x]++;
	}
	else{
//		cerr<<tmp<<" "<<x<<"\n"; 
		upd(1,1,n,dfn[tmp],dfn[tmp]+sz[tmp]-1,0);
		upd(1,1,n,dfn[x],dfn[x]+sz[x]-1,x);
	}
	ans=max(ans,dp[x]);
	for (int y:va[x]){
		if (y^fa){
			dfs1(y,x);
		}
	}
	if (tmp<=0){
		upd(1,1,n,dfn[x],dfn[x]+sz[x]-1,0);
	}
	else{
		upd(1,1,n,dfn[tmp],dfn[tmp]+sz[tmp]-1,tmp);
	}
}
void work(){
	n=read();
	F(i,2,n){
		int x=read();
		va[x].pb(i);
	} 
	F(i,2,n){
		int x=read();
		vb[x].pb(i);
	}
	build(1,1,n);
	yjy=0;
	dfs(1,0);
	ans=0;
	dfs1(1,0);
	cout<<ans<<"\n";
	F(i,1,n) va[i].clear(),vb[i].clear();
}
int main(){
	int T=read();
	while (T--) work();
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
1
7
1 1 3 4 4 5
1 2 1 4 2 5

1
5
1 2 3 3
1 1 1 2
*/