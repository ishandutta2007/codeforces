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
const int MN=3e5+5;
int n,m,f[MN],L[MN],R[MN],siz[MN],ind,dep[MN],top[MN],id[MN],up[MN][5];
vi e[MN];
struct BIT {
	static const int N=MN;
	int c[N];
	void upd(int x,int v) { for(;x<=n;x+=x&-x) c[x]+=v;}
//	void upd(int l,int r,int v) { Upd(l,v),Upd(r+1,-v);}
	int qry(int x) {
		int ans=0; for(;x;x-=x&-x) ans+=c[x];
		return ans;
	}
	
}tr;
int Qry(int x) {
	if(!x) x=1;
	return tr.qry(R[x])-tr.qry(L[x]-1);	
}
void dfs1(int u) {
	dep[u]=dep[f[u]]+1,siz[u]=1;
	for(auto v:e[u]) {
		dfs1(v); siz[u]+=siz[v];	
	}
}
#define upd(i) up[u][i] = up[f[up[u][i-1]]][i-1]
void dfs2(int u,int fir) {
	int hson=0; top[u]=fir; id[L[u]=++ind]=u,up[u][0]=fir;
	upd(1); upd(2); upd(3); upd(4);
	for(auto v:e[u]) if(siz[v]>siz[hson]) hson=v;
	if(hson) {
		dfs2(hson,fir);
		for(auto v:e[u]) if(v!=hson) dfs2(v,v);
	}
	R[u]=ind; 
}
#undef upd
int lca(int x,int y) {
	while(top[x]!=top[y]) {
		dep[top[x]]>dep[top[y]]?x=f[top[x]]:y=f[top[y]];
	}
	return dep[x]<dep[y]?x:y;
}
#define jump(i) if(up[u][i] && k > dep[u] - dep[up[u][i]]) k -= dep[u] - dep[up[u][i]] + 1, u = f[up[u][i]];	
inline int kth(int u, int k) {
	jump(4); jump(3); jump(2); jump(1); jump(0);
	return !u ? 0 : id[L[u] - k];
}
vector<pii>B;
struct Cmp {
	bool operator () (const pii &x,const pii &y) const {return dep[x.first]<dep[y.first];	 }
};

priority_queue<pii,vector<pii>,Cmp > A;
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read(),m=read();
	For(i,2,n) {
		f[i]=read(); e[f[i]].pb(i);	
	}
	dfs1(1),dfs2(1,1);
	For(i,1,m) {
		int x=read(),y=read(); if(dep[x]>dep[y]) swap(x,y);
		if(x==f[y]) return printf("-1\n"),0;
		if(lca(x,y)!=x) B.pb(mkp(x,y));
		else A.push(mkp(x,y));
	}
//	For(i,1,n) cerr<<L[i]<<' '<<R[i]<<endl;
	int ans=0;
	while(A.size()) {
		pii it=A.top(); A.pop();
		int u=it.first,v=it.second;int t=kth(v,dep[v]-dep[u]-1);
		if(Qry(v)==Qry(t)) 
			ans++,tr.upd(L[t],1);
	}
	for(auto it:B) {
		int u=it.first,v=it.second;
//		cerr<<u<<' '<<v<<' '<<Qry(v)<<' '<<Qry(u)<<' '<<Qry(lca(u,v))<<' '<<lca(u,v)<<endl;
		if(Qry(v)+Qry(u)==ans) {
			
			ans++; break;	
		}
	}
	cout<<ans<<endl;
	return FastIO::Fflush(),0;
}
/*
  
*/