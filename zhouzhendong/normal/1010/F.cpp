#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
//#define pb push_back
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
const int N=1<<19,mod=998244353;
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
namespace fft{
	int w[N],R[N];
	void init(int n){
		int d=0;
		while (1<<d<n)
			d++;
		For(i,0,n-1)
			R[i]=(R[i>>1]>>1)|((i&1)<<(d-1));
		w[0]=1,w[1]=Pow(3,(mod-1)/n);
		For(i,2,n-1)
			w[i]=(LL)w[i-1]*w[1]%mod;
	}
	void FFT(int *a,int n,int flag){
		For(i,0,n-1)
			if (i<R[i])
				swap(a[i],a[R[i]]);
		for (int t=n>>1,d=1;d<n;d<<=1,t>>=1)
			for (int i=0;i<n;i+=d<<1)
				for (int j=0;j<d;j++){
					int tmp=(LL)w[t*j]*a[i+j+d]%mod;
					a[i+j+d]=Del(a[i+j]-tmp);
					Add(a[i+j],tmp);
				}
		if (flag<0){
			reverse(a+1,a+n);
			int inv=Pow(n,mod-2);
			For(i,0,n-1)
				a[i]=(LL)a[i]*inv%mod;
		}
	}
	vi Mul(vi a,vi b){
		int n=1,m=max(0,(int)a.size()+(int)b.size()-1);
		while (n<m)
			n<<=1;
		a.resize(n),b.resize(n);
		init(n);
		FFT(&a[0],n,1),FFT(&b[0],n,1);
		For(i,0,n-1)
			a[i]=(LL)a[i]*b[i]%mod;
		FFT(&a[0],n,-1);
		a.resize(m);
		return a;
	}
}
vi operator + (vi a,vi b){
	int n=max(a.size(),b.size());
	a.resize(n),b.resize(n);
	For(i,0,n-1)
		Add(a[i],b[i]);
	return a;
}
vi operator * (vi a,vi b){
	return fft::Mul(a,b);
}
int n,m;
vector <int> e[N];
int fa[N],sz[N],son[N],dep[N];
void dfs(int x,int pre,int d){
	sz[x]=1,fa[x]=pre,dep[x]=d,son[x]=0;
	for (auto y : e[x])
		if (y!=pre){
			dfs(y,x,d+1);
			sz[x]+=sz[y];
			if (!son[x]||sz[y]>sz[son[x]])
				son[x]=y;
		}
}
vector <vi> Vs;
pair <vi,vi> calc(int L,int R){
	if (L==R)
		return mp(Vs[L],Vs[L]);
	int mid=(L+R)>>1;
	pair <vi,vi> lv=calc(L,mid),rv=calc(mid+1,R);
	return mp(lv.fi*rv.fi,lv.se+lv.fi*rv.se);
}
vi Solve(int x){
	vi id;
	vector <vi> vs;
	while (x){
		id.pb(x);
		vs.pb(vi({0,1}));
		for (auto y : e[x])
			if (y!=fa[x]&&y!=son[x])
				vs.back()=vs.back()*Solve(y);
		x=son[x];
	}
	swap(Vs,vs);
	vi res=calc(0,(int)Vs.size()-1).se;
	Add(res[0],1);
	return res;
}
int main(){
	n=read(),m=read()%mod;
	For(i,1,n-1){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
	}
	dfs(1,0,0);
	vi v=Solve(1);
	int ans=0,val=1;
	For(i,1,n){
		if (i>1)
			val=(LL)val*(m+i-1)%mod*Pow(i-1,mod-2)%mod;
		Add(ans,(LL)val*v[i]%mod);
	}
	cout<<ans<<endl;
	return 0;
}