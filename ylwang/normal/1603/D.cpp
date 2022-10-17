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
const int MN=1e5+5;
int sp[MN],prime[MN],tot,vis[MN];
void init(int n=MN-5) {
	For(i,2,n) {
		if(!vis[i]) prime[++tot]=i,sp[i]=i-1;
		for(int j=1;j<=tot&&i*prime[j]<=n;j++) {
			int tar=i*prime[j]; vis[tar]=1;
			if(i%prime[j]==0) {
				sp[tar]=sp[i]*prime[j];
				break;
			} else {
				sp[tar]=sp[i]*(prime[j]-1);
			}	
		}
	}
//	fprint(sp,n);
	sp[1]=1; For(i,2,n) sp[i]+=sp[i-1];
	
}
const int n=1e5,B=320;
int s1[MN][325],s2[MN][325],s3[MN];
int c(int l,int r) {
//	int fans=0;
//	For(i,l,r) For(j,i,r) {
//		fans+=__gcd(i,j)>=l;
//	}
	int fans2=0;
	For(i,l,r) {
		fans2+=sp[r/i];
	}
	int nxt=r/(r/l)+1,lst=r/(r/l+1)+1,ext=(nxt-l)*sp[r/l];
	int ans=lst<=B?s3[r]-s1[r][lst]+ext:s3[r]-s2[r][r/lst]+ext;
//	assert(ans==fans2);
	return ans;
}
int f[18][MN];
void doit(int *f,int *g,int l,int r,int L,int R) {
	if(l>r) return;
//	cerr<<l<<' '<<r<<' '<<L<<' '<<R<<endl;
	int mid=(l+r)>>1,mnp=0,mnv=INF;	
	For(i,L,min(mid,R)) {
		int t=g[i-1]+c(i,mid);
//		cerr<<i<<' '<<mid<<' '<<c(i,mid)<<endl;
		if(t<mnv)
			mnv=t,mnp=i;
	}
	f[mid]=mnv;
//	cerr<<mid<<' '<<mnv<<' '<<mnv<<endl;
	doit(f,g,l,mid-1,L,mnp);
	doit(f,g,mid+1,r,mnp,R); 
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	init();
//	cerr<<"?";
	For(i,1,n) {
		int op=0,lst=0;
		for(int l=1,r;l<=i;l=r+1) {
			int v=i/l;
			r=i/v; 
			int val=sp[v]*(r-l+1);
			s3[i]+=val;
			if(l<=B) s1[i][l]=s1[i][lst]+val,lst=l;
			else {
				if(!op) s2[i][v]=s1[i][lst]+val,op=1;
				else s2[i][v]=s2[i][lst]+val;
				lst=v;
			}
		}
	}
	
//	cerr<<"?";
//	For(i,1,10) For(j,i+1,10) {
//		cerr<<c(i,j)<<endl;
//	}
	For(i,1,n) f[0][i]=INF;
	For(i,1,17) {
		doit(f[i],f[i-1],1,n,1,n);
		fprint(f[i],10);
	}
	int T=read();
	while(T--) {
		int N=read(),K=read();
		if(K>17) FO(N),FO('\n');
		else FO(f[K][N]),FO('\n'); 
	}
	return FastIO::Fflush(),0;
}