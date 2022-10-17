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
const int MN=3e5+5;
int n,q,K,a[MN],ans[MN];
int t,b[MN],c[MN];
vector<pii>qr[MN],tqr[MN];


struct SMT {
	static const int N=MN<<2;
	int tag[N],val[N];
	#define ls (k<<1)
	#define rs (k<<1|1)
	#define mid ((l+r)>>1)
	void clear(int n) { For(i,1,n<<2) tag[i]=val[i]=0;}
	void pushr(int k,int l,int r,int v) { tag[k]=v,val[k]=(r-l+1)*v;}
	void pushup(int k) { val[k]=val[ls]+val[rs]; }
	void pushdown(int k,int l,int r) {
		if(tag[k]) pushr(ls,l,mid,tag[k]),pushr(rs,mid+1,r,tag[k]),tag[k]=0;	
	}
	void upd(int k,int l,int r,int ql,int qr,int v) {
		if(l>qr||r<ql) return; if(ql<=l&&r<=qr) return pushr(k,l,r,v);
		pushdown(k,l,r); upd(ls,l,mid,ql,qr,v),upd(rs,mid+1,r,ql,qr,v);
		pushup(k);
	}
	
	int qry(int k,int l,int r,int ql,int qr) {
		if(l>qr||r<ql) return 0; if(ql<=l&&r<=qr) return val[k];
		pushdown(k,l,r); return qry(ls,l,mid,ql,qr)+qry(rs,mid+1,r,ql,qr);
	}
}tr;
int top,s[MN];
void solve(int *a,int *b,int n,vector<pii> *qr) {
//	cerr<<"! ";fprint(a,n);
	tr.clear(n); s[top=1]=n+1;
	for(int i=n;i>=1;i--) {
		while(top>1&&b[s[top]]>a[i]) top--;
//		cerr<<i<<' '<<s[top]<<endl;
		tr.upd(1,1,n,i,s[top]-1,a[i]); 
		for(auto it:qr[i])
			ans[it.second]=tr.qry(1,1,n,i,it.first);

		while(top>1&&b[s[top]]>b[i]) top--;
		
		tr.upd(1,1,n,i,s[top]-1,b[i]); 
		s[++top]=i;
	}
}
struct SMT2 {
	static const int N=MN<<2;
	int mn[N];
	void build(int k,int l,int r) {
		if(l==r) return mn[k]=a[l],void();
		build(ls,l,mid),build(rs,mid+1,r);
		mn[k]=min(mn[ls],mn[rs]);	
	}
	int qry(int k,int l,int r,int ql,int qr) {
		if(l>qr||r<ql) return INF; if(ql<=l&&r<=qr) return mn[k];
		return min(qry(ls,l,mid,ql,qr),qry(rs,mid+1,r,ql,qr));
	}
}mtr;
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read(),q=read(),K=read();
	For(i,1,n) a[i]=read();	
	For(i,1,q) {
		int l=read(),r=read();
		qr[l].pb(mkp(r,i));
	}
	mtr.build(1,1,n);
	For(d,1,K) { t=0; 
		int lst=0;
		for(int i=d;i<=n;i+=K) {
			b[++t]=a[i],c[t]=mtr.qry(1,1,n,lst+1,i); lst=i;
			tqr[t]=qr[i];
			for(auto &it:tqr[t]) {
				it.first=(it.first-d)/K+1;
			}
		}
		solve(b,c,t,tqr);
	}
	For(i,1,q) {
		printf("%lld\n",ans[i]);
	}
	return FastIO::Fflush(),0;
}
/*
  
*/