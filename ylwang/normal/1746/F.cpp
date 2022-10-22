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
#define Foe(i,u) for(int i=lst[u],v=e[i].v;i;i=e[i].nxt,v=e[i].v)
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define Fin(s) freopen(s,"r",stdin)
#define Fout(s) freopen(s,"w",stdout)
#define file(s) Fin(s".in"),Fout(s".out")
#define INF ((1<<30)-1)
#define int long long
const int P=998244353; //
using namespace std;
template<typename T>inline void ckmax(T &a,T b) {(a<b)&&(a=b);}
template<typename T>inline void ckmin(T &a,T b) {(a>b)&&(a=b);}
inline int mul(int a,int b) {return 1ull*a*b%P;}
inline int add(int a,int b) {return a+b>=P?a+b-P:a+b;}
inline int sub(int a,int b) {return a-b>=0?a-b:a-b+P;}
inline void mulmod(int &a,int b) {a=mul(a, b);}
inline void addmod(int &a,int b) {((a+=b)>=P)&&(a-=P);}
inline void submod(int &a,int b) {((a-=b)<0)&&(a+=P);}
inline int ksm(int a,int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline void fprint(const int &x,char c=' ') {fprintf(stderr,"%d%c",x,c);}
inline void fprint(const pii &x,char c='\n') {fprintf(stderr,"%d %d%c",x.first,x.second,c);}
inline void fprint(const int *f,const int &n,char c='\n') {for(int i=1;i<=n;i++) fprint(f[i]); fprintf(stderr,"%c",c);}
inline void fprint(const vector<int> &f,char c='\n') {for(int i=0;i<(int)f.size();i++) fprint(f[i]); fprintf(stderr,"%c",c);}
inline int inv(int a) {return ksm(a,P-2);}
mt19937_64 rnd(3); int Rnd(int l,int r) { return rnd()%(r-l+1)+l; }
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
const int MN=6e5+5;
#define Isprime(P) PrimeJudger::Query(P)
int n,a[MN],b[MN],q,op[MN],X[MN],Y[MN],Z[MN],t,d[MN]; 

int val[MN]; 
struct BIT {
	static const int N=MN; ll c[N],n;
	void init(int N) {n=N; For(i,0,N) c[i]=0;}
	void upd(int x,int v) { for(;x<=n;x+=x&-x) c[x]+=v; }
	ll qry(int x) { ll ans=0; for(;x;x-=x&-x) ans+=c[x]; return ans; }
}tr;
int ans[MN]; 
void solve() {
	For(i,1,n) b[i]=a[i]; 

	For(i,1,t) val[i]=Rnd(1,1e9); 
	tr.init(n); 
	For(i,1,n) tr.upd(i,val[a[i]]); 
//	fprint(val,t);
	For(i,1,q) {
		if(op[i]==1) {
			tr.upd(X[i],-val[a[X[i]]]); 
			a[X[i]]=Y[i]; 
			tr.upd(X[i],val[a[X[i]]]); 
		} else {
			if(!ans[i]) continue; 
			ll v=tr.qry(Y[i])-tr.qry(X[i]-1); 
//			if(i==1) cerr<<v<<' '<<Z[i]<<endl;
			if(v%Z[i]!=0) ans[i]=0; 
		}
	}
	For(i,1,n) a[i]=b[i]; 
}	
void works() {
	n=read(),q=read();
	For(i,1,n) d[++t]=a[i]=read(); 
	For(i,1,q) {
		op[i]=read(),X[i]=read(),Y[i]=read();
		if(op[i]==1) d[++t]=Y[i]; 
		if(op[i]==2) Z[i]=read(); 
	}
	sort(d+1,d+1+t); t=unique(d+1,d+1+t)-d-1; 
	For(i,1,n) a[i]=lower_bound(d+1,d+1+t,a[i])-d; 
	For(i,1,q) if(op[i]==1) Y[i]=lower_bound(d+1,d+1+t,Y[i])-d; 
//	sieve(1e6);
	For(i,1,q) if(op[i]==2) ans[i]=1; 
	For(tt,1,60) solve(); 
	For(i,1,q) if(op[i]==2) printf(ans[i]?"YES\n":"NO\n"); 
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	int T=1;
	while(T--) works(); 
	return FastIO::Fflush(),0;
}
/*
  
*/