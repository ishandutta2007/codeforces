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
//#define int long long
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
const int MN=1e5+5;
int n,m,q,t[MN]; 
struct VAL {int mx,se;};
struct TAG {int x,y;}; //  
VAL operator + (const VAL &a,const VAL &b) {
	vector<int>t(4); t[0]=a.mx,t[1]=a.se,t[2]=b.mx,t[3]=b.se;
	sort(t.begin(),t.end(),greater<int>()); unique(t.begin(),t.end());
	return (VAL){t[0],t[1]};
}
struct SMT {
	static const int N=MN<<2;
	VAL a[N]; TAG t[N];
	#define ls (k<<1)
	#define rs (k<<1|1)
	#define mid ((l+r)>>1)
	SMT() { For(i,0,N-1) t[i].x=INF;}
	void pushr(int k,TAG C) {
		if(a[k].mx>=C.x) {
			a[k].mx=C.y;
			t[k]=(TAG){min(t[k].x,C.x),C.y};	
		}
	}	
	void pushdown(int k) {
		if(t[k].x!=INF) {
			pushr(ls,t[k]),pushr(rs,t[k]);
			t[k].x=INF,t[k].y=0;
		}
	}
	void mdf(int k,int l,int r,int p,int v) {
		if(l==r) return a[k].mx=v,void();pushdown(k); 
		p<=mid?mdf(ls,l,mid,p,v):mdf(rs,mid+1,r,p,v); 
		a[k]=a[ls]+a[rs];
	}
	void upd(int k,int l,int r,int ql,int qr,TAG v) {
		if(l>qr||r<ql||a[k].mx<v.x) return; if(ql<=l&&r<=qr&&a[k].se<v.x) return pushr(k,v);
		pushdown(k);upd(ls,l,mid,ql,qr,v),upd(rs,mid+1,r,ql,qr,v);
		a[k]=a[ls]+a[rs];
	}
	int qry(int k,int l,int r,int ql,int qr) {
		if(l>qr||r<ql) return -INF; if(ql<=l&&r<=qr) return a[k].mx; pushdown(k);
		return max(qry(ls,l,mid,ql,qr),qry(rs,mid+1,r,ql,qr));	
	}
		
}tr;
vector<pii>qr[MN]; int ans[MN];
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read(),m=read();
	For(i,1,m) {
		int l=read(),r=read();
		t[r]=l;	
	}
	q=read();
	For(i,1,q)  {
		int x=read(),y=read();
		qr[y].pb(mkp(x,i));	
	}
	For(i,1,n) {
		tr.mdf(1,1,n,i,i);
		if(t[i]) {
			tr.upd(1,1,n,1,t[i],(TAG){t[i],i});
		}
		for(auto it:qr[i]) {
			ans[it.second]=tr.qry(1,1,n,it.first,it.first);
		}
	}
	For(i,1,q) {
		printf("%d\n",ans[i]);	
	}
	return 0;	
}