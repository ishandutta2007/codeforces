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
inline int read() {int x=0; FI(x); return x;}
const int MN=1e6+5;
int n,a[MN],pcnt[MN],s1[MN],top1,s2[MN],top2;
struct SMT {
	int a[MN],b[MN]; 
	void build() {
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
	}
	void upd(int L,int R,int v) {
		for (int i = L; i <= n; i += i & -i) a[i] += v, b[i] += (L - 1) * v;
		for (int i = R + 1; i <= n; i += i & -i) a[i] -= v, b[i] -= R * v;
	}
	int qry(int L,int R) {
		int ans = 0; 
		for (int i = R; i; i -= i & -i) ans += 1ll * a[i] * R - b[i];
		for (int i = L - 1; i; i -= i & -i) ans -= a[i] * (L - 1) - b[i]; 
		return ans;
	}
}tr1,tr2;
void works() {
	n=read(); For(i,1,n) a[i]=read(),pcnt[i]=__builtin_popcountll(a[i]);
//	fprint(pcnt,n);
	int ans=0;
	For(bit,0,60) {
		tr1.build(),tr2.build(); s1[top1=1]=0,s2[top2=1]=0;
		int sum=0;
		For(i,1,n) {
			while(top1>1&&a[s1[top1]]<a[i]) {
				if(pcnt[s1[top1]]==bit) sum-=tr2.qry(s1[top1-1]+1,s1[top1]),tr1.upd(s1[top1-1]+1,s1[top1],-1);
				top1--;	
			}
			s1[++top1]=i; if(pcnt[i]==bit) sum+=tr2.qry(s1[top1-1]+1,s1[top1]),tr1.upd(s1[top1-1]+1,s1[top1],1);
			while(top2>1&&a[s2[top2]]>a[i]) {
				if(pcnt[s2[top2]]==bit) sum-=tr1.qry(s2[top2-1]+1,s2[top2]),tr2.upd(s2[top2-1]+1,s2[top2],-1);
				top2--;	
			}
			s2[++top2]=i; if(pcnt[i]==bit) sum+=tr1.qry(s2[top2-1]+1,s2[top2]),tr2.upd(s2[top2-1]+1,s2[top2],1);
			ans+=sum;
		}
		
	}
	cout<<ans<<endl;
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	works();
//	int T=read();
//	while(T--) {
//		works();	
//	}
	return FastIO::Fflush(),0;
}
/*
  
*/