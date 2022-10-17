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

const int MN=1e6+5;
int n,K,ans[MN]; char s[MN];
#define ls (u<<1)
#define rs (u<<1|1)
#define fa (u>>1)
#define mid ((l+r)>>1)
int dfs(int u,int l=0,int r=0) {
//	cerr<<u<<' '<<l<<' '<<r<<endl;
	if(ans[u]!=-1) return ans[u];
	if(s[u]=='?') ans[u]=dfs(ls,l,mid)+dfs(rs,mid+1,r);
	if(s[u]=='0') ans[u]=dfs(rs,mid+1,r);
	if(s[u]=='1') ans[u]=dfs(ls,l,mid);
	return ans[u];
}
void modify(int u) {
	while(u) {
//		cerr<<u<<endl;
		if(s[u]=='?') ans[u]=ans[ls]+ans[rs];
		if(s[u]=='0') ans[u]=ans[rs];
		if(s[u]=='1') ans[u]=ans[ls];
		u=fa;
	}
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	K=read(),n=(1<<K); FI(s+1);
	reverse(s+1,s+n);
	mst(ans,-1);
	For(i,n,(n<<1)-1) ans[i]=1;
//	cerr<<n<<endl;

	
	For(i,1,n-1) {
		if(ans[i]==-1) dfs(i);
	}
//	For(i,1,(n<<1)-1) cerr<<ans[i]<<' ';
//	cerr<<endl;
	int Q=read();
	while(Q--) {
		int x=n-read(); char o[55]; FI(o); char c=o[0],tmp=s[x];;
		
		s[x]=c; modify(x); 
//		cerr<<s+1<<endl;
		printf("%d\n",ans[1]); 
//		s[x]=tmp; modify(x);
//		For(i,1,n-1) cerr<<ans[i]<<' ';
//		cerr<<endl;
//		cerr<<(s+1)<<endl;
	}
	return FastIO::Fflush(),0; 
}
/*

*/