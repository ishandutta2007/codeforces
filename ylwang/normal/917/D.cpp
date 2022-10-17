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
inline int read() {int x; FI(x); return x;}
const int MN=8e3+5;
int fac[MN],ifac[MN];
int C(int n,int m) {
	if(n<m||n<0||m<0) return 0;
	return 1ll*fac[n]*ifac[m]%P*ifac[n-m]%P;
}
void init(int n=MN-5) {
	fac[0]=1; For(i,1,n) fac[i]=mul(fac[i-1],i); ifac[n]=inv(fac[n]);
	foR(i,n,1) ifac[i-1]=mul(ifac[i],i);
}
int n; vi e[MN],f[MN],g[MN];
int tf[MN],tg[MN],siz[MN];
void dfs(int u,int fa) {
//	cerr<<u<<endl;

	f[u].resize(2),g[u].resize(2);
	f[u][1]=1,g[u][1]=1; siz[u]=1; 
	for(auto v:e[u]) { if(v==fa) continue; dfs(v,u);
		
		foR(i,siz[u],1) foR(j,siz[v],1) {
			addmod(tf[j+i],mul(f[u][i],g[v][j]));
			addmod(tg[j+i],mul(g[u][i],g[v][j]));
			addmod(tf[j+i-1],mul(f[u][i],f[v][j]));
			addmod(tg[j+i-1],add(mul(g[u][i],f[v][j]),mul(f[u][i],g[v][j])));
		}
		siz[u]+=siz[v];
		f[u].resize(siz[u]+1),g[u].resize(siz[u]+1);
		f[v].clear(); f[v].shrink_to_fit();
		g[v].clear(); g[v].shrink_to_fit();
		For(i,1,siz[u]) f[u][i]=tf[i],g[u][i]=tg[i],tf[i]=0,tg[i]=0;
	}		
}
int ans[MN];
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("tree.in","r",stdin);
		freopen("tree.out","w",stdout);
	#endif
	n=read(); if(n==1) return printf("1\n"),0; init(n);
	For(i,1,n-1) {
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
//		cerr<<u<<' '<<v<<endl;	
	}
	dfs(1,0);
	For(i,0,n-2) {
		ans[i]=mul(g[1][n-i],ksm(n,n-i-2));
	}
	ans[n-1]=1;
	foR(i,n-1,0) {
		For(j,i+1,n-1) {
			submod(ans[i],mul(ans[j],C(j,i)));
		}
	}
	For(i,0,n-1) printf("%d ",ans[i]);
	printf("\n");
	return FastIO::Fflush(),0;
}

/*
*/