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
int n,K,f[MN],down[MN],dep[MN],hson[MN],len[MN],p[MN],R,B,W,cs[MN];
vi e[MN];
void dfs1(int u,int fa) {
	f[u]=fa,dep[u]=dep[fa]+1;
	for(auto v:e[u]) { if(v==fa) continue;
		dfs1(v,u); ckmax(down[u],down[v]+1);
		if(!hson[u]||down[v]>down[hson[u]]) hson[u]=v;
	}
}
void dfs2(int u,int len) {
	::len[u]=len; if(!hson[u]) return;
	::len[u]=-1+dep[u]-n;
	dfs2(hson[u],len+1); for(auto v:e[u]) if(v!=f[u]&&v!=hson[u]) dfs2(v,0);
}
void getB(int u,int fa) {
	int op=!cs[u];
	for(auto v:e[u]) { if(v==fa) continue;
		getB(v,u),cs[u]+=cs[v];
	}
	if(op) cs[u]?W++:B++;
}
void works() {
	n=read(),K=read();
	For(i,1,n-1) {
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);	
	}
	dfs1(1,0); dfs2(1,0); For(i,1,n) p[i]=i; sort(p+1,p+1+n,[&](int x,int y){return len[x]>len[y];});
	For(i,1,K) if(len[p[i]]>=0) R+=cs[p[i]]=1;
//	fprint(len,n);
//	cerr<<W<<' '<<B<<' '<<R<<endl;
	getB(1,0);
	while(R<K&&(W-1)*(R+1-B)>=W*(R-B)) W--,R++;
	while(B&&(W+1)*(R+1-B)<=W*(R-B)) W++,B--;
	cout<<W*(R-B)<<endl;
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
//	init();
//	int T=read();
	int T=1;
	while(T--) {
		works();	
	}
	return FastIO::Fflush(),0;
}
/*
  
*/