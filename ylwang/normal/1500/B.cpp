#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
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
inline int mul(int a,int b) {return 1ll*a*b%P;}
inline int add(int a,int b) {return a+b>=P?a+b-P:a+b;}
inline int sub(int a,int b) {return a-b>=0?a-b:a-b+P;}
inline void mulmod(int &a,int b) {a=mul(a, b);}
inline void addmod(int &a,int b) {((a+=b)>=P)&&(a-=P);}
inline void submod(int &a,int b) {((a-=b)<0)&&(a+=P);}
inline void fprint(const vector<int> &f) {for(int i=0;i<f.size();i++) fprintf(stderr,"%d ",f[i]); fprintf(stderr,"\n");}
inline int ksm(int a,int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline int inv(int a) {return ksm(a,P-2);}
namespace FastIO {
  const int SIZE=1<<16; char buf[SIZE],obuf[SIZE],str[64]; int bi=SIZE,bn=SIZE,opt;
  int read(char *s) {
    while (bn) {for (;bi<bn&&buf[bi]<=' ';bi++);if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}
    int sn=0;while (bn) {for (;bi<bn&&buf[bi]>' ';bi++) s[sn++]=buf[bi];if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}s[sn]=0;return sn;
  }
  bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n) return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
  
  void write(ll x) {
    if(!x) obuf[opt++]='0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
    if (opt>=(SIZE>>1)){fwrite(obuf,1,opt,stdout); opt=0;}
  }
  void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf,1,opt,stdout); opt=0;}}
	void Fflush() {if (opt) fwrite(obuf,1,opt,stdout); opt=0;}
};
inline int read() {int x; FI(x); return x;}
const int MN=2e6+5;
int n,m,k,a[MN],b[MN];

inline int exgcd(int a, int b, int &x, int &y) {
	if(!b) return x = 1, y = 0, a;
	int d = exgcd(b, a % b, y, x); y -= a / b * x; return d;
}
int solve(int a, int c, int p) {
	int x, y, d = exgcd(a, p, x, y);
	if(c % d) return -1; int m = c / d;
	x *= m, y *= m; int t = p / d;
	return x = (x % t + t) % t;
}
inline int lcm(int a, int b) {
	return a / __gcd(a, b) * b;
}
int excrt(int *A,int *B,int n) { // A: 
	int nB = 0, nA = 1;
	For(i, 0, n - 1) {
		int t = solve(nA, B[i] - nB, A[i]);
		if(t == -1) return -1;
		nB = (t * nA + nB) % lcm(nA, A[i]); nA = lcm(nA, A[i]);
	}
	return nB;
}
int pos1[MN],pos2[MN],v[MN];
int calc(int k) {
	int t=lcm(n,m),ans=k;
	For(i,1,2*max(n,m)) {
		if(v[i]==-1||v[i]>=k) continue;
		ans-=(k-1-v[i])/t+1;
//		cerr<<k<<' '<<i<<' '<<v[i]<<endl;
	}
//	cerr<<k<<' '<<ans<<endl;
	return ans;
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);    
	#endif
	n=read(),m=read(),k=read();
	mst(pos1,-1),mst(pos2,-1);
	For(i,0,n-1) {
		pos1[a[i]=read()]=i;
	}
	For(i,0,m-1) {
		pos2[b[i]=read()]=i;	
	}
	
	For(i,1,2*max(n,m)) {
		v[i]=-1;
		if(pos1[i]==-1||pos2[i]==-1) continue;
		int A[2]={n,m},B[2]={pos1[i]%n,pos2[i]%m}; 
		v[i]=excrt(A,B,2);
//		cerr<<i<<' '<<v[i]<<endl;
	}
	int l=1,r=1e18,ans=0;
	while(l<=r) {
		int mid=((l+r)>>1);
		if(calc(mid)<k) {
			l=mid+1;
		} else r=mid-1,ans=mid;
	}
	cout<<ans<<endl;
	return FastIO::Fflush(),0;		
}
/*
L2 L1 R1 R2
0. Enough array size? Enough array size? Integer overflow?

1. Think TWICE, Code ONCE!
Are there any counterexamples to your algo?

2. Be careful about the BOUNDARIES!
N=1? P=1? Something about 0?

3. Do not make STUPID MISTAKES!
Time complexity? Memory usage? Precision error?
*/