#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,sse4.1")
//#define mp make_pair
//#define OO(x) fixed<<setprecision(x)
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}

typedef unsigned long long ull;
typedef __uint128_t L;
struct FastMod {
    ull b, m;
    FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}
    ull reduce(ull a) {
        ull q = (ull)((L(m) * a) >> 64);
        ull r = a - q * b; // can be proven that 0 <= r < 2*b
        return r >= b ? r - b : r;
    }
};
FastMod T(2);


int mod;
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
const int M=5050+10;
LL fac[M],inv[M],iv[M];
int ooo[M][M];
void init(int n){
//	fac[0]=1;
//	F(i,1,n) fac[i]=fac[i-1]*i%mod;
//	inv[n]=fast(fac[n],mod-2);
//	DF(i,n,1) inv[i-1]=inv[i]*i%mod;
//	iv[1]=1;
//	F(i,2,n) iv[i]=(mod-mod/i)*iv[mod%i]%mod;
	F(i,0,n){
		ooo[i][0]=1;
		F(j,1,i){
			ooo[i][j]=(ooo[i-1][j]+ooo[i-1][j-1])%mod;
		}
	}
}
LL C(int x,int y){
	if (y<0 || x<y) return 0;
	return ooo[x][y];
}
int n;
LL f[M][2][2],c[2][M][2],ff[M],as[M],g[M],h[M],cc[M],gg[M];
LL fk[M][2][2];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	n=5000; mod=998244353;
	 
	n=read(); mod=read(); 
	T = FastMod(mod);
	init(n);
	f[1][1][1]=1;
	F(i,2,n){
		fk[i-1][0][0]=(f[i-1][0][1]+f[i-1][1][1])%mod;
		fk[i-1][0][1]=(f[i-1][0][1]+f[i-1][1][1])%mod;
		fk[i-1][1][1]=(f[i-1][0][1])%mod;
		F(j,1,i-2){
			LL coe=C(i-2,j-1);
//			if (i==3){
//				cerr<<coe<<"\n";
//			}
			fk[i-1][0][0]=(fk[i-1][0][0]+fk[i-j-1][0][0]*(f[j][0][1]+f[j][1][1])%mod*coe)%mod;
			fk[i-1][0][1]=(fk[i-1][0][1]+fk[i-j-1][0][1]*(f[j][0][1]+f[j][1][1])%mod*coe+fk[i-j-1][0][0]*(f[j][0][1]+f[j][1][1])%mod*coe)%mod;
			fk[i-1][1][1]=(fk[i-1][1][1]+fk[i-j-1][1][1]*f[j][0][1]%mod*coe)%mod;
		}
		F(o,0,1) F(oo,0,1) f[i][o][oo]=fk[i-1][o][oo]*i%mod;
	}
	F(i,1,n) g[i]=(f[i][0][0]+f[i][0][1]+(i==1))%mod,h[i]=f[i][1][1],c[0][i][0]=g[i],c[1][i][1]=h[i],gg[i]=cc[i]=(f[i][0][0]+(i==1))%mod;
//	return 0;
//	F(i,1,n){
//		cout<<g[i]<<" "<<h[i]<<" "<<gg[i]<<" g  f  gg\n";
//		cerr<<f[i][0][0]<<" "<<f[i][0][1]<<" "<<f[i][1][1]<<" ?????\n";
////		if (i>1) c[0][i][0][0]=c[1][i][1][0]=cc[i][0]=0;
//	}	
	F(o,0,1)
	F(i,1,n){
		F(oo,0,1)
		F(j,1,n-i){
			LL coe=C(i+j-1,j);
			if (!oo) c[o][i+j][1]=T.reduce(c[o][i+j][1]+T.reduce(c[o][i][oo]*h[j])*coe);
			c[o][i+j][0]=T.reduce(c[o][i+j][0]+T.reduce(c[o][i][oo]*g[j])*coe);
			if (!o && !oo){
				cc[i+j]=T.reduce(cc[i+j]+T.reduce(cc[i]*gg[j])*coe);
			}
		}
	}
//	return 0;
//	cerr<<cc[3][1]<<" "<<cc[4][1]<<" !!!! cc2\n";
//	cerr<<c[0][3][0][1]<<" "<<c[1][3][0][1]<<" "<<c[0][3][1][1]<<"  fuck\n";
//	cerr<<c[0][i][0][1]<<" "<<c[0][i][0][]
	F(i,1,n) ff[i]=(c[0][i][0]+c[1][i][0]+c[0][i][1]+mod-cc[i]+mod-f[i][0][1])%mod;//,cerr<<ff[i]<<" "<<i<<" ff \n";
	as[0]=1;
	F(i,1,n){
		F(j,1,i){
			LL coe=C(i-1,j-1);
			as[i]=(as[i]+as[i-j]*ff[j]%mod*coe)%mod;
		}
	}
	cout<<as[n]<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
3 998244353
4 998244353
2 998244353
*/