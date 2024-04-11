#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define mor > muu & operator<<(
#define ris return *this
#define R22(r) sim> typename enable_if<1 r sizeof(dud<c>(0)),muu&>::type operator<<(c g) {
sim> struct rge {c b, e;};
sim> rge<c> range(c i, c j) {return rge<c>{i, j};}
sim> auto dud(c*r)->decltype(cerr << *r);
sim> char dud(...);
struct muu {
	#ifdef LOCAL
	stringstream a;
	~muu() {cerr << a.str() << endl;}
	R22(<) a << boolalpha << g; ris;}
	R22(==) ris << range(begin(g), end(g));}
	sim mor rge<c> u) {
		a << "[";
		for (c i = u.b; i != u.e; ++i)
			*this << ", " + 2 * (i == u.b) << *i;
		ris << "]";
	}
	sim, class m mor pair<m,c> r) {ris << "(" << r.first << ", " << r.second << ")";}
	#else
	sim mor const c &){ris;}
	#endif
	muu & operator()(){ris;}
};
#define imie(r) "[" #r ": " << (r) << "] "
#define debug (muu() << __FUNCTION__ << "#" << __LINE__ << ": " )

struct edge {int to, next; }e[500007];

const int N = 1007;

struct Matching {
	int n, nxt[N], fa[N], S[N], Q[N], *Top = Q, pre[N], Vis[N], Tim = 0;
	int head[N], cnt = 1;
	
	inline void addedge(int x, int y) {e[++cnt] = (edge){y, head[x]}; head[x] = cnt;}
	int getfa(int x) { return (x == fa[x]) ? x : (fa[x] = getfa(fa[x]));}
	
	inline int lca(int x, int y) {
		for (++Tim, x = getfa(x), y = getfa(y); ; x^= y^= x ^= y) {
			if (x) {
				if (Vis[x] == Tim) return x;
				Vis[x] = Tim;
				x = getfa(pre[nxt[x]]);
			}
		}
	}
	
	inline void blossom(int x, int y, int l) {
		while (getfa(x) != l) {
			pre[x] = y;
			if (S[nxt[x]] == 1) S[*Top = nxt[x]] = 0, *Top++;
			if (fa[x] == x) fa[x] = l;
			if (fa[nxt[x]] == nxt[x]) fa[nxt[x]] = l;
			y = nxt[x];
			x = pre[y];
		}
	}
	
	inline int Match(int x) {
		for (int i = 1; i <= n; ++i) fa[i] = i;
		memset(S, 0xff, sizeof(S));
		S[*(Top = Q) = x] = 0; ++Top;
		for (int *i = Q; i != Top; *i++) {
			for (int T = head[*i]; T; T = e[T].next) {
				int y = e[T].to;
				if (S[y] == -1) {
					pre[y] = *i; S[y] = 1;
					if (!nxt[y]) {
						for (int u = y, v = *i, lst; v; u = lst, v = pre[u]) {
							lst = nxt[v], nxt[v] = u, nxt[u] = v;
						}
						return 1;
					}
					S[*Top = nxt[y]] = 0; *Top++;
				}
				else if (!S[y] && getfa(y) != getfa(*i)) {
					int l = lca(y, *i);
					blossom(y, *i, l);
					blossom(*i, y, l);
				}
			}
		}
		return 0;
	}
	
	int matching(int maxn) {
		int res = 0;
		for (int i = 1; i <= maxn; ++i) {
			if (!nxt[i]) res += Match(i);
		}
		return res;
	}
	
	void addDoubleEdge(int a, int b) {
		debug << imie(a) imie(b);
		addedge(a, b);
		addedge(b, a);
	}
	
} grafy[21];

char pom[157];

void solve(int it) {
	int n, m;
	scanf("%d %d", &n, &m);
	
	Matching &M = grafy[it];
	
	M.n = 2 * n + m;
	for (int i = 1; i <= n; ++i) {
		M.addDoubleEdge(2 * i - 1, 2 * i);
		scanf("%s", pom + 1);
		for (int j = 1; j <= m; ++j) {
			if (pom[j] == '1') {
				M.addDoubleEdge(2 * i - 1, 2 * n + j);
				M.addDoubleEdge(2 * i, 2 * n + j);
			}
		}
	}
	
	int wynik = M.matching(2 * n + m);
	debug << imie(wynik);
	wynik -= n;
	printf("%d\n", wynik);
}

int main() {
	int tt;
	scanf("%d", &tt);
	for (int i = 0; i < tt; ++i) solve(i);
}

/*
 * 1
3 4
0110
1100
0011
solve#130: [wynik: 4] 
 * 
 * addDoubleEdge#103: [a: 1] [b: 2] 
addDoubleEdge#103: [a: 1] [b: 8] 
addDoubleEdge#103: [a: 2] [b: 8] 
addDoubleEdge#103: [a: 1] [b: 9] 
addDoubleEdge#103: [a: 2] [b: 9] 
addDoubleEdge#103: [a: 3] [b: 4] 
addDoubleEdge#103: [a: 3] [b: 7] 
addDoubleEdge#103: [a: 4] [b: 7] 
addDoubleEdge#103: [a: 3] [b: 8] 
addDoubleEdge#103: [a: 4] [b: 8] 
addDoubleEdge#103: [a: 5] [b: 6] 
addDoubleEdge#103: [a: 5] [b: 9] 
addDoubleEdge#103: [a: 6] [b: 9] 
addDoubleEdge#103: [a: 5] [b: 10] 
addDoubleEdge#103: [a: 6] [b: 10] 
1
*/