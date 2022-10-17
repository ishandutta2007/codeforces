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
#define INF ((1<<30)-1)
#define int __int128
const int P=998244353; //
using namespace std;
template<typename T>void ckmax(T &a,T b) {(a<b)&&(a=b);}
template<typename T>void ckmin(T &a,T b) {(a>b)&&(a=b);}
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
inline int read() {int x=0; FI(x); return x;}
const int MN=1e6+5,lim=1e14;
int a[MN],n,m1,m2,b[MN],c[MN];
int calc(int t) {
	m1=m2=0;
	For(i,1,n) {
		if(a[i]+t<0) b[++m1]=a[i]+t;
		else c[++m2]=a[i]+t;
	}
	int ans=0;
	if(!m1) {
		For(i,2,m2) ans+=c[1]*c[i];
	} else if(!m2) {
		For(i,1,m1-1) ans+=b[m1]*b[i];	
	} else {
		For(i,1,m1) ans+=c[m2]*b[i];	
		For(i,1,m2-1) ans+=b[1]*c[i];
	}
//	cerr<<t<<' '<<ans<<' '<<ans-t*t*(n-1)<<endl;
	return ans-t*t*(n-1); 
}
void works(int td) {
	n=read();
	For(i,1,n) a[i]=read(); 
	sort(a+1,a+1+n);
	For(i,-10,10) calc(i);
	int l=-lim,r=lim;
	while(l<r) {
		int mid=(l+r)>>1;
		int lv=calc(mid),rv=calc(mid+1);
		if(lv<=rv) {
			l=mid+1;	
		} else {
			r=mid;
		}	
	}
	
//	cerr<<l<<' '<<calc(l)<<' '<<calc(l+1)<<endl;
	if((l==lim&&calc(l+1)!=calc(l))||(l==-lim&&(calc(l-1)!=calc(l)))) {
		FO('I'),FO('N'),FO('F'),FO('\n');	
	} else {;
		FO(calc(l));	FO('\n');
	}
}

signed main() {
	#ifdef wasa855
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	int T=read();
	For(td,1,T) {
		works(td);	
	}
	return FastIO::Fflush(),0;
}
/*
  
*/