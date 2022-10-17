#pragma GCC optimize("Ofast")
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
const int P=31607; //
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
inline void fprint(pii x,char c='\n') {fprintf(stderr,"%d %d%c",x.first,x.second,c);}
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
    if(opt>=(SIZE>>1)){fwrite(obuf,1,opt,stdout); opt=0;}
  }
  void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf,1,opt,stdout); opt=0;}}
	void Fflush() {if (opt) fwrite(obuf,1,opt,stdout); opt=0;}
};
inline int read() {int x=0; FI(x); return x;}
const int MN=21,MS=1<<21|1;
int n,a[MN][MN],cof[MN];
int para[MN][MS]; 
pair<int, int> approx(int p, int q, int A) {
  int x = q, y = p, a = 1, b = 0;
  while (x > A) {
    swap(x, y); swap(a, b);
    a -= x / y * b;
    x %= y;
  }
  return make_pair(x, a);
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read(); For(i,0,n-1) cof[i]=1; 
	
	For(i,0,n-1) For(j,0,n-1) {
		a[i][j]=mul(read(),inv(10000));	mulmod(cof[i],a[i][j]);
	}
//	For(i,0,n-1) fprint(a[i]-1,n);
	For(i,0,n-1) { para[i][0]=1;
		For(st,1,(1<<n)-1) {
			int lbt=__builtin_ctz(st),lst=st-(st&-st);
//			cerr<<st<<' '<<lbt<<' '<<lst<<endl;
			para[i][st]=mul(para[i][lst],a[lbt][i]);
		}
//		fprint(para[i]-1,(1<<n));
	}
	int fans=0,U=(1<<n)-1;
	For(tst,0,(1<<(n+2))-1) {
		int st=tst&U,x1=tst>>n&1,x2=tst>>(n+1)&1;
		int ok=U^st; int ans=1;
//		cerr<<"solve "<<tst<<' '<<x1<<' '<<x2<<endl; 
//		fprint(approx(P,ans,100));
		For(i,0,n-1) {
			int to=ok;
			if(x1) to&=~(1<<i);
			if(x2) to&=~(1<<(n-1-i));
			mulmod(ans,mul(para[i][U^to],sub(1,para[i][to])));  
		}
		
//		fprint(approx(P,ans,100));
		if(__builtin_popcount(tst)&1) submod(fans,ans);
		else addmod(fans,ans);
	}
	cout<<sub(1,fans)<<endl;
	return FastIO::Fflush(),0;
}