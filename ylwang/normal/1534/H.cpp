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
//#include "it.h"
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
inline int read() {int x=0; scanf("%d",&x); return x;}
const int MN=1e5+5;
 
int n,ans[MN],f[MN],dep[MN]; vi e[MN];
void dfs1(int u,int fa) {
	dep[u]=dep[fa]+1;
	for(auto v:e[u]) if(v!=fa) dfs1(v,u);
	sort(e[u].begin(),e[u].end(),[&](int i,int j){return f[i]>f[j];});
	f[u]=1; int now=0;
	for(auto v:e[u]) if(v!=fa) {
		ckmax(f[u],f[v]+now); now++;
	}
}
void dfs2(int u,int fa) {
//	cerr<<u<<' '<<fa<<endl;
	int tmp=f[u]; 
	sort(e[u].begin(),e[u].end(),[&](int i,int j){return f[i]>f[j];});
	int mx=0,now=-1;
	for(auto v:e[u]) {
		ckmax(ans[u],f[v]+mx+max(now,0)); now++;
		ckmax(mx,f[v]);
	}
	vi suf(e[u].size()+5); suf.clear();
	suf[SZ(e[u])]=0;
	for(int i=SZ(e[u])-1;i>=1;i--) { int v=e[u][i];
		suf[i]=max(suf[i+1],f[v]+i-1);	
	}
	mx=0;
	for(int i=0;i<SZ(e[u]);i++) { int v=e[u][i];
		f[u]=max(max(mx,suf[i+1]),1);
		ckmax(mx,f[v]+i); if(v!=fa) dfs2(v,u);
	}
	f[u]=tmp;
}
int query(int u) {
	cout<<"? "<<u<<endl;
	int x; scanf("%d",&x); return x;	
}
int dfs3(int u,int fa) {
	if(SZ(e[u])==1) return query(u);	
	for(auto v:e[u]) {
		if(v==fa) continue;
		int ans=dfs3(v,u);
		if(ans!=u) return ans;
	}
	return u;
}
pii solve(int u) {
	dfs1(u,0); int a=0,b=0;
	for(auto v:e[u]) {
		int res=dfs3(v,u);
		if(res!=u) {
			if(!a) a=res;
			else b=res;
		}
		if(a&&b) break;
	}
	if(!a) a=u;
	if(!b) b=u;
	return mkp(a,b);
}
//vector<int> init(int n,vector<pii>E) {
//	::n=n;
//	For(i,0,n-2) {
//		int u=E[i].first,v=E[i].second;
////		cerr<<u<<' '<<v<<endl;
//		e[u].pb(v),e[v].pb(u);	
//	}
//	dfs1(1,0);
////	fprint(f,n);
//	dfs2(1,0);
//	
////	fprint(f,n);
////	fprint(ans,n);
//	vi res(ans+1,ans+1+n);
//	return res;
//}
int main() {
	n=read();
	For(i,1,n-1) {
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	dfs1(1,0),dfs2(1,0);
	int res=0;
	For(i,1,n) {
		ckmax(res,ans[i]);
	}
	cout<<res<<endl;
	pii it=solve(read());
	cout<<"! "<<it.first<<' '<<it.second<<endl;
}
//namespace grader{
//	#define pb push_back
//	#define x first
//	#define y second
//	const int N=200005;
//	int n, q, mn[N][20], dfn[N], seq[N], dep[N], lg[N], cnt;
//	int a, b, x;
//	vector<int> e[N], ans;
//	void dfs(int u, int fa)
//	{
//		dfn[u]=++cnt;
//		seq[cnt]=u;
//		dep[u]=dep[fa]+1;
//		for(int v:e[u]) if(v!=fa)
//		{
//			dfs(v, u);
//			seq[++cnt]=u;
//		}
//	}
//	inline int gmn(int x, int y) { return dep[x]<dep[y]?x:y; }
//	void initl(void)
//	{
//		for(int i=2; i<=cnt; i<<=1) ++lg[i];
//		for(int i=1; i<=cnt; ++i) lg[i]+=lg[i-1];
//		for(int i=1; i<=cnt; ++i) mn[i][0]=seq[i];
//		for(int l=1; (1<<l)<=cnt; ++l) for(int i=1; i+(1<<l)-1<=cnt; ++i)
//			mn[i][l]=gmn(mn[i][l-1], mn[i+(1<<(l-1))][l-1]);
//	}
//	inline int lca(int x, int y)
//	{
//		x=dfn[x], y=dfn[y];
//		if(x>y) std::swap(x, y);
//		int l=lg[y-x+1];
//		return gmn(mn[x][l], mn[y-(1<<l)+1][l]);
//	}
//	int query(int v)
//	{
//		++cnt;
//		if(cnt>ans[x-1]) { puts("WA_Exceed"); exit(0); }
//		int l=lca(a, b);
//		if(lca(v, l)==v) return l;
//		return l^lca(a, v)^lca(b, v);
//	}
//	int main()
//	{
//		scanf("%d%d", &n, &q);
//		vector<pair<int, int> > re;
//		for(int i=1, x, y; i<n; ++i)
//		{
//			scanf("%d%d", &x, &y), e[x].pb(y), e[y].pb(x);
//			re.pb({x, y});
//		}
//		ans.resize(n);
//		for(int i=1; i<=n; ++i) scanf("%d", &ans[i-1]);
//		dfs(1, 0);
//		initl();
//		auto vec=init(n, re);
//		if(vec.size()!=ans.size()) return puts("WA_size"), 0;
//		for(int i=0; i<ans.size(); ++i) if(vec[i]>ans[i]) return puts("WA_answer"), 0;
//		for(int i=1; i<=q; ++i)
//		{
//			scanf("%d%d%d", &x, &a, &b);
//			cnt=-1;
//			x=query(x);
//			cnt=0;
//			if(a>b) std::swap(a, b);
//			pair<int, int> t=solve(x);
//			if(t.x>t.y) std::swap(t.x, t.y);
//			if(t.x!=a||t.y!=b)
//			{
////				printf("find %d %d %d %d %d %d\n", i, x, a, b, t.x, t.y);
//				return puts("WA_find"), 0;
//			}
////			cerr<<cnt<<' '<<vec[x-1]<<endl;
//			if(vec[x-1]<cnt) return puts("WA_Exceed"), 0;
////			printf("Cnt: %d %d\n", vec[x-1], cnt);
//		}
//		puts("AC");
//		return 0;
//	}
//}
//int query(int x)
//{
//	int ret=grader::query(x);
////	printf("query %d %d\n", x, ret);
//	return ret;
//}
//int main()
//{
////	freopen("it3.in","r",stdin);
//	grader::main();
//	return 0;
//}