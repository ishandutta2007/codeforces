#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
const int N=1<<20|7, mod=998244353, G=3, invG=332748118;
inline void inc(int &x, int y) {x+=y-mod, x+=x>>31&mod;}
inline void dec(int &x, int y) {x-=y, x+=x>>31&mod;}
inline int qpow(int a, int b) {
	int res=1;
	for (; b; b>>=1, a=(ll)a*a%mod)
		if (b&1) res=(ll)res*a%mod;
	return res;
}
namespace Poly {
	typedef uint64_t ull;
	int lstn, rev[N], g[N]={1};
	inline void init(int n) {
		if (lstn==n) return; lstn=n;
		for (int i=1; i<n; i++) rev[i]=rev[i>>1]>>1|(i&1?n>>1:0);
	}
	inline void NTT(int n, int *f, int op) {
		static ull A[N];
		for (int i=0; i<n; i++) A[i]=f[rev[i]];
		for (int len=2, p=1; len<=n; p=len, len<<=1) {
			int t=qpow(op?G:invG, (mod-1)/len);
			for (int i=1; i<p; i++) g[i]=(ll)g[i-1]*t%mod;
			for (int i=0; i<n; i+=len)
				for (int j=0; j<p; j++) {
					int l=i|j, r=l|p, t=A[r]*g[j]%mod;
					A[r]=A[l]+mod-t, A[l]+=t;
				}
			if (len==(1<<18))
				for (int i=0; i<n; i++) A[i]%=mod;
		}
		if (!op) {
			int inv=mod-(mod-1)/n;
			for (int i=0; i<n; i++) f[i]=A[i]*inv%mod;
		} else for (int i=0; i<n; i++) f[i]=A[i]%mod;
	}
	inline void px(int n, int *a, int *b) {
		for (int i=0; i<n; i++) a[i]=(ll)a[i]*b[i]%mod;
	}
	inline void clear(int n, int *a) {memset(a, 0, sizeof(*a)*n);}
	inline void cpy(int n, int *a, int *b) {memcpy(a, b, sizeof(*a)*n);}
	inline void Mul(int n, int *a, int *b) {
		static int B[N]; cpy(n, B, b);
		init(n), NTT(n, a, 1), NTT(n, B, 1), px(n, a, B), NTT(n, a, 0);
	}
	inline void Inv(int n, int *a) {
		static int b[N], c[N]; clear(n, b), b[0]=qpow(a[0], mod-2);
		for (int len=2, p=1; len<=n; p=len, len<<=1) {
			cpy(len, c, a), Mul(len, c, b), clear(p, c), Mul(len, c, b);
			for (int i=p; i<len; i++) b[i]=(mod-c[i])%mod;
		}
		cpy(n, a, b);
	}
	inline void Der(int n, int *a) {
		for (int i=1; i<n; i++) a[i-1]=(ll)a[i]*i%mod;
		a[n-1]=0;
	}
	int lstn_inv=1, inv[N]={0, 1};
	inline void init_inv(int n) {
		for (int i=lstn_inv+1; i<=n; i++) inv[i]=mod-(ll)(mod/i)*inv[mod%i]%mod;
		lstn_inv=n;
	}
	inline void Inte(int n, int *a) {
		init_inv(n-1);
		for (int i=n-1; i; i--) a[i]=(ll)a[i-1]*inv[i]%mod;
		a[0]=0;
	}
	inline void Ln(int n, int *a) {
		static int b[N]; for (int i=n; i<n+n; i++) b[i]=0;
		cpy(n, b, a), Der(n, a), Inv(n, b), Mul(n<<1, a, b), Inte(n, a);
	}
	void solve_exp(int l, int n, int *f, int *g) {
		if (n==1) {if (l) f[0]=(ll)f[0]*inv[l]%mod; return;}
		int p=n>>1; solve_exp(l, p, f, g);
		static int h[N]; cpy(p, h, f);
		for (int i=p; i<n; i++) h[i]=0;
		Mul(n, h, g);
		for (int i=p; i<n; i++) inc(f[i], h[i]);
		solve_exp(l+p, p, f+p, g);
	}
	inline void Exp(int n, int *a) {
		for(int i=1; i<n; i++) a[i]=(ll)a[i]*i%mod;
		static int b[N]; clear(n, b);
		b[0]=1, init_inv(n-1), solve_exp(0, n, b, a), cpy(n, a, b);
	}
	int A[N], B[N];
	inline int Get(int m) {int n=1; while (n<m) n<<=1; return n;}
	struct poly {
		vector<int>a;
		poly(int n=0) {a.resize(n);}
		inline int size() {return a.size();}
		inline void resize(int n) {a.resize(n);}
		int& operator [](int i) {return a[i];}
		poly& operator +=(poly b) {
			if (a.size()<b.size()) a.resize(b.size());
			for (int i=0; i<b.size(); i++) inc(a[i], b[i]);
			return *this;
		}
		poly& operator -=(poly b) {
			if (a.size()<b.size()) a.resize(b.size());
			for (int i=0; i<b.size(); i++) dec(a[i], b[i]);
			return *this;
		}
		poly& operator *=(poly b) {
			int n=Get(a.size()+b.size()-1);
			for (int i=0; i<(int)a.size(); i++) A[i]=a[i];
			for (int i=a.size(); i<n; i++) A[i]=0;
			for (int i=0; i<b.size(); i++) B[i]=b[i];
			for (int i=b.size(); i<n; i++) B[i]=0;
			Mul(n, A, B), a.resize(a.size()+b.size()-1);
			for (int i=0; i<(int)a.size(); i++) a[i]=A[i];
			return *this;
		}
		poly operator +(poly b) {poly tmp=*this; tmp+=b; return tmp;}
		poly operator -(poly b) {poly tmp=*this; tmp-=b; return tmp;}
		poly operator *(poly b) {poly tmp=*this; tmp*=b; return tmp;}
		poly inv() {
			int n=Get(a.size());
			for (int i=0; i<(int)a.size(); i++) A[i]=a[i];
			for (int i=a.size(); i<n; i++) A[i]=0;
			Inv(n, A); poly b(a.size());
			for (int i=0; i<b.size(); i++) b[i]=A[i];
			return b;
		}
		poly der() {
			poly b(a.size()-1);
			for (int i=1; i<(int)a.size(); i++) b[i-1]=(ll)a[i]*i%mod;
			return b;
		}
		poly inte() {
			poly b(a.size()+1); init_inv(a.size());
			for (int i=1; i<b.size(); i++) b[i]=(ll)a[i-1]*Poly::inv[i]%mod;
			return b;
		}
		poly ln() {
			int n=Get(a.size());
			for (int i=0; i<(int)a.size(); i++) A[i]=a[i];
			for (int i=a.size(); i<n; i++) A[i]=0;
			Ln(n, A); poly b(a.size());
			for (int i=0; i<b.size(); i++) b[i]=A[i];
			return b;
		}
		poly exp() {
			int n=Get(a.size());
			for (int i=0; i<(int)a.size(); i++) A[i]=a[i];
			for (int i=a.size(); i<n; i++) A[i]=0;
			Exp(n, A); poly b(a.size());
			for (int i=0; i<b.size(); i++) b[i]=A[i];
			return b;
		}
	};
} using Poly::poly;
int n, K, m;
int main() {
#ifdef LOCAL
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), K=read(), m=read(); if (m>2*K) puts("0"), exit(0);
	poly f(K+K+1); for (int i=0; i<=K; i++) f[i]=1;
	for (int j=1; j<=n; j++) {
		f*=f, f.resize(2*K+1);
		if (j==n) break; int sum=0;
		for (int i=2*K; ~i; i--) {
			int tmp=f[i];
			if (i>K) f[i]=0;
			else f[i]=(sum+(ll)(K-i+1)*tmp)%mod;
			inc(sum, tmp);
		}
	}
	printf("%d\n", f[m]);
	return 0;
}