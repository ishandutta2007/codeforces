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
const int MN=3e5+5;
namespace Tree {
	static const int N=MN<<2;
	int n,w[N],tot,dfn[N],vmn[N],vid[N],dep[N];
	vi e[N];
	struct ST {
		static const int N=MN<<2,LG=21;
		int mn[LG+1][N]; int lg[N];
		#define G(x,y) dep[x]<dep[y]?x:y
		void init(int n,int *vid) {
			lg[1]=0; For(i,2,n) lg[i]=lg[i>>1]+1;
			For(i,1,n) mn[0][i]=vid[i];
			
			For(i,1,LG) For(j,1,n-(1<<i)+1) {
				mn[i][j]=G(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
			}
		}
		int qmn(int l,int r) { if(l>r) swap(l,r); int d=lg[r-l+1]; return G(mn[d][l],mn[d][r-(1<<d)+1]); }
	} st;
	int qry(int x,int y) {
		return w[st.qmn(dfn[x],dfn[y])];	
	}
	void dfs(int u,int fa) {
		dep[u]=dep[fa]+1; vid[dfn[u]=++tot]=u,vmn[dfn[u]]=dep[u]; 
		for(auto v:e[u]) {
			dfs(v,u); vid[++tot]=u,vmn[tot]=dep[u]; 
		}
	}
	void init() {
		dfs(n,0);
		st.init(tot,vid);
	}
}
#define dist(x,y) Tree::qry(x,y)

struct DSU {
	static const int N=MN<<1;
	int f[N];
	void init(int n) { For(i,0,n) f[i]=i; }
	int find(int x) { return x==f[x]?x:f[x]=find(f[x]);	 }
	void merge(int u,int v,int w) {
		
//		cerr<<' '<<u<<' '<<v<<endl;
		u=find(u),v=find(v); int &n=Tree::n;
		Tree::w[++n]=w; Tree::e[n].pb(u),Tree::e[n].pb(v);
//		cerr<<n<<' '<<u<<' '<<v<<endl;
		f[u]=f[v]=n;
			
	}
} dsu;
struct ele {
	int x,y,z;
	ele(){} ele(int X,int Y,int Z):x(X),y(Y),z(Z){}
	bool operator < (const ele &b) const {
		return z<b.z;
	}
} e[MN];
pii operator + (const pii &a,const pii &b) {
	if(a.second==-1) return b;
	if(b.second==-1) return a;
	int ans=max(max(a.second,b.second),dist(a.first,b.first));
	return mkp(a.first,ans);
}
struct SMT {
	static const int N=MN<<2;
	#define ls (k<<1)
	#define rs (k<<1|1)
	#define mid ((l+r)>>1)
	pii a[N],all[N]; int tag[N];
	void build(int k,int l,int r) {
		a[k]=mkp(-1,-1);
		if(l==r) return all[k]=mkp(l,0),void();
		build(ls,l,mid),build(rs,mid+1,r);
		all[k]=all[ls]+all[rs];
	}
	void pushr(int k,int v) {
		if(v==1) a[k]=all[k];
		else a[k]=mkp(-1,-1);
		tag[k]=v;
	}
	void pushdown(int k) {
		if(tag[k]) pushr(ls,tag[k]),pushr(rs,tag[k]),tag[k]=0;	
	}
	void upd(int k,int l,int r,int ql,int qr,int op) {
		if(l>qr||r<ql) return; if(ql<=l&&r<=qr) return pushr(k,op); pushdown(k);
		upd(ls,l,mid,ql,qr,op),upd(rs,mid+1,r,ql,qr,op); 
		a[k]=a[ls]+a[rs];
	}
} tr;
int n,q;
void works() {
	n=read(),q=read(); dsu.init(2*n); Tree::n=n;
	For(i,1,n-1) {
		int u=read(),v=read(),w=read();
		e[i].x=u,e[i].y=v,e[i].z=w;
	}
	sort(e+1,e+n);
	For(i,1,n-1) dsu.merge(e[i].x,e[i].y,e[i].z);
//	cerr<<"?";
	Tree::init(); tr.build(1,1,n);
//	For(i,1,n) For(j,1,n) cerr<<i<<' '<<j<<' '<<dist(i,j)<<endl;
	while(q--) {
		int op=read();
		if(op==1||op==2) {
			int l=read(),r=read();
			tr.upd(1,1,n,l,r,op==1?1:-1);
		} else {
			pii ans=tr.a[1]; 
			int x=read();
			if(ans.first==-1) {FO(-1); FO('\n');continue;}
			int fans=max(ans.second,dist(x,ans.first));
			if(fans>0) FO(fans); 
			else FO(-1);
			FO('\n');
		}
	}
}
signed main() {
	#ifndef ONLINE_JUDGE
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