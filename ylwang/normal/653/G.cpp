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
inline int read() {int x=0; FI(x); return x;}
const int MN=1e6+5;
int n; vi a[MN];
int fac[MN],ifac[MN];
int C(int n,int m) {
	if(n<m||n<0||m<0) return 0;
	return 1ll*fac[n]*ifac[m]%P*ifac[n-m]%P;
}
void init(int n=MN-5) {
	fac[0]=1; For(i,1,n) fac[i]=mul(fac[i-1],i); ifac[n]=inv(fac[n]);
	foR(i,n,1) ifac[i-1]=mul(ifac[i],i);
}
int cnt[65],ans=0,s[MN];
void solve(vi &a) {
	for(auto it:a) { cnt[it]++; } 
	if(a.size()!=::n) cnt[0]=::n-a.size(),a.pb(0);
	sort(a.begin(),a.end()); a.erase(unique(a.begin(),a.end()),a.end());
	int n=a.size(),sans=0; vi b=a;
	For(i,0,n-1) a[i]=cnt[a[i]];
	For(i,1,n-1) a[i]+=a[i-1];
	For(i,0,n-2) {
		int L=a[i],R=::n-a[i];
		int pans=0;
		For(y,0,R) s[y]=C(R,y); foR(y,R-1,0) addmod(s[y],s[y+1]); 
		For(x,0,min(L,R)) addmod(pans,mul(mul(C(L,x),x),s[x]));
		s[0]=ksm(2,L)-1; For(x,1,min(L-1,R)) s[x]=sub(s[x-1],C(L,x));
		For(y,0,min(L-1,R)) {
			int para=0; For(x,y+1,L) addmod(para,C(L,x));
			addmod(pans,mul(mul(C(R,y),y),s[y]) );
		}
		addmod(sans,mul(b[i+1]-b[i],pans));
	}
	addmod(ans,sans);
	for(auto it:b) cnt[it]=0;
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("game.in","r",stdin);
		freopen("game.out","w",stdout);
	#endif
	n=read(); init();
	For(i,1,n) {
		int x=read();
		for(int j=2;j*j<=x;j++) {
			int cnt=0;
			while(x%j==0) cnt++,x/=j;
			if(cnt>0) {
				a[j].pb(cnt);
			}
		}
		if(x!=1) a[x].pb(1);	
	}
	For(i,2,1000000) {
		if(a[i].size()) solve(a[i]);
	}
	cout<<ans<<endl;
	return FastIO::Fflush(),0;
}