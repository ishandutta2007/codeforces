#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
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
const int N=50005;
int n,q;
vector <int> e[N];
int a[N],dep[N],fa[N],fa_base[N];
int v[N][256];
int base=256;
void ckmax(int &a,int b){
	if (a<b)
		a=b;
}
void dfs(int x,int pre,int d){
	dep[x]=d,fa[x]=pre;
	for (auto y : e[x])
		if (y!=pre)
			dfs(y,x,d+1);
	if (d>=base-1){
		int *f=v[x];
		For(i,0,base-1)
			f[i]=-1;
		int i;
		for (i=x;dep[i]>d-base;i=fa[i]){
			int v=a[i]^(d-dep[i]);
			ckmax(f[v>>8],v&(base-1));
		}
		fa_base[x]=i;
		For(i,0,7)
			For(j,0,base-1)
				if (j>>i&1){
					int a=f[j],b=f[j^1<<i];
					if (b!=-1)
						ckmax(f[j],b+(base<<i));
					if (a!=-1)
						ckmax(f[j^1<<i],a+(base<<i));
				}
	}
}
int main(){
	n=read(),q=read();
	For(i,1,n)
		a[i]=read();
	For(j,1,n-1){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
	}
	dep[0]=-1;
	dfs(1,0,0);
	while (q--){
		int x=read(),y=read(),i;
		int ans=0;
		for (i=y;dep[i]-base+1>=dep[x];i=fa_base[i])
			ckmax(ans,v[i][(dep[y]-dep[i])>>8]);
		while (dep[i]>=dep[x])
			ckmax(ans,a[i]^(dep[y]-dep[i])),i=fa[i];
		printf("%d\n",ans);
	}
	return 0;
}