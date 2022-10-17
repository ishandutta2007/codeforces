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
inline int read() {int x; FI(x); return x;}
const int MN=2200+5;
int n;
struct Node {
	int A, B, bel;
	Node(){} Node(int a, int b) : A(a), B(b), bel(0) {}
}a[MN], b[MN], tmp[MN * 2];
ll getval(Node x, int t) {
	return 1ll * x.A * t + x.B;
}
inline void fprint(const Node &x,char c='\n') {fprintf(stderr,"%d %d %d%c",x.A,x.B,x.bel,c);}
inline void fprint(const Node *f,const int &n,char c='\n') {for(int i=1;i<=n;i++) fprint(f[i]); fprintf(stderr,"%c",c);}
int p[MN << 1], MID;
bool cmp(Node i, Node j) {
	if(getval(i, MID) != getval(j, MID)) return getval(i, MID) < getval(j, MID);	
	return i.bel > j.bel;
}
int cnt[2 * MN];
bool check(int mid) {
	fprintf(stderr, "check on %d\n", mid);
	MID = mid;
	For(i, 1, n) tmp[i] = a[i];
	For(i, 1, n) tmp[i + n] = b[i], tmp[i + n].bel = 1;
	sort(tmp + 1, tmp + 1 + 2 * n, cmp);
	For(i, 1, 2 * n) cnt[i] = 0;
	For(i, 1, n) {
		ll v = getval(a[i], 0); int ans = 0;
		For(j, 0, 2 * n) {
			if(getval(tmp[j], 0) <= v && (!ans || getval(tmp[j], MID) > getval(tmp[ans], MID) || getval(tmp[j], MID) == getval(tmp[ans], MID) && tmp[j].bel < tmp[ans].bel)) {
				ans = j;
			}
		}
		cnt[ans]++;
	}
	fprint(cnt, 2 * n);
	int now = 0;
	foR(i, 2 * n, 1) {
		cnt[i] += cnt[i + 1]; now += tmp[i].bel;
		if(now > cnt[i]) return 0;
	}
	return 1;
}
struct Edge {int v, cap, cost, nxt;};
struct DIJ_NODE {
	int u, y; DIJ_NODE(int tx, int ty) : u(tx), y(ty) {}
	bool operator < (const DIJ_NODE &b) const {return y > b.y;}
};
struct ZKW { // Don't forget to init!
	static const int MAXN = MN << 3;
	static const int MAXM = MN << 4;
	int n, s, t, lst[MAXN], tot, vis[MAXN], cur[MAXN], dis[MAXN], maxflow, mincost;
	Edge e[MAXM<<1];
	void init(int tn, int ts, int tt) {n = tn, s = ts, t = tt, tot = 1; mst(dis, 0);}
	inline void addedge(int u, int v, int cap, int cost) {
//		cerr << u << ' ' << v << ' '<< cap << ' ' << cost << endl; 
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
//		cerr << n << endl; 
//		fprint(dis - 1, n + 1);
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
int in[MN << 1], out[MN << 1], pre[MN << 1];
bool cmp1(int i, int j) {
	return getval(tmp[i], 0) < getval(tmp[j], 0);	
}
bool cmp2(int i, int j) {
	if(getval(tmp[i], MID) !=  getval(tmp[j], MID)) return getval(tmp[i], MID) < getval(tmp[j], MID);	
	return i > j;
}
int doit(int x) { MID = x;
	int s = 0, t = 8 * n + 1;
	For(i, 1, n) tmp[i] = a[i];
	For(i, 1, n) tmp[i + n] = b[i], tmp[i + n].bel = 1;
	For(i, 1, 2 * n) {
		p[i] = i;
	}
	d.init(t, s, t);
	For(i, 1, 2 * n) {
		in[i] = i * 2 - 1, out[i] = i * 2;
		if(i <= n) d.addedge(s, in[i], 1, 0);
		else d.addedge(out[i], t, 1, 0);
		d.addedge(in[i], out[i], INF, 0);
	}
	sort(p + 1, p + 1 + 2 * n, cmp1);
//	fprint(p, 2 * n);
	pre[1] = in[p[1]];
	For(i, 2, 2 * n) {
		pre[i] = 4 * n + i;
		d.addedge(pre[i], pre[i - 1], INF, 0);
		d.addedge(pre[i], in[p[i]], INF, 0);
	}
	For(i, 2, 2 * n) 
		d.addedge(in[p[i]], pre[i - 1], INF, 1);
	sort(p + 1, p + 1 + 2 * n, cmp2);
//	fprint(p, 2 * n);
	pre[1] = out[p[1]];
	for (int i = 2; i <= 2 * n; i++) {
		pre[i] = 6 * n + i;
		d.addedge(pre[i], pre[i - 1], INF, 0);
		d.addedge(pre[i], out[p[i]], INF, 0);
	}
	For(i, 2, 2 * n)
		d.addedge(out[p[i]], pre[i - 1], INF, 1);
//	cerr << "?";
	return d.solve().second;
}
signed main() {
	#ifndef ONLINE_JUDGE
		file("stock");	
	#endif
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i].A = read(), a[i].B = read();	
	}
	for(int i = 1; i <= n; i++) {
		b[i].A = read(), b[i].B = read();	
	}
	int l = 0, r = 1e9, ans = -1;
	while(l <= r) { int mid = (l + r) >> 1;
		if(check(mid)) {
			r = mid - 1, ans = mid;
		} else l = mid + 1;
	}
	cout << ans << ' ';
	if(ans == -1) return 0;
	cout << doit(ans) << endl; 
	return FastIO::Fflush(),0;
}