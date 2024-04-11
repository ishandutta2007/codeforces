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
struct DSU {
	static const int N=MN<<1;
	struct ele { int x,y,z,w; }; stack<ele>s;
	int f[N],siz[N]; DSU() {For(i,0,N-5) f[i]=i,siz[i]=1;}
	void init(int n) {For(i,0,n) f[i]=i,siz[i]=1;}
	int find(int x) {return x==f[x]?x:find(f[x]);}
	int merge(int x,int y) {
		x=find(x),y=find(y); 
		if(x==y) return 0; if(siz[x]>siz[y]) swap(x,y);
		s.push((ele){x,f[x],siz[x],nowk}); s.push((ele){y,f[y],siz[y],nowk}); f[x]=y,siz[y]+=siz[x];
		return 1;
	}
	void undo(int k) {
		while(s.size()) {
			ele u=s.top(); if(u.w!=k) break; s.pop();
			f[u.x]=u.y,siz[u.x]=u.z;	
		}
	}
};

int n,m,q,K,U[MN],V[MN],E[MN],C[MN],nxt[MN],lst[MN],pnxt[MN],ans[MN];
DSU d[51];
vi t[MN<<2]; 
#define ls (k<<1)
#define rs (k<<1|1)
#define mid ((l+r)>>1)
void ins(int k,int l,int r,int ql,int qr,int id) {
	if(!C[id]) return; 
	if(l>qr||r<ql) return; if(ql<=l&&r<=qr) return t[k].pb(id),void();
	ins(ls,l,mid,ql,qr,id),ins(rs,mid+1,r,ql,qr,id);
}
void solve(int k) {
	nowk=k; 
	for(auto it:t[k]) {
		int u=U[E[it]],v=V[E[it]],c=C[it];
		assert(it);
		d[c].merge(u,v+n),d[c].merge(v,u+n);
	}
}
void dfs(int k,int l,int r) {
	if(l==r) t[k].pb(l); solve(k); 
	if(l==r) { 
		int u=U[E[l]],v=V[E[l]],c=C[l];
		ans[l]=d[c].find(u)!=d[c].find(u+n)&&d[c].find(v)!=d[c].find(v+n);
		if(!ans[l]) C[l]=C[lst[l]]; 
		ins(1,1,q,l+1,nxt[l]-1,l);
	} else dfs(ls,l,mid),dfs(rs,mid+1,r);
	For(i,1,K) d[i].undo(k); 
	t[k].clear(); t[k].shrink_to_fit();
}
void works() {
	n=read(),m=read(),K=read(),q=read();
	For(i,1,m) U[i]=read(),V[i]=read();
	For(i,1,m) pnxt[i]=q+1;
	For(i,1,q) E[i]=read(),C[i]=read();
	foR(i,q,1) nxt[i]=pnxt[E[i]],pnxt[E[i]]=i;
	For(i,1,q) lst[nxt[i]]=i;
//	fprint(nxt,q),fprint(lst,q);
	dfs(1,1,q);
	For(i,1,q) printf(ans[i]?"YES\n":"NO\n");
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