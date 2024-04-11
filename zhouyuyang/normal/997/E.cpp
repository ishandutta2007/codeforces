#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define y1 wzpakking 
#define fi first
#define se second
#define BG begin
#define ED end
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
 
#define INF (1ll<<60)
using namespace std;
const int N=233333;
const int Blk=444;
vi vec[N];
int n,p[N],Q;
int l[N],r[N];
int q1[N],q2[N];
ll x[N],tg[N],cnt[N];
pll mn[N],mt[N],val[N];
pll operator +(pll a,pll b){
	if (!a.se) return b;
	if (!b.se) return a;
	if (a.fi<b.fi) return a;
	if (a.fi>b.fi) return b;
	return pll(a.fi,a.se+b.se);
}
void pushdown(int be){
	if (!tg[be]&&!mt[be].se) return;
	mn[be]=pll(8e18,0);
	for (int j=be*Blk;j<be*Blk+Blk;j++){
		val[j]=val[j]+pll(mt[be].fi+x[j],mt[be].se);
		x[j]+=tg[be]; mn[be]=mn[be]+pll(x[j],1);
	}
	mt[be]=pll(0,0); tg[be]=0;
}
void bf(int be,int l,int r,int v){
	for (int j=max(be*Blk,l);j<be*Blk+Blk&&j<=r;j++) x[j]+=v;
	mn[be]=pll(8e18,0);
	for (int i=be*Blk;i<be*Blk+Blk;i++)
		mn[be]=mn[be]+pll(x[i],1);
}
void chg(int l,int r,int x){
	pushdown(l/Blk);
	bf(l/Blk,l,r,x);
	if (l/Blk!=r/Blk){
		pushdown(r/Blk);
		bf(r/Blk,l,r,x);
	}
	For(i,l/Blk+1,r/Blk-1) tg[i]+=x;
}
void init(){
	For(i,0,n/Blk){
		if (mn[i].fi+tg[i]==-1)
			cnt[i]+=mn[i].se;
		mt[i]=mt[i]+pll(tg[i],1);
	}
}
ll ask(int x){
	int be=x/Blk; ll ans=0;
	pushdown(be);
	for (int i=x;i/Blk==be;i++)
		ans+=(val[i].fi==-1?val[i].se:0);
	For(i,be+1,n/Blk) ans+=cnt[i];
	return ans;
}
ll ans[N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&p[i]);
	scanf("%d",&Q);
	For(i,1,Q){
		scanf("%d%d",&l[i],&r[i]);
		vec[r[i]].PB(i);
	}
	int t1=0,t2=0;
	For(i,1,n){
		for (;t1&&p[q1[t1]]<p[i];t1--)
			chg(q1[t1-1]+1,q1[t1],p[i]-p[q1[t1]]);
		for (;t2&&p[q2[t2]]>p[i];t2--)
			chg(q2[t2-1]+1,q2[t2],p[q2[t2]]-p[i]);
		q1[++t1]=q2[++t2]=i; chg(1,i,-1); init();
		For(j,0,vec[i].size()-1)
			ans[vec[i][j]]=ask(l[vec[i][j]]);
	}
	For(i,1,Q) printf("%lld\n",ans[i]);
}