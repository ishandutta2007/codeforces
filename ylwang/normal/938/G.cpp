#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
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
//#define int  ll
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
const int MN=5e5+5;
int nowk;
struct LINER_BASE {
	static const int N=30;
	int a[N];
	
	struct ele { int x,y,o; }; stack<ele>s;
	void insert(int x) {
//		cerr<<"! "<<x<<endl;
		foR(i,29,0) {
			if(!(x>>i&1)) continue;
			if(!a[i]) return s.push((ele){i,a[i],nowk}),a[i]=x,void();
			x^=a[i]; 
		}
	}
	int qry(int x) {
		foR(i,29,0) if((x^a[i])<x) x^=a[i];
//		fprint(a-1,30);
		return x;
	}
	void undo(int k) {
		while(s.size()) {
			ele u=s.top(); if(u.o!=k) break; s.pop();
			a[u.x]=u.y;
		}
	}
}	lb;
int n,m,q,K,U[MN],V[MN],W[MN],ans[MN],QU[MN],QV[MN];
struct DSU {
	static const int N=MN<<1;
	struct ele { int x,y,z,w,o; }; stack<ele>s;
	int f[N],siz[N],dis[N]; DSU() {For(i,0,N-5) f[i]=i,siz[i]=1,dis[i]=0;}
	void init(int n) {For(i,0,n) f[i]=i,siz[i]=1,dis[i]=0;}
	int find(int x) {return x==f[x]?x:find(f[x]);}
	int qry(int x) { return x==f[x]?0:(qry(f[x])^dis[x]);}
	
	int qry(int x,int y) { assert(find(x)==find(y)); return qry(x)^qry(y);	}
	int merge(int x,int y,int w) {
//		fprint(f,n);
//		fprint(dis,n);
		int fx=find(x),fy=find(y),tx=qry(x),ty=qry(y);
		if(fx==fy) {
			lb.insert(w^tx^ty);
			return 0;
		}
		x=fx,y=fy; if(siz[x]>siz[y]) swap(x,y);
		s.push((ele){x,f[x],siz[x],dis[x],nowk}); s.push((ele){y,f[y],siz[y],dis[y],nowk});
		f[x]=y,siz[y]+=siz[x],dis[x]=tx^ty^w;
		return 1;
	}
	
	void undo(int k) {
		while(s.size()) {
			ele u=s.top(); if(u.o!=k) break; s.pop();
			f[u.x]=u.y,siz[u.x]=u.z,dis[u.x]=u.w;	
		}
	}
}d;

map<pii,int>lst;
vi t[MN<<2],qr[MN]; 
#define ls (k<<1)
#define rs (k<<1|1)
#define mid ((l+r)>>1)
void ins(int k,int l,int r,int ql,int qr,int id) {
//	cerr<<ql<<' '<<qr<<' '<<id<<endl;
	if(l>qr||r<ql) return; if(ql<=l&&r<=qr) return t[k].pb(id),void();
	ins(ls,l,mid,ql,qr,id),ins(rs,mid+1,r,ql,qr,id);
}
void dfs(int k,int l,int r) {
	
	nowk=k; 
	for(auto it:t[k]) {
		int u=U[it],v=V[it],w=W[it];
//		cerr<<"merge "<<' '<<u<<' '<<v<<' '<<w<<endl; 
		d.merge(u,v,w);
	}
	if(l==r) { 
		for(auto id:qr[l]) {
			int u=QU[id],v=QV[id]; int dist=d.qry(u,v);
//			cerr<<id<<' '<<dist<<endl;
			ans[id]=lb.qry(dist);
		}
	} else dfs(ls,l,mid),dfs(rs,mid+1,r);
	d.undo(k); lb.undo(k);
	
	for(auto it:t[k]) {
		int u=U[it],v=V[it],w=W[it];
//		cerr<<"undo "<<' '<<u<<' '<<v<<' '<<w<<endl; 
	}
	t[k].clear(); t[k].shrink_to_fit();
}
void works() {
	n=read(),m=read(); 
	For(i,1,m) U[i]=read(),V[i]=read(),W[i]=read(),lst[mkp(U[i],V[i])]=i;
	q=read();
	int tq=0,t=m+q+1;
	For(i,1,q) {
		int op=read(),u=read(),v=read();
		if(op==1) {
			int w=read();
			U[++m]=u,V[m]=v,W[m]=w;
			lst[mkp(U[m],V[m])]=m;
		} else if(op==2) {
			int lst=::lst[mkp(u,v)]; ::lst.erase(mkp(u,v));
//			cerr<<lst<<' '<<m<<endl; 
			ins(1,1,t,lst,m,lst); 
			m++;
		} else {
			qr[m].pb(++tq),QU[tq]=u,QV[tq]=v;
		}
	}
	for(auto it:lst) {
		ins(1,1,t,it.second,m+q+1,it.second);
	}
	dfs(1,1,t);
	For(i,1,tq) printf("%d\n",ans[i]);
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
?t??? 1??? 12?
*/