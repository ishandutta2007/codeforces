#pragma GCC optimize("Ofast")
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
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define Fin(s) freopen(s,"r",stdin)
#define Fout(s) freopen(s,"w",stdout)
#define file(s) Fin(s".in"),Fout(s".out")
#define INF (2e9)
//#define int long long
const int P=1e9+7; //
using namespace std;
template<typename T>void ckmax(T &a,T b) {if(a<b) a=b; ;}
template<typename T>void ckmin(T &a,T b) {if(a>b) a=b; ;}
inline int mul(int a,int b) {return 1ull*a*b%P;}
inline int add(int a,int b) {return a+b>=P?a+b-P:a+b;}
inline int sub(int a,int b) {return a-b>=0?a-b:a-b+P;}
inline void mulmod(int &a,int b) {a=mul(a, b);}
inline void addmod(int &a,int b) {((a+=b)>=P)&&(a-=P);}
inline void submod(int &a,int b) {((a-=b)<0)&&(a+=P);}
void fprint(const int &x,char c=' ') {fprintf(stderr,"%d%c",x,c);}
void fprint(const pii &x,char c=' ') {fprintf(stderr,"{%d,%d}%c",x.first,x.second,c);}
template<typename T> void fprint(const T &f) { for(auto &it:f) fprint(it); fprintf(stderr,"%c",'\n');}
template<typename T> void fprint(const T *f,const int &n) {for(int i=1;i<=n;i++) fprint(f[i]); fprintf(stderr,"%c",'\n');}
inline int ksm(int a,int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
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
inline int read() {int x=0; FI(x);  return x;}
const int MN=1e5+5,MM=205+5; 
int n,m,S[MM][MM],f[MN][MM],ans[MM],siz[MN],t[MN];
int fac[MM<<1],ifac[MM<<1];
int C(int n,int m) {
	if(n<m||n<0||m<0) return 0;
	return 1ll*fac[n]*ifac[m]%P*ifac[n-m]%P;
}
void init(int n) {
	fac[0]=1; For(i,1,n) fac[i]=mul(fac[i-1],i); ifac[n]=inv(fac[n]);
	foR(i,n,1) ifac[i-1]=mul(ifac[i],i);
}
vi e[MN]; 
void dfs(int u,int fa) {
	f[u][0]=2; siz[u]=1; 
	for(auto v:e[u]) {
		if(v==fa) continue; 	
		dfs(v,u); 
		For(i,0,min(m,siz[u]))
			For(j,0,min(m-i,siz[v]))
				addmod(t[i+j],mul(f[u][i],f[v][j]));		
		siz[u]+=siz[v]; 
		For(i,0,min(m,siz[u])) submod(ans[i],f[v][i]),f[u][i]=t[i],t[i]=0; 
	}
	foR(i,min(siz[u],m),1) addmod(ans[i],f[u][i]),addmod(f[u][i],f[u][i-1]);
	submod(f[u][1],1);  
}
void works() {
	n=read(),m=read(); init((MM<<1)-5); 
	For(i,1,n) {
		int u=read(),v=read(); 
		e[u].pb(v),e[v].pb(u); 	
	}
	S[0][0]=1; For(i,1,m) { S[i][0]=0; For(j,1,i) S[i][j]=add(S[i-1][j-1],mul(j,S[i-1][j])); fprint(S[i],m);}
//	For(i,1,n) For(j,0,m)  
	dfs(1,0); int fans=0; 
	For(i,1,m) {
//		cerr<<ans[i]<<endl;
		addmod(fans,mul(mul(S[m][i],fac[i]),ans[i])); 
	}
	cout<<fans<<endl; 
}

signed main() {
	#ifdef wasa855
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	int T=1; 
	while(T--) {
		works(); 
	}
	
	return FastIO::Fflush(),0;
}
/*
  
*/