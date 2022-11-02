#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define clrint(x,n) memset(x,0,(n)<<2)
#define cpyint(a,b,n) memcpy(a,b,(n)<<2)
#define For(i,a,b) for (int i=a;i<=b;i++)
#define Fod(i,b,a) for (int i=b;i>=a;i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define real __zzd001
#define _SEED_ ('C'+'L'+'Y'+'A'+'K'+'I'+'O'+'I')
#define outval(x) printf(#x" = %d\n",x)
#define outvec(x) printf("vec "#x" = ");for (auto _v : x)printf("%d ",_v);puts("")
#define outtag(x) puts("----------"#x"----------")
#define outarr(a,L,R) printf(#a"[%d...%d] = ",L,R);\
						For(_v2,L,R)printf("%d ",a[_v2]);puts("");
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> vi;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=1<<19,mod=998244353,inv2=(mod+1)>>1;
const int YG=3;
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
namespace Math{
	int Iv[N];
	void prework(){
		int n=N-1;
		Iv[1]=1;
		For(i,2,n)
			Iv[i]=(LL)(mod-mod/i)*Iv[mod%i]%mod;
	}
	map <int,int> Map;
	int ind(int x){
		static int M,bas;
		if (Map.empty()){
			M=max((int)sqrt(mod),1);
			bas=Pow(YG,M);
			for (int i=1,v=YG;i<=M;i++,v=(LL)v*YG%mod)
				Map[v]=i;
		}
		for (int i=M,v=(LL)bas*Pow(x,mod-2)%mod;i<=mod-1+M;i+=M,v=(LL)v*bas%mod)
			if (Map[v])
				return i-Map[v];
		return -1;
	}
}
namespace fft{
	int w[N],R[N];
	int Log[N+1];
	void init(int n){
		if (!Log[2]){
			For(i,2,N)
				Log[i]=Log[i>>1]+1;
		}
		int d=Log[n];
		assert(n==(1<<d));
		For(i,0,n-1)
			R[i]=(R[i>>1]>>1)|((i&1)<<(d-1));
		w[0]=1,w[1]=Pow(YG,(mod-1)/n);
		For(i,2,n-1)
			w[i]=(LL)w[i-1]*w[1]%mod;
	}
	void FFT(int *a,int n,int flag){
		if (flag<0)
			reverse(w+1,w+n);
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
			reverse(w+1,w+n);
			int inv=Pow(n,mod-2);
			For(i,0,n-1)
				a[i]=(LL)a[i]*inv%mod;
		}
	}
	void CirMul(int *a,int *b,int *c,int n){
		init(n),FFT(a,n,1),FFT(b,n,1);
		For(i,0,n-1)
			c[i]=(LL)a[i]*b[i]%mod;
		FFT(c,n,-1);
	}
}
using fft::FFT;
using fft::CirMul;
int calc_up(int x){
	int n=1;
	while (n<=x)
		n<<=1;
	return n;
}
void Inv(int *a,int *b,int n){
	static int f[N],g[N];
	b[0]=Pow(a[0],mod-2);
	int now=1;
	while (now<n){
		int len=now<<2;
		For(i,0,len-1)
			f[i]=g[i]=0;
		cpyint(g,b,now),now<<=1,cpyint(f,a,min(n,now));
		fft::init(len);
		FFT(f,len,1),FFT(g,len,1);
		For(i,0,len-1)
			g[i]=(2LL*g[i]-(LL)f[i]*g[i]%mod*g[i]%mod+mod)%mod;
		FFT(g,len,-1);
		cpyint(b,g,min(n,now));
	}
}
int Sqrt(int a){
	int k=Math::ind(a);
	assert(~k&1);
	k=Pow(YG,k>>1);
	return min(k,mod-k);
}
void Sqrt(int *a,int *b,int n){
	static int f[N],g[N],h[N];
	b[0]=Sqrt(a[0]);
	int now=1;
	while (now<n){
		int len=now<<2;
		For(i,0,len-1)
			f[i]=g[i]=h[i]=0;
		cpyint(f,b,now),now<<=1,Inv(f,h,now),cpyint(g,a,min(n,now));
		CirMul(g,h,g,len);
		For(i,0,len-1)
			f[i]=((g[i]+f[i])&1)?Add(((LL)g[i]+f[i]+mod)>>1):((g[i]+f[i])>>1);
		cpyint(b,f,min(n,now));
	}
}
void Der(int *a,int n){
	For(i,0,n-2)
		a[i]=(LL)a[i+1]*(i+1)%mod;
	a[n-1]=0;
}
void Int(int *a,int n){
	if (!Math::Iv[1])
		Math::prework();
	Fod(i,n,1)
		a[i]=(LL)a[i-1]*Math::Iv[i]%mod;
	a[0]=0;
}
void Ln(int *a,int *b,int n){
	static int f[N],g[N];
	int len=calc_up(n*2);
	For(i,0,len-1)
		f[i]=g[i]=0;
	cpyint(f,a,n),Inv(f,g,n),Der(f,n);
	CirMul(f,g,f,len);
	Int(f,n),cpyint(b,f,n);
}
void Exp(int *a,int *b,int n){
	static int f[N],g[N],h[N];
	b[0]=1;
	int now=1;
	while (now<n){
		int len=now<<2;
		For(i,0,len-1)
			f[i]=g[i]=h[i]=0;
		cpyint(f,b,now),now<<=1,Ln(f,g,now),cpyint(h,a,min(n,now));
		For(i,0,now-1)
			g[i]=Del(h[i]-g[i]);
		Add(g[0],1);
		CirMul(f,g,f,len),cpyint(b,f,min(n,now));
	}
}
void Pow(int *a,int *b,int n,int k){
	static int f[N];
	clrint(b,n);
	if (k==0)
		return (void)(b[0]=1);
	int fir=0;
	for (;fir<n&&!a[fir];fir++);
	if ((LL)fir*k>=n)
		return;
	int m=n-fir*k;
	cpyint(f,a+fir,m);
	int t=Pow(f[0],k),it=Pow(f[0],mod-2);
	For(i,0,m-1)
		f[i]=(LL)f[i]*it%mod;
	Ln(f,f,m);
	For(i,0,m-1)
		f[i]=(LL)f[i]*k%mod;
	Exp(f,b+fir*k,m);
	For(i,fir*k,n-1)
		b[i]=(LL)b[i]*t%mod;
}
int n,m;
int f[N],g[N];
int main(){
	n=read(),m=read()+1;
	while (n--)
		g[read()]=mod-4;
	Add(g[0],1);
	Sqrt(g,f,m);
	Add(f[0],1);
	Inv(f,g,m);
	For(i,1,m-1)
		printf("%d\n",g[i]=g[i]*2%mod);
	return 0;
}