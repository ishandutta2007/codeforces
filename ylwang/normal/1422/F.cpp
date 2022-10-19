#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define rint register int
#define INF ((1ll << 62) - 1)
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define Pair pair < int, int >
#define ull unsigned long long
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(rint i = (k); i >= (j); i--)
#define For(i, k, j) for(rint i = (k); i <= (j); i++)
#define Foe(i, u) for(rint i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define Fin(s) freopen(s, "r", stdin)
#define Fout(s) freopen(s, "w", stdout)
#define file(s) Fin(s".in"), Fout(s".out")
//#define int long long
const int P = 1000000007; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void mulmod(int &a, int b) {a = 1ll * a * b % P;}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= P ? t - P : t); }
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline int inv(int a) {return ksm(a, P-2);}

inline void printarray(int *a, int n) {For(i, 1, n) fprintf(stderr, "%d ", a[i]); fprintf(stderr, "\n");}
namespace FastIO {
    const int SIZE=1<<16; char buf[SIZE], obuf[SIZE], str[64]; int bi=SIZE, bn=SIZE, opt;
    int read(char *s) {
        while (bn) {for (;bi<bn&&buf[bi]<=' ';bi++);if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}
        int sn=0;while (bn) {for (;bi<bn&&buf[bi]>' ';bi++) s[sn++]=buf[bi];if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}s[sn]=0;return sn;
    }
    bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n) return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
    void write(int x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
};
inline int read() {int x; FI(x); return x;}
const int MAXN = 1e5 + 5;
const int MAXA = 2e5 + 50;
int a[MAXN], n, Qnum;
int prime[MAXA];
vector < Pair > g[MAXA];
namespace xxs {
	int vis[MAXA], id[MAXA], tot = 0;
	inline void init(int n = MAXA - 5) {
		tot = 0;
		For(i, 2, n) {
			if(!vis[i]) prime[++tot] = i, id[i] = tot;
			for(int j = 1; j <= tot && i * prime[j] <= n; j++) {
				vis[i * prime[j]] = 1;
				if(i % prime[j]) break;
			}
		}
//		cerr << tot << endl;
		For(i, 1, n) {
			int t = i;
//			cerr << i << ' ' << t << endl;
			for(int j = 1; j <= tot && prime[j] * prime[j] <= t; j++) {
				if(t % prime[j] == 0) {
					int cnt = 0;
					while(t % prime[j] == 0) t /= prime[j], cnt++;
					g[i].pb(mkp(j, cnt));
				}
			}
			if(t != 1) g[i].pb(mkp(id[t], 1));
		}
//		cerr << "?";
	}
}
int rt[MAXN*20], tot = 0, pos[MAXN];
struct CM_tree {
	static const int N = MAXN * 290;
	#define ls c[p][0]
	#define rs c[p][1]
	#define mid ((l + r) >> 1)
	int val[N], c[N][2];
	CM_tree() {For(i, 1, N-3) val[i] = 1;}
	void build(int &p, int l, int r) {
		if(!p) p = ++tot;
		if(l == r) return; build(ls, l, mid), build(rs, mid+1, r);
	}
	void update(int &p, int q, int l, int r, int pos, int v) {
//		cerr << p << ' ' << q << ' ' << l << ' ' << r << endl;
		if(!p) p = ++tot;
		if(l == r) return val[p] = 1ll * val[q] * v % P, void();
		if(pos <= mid) update(ls, c[q][0], l, mid, pos, v), rs = c[q][1];
		else update(rs, c[q][1], mid+1, r, pos, v), ls = c[q][0];
		val[p] = 1ll * val[ls] * val[rs] % P;
	}
	int query(int p, int l, int r, int ql, int qr) {
		if(l == ql && r == qr) return val[p];
		if(qr <= mid) return query(ls, l, mid, ql, qr);
		if(mid < ql) return query(rs, mid+1, r, ql, qr);
		return 1ll * query(ls, l, mid, ql, mid) * query(rs, mid+1, r, mid+1, qr) % P;
	}
}tr;
stack < int > s[MAXA];
inline int find(int x, int y) {
	for(auto it : g[a[x]])
		if(it.first == y) return it.second;
	assert(0); return 0;
}
inline int query(int l, int r) {
	return tr.query(rt[pos[r]], 1, n, l, n);
}
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
	n = read();
    For(i, 1, n) a[i] = read();
    xxs::init();
    
    tr.build(rt[0], 1, n); int C = 0;
    For(i, 1, n) {
    	for(auto it : g[a[i]]) {
    		int v = it.first, cnt = it.second, t, pos, val = 0; 
    		while(s[v].size() && (t = find(s[v].top(), v)) < cnt) {
    			pos = s[v].top(); s[v].pop();
    			C++, tr.update(rt[C], rt[C - 1], 1, n, pos, inv(ksm(prime[v], t - val))); val = t;
			}
			if(s[v].size())
				C++, tr.update(rt[C], rt[C - 1], 1, n, s[v].top(), inv(ksm(prime[v], cnt - val)));
			s[v].push(i);
		}
		
		C++, tr.update(rt[C], rt[C - 1], 1, n, i, a[i]); pos[i] = C;
//		cerr << "?";
	}
//	cerr << "?" << endl;
	Qnum = read();
    int lstans = 0;
    while(Qnum--) {
    	int l = (read() + lstans) % n + 1, r = (read() + lstans) % n + 1;
		if(l > r) swap(l, r);
		printf("%d\n", lstans = query(l, r));
	}
    return FastIO::Fflush(), 0;
}
/*

*/