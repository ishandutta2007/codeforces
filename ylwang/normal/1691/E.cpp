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
#define int long long
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
const int MN=4e5+5; 
int disc[MN],t,n; 
vector<pii>qr; 
struct DSU {
	static const int N=MN;
	int f[N],sz[N]; DSU() {For(i,0,N-5) f[i]=i,sz[i]=1;}
	void init(int n) {For(i,0,n) f[i]=i,sz[i]=1;}
	inline int find(int x) {return x==f[x]?x:f[x]=find(f[x]);}
	inline int merge(int x,int y) {
		x=find(x),y=find(y);
		if(x==y) return 0;
		return f[x]=y,sz[y]+=sz[x],1;
	}
}dsu;
struct node {
	int l,r,c; 
	node(){} 
} a[MN]; 
void works() {
	n=read(); 
	For(i,1,n) {
		a[i].c=read();
		disc[++t]=a[i].l=read(),disc[++t]=a[i].r=read();
//		cerr<<a[i].c<<' '<<a[i].l<<' '<<a[i].r<<endl; 
//		disc[++t]=a[i].l-1,disc[++t]=a[i].r+1; 
//		disc[++t]=a[i].l+1,disc[++t]=a[i].r-1;
	}
	sort(disc+1,disc+1+t); t=unique(disc+1,disc+1+t)-disc-1; 
//	fprint(disc,t); 
	For(i,1,n) a[i].l=lower_bound(disc+1,disc+1+t,a[i].l)-disc; 
	For(i,1,n) a[i].r=lower_bound(disc+1,disc+1+t,a[i].r)-disc; 
//	For(i,1,n) {
//		cerr<<a[i].l<<' '<<a[i].r<<' '<<a[i].c<<endl;	
//	}
	For(i,1,n) qr.pb(mkp(a[i].l,-i)),qr.pb(mkp(a[i].r,i)); 
	sort(qr.begin(),qr.end()); 
	dsu.init(n); 
	set<pii>s[2];  
	for(auto it:qr) {
		int i=abs(it.second); 
		if(it.second<0) {
			s[a[i].c].insert(mkp(a[i].r,i));
			int t=a[i].c^1;
			if(SZ(s[t])) {
				
				while(SZ(s[t])>1)
					dsu.merge(s[t].begin()->second,i),s[t].erase(s[t].begin());	
				dsu.merge(s[t].begin()->second,i);
			}
				
		} else {
			s[a[i].c].erase(mkp(a[i].r,i));
		}
	}	
	qr.clear(); t=0; 
	int ans=0;  
	For(i,1,n) ans+=dsu.find(i)==i; 
	cout<<ans<<endl;
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