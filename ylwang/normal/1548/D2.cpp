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
#define INF ((1ll<<60)-1)
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
inline int read() {int x; FI(x); return x;}
const int MN=6e3+5;
int n,f[MN][4][4][4],X[MN],Y[MN];
ll C(int x) {
	return 1ll*x*(x-1)/2;		
}
ll sqr(int x) {
	return 1ll*x*x;	
}
ll area(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return abs(x1*y2+x2*y3+x3*y1-x2*y1-x3*y2-x1*y3)&3;
}
 
void works() {
	n=read();
	For(i,1,n) X[i]=read(),Y[i]=read();
	For(i,1,n) For(j,i+1,n) {
		int dx=abs(X[i]-X[j]),dy=abs(Y[i]-Y[j]),d=__gcd(dx,dy)%4;
//		cerr<<i<<' '<<j<<' '<<d<<endl;
		f[i][X[j]%4][Y[j]%4][d]++;
		f[j][X[i]%4][Y[i]%4][d]++;
	}
	ll ans=0,ans1=0,ans2=0;
	For(i,1,n) {
		For(b1,0,3) for(int b2=b1;b2<=3;b2+=2) {
			 
//			For(x1,0,3) For(y1,0,3) for(int x2=(x1&1);x2<=3;x2+=2) for(int y2=(y1&1);y2<=3;y2+=2) {
			For(x1,0,3) For(y1,0,3) For(x2,0,3) For(y2,0,3) {
				if(x1%2!=x2%2||y1%2!=y2%2) continue;
				if(b1==b2&&(x2<x1||x2==x1&&y2<y1)) continue;
				int b3=0; ll o=0;
				if(x1==x2&&y1==y2) {
					b3=0,o=(b1==b2?C(f[i][x1][y1][b1]):1ll*f[i][x1][y1][b1]*f[i][x2][y2][b2]);
				} else {
					b3=2,o=1ll*f[i][x1][y1][b1]*f[i][x2][y2][b2];
				}
//				cerr<<o<<endl;
				int x3=X[i],y3=Y[i];
				int t=abs(x1*y2-x2*y1+x2*y3-x3*y2+x3*y1-x1*y3);
//				cerr<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<' '<<x3<<' '<<y3<<' '<<t<<endl;
				if((t%4)==((b1+b2+b3)%4)) {
//					if(o) cerr<<b1<<' '<<b2<<' '<<b3<<' '<<o<<' '<<f[i][x1][y1][b1]<<' '<<f[i][x2][y2][b2]<<endl;
					if(b1%2==0) ans1+=o;
					else ans2+=o;
				}
			}
		}
	}
	
//	cerr<<ans1<<' '<<ans2<<endl;
	cout<<ans1/3+ans2<<endl;
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
5 5 5
2 3 5 4 3 
2 3 2 2 5 
*/