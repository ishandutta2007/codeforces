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
const int M=3e5+10,N=5e6+10,inf=1e9;
#define mid (l+r>>1)
int mx[N],lc[N],rc[N],tot;
void pu(int x){
	mx[x]=max(mx[lc[x]],mx[rc[x]]);
}
void upd(int &x,int l,int r,int p,int v){
	if (!x) x=++tot;
	if (l==r){
		mx[x]=v;
		return ;
	}
	if (p<=mid) upd(lc[x],l,mid,p,v);
	else upd(rc[x],mid+1,r,p,v);
	pu(x);
}
int query(int x,int l,int r,int ll,int rr){
	if (ll>r || rr<l) return 0;
	if (ll<=l && r<=rr) return mx[x];
	return max(query(lc[x],l,mid,ll,rr),query(rc[x],mid+1,r,ll,rr)); 
}
#define lowbit(x) (x&-x)
int d[M],m,n;
void add(int x,int y){
	for (;x;x-=lowbit(x)) d[x]=min(d[x],y);
}
int ask(int x){
	int ret=inf;
	for (;x<=n;x+=lowbit(x)) ret=min(ret,d[x]);
	return ret;
}
int a[M],rt,ans[M],L[M],R[M];
vector<int> va[M],vb[M];
void work(bool rev){
//	cerr<<rev<<" -------------\n";
	F(i,1,tot) mx[i]=0;
	F(i,1,n) d[i]=inf;
	if (rev) reverse(a+1,a+n+1);
	F(i,1,n){
		int ps=i,bd=0;
		while (ps){
			ps=query(rt,0,inf,bd,a[i]);
			if (!ps) break;
			add(ps,a[i]-a[ps]);
			bd=max(a[ps]+(a[i]-a[ps])/2,bd+1);		
			//	cerr<<bd<<" "<<a[i]<<" "<<ps<<" ??\n";

		}
//		cerr<<" !!!!\n";
		upd(rt,0,inf,a[i],i);
		if (rev){
			for (int id:vb[i]){
				ans[id]=min(ans[id],ask(n-R[id]+1));
			}
		}
		else{
			for (int id:va[i]){
				ans[id]=min(ans[id],ask(L[id]));
			}
		}
	}
}
int main(){
	n=read();
	F(i,1,n) a[i]=read();
	m=read();
	F(i,1,m){
		L[i]=read(); R[i]=read();
		va[R[i]].pb(i);
		vb[n-L[i]+1].pb(i);
		ans[i]=inf;
	}
	work(0); work(1);
//	cerr<<m<<" ---------------\n";
	F(i,1,m){
		cout<<ans[i]<<"\n";
	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/