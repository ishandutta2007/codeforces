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
struct Edge {int v, cap, cost, nxt;};
struct DIJ_NODE {
	int u, y; DIJ_NODE(int tx, int ty) : u(tx), y(ty) {}
	bool operator < (const DIJ_NODE &b) const {return y > b.y;}
};
struct ZKW { // Don't forget to init!
	static const int MAXN = 16000 + 5;
	static const int MAXM = (16000 + 5) * 10;
	int n, s, t, lst[MAXN], tot, vis[MAXN], cur[MAXN], dis[MAXN], maxflow, mincost;
	Edge e[MAXM<<1];
	ZKW() { tot = 1; }
	void init(int tn, int ts, int tt) {n = tn, s = ts, t = tt; mst(dis, 0);}
	inline void addedge(int u, int v, int cap, int cost) {
		e[++tot] = (Edge) {v, cap, cost, lst[u]}; lst[u] = tot;
		e[++tot] = (Edge) {u, 0, -cost, lst[v]}; lst[v] = tot;
	}
	priority_queue < DIJ_NODE > q; int used[MAXN], h[MAXN];  
	int DIJ() {
		For(i, 0, n) h[i] += dis[i], dis[i] = (1 << 30), used[i] = 0;
		dis[s] = 0; q.push(DIJ_NODE(s, 0));
		while(q.size()) {
			int u = q.top().u; q.pop();
			if(used[u]) continue; used[u] = 1;
			Foe(i, u) {
				if(e[i].cap && dis[u] + e[i].cost + h[u] - h[v] < dis[v]) {
					dis[v] = dis[u] + e[i].cost + h[u] - h[v];
					q.push(DIJ_NODE(v, dis[v]));
				}
			}
		}
		return dis[t] != (1 << 30);
	}
	int DFS(int u, int nowflow) {
		if(u == t) return nowflow;
		int flow = 0; vis[u] = 1;
		for(int &i = cur[u]; i; i = e[i].nxt) {
			int v = e[i].v, x;
			if(!vis[v] && dis[v] == dis[u] + e[i].cost + h[u] - h[v] && e[i].cap && (x = DFS(v, min(nowflow, e[i].cap))))
				e[i].cap -= x, e[i^1].cap += x, nowflow -= x, flow += x, mincost += x * e[i].cost;
			if(!nowflow) break;
		}
		return flow + (vis[u] = 0);
	}
	void Dinic() {
		maxflow = mincost = 0;
		while(DIJ()) {
			memcpy(cur, lst, sizeof(cur));
			int x = 0; while((x = DFS(s, (1 << 30)))) maxflow += x;
		}
	}
	pair < int, int > solve() {
		Dinic();
		return mkp(maxflow, mincost);
	}
}d;
const int MN=1<<20|1;
int n,k,t1,t2,m,a[MN];
struct edge {
	int u,v,w;	
}e[MN*20];
int id[MN]; int tot;
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read(),k=read();
	For(i,0,(1<<n)-1) {
		a[i]=read();
	}
	For(i,0,(1<<n)-1) {
		if(__builtin_popcount(i)&1) continue;
		For(j,0,n-1) {
			e[++m]=(edge){i,i^(1<<j),a[i]+a[i^(1<<j)]};
		}	
	}
	cerr<<m<<endl;
	int lim=min(m,k*2*n+1);
	sort(e+1,e+1+m,[&](edge a,edge b){return a.w>b.w;});
//	cerr<<"?";
//	cerr<<lim<<' '<<m<<endl;
	tot=2;
	For(i,1,lim) {
//		cerr<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<endl;
		if(!id[e[i].u]) id[e[i].u]=++tot,d.addedge(0,id[e[i].u],1,0);;
		if(!id[e[i].v]) id[e[i].v]=++tot,d.addedge(id[e[i].v],1,1,0);;
	}
	d.init(tot,0,2);
	d.addedge(1,2,k,0);
	For(i,1,lim) {
//		cerr<<id[e[i].u]<<' '<<id[e[i].v]<<' '<<2000000-e[i].w<<endl;
		
		d.addedge(id[e[i].u],id[e[i].v],1,2e6-e[i].w);
	}
	auto it=d.solve(); int x=it.first,y=it.second;
	
	cout<<x*2000000-y<<endl;
	return FastIO::Fflush(),0;
}
/*
  
*/