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
//#define int long long
const int P=998244353; //
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
inline int read() {int x=0; FI(x); return x;}
const int MN=75; 
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
}d;

int n,d1[MN][MN],d2[MN][MN],t,m,a,b,id[MN];
vector<pii> e[MN];
int f[1<<17][MN],bel[MN]; 
struct ele {
	int x,y,z;
	ele(){} ele(int X,int Y,int Z):x(X),y(Y),z(Z){}
	bool operator < (const ele &b) const {
		return z>b.z; 
	}
};

void works() {
	n=read(),m=read(),a=read(),b=read(); 
	d.init(n); 
	For(i,1,m) {
		int u=read(),v=read(),w=read();
		e[u].pb(mkp(v,w)),e[v].pb(mkp(u,w)); 
		if(w==a) d.merge(u,v); 
	}
	mst(id,-1); 
	For(i,1,n) if(d.find(i)==i&&d.sz[i]>=4) id[i]=t++;  
	For(i,1,n) id[i]=id[d.find(i)];
	For(i,0,(1<<t)-1) For(j,1,n) f[i][j]=INF; f[0][1]=0;   
//	fprint(id,n); 
//	cerr<<t<<endl;
	priority_queue<ele>q; q.push(ele(0,1,0));
	For(i,1,n) bel[i]=d.find(i); 
	while(SZ(q)) { 
		int st=q.top().x,u=q.top().y,d=q.top().z; q.pop(); 
//		cerr<<f[st][u]<<' '<<d<<endl;
		if(f[st][u]<d) continue; 
		for(auto it:e[u]) {
			int v=it.first,w=it.second; 
			if(w==b&&(((~id[v])&&(st>>id[v]&1))||(bel[u]==bel[v]))) continue; 
			int nst=st|(((id[u]==-1)||w==a)?0:(1<<id[u]));
//			cerr<<st<<' '<<nst<<' '<<w<<' '<<u<<' '<<(1<<id[u])<<endl;
			if(f[nst][v]>f[st][u]+w) {
				f[nst][v]=f[st][u]+w; 
				q.push(ele(nst,v,w)); 
			}	
		}
	}
	For(i,1,n) {
		int ans=INF; 
		For(st,0,(1<<t)-1) {
			ckmin(ans,f[st][i]); 	
		}
		cout<<ans<<' '; 
	}	
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