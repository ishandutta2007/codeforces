#include<bits/stdc++.h>
#define ll long long
#define pb push_back
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
#define INF ((1ll<<60)-1)
#define int long long
int P=1e9+7; //
struct FastMod {
	typedef __uint128_t lll;
	ull b,m; void init(ull b) {this->b=b,m=(ull)((lll(1)<<64)/b);} ull operator()(ull a) { ull q=(ull)((lll(m)*a)>>64),r=a-q*b; return r>=b?r-b:r; }
}M;
using namespace std;
template<typename T>inline void ckmax(T &a,T b) {(a<b)&&(a=b);}
template<typename T>inline void ckmin(T &a,T b) {(a>b)&&(a=b);}
inline int mul(int a,int b) {return M(1ull*a*b);}
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
const int MN=85;
int n,m,c[MN][MN],tot[MN][MN],pw[MN*MN],g[MN][MN],f[MN][MN];
int down(int x,int y) {
	int ans=1;
	for(int i=x;i>=x-y+1;i--) mulmod(ans,i);	 return ans;
}
void init(int n) {
	pw[0]=1; For(i,1,n*n) pw[i]=mul(pw[i-1],2);
	For(i,0,n) { c[i][0]=1; For(j,1,i) c[i][j]=add(c[i-1][j-1],c[i-1][j]); }
	For(i,0,n) For(j,0,n) {
		tot[i][j]=pw[j*i],g[i][j]=down(pw[j]-1,i);
		For(k,0,j-1) submod(tot[i][j],mul(c[j][k],tot[i][k]));
		For(k,0,j-1) submod(g[i][j],mul(c[j][k],g[i][k]));
		cerr<<i<<' '<<j<<' '<<tot[i][j]<<' '<<g[i][j]<<endl;
	}
	
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read(),m=read(); P=read(); M.init(P);
	init(max(n,m));
	For(i,1,n) For(j,0,m) For(ii,0,i-1) For(jj,0,j-1) {
		if((n&1)&&i==n&&ii==i-1) continue;
		int para=mul(mul(mul(c[i][ii],c[j][jj]),pw[(i-ii)*jj]),g[i-ii][j-jj]);
		addmod(f[i][j],mul(para,sub(tot[ii][jj],f[ii][jj]))); 
//		cerr<<tot[ii][jj]<<' '<<f[ii][jj]<<endl;
	}
	int ans=0;
	For(i,0,m) addmod(ans,mul(c[m][i],sub(tot[n][i],f[n][i])));
	cout<<ans<<endl;
	return FastIO::Fflush(),0;
}