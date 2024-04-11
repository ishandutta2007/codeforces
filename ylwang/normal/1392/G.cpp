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
const int MN=2e6+5;
const int MM=25;
int n,t,m,X[MN],Y[MN],all; char s[MM];
struct Permu {
	int p[MM];	
	Permu() {
		For(i,1,m) {
			p[i]=i;
		}
	}
	int &operator [] (const int &x) {return p[x];}
}A,B,f[MN];
Permu operator * (Permu a,Permu b) {
	Permu ans;
	For(i,1,m) ans[i]=a[b[i]];
	return ans;	
}
int getnum(Permu tmp) {
	int ans=0;
	For(i,1,m) ans<<=1,ans+=tmp[i];
	return ans;	
}
int f1[MN],f2[MN];
signed main() {
	#ifndef ONLINE_JUDGE
		file("option");
	#endif
	n=read(),t=read(),m=read(); FI(s+1);
	For(i,1,m) A[i]=s[i]-'0'; FI(s+1);
	For(i,1,m) B[i]=s[i]-'0';
	For(i,1,n) {
		int x=read(),y=read(); f[i]=Permu();
		swap(f[i][x],f[i][y]);
		
	}
	f[n+1]=Permu();
	foR(i,n,1) {
		f[i]=f[i]*f[i+1];	
	}
	mst(f1,127/2);
	For(i,1,n+1) {
		ckmin(f1[getnum(A*f[i])],i);
//		cerr<<getnum(A*f[i])<<endl;
		ckmax(f2[getnum(B*f[i])],i);
	}
	foR(st,(1<<m)-1,0) {
		For(i,0,m-1) {
			if(st>>i&1) {
				int to=st^(1<<i);
				ckmin(f1[to],f1[st]);	
				ckmax(f2[to],f2[st]);	
			}
		}
	}
	
	int ans=0,L=1,R=1;
	For(i,0,(1<<m)-1) {
		if(f2[i]-f1[i]>=t) {
			int tmp=__builtin_popcount(i);
			if(tmp>ans) {
//				cerr<<i<<endl;
				ans=tmp;
				L=f1[i],R=f2[i]-1;	
			}
				
		}
	}
	int X=__builtin_popcount(getnum(A)),Y=__builtin_popcount(getnum(B));
	cout<<m+2*ans-X-Y<<endl;
	cout<<L<<' '<<R<<endl;
	return FastIO::Fflush(),0;
}