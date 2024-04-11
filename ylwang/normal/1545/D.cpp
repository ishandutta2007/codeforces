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
inline int read() {int x; scanf("%lld",&x); return x;}
const int MN=1e3+5;
int a[MN][MN],n,m,sum[MN],s[MN];
int x[4];
int sqr(int x) {
	return x*x;	
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	m=read(),n=read();
	For(i,1,n) For(j,1,m) {
		a[i][j]=read(),sum[i]+=a[i][j];	
		s[i]+=a[i][j]*a[i][j];
	}
//	For(i,1,m) sum[i]+=sum[i-1];
	int del=(sum[n]-sum[1])/(n-1),pos=1;
//	cerr<<del<<' '<<sum[n]-sum[1]<<endl;
//	fprint(sum,n);
	while(pos<=n) {
		if(sum[pos+1]!=sum[pos]+del) {
			break;
		} pos++;
		
	} pos++;
//	cerr<<pos<<endl;
	int now=1;
	For(i,1,3) {
		now++; if(now==pos) now++;
		x[i]=now;
	}
	int A=0,B=0,C=s[1]; int x1=x[1]-1,x2=x[2]-1;
//	cerr<<x1<<' '<<x2<<' '<<(x1*x1*x2-x1*x2*x2)<<endl;
	
	A=((s[x1+1]-C)*x2-(s[x2+1]-C)*x1)/(x1*x1*x2-x1*x2*x2);
	B=(s[x1+1]-C-A*x1*x1)/x1;
//  cerr<<A<<' '<<B<<' '<<C<<' '<<x1<<endl;
	int val=A*(pos-1)*(pos-1)+B*(pos-1)+C,shd=sum[1]+(pos-1)*del;
	For(j,1,m) {
		int nw=shd-(sum[pos]-a[pos][j]);
//  	cerr<<sqr()<<endl;
//  	cerr<<j<<' '<<nw<<' '<<s[pos]-sqr(a[pos][j])+sqr(nw)<<endl;
		if(val==s[pos]-sqr(a[pos][j])+sqr(nw)) {
			cout<<pos-1<<' '<<nw<<endl;
			return 0;
		}
	}
	return FastIO::Fflush(),0;
}