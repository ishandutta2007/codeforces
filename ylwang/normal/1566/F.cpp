#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mkp make_pair
#define vi vector<int>
#define pii pair<int,int>
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
#define INF ((1ll<<60)-1)
#define int long long
const int P=1e9+7; //
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
inline void fprint(const pii &x,char c='\n') {fprintf(stderr,"%lld %lld%c",x.first,x.second,c);}
inline void fprint(const int &x,char c=' ') {fprintf(stderr,"%lld%c",x,c);}
inline void fprint(const int *f,const int &n,char c='\n') {for(int i=1;i<=n;i++) fprint(f[i]); fprintf(stderr,"%c",c);}
inline void fprint(const vector<int> &f,char c='\n') {for(int i=0;i<(int)f.size();i++) fprint(f[i]); fprintf(stderr,"%c",c);}
inline int inv(int a) {return ksm(a,P-2);}
namespace FastIO {
  const int SIZE=1<<16; char buf[SIZE],obuf[SIZE],str[64]; int bi=SIZE,bn=SIZE,opt;
  int read(char *s) {
    while (bn) {for (;bi<bn&&buf[bi]<=' ';bi++);if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}
    int sn=0;while (bn) {for (;bi<bn&&buf[bi]>' ';bi++) s[sn++]=buf[bi];if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}s[sn]=0;return sn;
  }
  bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n) return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
  void write(ll x) {
    if(!x) obuf[opt++]='0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
    if (opt>=(SIZE>>1)){fwrite(obuf,1,opt,stdout); opt=0;}
  }
  void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf,1,opt,stdout); opt=0;}}
	void Fflush() {if (opt) fwrite(obuf,1,opt,stdout); opt=0;}
};
inline int read() {int x=0; FI(x); return x;}
const int MN=2e5+5;
int a[MN],n,m,Tm;
struct Seg {
	int l,r;	
	bool operator < (const Seg &b) const {
		if(l!=b.l) return l<b.l;
		return r<b.r;
	}
}b[MN],c[MN],tmp[MN];
int f[MN],g[MN],cnt;
void works() {
	n=read(),m=read();
	For(i,1,n) a[i]=read(); a[0]=-INF,a[n+1]=INF;
	For(i,1,m) {
		b[i].l=read(),b[i].r=read();
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+m); Tm=0;
	For(i,1,m) {
		int x=lower_bound(a+1,a+1+n,b[i].l)-a;
		if(a[x]<=b[i].r) continue;
		else {
			while(Tm&&c[Tm].r>=b[i].r) Tm--;
			c[++Tm]=b[i];
		}
	}
	m=Tm; For(i,1,m) b[i]=c[i];
//	For(i,1,m) {
//		cerr<<"! "<<b[i].l<<' '<<b[i].r<<endl;	
//	}
	int now=0; f[0]=g[0]=0;
	For(i,1,n+1) { cnt=0;
		tmp[++cnt].l=a[i-1]; tmp[cnt].r=0;
		f[i]=g[i]=INF;
		while(now<m&&b[now+1].r<a[i]) { now++;
			tmp[++cnt]=b[now];
		}
		tmp[++cnt].r=a[i]; tmp[cnt].l=0;
//		cerr<<i<<endl;
		For(j,1,cnt-1) {
			int x=tmp[j].l-a[i-1],y=a[i]-tmp[j+1].r;
//			cerr<<x<<' '<<y<<endl;
			ckmin(f[i],min(f[i-1]+x,g[i-1]+2*x)+2*y);
			ckmin(g[i],min(f[i-1]+x,g[i-1]+2*x)+y);
		}
	
	}
//	fprint(f,n+1),fprint(g,n+1);
	cout<<g[n+1]<<endl;
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	int T=read();
	while(T--) {
		works(); 
	}
	return FastIO::Fflush(),0;
}

/*
// p[i] < p[j] : iff pos[i] > j && a[i] < j
*/