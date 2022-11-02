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
int n;
int a[N];
int sqr(int x){
	return (LL)x*x%mod;
}
void R(vi &a){
	a.resize(n+1);
}
int main(){
	n=read();
	a[0]=1,a[2]=1;
	For(i,4,n)
		a[i]=Add(a[i-2]+a[i-4]);
	int ans=0;
	Add(ans,(LL)(a[n-1]+a[n-3])*sqr(n-1)%mod*n%mod);
	vi f(n+10),g(n+10),h(n+10);
	For(i,0,n){
		f[i+1]=(LL)a[i]*sqr(i+0)%mod;
		g[i+2]=(LL)a[i]*sqr(i+1)%mod;
		h[i+3]=(LL)a[i]*sqr(i+2)%mod;
	}
	R(f),R(g),R(h);
	vi sf=f,sg=g,sh=h,F=f,G=g,H=h;
	For(_,1,16){
		vi sf2=sf+sg*g+sf*f;
		vi sg2=sg+sg*h+sf*g;
		vi sh2=sh+sg*g+sh*h;
		vi f2=f*f+g*g;
		vi g2=f*g+h*g;
		vi h2=h*h+g*g;
		swap(sf,sf2),swap(sg,sg2),swap(sh,sh2);
		swap(f,f2),swap(g,g2),swap(h,h2);
		R(f),R(g),R(h),R(sf),R(sg),R(sh);
	}
	For(i,0,n){
		Add(ans,(LL)F[i]*sf[n-i]%mod*i%mod);
		Add(ans,(LL)G[i]*sg[n-i]%mod*i%mod);
		Add(ans,(LL)G[i]*sg[n-i]%mod*i%mod);
		Add(ans,(LL)H[i]*sh[n-i]%mod*i%mod);
	}
	cout<<ans<<endl;
	return 0;
}