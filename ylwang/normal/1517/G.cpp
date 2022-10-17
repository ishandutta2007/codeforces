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
const int MN = 1e3 + 5;
struct Edge {
	int v, w, nxt;	
};
struct Dinic {
	static const int N = MN << 2;
	static const int M = MN << 4;
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
int n, x[MN], y[MN], w[MN], ans;
#define in(i) (i * 2 - 1)
#define out(i) (i * 2)
map < pii, int > v;
int id(int i, int j) {
	
	if(i % 2 == 1 && j % 2 == 1) return 3;
	if(i % 2 == 1 && j % 2 == 0) return 2;
	if(i % 2 == 0 && j % 2 == 1) return 0;
	if(i % 2 == 0 && j % 2 == 0) return 1;
	assert(0); return -1;
}
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n = read();
	For(i, 1, n) {
		v[mkp(x[i] = read() + 1e9, y[i] = read() + 1e9)] = i;
		ans += (w[i] = read());
//		cerr << x[i] << ' ' << y[i] << ' ' << w[i] << endl; 
	}
	d.init(0, 2 * n + 1);
	For(i, 1, n) {
		d.addedge(in(i), out(i), w[i]);
	}
	For(i, 1, n) {
		For(k, 0, 3) {
			int tx = x[i] + dx[k], ty = y[i] + dy[k]; int j = v[mkp(tx, ty)];
			if(j && id(x[j], y[j]) == id(x[i], y[i]) + 1) {
				d.addedge(out(i), in(j), INF);
			}
		}
	}
	For(i, 1, n) {
		if(id(x[i], y[i]) == 0) d.addedge(0, in(i), INF);
		else if(id(x[i], y[i]) == 3) d.addedge(out(i), 2 * n + 1, INF);
	}
//	cerr << d.solve() << endl; 
	cout << ans - d.solve() << endl; 
	return FastIO::Fflush(),0;
}