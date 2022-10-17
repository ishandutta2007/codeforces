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
inline int read() {int x; FI(x); return x;}
const int MN=2e5+5;
int a[MN],n,p[MN],vis[MN];
bool cmp(int i,int j) {
	return a[i]<a[j];
}
struct SMT {
	static const int N=MN<<2;	
	#define ls (k<<1)
	#define rs (k<<1|1)
	#define mid ((l+r)>>1)
	int mx[N],tag[N];
	void clear(int n) {
		For(i,0,n<<2) mx[i]=tag[i]=0;
	}
	void pushr(int k,int v) {
		tag[k]+=v,mx[k]+=v;	
	}
	void pushdown(int k) {
		if(tag[k]) {
			pushr(ls,tag[k]),pushr(rs,tag[k]);
			tag[k]=0;
		}
	}
	void pushup(int k) {
		mx[k]=max(mx[ls],mx[rs]);	
	}
	void upd(int k,int l,int r,int ql,int qr,int v) {
//		cerr<<l<<' '<<r<<' '<<ql<<' '<<qr<<endl;
		if(r<ql||qr<l) return;
		if(ql<=l&&r<=qr) return pushr(k,v); pushdown(k);
		upd(ls,l,mid,ql,qr,v),upd(rs,mid+1,r,ql,qr,v);
		pushup(k);
	}
	int qry(int k,int l,int r,int ql,int qr) {
		if(r<ql||qr<l) return -INF;
		if(ql<=l&&r<=qr) return mx[k]; pushdown(k);
		return max(qry(ls,l,mid,ql,qr),qry(rs,mid+1,r,ql,qr));
	}
}tr;
void works() {
//	cerr<<n<<endl;
	n=read(); For(i,1,n) vis[i]=0;
//	cerr<<"?";
	For(i,1,n) a[i]=read(),p[i]=i;
	sort(p+1,p+1+n,cmp);
	int r=n,ans=0;
	tr.clear(n);
	For(i,1,n) tr.upd(1,1,n,i,i,-INF);
	foR(i,n,1) {
//		cerr<<i<<endl;
		int x=p[i]; vis[x]=1;
		tr.upd(1,1,n,x,x,INF); tr.upd(1,1,n,x,x,(x%2==0)-x);
		while(vis[r]) r--;
		if(!r) break;
		tr.upd(1,1,n,x+1,r,2);
		int now=tr.qry(1,1,n,1,r)+i;
//		cerr<<i<<' '<<x<<' '<<r<<' '<<now<<endl;
		ckmax(ans,now);	
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