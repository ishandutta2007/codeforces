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
#define INF ((1ll<<60)-1) 
#define int long long
const int P=1e9+7; //
using namespace std;
template<typename T>void ckmax(T &a,T b) {a=max(a,b);}
template<typename T>void ckmin(T &a,T b) {a=min(a,b);}
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
	bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n) return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) if(str[i]=='?') return x=INF,1; else x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
	void write(int x) {
		if(!x) obuf[opt++]='0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
		if (opt>=(SIZE>>1)){fwrite(obuf,1,opt,stdout); opt=0;}
	}
	void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf,1,opt,stdout); opt=0;}}
	void Fflush() {if (opt) fwrite(obuf,1,opt,stdout); opt=0;}
};
inline int read() {int x=0; FI(x); return x;}
const int MN=3e5+5,MM=1e6+5;
int n,C,v[MM+5],t[MM+5],fans[MN],lim;
pii q[MN]; vi d[MM+5]; 
void works() {
	n=read(),lim=read();
	For(i,1,lim) {
		v[i]=-INF; 
		for(int j=i;j<=lim;j+=i) {
			d[j].pb(i);
		}
	}
	For(i,1,n) {
		int x=read(),y=read(),h=read();
		ckmax(v[x],y*h);
	}
	int m=read();
	For(i,1,m) q[i]=mkp(read()*read(),i);
	sort(q+1,q+1+m);
	t[0]=0; 
	For(i,1,lim) {
		t[i]=t[i-1];
		for(auto j:d[i]) {
			if(v[j]>0) {
				ckmax(t[i],v[j]*(i/j));	
			}
			
		}
	}
	int nowans=1;
	For(i,1,m) {
		while(nowans<=lim&&t[nowans]<=q[i].first) {
			nowans++;
		}
		fans[q[i].second]=nowans>lim?-1:nowans;
	}
	For(i,1,m) {
		printf("%lld ",fans[i]);	
	}
	printf("\n");
//	while(m--) {
//		int x=read()*read();	
//		sort(p+1,p+1+n,[&](int i,int j){return ((__int128)x/a[i])*b[i]+b[i]<((__int128)x/a[j])*b[j]+b[j];} );
//		int ans=((__int128)x/a[p[1]])*b[p[1]]+b[p[1]];
//		printf("%lld ",(ans>C)?-1:ans);
//	}
//	printf("\n");
	 
}

signed main() {
	#ifdef wasa855
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