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
const int MN=2e6+5;

int n,m,a[MN],b[MN],d[MN],t; 
vi val[MN];
struct SMT {
	static const int N=MN<<2;
	pii mn[N]; int tag[N];
	#define ls (k<<1)
	#define rs (k<<1|1)
	#define mid ((l+r)>>1)
	void pushup(int k) { mn[k]=min(mn[ls],mn[rs]); }
	void pushr(int k,int v) {mn[k].first+=v,tag[k]+=v;}
	void build(int k,int l,int r) {
		tag[k]=0;;
		if(l==r) return mn[k]=mkp(0,l),void();
		build(ls,l,mid),build(rs,mid+1,r);
		pushup(k);
	}
	void pushdown(int k) {
		if(tag[k]) {
			pushr(ls,tag[k]),pushr(rs,tag[k]),tag[k]=0;	
		}
	}
	void upd(int k,int l,int r,int ql,int qr,int v) {
		assert(ql<=qr); 
		if(l>qr||r<ql) return; if(ql<=l&&r<=qr) return pushr(k,v); pushdown(k);
		upd(ls,l,mid,ql,qr,v),upd(rs,mid+1,r,ql,qr,v);
		pushup(k); 
	}
	pii qry(int k,int l,int r,int ql,int qr) {
//		assert(ql<=qr); 
		if(l>qr||r<ql) return mkp(INF,0); if(ql<=l&&r<=qr) return mn[k]; pushdown(k);
		return min(qry(ls,l,mid,ql,qr),qry(rs,mid+1,r,ql,qr));
	}
}tr;
struct BIT {
	static const int N=MN;
	int c[N],t;
	void clear(int n) {For(i,1,n) c[i]=0; t=n;}
	void upd(int x,int v) {	
		for(;x;x-=x&-x) c[x]+=v;
	}
	int qry(int x) {
		int ans=0;
		for(;x<=t;x+=x&-x) ans+=c[x];
		return ans;	
	}
}bit;
void works() {
	n=read(),m=read(),t=0;
	For(i,1,n) a[i]=read(),d[++t]=a[i];
	For(i,1,m) b[i]=read(),d[++t]=b[i];
	sort(d+1,d+1+t); For(i,1,n) a[i]=lower_bound(d+1,d+1+t,a[i])-d; For(i,1,m) b[i]=lower_bound(d+1,d+1+t,b[i])-d;
	For(i,1,t) val[i].clear();
	For(i,1,n) val[a[i]].pb(i);
//	cerr<<t<<endl;
	sort(b+1,b+1+m); int now=0;
	tr.build(1,0,n),bit.clear(t);
	For(i,1,n) tr.upd(1,0,n,i,n,1);
	
//		pii it=tr.qry(1,0,n,1,n);
//		cerr<<it.first<<' '<<it.second<<endl;
	int lst=0; ll ans=0;
	For(i,1,n) ans+=bit.qry(a[i]+1),bit.upd(a[i],1);
//	cerr<<t<<' '<<b[m]<<endl; 
//	cerr<<ans<<endl;
	For(i,1,m) {
		while(now<=t&&now<b[i]) { 
			for(auto ii:val[now]) {
//				cerr<<ii<<endl;
				tr.upd(1,0,n,ii,n,-1);
				tr.upd(1,0,n,0,ii-1,1);	
			} now++;
//			if(now>=MN) cerr<<now<<endl;
		}
		
		if(b[i]!=b[i-1]) for(auto ii:val[b[i]]) tr.upd(1,0,n,ii,n,-1);
//		cerr<<lst<<endl;
//		if(i%10000==0) cerr<<i<<endl;
		pii it=tr.qry(1,0,n,lst,n);
//		cerr<<it.first<<' '<<it.second<<endl;
		ans+=it.first; lst=it.second;
		if(i!=m&&b[i]!=b[i+1]) {
			for(auto ii:val[b[i]]) tr.upd(1,0,n,0,ii-1,1);
			now++;
		}
	}
	cout<<ans<<endl;
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
  
*/