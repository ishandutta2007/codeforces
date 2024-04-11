#pragma GCC optimize("Ofast")
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
const int MN=4e5+5;
int n,m;
struct edge {
	int u,v,w;
	edge(){} edge(int U,int V,int W):u(U),v(V),w(W){}
	bool operator < (const edge &b) const {
		if(w!=b.w) return w<b.w;
		if(v!=b.v) return v<b.v;
		return u<b.u;
	}
}e[MN];
set<edge>s[MN],all; 
unordered_map<ull,int>ew,cw;
set<edge>curmn; vector<edge>now[MN]; 
set<ll>tans2; ll ta2[MN]; 
ll ans2=1e18;
inline ull go(const edge &x) { 
	return 1ull*x.u*n+x.v;	
}
inline ull go(const pii &x) { 
	return 1ull*x.first*n+x.second;	
}
void upd(int u) {
	int cnt=0; ll ans=0;
	tans2.erase(ta2[u]);
	for(auto it:now[u]) curmn.erase(it),cw[go(it)]--; now[u].clear();
	for(auto it:s[u]) {
		cnt++; ans+=it.w;
		cw[go(it)]++; if(cw[go(it)]==2) curmn.insert(it); now[u].pb(it); 
		if(cnt>=3) break;
	}
	if(cnt>=3) tans2.insert(ta2[u]=ans);
	if(tans2.size()) ans2=*tans2.begin();
}
void addedge(int u,int v,int w) { if(u>v) swap(u,v);
	edge it={u,v,w}; 
	ew[go(mkp(u,v))]=w; all.insert(it),s[u].insert(it),s[v].insert(it);
	upd(u),upd(v);
}
void deledge(int u,int v) { if(u>v) swap(u,v);
	int w=ew[go(mkp(u,v))]; edge it={u,v,w}; 
	all.erase(it); s[u].erase(it); s[v].erase(it);
	upd(u),upd(v);
}
int check(int x,int y,int r,int c) {
	if(x==r||x==c||y==r||y==c) return 0;
	return 1;	
}
ll qry1() {
	int cnt=0; vector<edge>tmp;
	for(auto it:curmn) {
		cnt++; tmp.pb(it);
		if(cnt>=10) break;
	}
	ll ans=1e18;
	For(i,0,cnt-1) For(j,i+1,cnt-1) {
		if(check(tmp[i].u,tmp[i].v,tmp[j].u,tmp[j].v)) ckmin(ans,(ll)tmp[i].w+tmp[j].w);
	}
	return ans;
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read(),m=read();
	For(i,1,m) {
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
	}
	int q=read();
	
	ll ans1=qry1();
	printf("%lld\n",min(ans1,ans2));
	while(q--) {
		int op=read();
		if(op==0) {
			int u=read(),v=read();
			deledge(u,v);
		} else {
			int u=read(),v=read(),w=read();
			addedge(u,v,w);
		}
		ll ans1=qry1();
		printf("%lld\n",min(ans1,ans2));
	}
	return FastIO::Fflush(),0;
}