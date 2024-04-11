#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define kill _z_kill
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
#define User_Time ((double)clock()/CLOCKS_PER_SEC)
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
typedef pair <int,int> pii;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int mod=1e9+7;
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=(LL)x*x%mod)
		if (y&1)
			ans=(LL)ans*x%mod;
	return ans;
}
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
void Del(int &x,int y){
	if ((x-=y)<0)
		x+=mod;
}
int Add(int x){
	return x>=mod?x-mod:x;
}
int Del(int x){
	return x<0?x+mod:x;
}
const int N=1.1e6;
int n,m=1<<20;
pii a[N];
int fa[N];
int vis[N],cnt[N];
int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
int check(int k){
	clr(vis),clr(cnt);
	For(i,0,m-1)
		fa[i]=i;
	For(i,1,n){
		int x=a[i].fi&((1<<k)-1);
		int y=a[i].se&((1<<k)-1);
		vis[x]=vis[y]=1;
		cnt[x]^=1,cnt[y]^=1;
		fa[getf(x)]=getf(y);
	}
	int p=-1;
	For(i,0,m-1){
		if (!vis[i])
			continue;
		if (cnt[i])
			return 0;
		if (p==-1)
			p=getf(i);
		else if (p!=getf(i))
			return 0;
	}
	return 1;
}
vector <pii> e[N];
vi fk;
int vise[N];
void gao(int x){
//	outval(x);
//	for (auto i : e[x])
//		printf("(%d,%d)\n",i.fi,i.se);
	while (!e[x].empty()){
		while (!e[x].empty()&&vise[abs(e[x].back().se)]){
//			outval(e[x].back().se);
			e[x].pop_back();
		}
		if (e[x].empty())
			return;
		pii p=e[x].back();
//		outval(p.fi),outval(p.se);
		e[x].pop_back();
		vise[abs(p.se)]=1;
		gao(p.fi);
		fk.pb(p.se);
	}
}
int main(){
	n=read();
	For(i,1,n)
		a[i].fi=read(),a[i].se=read();
	int L=0,R=20,ans=0;
	while (L<=R){
		int mid=(L+R)>>1;
		if (check(mid))
			L=mid+1,ans=mid;
		else
			R=mid-1;
	}
	clr(vis);
	For(i,1,n){
		int x=a[i].fi&((1<<ans)-1);
		int y=a[i].se&((1<<ans)-1);
		vis[x]=vis[y]=1;
		e[x].pb(mp(y,-i));
		e[y].pb(mp(x,i));
//		printf("e[%d].pb(%d,%d)\n",x,y,-i);
//		printf("e[%d].pb(%d,%d)\n",y,x,i);
	}
//	for (auto i : e[1])
//		printf("(%d,%d)\n",i.fi,i.se);
	For(i,0,m-1)
		if (vis[i]){
			gao(i);
			break;
		}
	cout<<ans<<endl;
	vi v;
//	outarr(fk,0,(int)fk.size()-1);
	for (auto i : fk){
		int x=2*abs(i)-1,y=x+1;
		if (i<0)
			swap(x,y);
		v.pb(x),v.pb(y);
		printf("%d %d ",x,y);
	}
	puts("");
//	For(i,0,(int)v.size()-1)
//		if (v[i]&1)
//			v[i]=a[(v[i]+1)/2].fi;
//		else
//			v[i]=a[v[i]/2].se;
//	outarr(v,0,(int)v.size()-1);
//	For(i,0,(int)v.size()-1)
//		if (i&1){
//			outval(i);
//			outval(((v[i]^v[(i+1)%(int)v.size()])&((1<<ans)-1)));
//			assert(!((v[i]^v[(i+1)%(int)v.size()])&((1<<ans)-1)));
//		}
	return 0;
}