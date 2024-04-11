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
inline int read() {int x; FI(x); return x;}
const int MN=3e5+5;
int n,Q,a[MN],ans[MN];
vector<pii> qr[MN];
struct BIT { static const int N=MN<<2;
	int c[N];
	BIT() { For(i,0,N-1) c[i]=2e9;}
	void clear() {For(i,0,N-1) c[i]=2e9;}
	void upd(int x,int v) {
		for(;x;x-=x&-x) ckmin(c[x],v);
	}
	int qry(int x) { int ans=2e9;
		for(;x<=n;x+=x&-x) ckmin(ans,c[x]); 	
		return ans;
	}
}tr;
set<pii>s;
const int N=MN*40;
int tot=0,rt,mx[N],c[N][2];
#define mid ((l+r)>>1)
#define ls c[k][0]
#define rs c[k][1]
void upd(int &k,int l,int r,int pos,int val) {
	if(!k) k=++tot; ckmax(mx[k],val); if(l==r) return; 
	pos<=mid?upd(ls,l,mid,pos,val):upd(rs,mid+1,r,pos,val);
}
int qry(int k,int l,int r,int ql,int qr) { if(ql>qr) return 0;
	if(!k||l>qr||r<ql) return 0;  if(ql<=l&&r<=qr) return mx[k];
	return max(qry(ls,l,mid,ql,qr),qry(rs,mid+1,r,ql,qr));	
}
void works() {
	tr.clear(); For(i,0,tot) mx[i]=c[i][0]=c[i][1]=0; rt=0,tot=0;
//	fprint(a,n);
	For(i,1,n) { 
		s.insert(mkp(a[i],i)); int pos=qry(1,0,1e9,a[i],1e9); 
		while(pos) {
//			cerr<<i<<' '<<pos<<' '<<a[i]<<' '<<(a[i]+a[pos]+1)/2-1<<endl;
			tr.upd(pos,a[pos]-a[i]);
			pos=qry(1,0,1e9,a[i],(a[i]+a[pos]+1)/2-1); 
		}
		for(auto it:qr[i]) {
			int l=it.first,id=it.second;
			ckmin(ans[id],tr.qry(l));
		}
		upd(rt,0,1e9,a[i],i);
	}
	
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read();
	For(i,1,n) a[i]=read();
	Q=read();
	For(i,1,Q) {
		int l=read(),r=read();
		qr[r].pb(mkp(l,i)); ans[i]=2e9;
	}
	works();
	For(i,1,n) a[i]=1e9-a[i];
	works();
	For(i,1,Q) printf("%d\n",ans[i]);
	return FastIO::Fflush(),0;
}