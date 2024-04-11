#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define ull unsigned long long
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i,k,j) for(int i=(k);i>=(j);i--)
#define For(i,k,j) for(int i=(k);i<=(j);i++)
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define Fin(s) freopen(s,"r",stdin)
#define Fout(s) freopen(s,"w",stdout)
#define file(s) Fin(s".in"),Fout(s".out")
#define INF ((int)1e8)
//#define int long long
const int P=998244353; //
using namespace std;
template<typename T>void ckmax(T &a,T b) {(a<b)&&(a=b);}
template<typename T>void ckmin(T &a,T b) {(a>b)&&(a=b);}
inline int mul(int a,int b) {return 1ull*a*b%P;}
inline int add(int a,int b) {return a+b>=P?a+b-P:a+b;}
inline int sub(int a,int b) {return a-b>=0?a-b:a-b+P;}
inline void mulmod(int &a,int b) {a=mul(a, b);}
inline void addmod(int &a,int b) {((a+=b)>=P)&&(a-=P);}
inline void submod(int &a,int b) {((a-=b)<0)&&(a+=P);}
void fprint(const int &x,char c=' ') {fprintf(stderr,"%d%c",x,c);}
void fprint(const pii &x,char c=' ') {fprintf(stderr,"{%d,%d}%c",x.first,x.second,c);}
template<typename T> void fprint(const T &f) { for(auto &it:f) fprint(it); fprintf(stderr,"%c",'\n');}
template<typename T> void fprint(const T *f,const int &n) {for(int i=1;i<=n;i++) fprint(f[i]); fprintf(stderr,"%c",'\n');}
inline int ksm(int a,int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline int inv(int a) {return ksm(a,P-2);}
mt19937_64 rnd(time(0)); int Rnd(int l,int r) { return rnd()%(r-l+1)+l; }
namespace FastIO {
	const int SIZE=1<<16; char buf[SIZE],obuf[SIZE],str[64]; int bi=SIZE,bn=SIZE,opt;
	int read(char *s) {
		while (bn) {for (;bi<bn&&buf[bi]<=' ';bi++);if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}
		int sn=0;while (bn) {for (;bi<bn&&buf[bi]>' ';bi++) s[sn++]=buf[bi];if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}s[sn]=0;return sn;
	}
	bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n) return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
	void write(int x) {
		if(!x) obuf[opt++]='0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
		if (opt>=(SIZE>>1)){fwrite(obuf,1,opt,stdout); opt=0;}
	}
	void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf,1,opt,stdout); opt=0;}}
	void Fflush() {if (opt) fwrite(obuf,1,opt,stdout); opt=0;}
};
inline int read() {int x=0; FI(x); return x;}
const int MN=4e3+5;
int fac[MN],ifac[MN],n,m,t,banx[MN],bany[MN];
int C(int n,int m) {
	if(n<m||n<0||m<0) return 0;
	return 1ll*fac[n]*ifac[m]%P*ifac[n-m]%P;
}
int Fib[MN][MN],F[MN],G[MN];
void init(int n=MN-5) {
	fac[0]=1; For(i,1,n) fac[i]=mul(fac[i-1],i); ifac[n]=inv(fac[n]);
	foR(i,n,1) ifac[i-1]=mul(ifac[i],i);
	Fib[0][0]=1; 
	For(i,1,n) {
		For(j,0,i/2) {
			if(j) addmod(Fib[i][j],Fib[i-2][j-1]); 
			addmod(Fib[i][j],Fib[i-1][j]);
		}
	}	
}
int g[MN]; 
void solve(int *f,int n,int m) {
	For(i,0,n+m) g[i]=0; 
	foR(i,n+m,0) {
		For(j,0,min(m,i)) {
			addmod(g[i],mul(Fib[m][j],f[i-j])); 
		}	
	}
	For(i,0,n+m) f[i]=g[i]; 
}	
void works() {
	n=read(),m=read(),t=read();
	For(i,1,t) {
		int x=read(),y=read(),r=read(),c=read();
		For(j,x,r) banx[j]=1;
		For(j,y,c) bany[j]=1; 
	}
	F[0]=G[0]=1; 
	int totx=0,toty=0; 
	For(i,1,n) {
		if(!banx[i]) {
			int j=i; 
			while(j<n&&!banx[j+1]) j++;
			solve(F,totx,j-i+1); totx+=j-i+1; 
			i=j+1; 
		}
	}
	For(i,1,m) {
		if(!bany[i]) {
			int j=i; 
			while(j<m&&!bany[j+1]) j++;
			solve(G,toty,j-i+1); toty+=j-i+1; 
			i=j+1; 
		}
	}
	int ans=0; 
	For(tx,0,max(n,m)) For(ty,0,max(n,m)) {
		int cntx=2*tx+ty,cnty=2*ty+tx; 
		if(cntx>totx||cnty>toty) continue; 
		int px=mul(F[tx],mul(C(totx-2*tx,ty),fac[ty])); 
		int py=mul(G[ty],mul(C(toty-2*ty,tx),fac[tx])); 
		addmod(ans,mul(px,py)); 
	}
	cout<<ans<<endl; 
}
signed main() {
	#ifdef wasa855
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	init(); 
	int T=1;
	while(T--) {
		works(); 
	}
	return FastIO::Fflush(),0;
}