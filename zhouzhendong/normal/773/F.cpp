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
const int N=1<<16;
int n,m,mod;
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
	const double pi=acos(-1.0);
	struct cp{
		double r,i;
		cp(){}
		cp(double _r){
			r=_r,i=0;
		}
		cp(double _r,double _i){
			r=_r,i=_i;
		}
		friend cp operator + (cp a,cp b){
			return cp(a.r+b.r,a.i+b.i);
		}
		friend cp operator - (cp a,cp b){
			return cp(a.r-b.r,a.i-b.i);
		}
		friend cp operator * (cp a,cp b){
			return cp(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);
		}
	}w[N],a0[N],a1[N],b0[N],b1[N],A[N],B[N],C[N];
	int R[N];
	void init(int n){
		int d=0;
		while (1<<d<n)
			d++;
		For(i,0,n-1){
			R[i]=(R[i>>1]>>1)|((i&1)<<(d-1));
			w[i]=cp(cos(pi*2*i/n),sin(pi*2*i/n));
		}
	}
	void FFT(cp *a,int n,int flag){
		For(i,0,n-1)
			if (i<R[i])
				swap(a[i],a[R[i]]);
		for (int t=n>>1,d=1;d<n;d<<=1,t>>=1)
			for (int i=0;i<n;i+=d<<1)
				for (int j=0;j<d;j++){
					cp tmp=w[t*j]*a[i+j+d];
					a[i+j+d]=a[i+j]-tmp;
					a[i+j]=a[i+j]+tmp;
				}
		if (flag<0){
			reverse(a+1,a+n);
			For(i,0,n-1)
				a[i].r/=n,a[i].i/=n;
		}
	}
	vi Mul(vi a,vi b){
		int n=1,m=max(0,(int)a.size()+(int)b.size()-1);
		while (n<m)
			n<<=1;
		a.resize(n),b.resize(n);
		init(n);
		For(i,0,n-1){
			a0[i]=cp(a[i]&255);
			a1[i]=cp(a[i]>>8);
			b0[i]=cp(b[i]&255);
			b1[i]=cp(b[i]>>8);
		}
		FFT(a0,n,1),FFT(a1,n,1),FFT(b0,n,1),FFT(b1,n,1);
		For(i,0,n-1){
			A[i]=a1[i]*b1[i];
			B[i]=a1[i]*b0[i]+a0[i]*b1[i];
			C[i]=a0[i]*b0[i];
		};
		FFT(A,n,-1),FFT(B,n,-1),FFT(C,n,-1);
		For(i,0,n-1)
			a[i]=((LL)(A[i].r+0.5)*65536
				+(LL)(B[i].r+0.5)*256
				+(LL)(C[i].r+0.5))%mod;
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
	a=fft::Mul(a,b);
	if ((int)a.size()>n)
		a.resize(n);
	return a;
}
int main(){
	n=read(),m=read(),mod=read();
	int ans=0;
	vi f(n),g0(n),g1(n);
	f[0]=1;
	int v=0;
	Fod(d,30,1){
		vi ng0,ng1;
		if (v&1)
			ng0=g0+f*g1,ng1=g1+f*g0;
		else
			ng0=g0+f*g0,ng1=g1+f*g1;
		f=f*f,g0=ng0,g1=ng1;
		v<<=1;
		if (m>>d&1){
			g1=g1+f;
			if ((int)f.size()<n)
				f.pb(0);
			Fod(i,(int)f.size()-1,1)
				Add(f[i],f[i-1]);
			v++;
		}
		For(i,0,(int)g1.size()-1)
			if (~i&1)
				Add(ans,g1[i]);
	}
	cout<<ans<<endl;
	return 0;
}