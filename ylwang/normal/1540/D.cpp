#include<bits/stdc++.h>
#define ll long long
#define pb push_back
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
#define INF ((1<<30)-1)
const int P=998244353; //
using namespace std;
template<typename T>inline void ckmax(T &a,T b) {(a<b)&&(a=b);}
template<typename T>inline void ckmin(T &a,T b) {(a>b)&&(a=b);}
inline int mul(int a,int b) {return 1ll*a*b%P;}
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
inline int read() {int x; FI(x); return x;}
const int MN=1e5+5;
const int S=150,B=MN/S,MB=B+10;
int n,a[MN],bel[MN],rk[MN],L[MN],R[MN],Bcnt;
struct BIT {
	static const int N=MN; int c[N],n;
	void init(int N) {n=N; For(i,0,N) c[i]=0;}
	void upd(int x,int v) { for(;x<=n;x+=x&-x) c[x]+=v; } // suffix add one
	int qry(int x) { int ans=0; for(;x;x-=x&-x) ans+=c[x]; return ans; } // single val
	int find(int x) { // find the leftmost position that val[i] >= x;
		int now=0;
		for(int i=17;i>=0;i--) { if(now+(1<<i)>n) continue;
			int p=now+(1<<i);
			if(x>c[p]) now=p,x-=c[p]; 
		}
		return now+1;
	}
}tr;

struct BLK {
	static const int N=S+5;
	int v[N],sz,x[N],y[N];
	void build() {
		For(i,1,sz) {
			int p=tr.find(v[i]);
			tr.upd(p,1); x[i]=p;
		}
		sort(x+1,x+1+sz);
		For(i,1,sz) y[i]=tr.qry(x[i])-x[i];
		For(i,1,sz) tr.upd(x[i],-1); 
	}
	void doit(int &val) {
//		fprint(x,sz),fprint(y,sz);
		val+=y[upper_bound(x+1,x+1+sz,val)-1-x];
	}
} bl[MB];
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read(); For(i,1,n) a[i]=i-read();
	tr.init(n);
	For(i,1,n) tr.upd(i,1);
//	For(i,1,n) cerr<<tr.find(i)<<endl;
	for(int l=1,r;l<=n;l=r+1) {
		r=min(n,l+S-1); Bcnt++;
		For(i,l,r) {
			L[i]=l,R[i]=r,bel[i]=Bcnt;
			rk[i]=++bl[Bcnt].sz;
			bl[Bcnt].v[bl[Bcnt].sz]=a[i];
		}
		bl[Bcnt].build();
		
	}
//	cerr<<Bcnt<<endl;
	int q=read();
	while(q--) {
		int op=read(),x=read();
		if(op==1) {
			a[x]=x-read();
			bl[bel[x]].v[rk[x]]=a[x];
			bl[bel[x]].build();
		} else {
			int ans=a[x];
			For(i,x+1,R[x+1]) if(ans>=a[i]) ans++;
			if(x!=n) For(i,bel[x+1]+1,Bcnt) bl[i].doit(ans);
			FO(ans); FO('\n');
		}
	}
	return FastIO::Fflush(),0;
}