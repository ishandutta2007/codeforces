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
#define INF (int)((1<<30)-1)
#define int ll
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
const int MN=5e5+5;
int n,m,q,a[MN],f[MN],dep[MN],U[MN],V[MN],ans[MN],ext=0,op;
vi e[MN],g[MN]; int sum[2];
void dfs1(int u,int fa) {
	dep[u]=dep[fa]+1;
	sum[dep[u]&1]+=a[u];
	for(auto i:e[u]) { int v=U[i]==u?V[i]:U[i]; if(v==fa) continue;
		if(!dep[v]) g[v].pb(i),g[u].pb(i),dfs1(v,u);
		else if(dep[v]<dep[u]) {
			if(!((dep[v]-dep[u])&1)) ext=i,op=dep[v]&1;
		}
	}
}
void dfs2(int u,int fa) {
	for(auto i:g[u]) { int v=U[i]==u?V[i]:U[i]; if(v==fa) continue;
		dfs2(v,u); ans[i]=a[v],a[u]-=a[v];
	}
	
}
void works() {
	n=read(),m=read();
	For(i,1,n) a[i]=read();
	For(i,1,m) {
		int u=read(),v=read();
		U[i]=u,V[i]=v;
		e[u].pb(i),e[v].pb(i);	
	}
	dfs1(1,0);
	assert(abs(sum[0]-sum[1])%2==0);
	if(!ext) {
		if(sum[0]!=sum[1]) return printf("NO\n"),void();
	}	else {
			
		if(op==1) {
			ans[ext]=(sum[1]-sum[0])/2;
		} else {
			ans[ext]=(sum[0]-sum[1])/2;
		}
		a[U[ext]]-=ans[ext],a[V[ext]]-=ans[ext];
	}
	printf("YES\n");
	dfs2(1,0); assert(!a[1]);
	For(i,1,m) printf("%lld\n",ans[i]);
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
//	int T=read();
	int T=1;
	while(T--) {
		works();	
	}
	
	return FastIO::Fflush(),0;
}
/*

*/