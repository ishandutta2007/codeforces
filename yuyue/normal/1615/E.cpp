#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=3e5+10;

int n,m;
int f[M];
bool del[M];
vector<int> v[M];
int fr[M],sz[M],dfn[M],tot,dep[M],wn[M];
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	dfn[x]=++tot; sz[x]=1; wn[tot]=x;
	f[x]=fa; 
	for (int y:v[x]){
		if (y==fa) continue;
		dfs(y,x);
		sz[x]+=sz[y];
	}
}
struct SGT{
	#define lc (x<<1)
	#define rc (x<<1|1)
	int tg[M<<2],mx[M<<2],mxp[M<<2];
	#define mid (l+r>>1)
	void pu(int x){
		mx[x]=max(mx[lc],mx[rc]);
		if (mx[x]==mx[lc]) mxp[x]=mxp[lc];
		else mxp[x]=mxp[rc];
	}
	void pd(int x){
		if (tg[x]){
			
			mx[lc]-=tg[x];
			mx[rc]-=tg[x];
			tg[lc]+=tg[x];
			tg[rc]+=tg[x];
			tg[x]=0;
		}
	}
	void build(int x,int l,int r){
		if (l==r){
			mxp[x]=l; mx[x]=dep[wn[l]];
			return ;
		}
		build(lc,l,mid);
		build(rc,mid+1,r);
		pu(x);
	}
	void upd(int x,int l,int r,int ll,int rr){
		if (l>rr || r<ll) return ;
		if (ll<=l && r<=rr){
			tg[x]++;
			mx[x]--;
			return;
		}
		pd(x);
		upd(lc,l,mid,ll,rr); 
		upd(rc,mid+1,r,ll,rr);
		pu(x);
	}
}SGT;
void work(){
	n=read(); m=read();
	F(i,1,n-1){
		int x=read(),y=read();
		v[x].pb(y); v[y].pb(x);
	}
	dfs(1,0);
	SGT.build(1,1,n);
	int num=n;
	LL ans=-1ll*(n-(n/2))*(n/2);
	F(i,1,m){
		int x=wn[SGT.mxp[1]],val=SGT.mx[1];
//		if (!val) break;
		while (x && !del[x]){
			num--;
			SGT.upd(1,1,n,dfn[x],dfn[x]+sz[x]-1);
			del[x]=1;
			val--;
			x=f[x];
		}
		int opt=min(num,(n/2));
		ans=max(ans,1ll*(n-i)*i-1ll*(n-opt)*opt);
//		assert(val==0);
	}
	cout<<ans<<"\n";
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T=1;
	while (T--) work();

	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/