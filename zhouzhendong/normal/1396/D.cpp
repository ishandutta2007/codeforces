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
typedef unsigned long long ull;
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
template <class T> void ckmax(T &x,const T y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,const T y){
	if (x>y)
		x=y;
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
int md(LL x){
	return (x%mod+mod)%mod;
}
const int N=2005,INF=1.05e9;
int n,k,L;
vi hx,hy;
int hsx,hsy;
struct P{
	int x,y,c;
}a[N];
int gid(vi &h,int v){
	return lower_bound(h.begin(),h.end(),v)-h.begin();
}
namespace seg{
	const int S=N*4;
	int mi[S],mx[S],c[S],s[S];
	int cov[S];
	void pushup(int rt){
		int ls=rt<<1,rs=ls|1;
		mi[rt]=min(mi[ls],mi[rs]);
		mx[rt]=max(mx[ls],mx[rs]);
		s[rt]=Add(s[ls]+s[rs]);
	}
	void pushdown(int rt){
		if (cov[rt]!=-1){
			int ls=rt<<1,rs=ls|1;
			cov[ls]=cov[rs]=cov[rt];
			mi[ls]=mi[rs]=mx[ls]=mx[rs]=cov[rt];
			s[ls]=(LL)mi[ls]*c[ls]%mod;
			s[rs]=(LL)mi[rs]*c[rs]%mod;
			cov[rt]=-1;
		}
	}
	void build(int rt,int L,int R,int *h){
		cov[rt]=-1;
		if (L==R){
			mi[rt]=mx[rt]=hy[h[L]];
			c[rt]=hy[L+1]-hy[L];
			s[rt]=(LL)c[rt]*mi[rt]%mod;
			return;
		}
		int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
		build(ls,L,mid,h);
		build(rs,mid+1,R,h);
		pushup(rt);
		c[rt]=Add(c[ls]+c[rs]);
	}
	void update(int rt,int L,int R,int xL,int xR,int v){
		if (xL>xR||R<xL||L>xR)
			return;
		int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
		if (L<R)
			pushdown(rt);
		if (xL<=L&&R<=xR){
			if (mx[rt]<=v)
				return;
			if (mi[rt]>=v){
				cov[rt]=mx[rt]=mi[rt]=v;
				s[rt]=(LL)c[rt]*v%mod;
				return;
			}
			update(ls,L,mid,xL,xR,v);
			update(rs,mid+1,R,xL,xR,v);
		}
		else {
			update(ls,L,mid,xL,xR,v);
			update(rs,mid+1,R,xL,xR,v);
		}
		pushup(rt);
	}
	int query(){
		return s[1];
	}
}
vi vx[N],vy[N],vc[N];
int pre[N],nxt[N];
int h[N];
int main(){
	n=read(),k=read(),L=read();
	hx=hy={0,L+1};
	For(i,1,n){
		a[i].x=read()+1,a[i].y=read()+1,a[i].c=read();
		hx.pb(a[i].x);
		hy.pb(a[i].y);
	}
	sort(hx.begin(),hx.end());
	sort(hy.begin(),hy.end());
	hx.resize(unique(hx.begin(),hx.end())-hx.begin());
	hy.resize(unique(hy.begin(),hy.end())-hy.begin());
	hsx=(int)hx.size()-2;
	hsy=(int)hy.size()-2;
//	outarr(hx,1,hsx);
//	outarr(hy,1,hsy);
	For(i,1,n){
		a[i].x=gid(hx,a[i].x);
		a[i].y=gid(hy,a[i].y);
		vx[a[i].x].pb(i);
		vy[a[i].y].pb(i);
	}
	a[0]={0,0,0};
	a[n+1]={0,L+1,0};
	int ans=0;
	For(u,1,hsx){
		For(i,1,k)
			vc[i].clear();
		For(i,1,n)
			if (a[i].x>=u)
				vc[a[i].c].pb(i);
		h[hsy]=hsy;
		For(i,1,k){
			sort(vc[i].begin(),vc[i].end(),[&](int x,int y){
				return a[x].y<a[y].y;
			});
			int las=0;
			for (auto j : vc[i])
				pre[j]=las,nxt[las]=j,las=j;
			nxt[las]=n+1;
			ckmin(h[hsy],a[las].y);
		}
		nxt[0]=0;
		Fod(i,hsy,2){
			h[i-1]=h[i];
			for (auto j : vy[i])
				if (a[j].x>=u)
					ckmin(h[i-1],a[pre[j]].y);
		}
//		outval(u);outarr(h,1,hsy);
		seg::build(1,1,hsy,h);
		Fod(i,hsx,1){
			Add(ans,(LL)seg::query()*(hx[i+1]-hx[i])%mod*(hx[u]-hx[u-1])%mod);
//			outv(u),outv(i),outval(ans);
			for (auto j : vx[i]){
				seg::update(1,1,hsy,a[j].y,a[nxt[j]].y-1,hy[a[pre[j]].y]);
				nxt[pre[j]]=nxt[j];
				pre[nxt[j]]=pre[j];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}