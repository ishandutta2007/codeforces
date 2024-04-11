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
template <class T> void ckmax(T &x,const T &y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,const T &y){
	if (x>y)
		x=y;
}
LL absl(LL x){
	return x<0?-x:x;
}
//int Pow(int x,int y){
//	int ans=1;
//	for (;y;y>>=1,x=(LL)x*x%mod)
//		if (y&1)
//			ans=(LL)ans*x%mod;
//	return ans;
//}
//void Add(int &x,int y){
//	if ((x+=y)>=mod)
//		x-=mod;
//}
//void Del(int &x,int y){
//	if ((x-=y)<0)
//		x+=mod;
//}
//int Add(int x){
//	return x>=mod?x-mod:x;
//}
//int Del(int x){
//	return x<0?x+mod:x;
//}
const int N=500005*2;
int n;
vi e[N];
int ans[N];
pii mx1[N],mx2[N];
void dfs1(int x,int pre){
	for (auto y : e[x])
		if (y!=pre){
			dfs1(y,x);
			pii tmp=mp(mx1[y].fi+1,y);
			if (tmp>mx1[x])
				swap(tmp,mx1[x]);
			if (tmp>mx2[x])
				swap(tmp,mx2[x]);
		}
}
void dfs2(int x,int pre){
	for (auto y : e[x])
		if (y!=pre){
			pii tmp=mp(mx1[x].se!=y?mx1[x].fi+1:mx2[x].fi+1,x);
			if (tmp>mx1[y])
				swap(tmp,mx1[y]);
			if (tmp>mx2[y])
				swap(tmp,mx2[y]);
			dfs2(y,x);
		}
}
void solver1(int x){
	vi len;
	for (auto y : e[x])
		len.pb((mx1[y].se!=x?mx1[y].fi:mx2[y].fi)+1);
	sort(len.begin(),len.end(),greater <int>());
	int las=-2,cnt=0;
	for (auto i : len){
		cnt++;
		ckmax(ans[i*2],cnt);
		ckmax(ans[i*2-1],cnt);
		if (las>i)
			ckmax(ans[i*2+1],cnt);
		las=i;
	}
}
int Size,RT;
int sz[N],mxs[N],vis[N];
void getrt(int x,int pre){
	sz[x]=1,mxs[x]=0;
	for (auto y : e[x])
		if (!vis[y]&&y!=pre){
			getrt(y,x);
			sz[x]+=sz[y];
			ckmax(mxs[x],sz[y]);
		}
	ckmax(mxs[x],Size-sz[x]);
	if (!RT||mxs[x]<mxs[RT])
		RT=x;
}
int cnt[N];
void solve(int x,int SZ){
	Size=SZ,RT=0;
	getrt(x,0);
	x=RT;
	vector <pii> val;
	cnt[x]=0;
	for (auto y : e[x]){
		val.pb(mp(mx1[y].se!=x?mx1[y].fi+1:mx2[y].fi+1,x));
		if (!vis[y]){
			cnt[y]=0;
			for (auto z : e[y])
				val.pb(mp(mx1[z].se!=y?mx1[z].fi+1:mx2[z].fi+1,y));
		}
	}
	sort(val.begin(),val.end(),greater <pii>());
	int mx=-1;
	for (auto p : val){
		cnt[p.se]++;
		if (p.se!=x)
			ckmax(mx,cnt[p.se]);
		if (mx>0&&cnt[x]>0)
			ckmax(ans[p.fi*2],cnt[x]+mx-2);
	}
	vis[x]=1;
	for (auto y : e[x])
		if (!vis[y])
			solve(y,sz[y]<sz[x]?sz[y]:SZ-sz[x]);
}
int main(){
	n=read();
	For(i,1,n-1){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
	}
	For(i,1,n){
		ckmax(ans[i],1);
		ckmax(ans[1],(int)e[i].size()+1);
	}
	dfs1(1,0);
	dfs2(1,0);
	For(x,1,n)
		solver1(x);
	solve(1,n);
	Fod(i,n-2,1)
		ckmax(ans[i],ans[i+2]);
	For(i,1,n)
		printf("%d ",ans[i]);
	puts("");
	return 0;
}