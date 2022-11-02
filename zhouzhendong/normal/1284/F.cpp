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
//void ckmax(int &x,int y){
//	if (x<y)
//		x=y;
//}
//void ckmin(int &x,int y){
//	if (x>y)
//		x=y;
//}
const int N=250005;
int n;
vi e[2][N];
namespace S{
	int fa[N];
	void init(){
		For(i,1,n)
			fa[i]=i;
	}
	int getf(int x){
		return fa[x]==x?x:fa[x]=getf(fa[x]);
	}
	void Merge(int x,int y){
		fa[getf(x)]=getf(y);
	}
}
int dep[N];
int fa[N][20];
vector <pii> e0;
void dfs0(int x,int pre){
	for (auto y : e[0][x])
		if (y!=pre)
			dfs0(y,x);
	if (pre)
		e0.pb(mp(x,pre));
}
void dfs1(int x,int pre,int d=0){
	dep[x]=d,fa[x][0]=pre;
	For(i,1,19)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for (auto y : e[1][x])
		if (y!=pre)
			dfs1(y,x,d+1);
}
int LCA(int x,int y){
	if (dep[x]<dep[y])
		swap(x,y);
	Fod(i,19,0)
		if (dep[x]-(1<<i)>=dep[y])
			x=fa[x][i];
	if (x==y)
		return x;
	Fod(i,19,0)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int main(){
	n=read();
	Fod(t,1,0){
		For(i,1,n-1){
			int x=read(),y=read();
			e[t][x].pb(y),e[t][y].pb(x);
		}
	}
	dfs0(1,0);
	dfs1(1,0,0);
	S::init();
	printf("%d\n",n-1);
	for (auto E : e0){
		int x=E.fi,y=E.se,xid=S::getf(x);
		int lca=LCA(x,y);
		int p,q;
		if (S::getf(lca)!=xid){
			p=x;
//			outtag(a);
			Fod(i,19,0)
				if (dep[p]-(1<<i)>dep[lca]&&S::getf(fa[p][i])==xid)
					p=fa[p][i];
			q=fa[p][0];
		}
		else {
			p=y;
//			outtag(b);
			Fod(i,19,0)
				if (dep[p]-(1<<i)>dep[lca]&&S::getf(fa[p][i])!=xid)
					p=fa[p][i];
			q=fa[p][0];
		}
		printf("%d %d %d %d\n",p,q,x,y);
		S::Merge(p,q);
	}
	return 0;
}