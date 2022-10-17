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
const int MN=2e3+5;
int n,m,deg[MN],p[MN],a[MN][MN],mn=INF,cnt=0;
void ck(int val) {
	For(i,1,n) deg[i]=0;
	For(i,1,n) For(j,1,n) deg[i]+=a[i][j];
	sort(p+1,p+1+n,[&](int i,int j){return deg[i]<deg[j];});
	int ok=1,sum=0;
	For(i,1,n-1) {
		sum+=deg[p[i]];
//		cerr<<i<<' '<<sum<<endl;
		if(sum==i*(i-1)/2) ok=0;
	}
	if(ok) {
		if(val<mn) mn=val,cnt=1;
		else if(val==mn) cnt++;
	}
}
void dfs(int u,int sm) {
	if(u==n+1) return ck(sm); 
	dfs(u+1,sm);
	For(i,1,n) if(u!=i) a[u][i]^=1,a[i][u]^=1; 
	dfs(u+1,sm+1);
	For(i,1,n) if(u!=i) a[u][i]^=1,a[i][u]^=1; 
}
int fac[MN],ifac[MN];
int C(int n,int m) {
	if(n<m||n<0||m<0) return 0;
	return 1ll*fac[n]*ifac[m]%P*ifac[n-m]%P;
}
void init(int n=MN-5) {
	fac[0]=1; For(i,1,n) fac[i]=mul(fac[i-1],i); ifac[n]=inv(fac[n]);
	foR(i,n,1) ifac[i-1]=mul(ifac[i],i);
}

signed main() {
	#ifdef wasa855
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	init();
	n=read();
	For(i,1,n) {
		p[i]=i;
		char s[MN]; FI(s+1);
		For(j,1,n) {
			a[i][j]=s[j]-'0',deg[i]+=a[i][j];
		}
	}
	if(n<=6) {
		dfs(1,0);
		if(mn==INF) printf("-1\n"); 
		else cout<<mn<<' '<<mul(cnt,fac[mn])<<endl;	
	} else {
		int cnt=0;
		sort(p+1,p+1+n,[&](int i,int j){return deg[i]<deg[j];});
		int ok=1,sum=0;
		For(i,1,n-1) {
			sum+=deg[p[i]];
			if(sum==i*(i-1)/2) ok=0;
		}
		if(ok) return printf("0 1\n"),0;
		For(i,1,n) {
			For(j,1,n) {
				if(a[i][j]) deg[i]--,deg[j]++;
				else deg[i]++,deg[j]--;
			}	
			sort(p+1,p+1+n,[&](int i,int j){return deg[i]<deg[j];});
			int ok=1,sum=0;
			For(i,1,n-1) {
				sum+=deg[p[i]];
				if(sum==i*(i-1)/2) ok=0;
			}
			For(j,1,n) {
				if(a[i][j]) deg[j]--,deg[i]++;
				else deg[j]++,deg[i]--;
			}	
			cnt+=ok;
		}
		cout<<1<<' '<<cnt<<endl; 
	}
	return FastIO::Fflush(),0;
	
}
/*

*/