#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define rint register int
#define INF ((1 << 30) - 1)
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define Pair pair < int, int >
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(rint i = (k); i >= (j); i--)
#define For(i, k, j) for(rint i = (k); i <= (j); i++)
#define Foe(i, u) for(rint i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define file(s) freopen(s".in", "r", stdin); freopen(s".out", "w", stdout)
//#define int long long
const int P = 998244353; //
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
const int MAXN = 5e5 + 5;
const int LOGMAXN = 20;
int n, Qnum, a[MAXN], pos[MAXN];
vector < int > e[MAXN];

int lg2[MAXN<<1], st[MAXN<<1][LOGMAXN+1], fir[MAXN], ind, dep[MAXN];
void LCA_init_dfs(int u, int Fa) {
	dep[u] = dep[Fa] + 1, fir[u] = ++ind, st[ind][0] = u;
	for(auto v : e[u]) {
		if(v == Fa) continue;
		LCA_init_dfs(v, u); st[++ind][0] = u;
	}
	
}
inline void LCA_init(int s) {
	lg2[1] = 0;
	For(i, 2, n << 1) lg2[i] = lg2[i >> 1] + 1;
	LCA_init_dfs(s, 0); 
	For(i, 1, lg2[ind]) {
		for(rint j = 1; j <= ind - (1 << i) + 1; j++) {
			if(dep[st[j][i-1]] < dep[st[j+(1<<(i-1))][i-1]]) st[j][i] = st[j][i-1];
			else st[j][i] = st[j+(1<<(i-1))][i-1];
		}
	}
}
inline int LCA(int u, int v) {
	if(fir[u] > fir[v]) swap(v, u);
	rint l = fir[u], r = fir[v], k = lg2[r-l+1];
	return dep[st[l][k]] < dep[st[r-(1<<k)+1][k]] ? st[l][k] : st[r-(1<<k)+1][k];
}
struct Node {
	int u, v;
};
bool check(int x, int u, int v) {
	int y = LCA(u, v);
//	cerr << u << ' ' << v << ' ' << y << endl;
	return (LCA(u, x) == x || LCA(v, x) == x) && (LCA(x, y) == y);
}
Node merge(const Node &a, const Node &b) {
	if(a.u == -1 || b.u == -1) return (Node) {-1, -1};
	if(check(b.u, a.u, a.v) && check(b.v, a.u, a.v)) return a;
	if(check(a.u, b.u, b.v) && check(a.v, b.u, b.v)) return b;
	if(check(a.v, a.u, b.v) && check(b.u, a.u, b.v)) return (Node) {a.u, b.v};
	if(check(a.v, a.u, b.u) && check(b.v, a.u, b.u)) return (Node) {a.u, b.u};
	if(check(a.u, a.v, b.v) && check(b.u, a.v, b.v)) return (Node) {a.v, b.v};
	if(check(a.u, a.v, b.u) && check(b.v, a.v, b.u)) return (Node) {a.v, b.u};
	return (Node) {-1, -1};
}
struct Segment_tree {
	static const int N = MAXN << 2;
	Node t[N];
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	void build(int k, int l, int r) {
		if(l == r) return t[k] = (Node) {pos[l], pos[l]}, void();
		build(ls, l, mid); build(rs, mid+1, r);
		t[k] = merge(t[ls], t[rs]);
	}
	void update(int k, int l, int r, int pos, int val) {
		if(l == r) return t[k] = (Node) {val, val}, void();
		pos <= mid ? update(ls, l, mid, pos, val) : update(rs, mid+1, r, pos, val);
		t[k] = merge(t[ls], t[rs]);
	}
	int query(int k, int l, int r, Node &x) {
		if(t[k].u != -1) {
			if(x.u == -1) return x = t[k], r;
			Node tmp = merge(x, t[k]);
			if(~tmp.u) return x = tmp, r;
		}
		if(l == r) return (~merge(x, t[k]).u ? l : 0);
		int res = query(ls, l, mid, x);
		if(res < mid) return res;
		else return max(query(rs, mid+1, r, x), res);
	}
}tr;
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    FI(n); 
//	cerr << n << endl;
    For(i, 1, n) FI(a[i]), a[i]++, pos[a[i]] = i;
//    For(i, 1, n) cerr << pos[i] << ' ';
//    cerr << endl;
    For(i, 2, n) {
    	int f; FI(f); e[f].pb(i), e[i].pb(f);
	}
	LCA_init(1); tr.build(1, 1, n);
	FI(Qnum); 
	
//	cerr << Qnum << endl;
    For(tq, 1, Qnum) {
//    	cerr << "*" << tq << endl;
    	int op; FI(op);
    	if(op == 1) {
    		int x, y; FI(x); FI(y);
			tr.update(1, 1, n, a[x], y), tr.update(1, 1, n, a[y], x); swap(a[x], a[y]);		
		} else {
			Node x = (Node) {-1, -1};
			printf("%d\n", tr.query(1, 1, n, x));
		}
	}
    return FastIO::Fflush(), 0;
}
/*
Think twice :
mod ?
INF ?
n = 1 ?
long long ?
Fastio::Fflush() ?

*/