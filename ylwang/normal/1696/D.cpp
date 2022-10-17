#pragma GCC optimize("Ofast")
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
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define Fin(s) freopen(s,"r",stdin)
#define Fout(s) freopen(s,"w",stdout)
#define file(s) Fin(s".in"),Fout(s".out")
#define INF (2e9)
#define int long long
const int P=1e9+7; //
using namespace std;
template<typename T>void ckmax(T &a,T b) {if(a<b) a=b; ;}
template<typename T>void ckmin(T &a,T b) {if(a>b) a=b; ;}
inline int mul(int a,int b) {return 1ull*a*b%P;}
inline int add(int a,int b) {return a+b>=P?a+b-P:a+b;}
inline int sub(int a,int b) {return a-b>=0?a-b:a-b+P;}
inline void mulmod(int &a,int b) {a=mul(a, b);}
inline void addmod(int &a,int b) {((a+=b)>=P)&&(a-=P);}
inline void submod(int &a,int b) {((a-=b)<0)&&(a+=P);}
void fprint(const int &x,char c=' ') {fprintf(stderr,"%d%c",x,c);}
void fprint(const pii &x,char c=' ') {fprintf(stderr,"{%d,%d}%c",x.first,x.second,c);}
template<typename T> void fprint(const T &f) { for(auto &it:f) fprint(it); fprintf(stderr,"%c",'\n');}
template<typename T> void fprint(const T *f,const int &n) {for(int i=1;i<=n;i++) fprint(f[i]); fprintf(stderr,"%c",'\n');}
inline int ksm(int a,int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
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
inline int read() {int x=0; FI(x);  return x;}
const int MN=5e5+5; 
int a[MN],b[MN],n; 
int sta[MN],ta,stb[MN],tb,f[MN]; 
struct SMT {
	static const int N=MN<<2; 
	#define ls (k<<1)
	#define rs (k<<1|1)
	#define mid ((l+r)>>1) 
	int mn[N]; 
	void upd(int k,int l,int r,int p,int v) {
		if(l==r) return mn[k]=v,void();
		p<=mid?upd(ls,l,mid,p,v):upd(rs,mid+1,r,p,v); 
		mn[k]=min(mn[ls],mn[rs]);  
	}
	int qry(int k,int l,int r,int ql,int qr) {
		if(l>qr||r<ql) return INF; if(ql<=l&&r<=qr) return mn[k]; 
		return min(qry(ls,l,mid,ql,qr),qry(rs,mid+1,r,ql,qr)); 
	}
	void clear(int n) {
		For(i,1,(n<<2)+5) mn[i]=INF; 
	}
} tr1,tr2; 
void works() {
	n=read(); For(i,1,n) a[i]=read(),b[i]=n-a[i]+1; 
	sta[ta=1]=n+1,stb[tb=1]=n+1; tr1.clear(n),tr2.clear(n); 
	f[n]=0; 
	foR(i,n,1) {
		while(ta>1&&a[sta[ta]]>a[i]) tr1.upd(1,1,n,sta[ta--],INF); //  
		while(tb>1&&a[stb[tb]]<a[i]) tr2.upd(1,1,n,stb[tb--],INF); // 
		if(i!=n) f[i]=min(tr1.qry(1,1,n,i+1,stb[tb]-1),tr2.qry(1,1,n,i+1,sta[ta]-1))+1;
		sta[++ta]=stb[++tb]=i; 
		tr1.upd(1,1,n,i,f[i]),tr2.upd(1,1,n,i,f[i]); 
	}
	cout<<f[1]<<endl; 
}
signed main() {
	#ifdef wasa855
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	int T=read(); 
	while(T--) {
		works(); 
	}
	
	return FastIO::Fflush(),0;
}
/*
  
*/