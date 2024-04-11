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
inline int mul(int a,int b) {return 1ll*a*b%P;}
inline int add(int a,int b) {return a+b>=P?a+b-P:a+b;}
inline int sub(int a,int b) {return a-b>=0?a-b:a-b+P;}
inline void mulmod(int &a,int b) {a=mul(a, b);}
inline void addmod(int &a,int b) {((a+=b)>=P)&&(a-=P);}
inline void submod(int &a,int b) {((a-=b)<0)&&(a+=P);}
inline int ksm(int a,int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline void fprint(const vector<int> &f) {for(int i=0;i<(int)f.size();i++) fprintf(stderr,"%d ",f[i]); fprintf(stderr,"\n");}
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
const int MN=3e5+5;
int n,m,a[MN],vis[MN],x;
vector<pii> g[MN],e[MN];
void gettree(int u) {
	vis[u]=1;
	for(auto it:g[u]) {
		int v=it.first,w=it.second;
		if(vis[v]) continue;
		e[u].pb(it),e[v].pb(mkp(u,w)), gettree(v);
	}
}
int f[MN];
int find(int x) {
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
void merge(int u,int v) {
	u=find(u),v=find(v);
	if(u==v) return;
	f[v]=u;	
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read(),m=read(),x=read(); int sum=0;
	For(i,1,n) a[i]=read(),sum+=a[i];
	if(sum<(n-1)*x) return printf("NO\n"),0;
	For(i,1,m) {
		int u=read(),v=read();	
		e[u].pb(mkp(v,i)),e[v].pb(mkp(u,i));
	}
//	gettree(1);
//	cerr<<"?";
	For(i,1,n) f[i]=i;
	priority_queue<pii>q;
	printf("YES\n");
	For(i,1,n) q.push(mkp(a[i],i));
	For(i,1,n-1) {
//		assert(q.size());
		int u=q.top().second,V=q.top().first; q.pop();
		while(q.size()&&(find(u)!=u||V!=a[u])) {
			u=q.top().second,V=q.top().first; q.pop();
		}
		assert(find(u)==u);
		pii it=e[u].back(); 
		
		while(find(it.first)==u) e[u].pop_back(),it=e[u].back(); 
		int v=find(it.first),id=it.second;
//		cerr<<u<<' '<<v<<endl;
		printf("%d ",id);
		if(e[u].size()<e[v].size()) swap(u,v);
		assert(a[u]+a[v]>=x);
		a[u]=a[u]+a[v]-x; merge(u,v); q.push(mkp(a[u],u));
		for(auto it:e[v]) {
//			if(find(it.first)!=u) 
			e[u].pb(it);	
		}
//		e[v].clear();
		
	}
	return FastIO::Fflush(),0;
}