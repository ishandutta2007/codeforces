#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
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
#define int ll
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
const int MN=2e5+5;
int a[MN],b[MN],n,m,q,para[MN];
vector<pii> e[MN];
struct SMT {
	static const int N=MN<<2;
	#define ls (k<<1)
	#define rs (k<<1|1)
	#define mid ((l+r)>>1)
	int tag[N],mn[N];
	void pushup(int k) {
		mn[k]=min(mn[ls]+tag[ls],mn[rs]+tag[rs]);
	}
	void build(int k,int l,int r) {
		if(l==r) return mn[k]=b[l],void();
		build(ls,l,mid),build(rs,mid+1,r); pushup(k);
	}
	void upd(int k,int l,int r,int ql,int qr,int v) {
		if(l>qr||r<ql) return; if(ql<=l&&r<=qr) return tag[k]+=v,void();
		upd(ls,l,mid,ql,qr,v),upd(rs,mid+1,r,ql,qr,v); pushup(k);
	}
	int qry() { return mn[1]+tag[1]; }
}tr;
void works() {
	n=read(),m=read(),q=read();
	For(i,1,n-1) a[i]=read(),b[i+1]=read();
	For(i,1,m) {
		int u=read(),v=read(),w=read();
		e[u].pb(mkp(v,w));
	}
	multiset<int>s;
	tr.build(1,1,n);
	For(u,1,n) {
		for(auto it:e[u]) {
			tr.upd(1,1,n,1,it.first,it.second);
		}
		para[u]=tr.qry();
	}
//	fprint(para,n);
	For(i,1,n) s.insert(a[i]+para[i]);
	FO(*s.begin()); FO('\n');
	while(q--) {
		int x=read(),v=read();
		s.erase(s.find(a[x]+para[x]));
		a[x]=v; 
		s.insert(a[x]+para[x]);
		FO(*s.begin()); FO('\n');
	}
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	int T=1;
	while(T--) {
		works();
	}
	return FastIO::Fflush(),0;
}
/*
?t??? 1??? 12?
*/