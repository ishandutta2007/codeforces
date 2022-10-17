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
#define INF ((1ll<<60)-1)
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
inline int read() {int x; FI(x); return x;}
const int MN=2e2+5;
struct Edge {
	int v, w, nxt;	
};
struct Dinic {
	static const int N = 5e5 + 5;
	static const int M = 5e5 + 5;
	int lst[N], tot, s, t, dis[N], cur[N];
	Edge e[M << 1];
	void init(int S, int T) {s = S, t = T, tot = 1; mst(lst, 0); }
	void addedge(int u, int v, int w) {
		e[++tot] = (Edge) {v, w, lst[u]}; lst[u] = tot;
		e[++tot] = (Edge) {u, 0, lst[v]}; lst[v] = tot;
	}
	bool bfs() {
		mst(dis, 0);
		queue < int > q; q.push(s); dis[s] = 1;
		while(q.size()) {
			int u = q.front(); q.pop();
			Foe(i, u) {
				if(e[i].w && !dis[v]) {
					dis[v] = dis[u] + 1;
					q.push(v);	
					if(v == t) return 1;
				}
			}
		}
		return dis[t];
	}
	int dfs(int u, int nowflow) {
		if(u == t) return nowflow;
		int flow = 0;
		for(int &i = cur[u]; i; i = e[i].nxt) {
			int v = e[i].v, di = 0;
			if(dis[v] == dis[u] + 1 && (di = dfs(v, min(nowflow, e[i].w))) ) 
				nowflow -= di, flow += di, e[i].w -= di, e[i ^ 1].w += di;
			if(!nowflow) break;
		}
		return flow;
	}
	int solve() {
		int ans = 0;
		while(bfs()) {
			memcpy(cur, lst, sizeof(cur));
			int di = 0;
			while((di = dfs(s, INF))) ans += di;
		}
		return ans;
	}
}d;
#define id(i,j) ((i-1)*m+j)
int ans=0,n,m;
char s[MN][MN];
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read(),m=read(); int S=0,T=4*n*m+1; d.init(S,T);
	For(i,1,n) FI(s[i]+1);
	int ans=0,tmp=0,t=n*m;
	For(i,1,n) {
		For(j,1,m) {
			ans+=s[i][j]=='#';			
			if(s[i][j]=='#') {
				if(s[i][j+1]=='#') {
					++t,++tmp; 
					d.addedge(S,t,1),d.addedge(t,id(i,j),1),d.addedge(t,id(i,j+1),1);	
				}
				if(s[i+1][j]=='#') {
					++t,++tmp; 
					d.addedge(t,T,1),d.addedge(id(i,j),t,1),d.addedge(id(i+1,j),t,1);		
				}
			}
		}
	}
	int tt=d.solve(); cerr<<tt<<endl;
	cout<<ans-tmp+tt<<endl;
	return FastIO::Fflush(),0; 
}
/*

*/