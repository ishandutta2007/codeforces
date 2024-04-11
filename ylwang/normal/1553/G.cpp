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
#define INF ((1ll<<60)-1)
//#define int long long
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
const int MN=2e6+5;
int n,q,vis[MN],a[MN],t=2e6; 
vi g[MN]; map<pii,int>mp;
pii norm(int x,int y) { return mkp(min(x,y),max(x,y));}
struct DSU {
	static const int N=MN;
	int f[N]; DSU() {For(i,0,N-5) f[i]=i;}
	void init(int n) {For(i,0,n) f[i]=i;}
	inline int find(int x) {return x==f[x]?x:f[x]=find(f[x]);}
	inline int merge(int x,int y) {
		x=find(x),y=find(y);
		if(x==y) return 0;
		return f[x]=y,1;
	}
}d;

signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read(),q=read(); d.init(t);
//	cerr<<t<<endl;
	For(i,2,t) if(!vis[i]) {
		for(int j=i;j<=t;j+=i) g[j].pb(i),vis[j]=1;
	}
//	For(i,2,10) fprint(g[i]);
	For(i,1,n) a[i]=read();
	For(i,1,n) {
		for(auto it:g[a[i]]) d.merge(a[i],it);
	}	
//	For(i,1,100) cerr<<d.find(i)<<' ';
//	cerr<<endl;
	For(i,1,n) {
		int x=a[i]+1; vi tmp; tmp.pb(d.find(a[i])); for(auto it:g[x]) tmp.pb(d.find(it));
//		fprint(tmp);
		for(auto itx:tmp) for(auto ity:tmp) {
//			cerr<<itx<<' '<<ity<<endl;
			mp[norm(itx,ity)]=1;
		}
	}
	while(q--) {
		int s=read(),t=read();
		s=d.find(a[s]),t=d.find(a[t]); 
//		cerr<<s<<' '<<t<<endl;
		if(s==t) printf("0\n");
		else printf("%d\n",2-mp[norm(s,t)]);
	}
	return FastIO::Fflush(),0;
}