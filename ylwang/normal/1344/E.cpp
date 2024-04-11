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
inline void fprint(const pii &x,char c='\n') {fprintf(stderr,"%d %d%c",x.first,x.second,c);}
inline void fprint(const int &x,char c=' ') {fprintf(stderr,"%d%c",x,c);}
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
const int MN=2e5+5;
int n,m,dest[MN],tim[MN];
struct Seg {
	int l,r;
	Seg(){} Seg(int L,int R):l(L),r(R){};
	bool operator < (const Seg &b) const {
		if(l!=b.l) return l<b.l;
		return r<b.r;
		
	}
};
inline void fprint(const Seg &x,char c=' ') {fprintf(stderr,"[%d,%d]%c",x.l,x.r,c);}
inline void fprint(const Seg *f,const int &n,char c='\n') {for(int i=1;i<=n;i++) fprint(f[i]); fprintf(stderr,"%c",c);}
inline void fprint(const vector<Seg> &f,char c='\n') {for(int i=0;i<(int)f.size();i++) fprint(f[i]); fprintf(stderr,"%c",c);}
vector<Seg> A;
ll dis[MN];
namespace LCT {
	const int N=MN;
	int	c[N][2],f[N],lst[N],tag[N],q[N],tot;
	int get(int x) { return c[f[x]][1]==x; }
	int nrt(int x) {if(!f[x]) return 0; return c[f[x]][0]==x||c[f[x]][1]==x; }
	
	void rotate(int x) {
		int F=f[x],G=f[F],p=get(x),q=get(F),R=c[x][p^1];
		if(nrt(F)) c[G][q]=x; c[x][p^1]=F,c[F][p]=R; 
		if(R) f[R]=F; f[x]=G,f[F]=x;
	}
	void pushr(int x,int v) {if(!x) return; tag[x]=lst[x]=v;}
	void pushdown(int x) {
		if(tag[x]) pushr(c[x][0],tag[x]),pushr(c[x][1],tag[x]),tag[x]=0;	
	}
	void splay(int x) {
		int tot=0,i;
		for(i=x;nrt(i);i=f[i]) q[++tot]=i; q[++tot]=i; 
		for(i=tot;i;i--) pushdown(q[i]);
		while(nrt(x)) {
			int fa=f[x];
			if(nrt(fa)) rotate(get(fa)==get(x)?fa:x);
			rotate(x);
		}
	}
	void access(int x,int t) { int u=x;
//		cerr<<"access "<<x<<' '<<t<<endl;
		for(int y=0;x;y=x,x=f[x]) {
			splay(x); 
			if(y) { c[x][1]=y;
//				cerr<<x<<' '<<y<<' ';fprint(Seg(lst[x]+dis[x]+1,t+dis[x])); cerr<<endl;
				A.pb(Seg(lst[x]+dis[x]+1,t+dis[x]));
			}
		} splay(u); pushr(c[u][0],t);
//		fprint(f,n);
	}
}
vector<pii>e[MN];
void dfs(int u,int fa) {
	LCT::lst[u]=-dis[u];
	for(auto it:e[u]) { int v=it.first,w=it.second;
		dis[v]=dis[u]+w; dfs(v,u);
	}
	if(!e[u].size()) return ; int v=e[u].back().first;
//	cerr<<u<<' '<<v<<endl;
	LCT::c[u][1]=v;
}

int p,tot;
priority_queue<pii>q;

void ad(int x) {
	while(p<tot&&A[p+1].l<=x) {
		p++; q.push(mkp(-A[p].r,p));
	}
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read(),m=read();
	For(i,1,n-1) {
		int u=read(),v=read(),w=read();
		e[u].pb(mkp(v,w)); LCT::f[v]=u;
	}
	For(i,1,n) LCT::lst[i]=0;
	dfs(1,0);
//	For(i,1,n) cerr<<dis[i]<<' '; cerr<<endl;
	For(i,1,m) { int s=read(),t=read();
		LCT::access(s,t);	
	}
	A.pb(Seg(-1,-1));
	map<int,int>cnt;
//	fprint(A);
	sort(A.begin(),A.end()); tot=A.size()-1;
	int now=1; ad(1);
	while(1) {
		while(q.size()) {
			int u=q.top().second; q.pop();
			if(now>A[u].r) { int acnt=0;
				for(auto it:cnt) {
					if(it.first<A[u].r) acnt+=it.second;
				}
				cout<<A[u].r<<' '<<acnt<<endl;
				return 0;
			}
			now++; ad(now),cnt[A[u].r]++;
		}
		if(p==tot) break;
		ckmax(now,A[p+1].l); ad(now);
	}
	cout<<"-1 "<<tot<<endl;
	return 0;
}

/*
// p[i] < p[j] : iff pos[i] > j && a[i] < j
*/