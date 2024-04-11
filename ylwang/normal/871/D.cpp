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
const int MN=1e7+5;
int n,prime[MN/10],md[MN],cnt=0,sum[MN],phi[MN],suf[MN];
void init(int n=MN-5) {
	phi[1] = 1, md[1] = INF;
	for(int i = 2; i <= n; i++) {
		if(!md[i]) prime[++cnt] = i, phi[i] = i - 1, md[i] = i;
		for(int j = 1; j <= cnt && i * prime[j] <= n; j++) {
			md[i * prime[j]] = prime[j];
			if(i % prime[j] != 0) {
				phi[i * prime[j]] = phi[i] * (prime[j] - 1);
			} else {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
		}
	}
	
	For(i,2,n) sum[md[i]]++;
	foR(i,n,2) suf[i]=suf[i+1]+sum[i];
}
void works() {
	n=read(); init(n);
	int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
	For(i,2,n) cnt1+=i-1-phi[i],cnt2+=phi[i]-1;
//	For(i,2,n) For(j,i+1,n) {
//		if(__gcd(i,j)==1) {
//			cerr<<i<<' '<<j<<endl;
//		}
//	}
	For(i,2,n/2) {
		if(!sum[i])  continue;
		int lw=n/i+1; // i>md[j]>=up
//		cerr<<i<<' '<<lw<<endl;
		if(lw<=i) cnt3+=(suf[lw]-suf[i])*sum[i];
	}
	For(i,n/2+1,n) {
		if(!sum[i])  continue;
		int lw=n/i+1; // i>md[j]>=up
//		cerr<<i<<' '<<lw<<endl;
		if(lw<=i) cnt4+=(suf[lw]-suf[i])*sum[i];
	}
	cnt2-=cnt3+cnt4;
	cerr<<cnt1<<' '<<cnt2<<' '<<cnt3<<' '<<cnt4<<endl;
	cout<<cnt1+cnt2*2+cnt3*3<<endl;
}
signed main() {
	#ifndef ONLINE_JUDGE
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