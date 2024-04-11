# include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
#define sim template <class c
#define dor >debug & operator<< (
#define ris return *this
#define eni(r) sim> typename enable_if<sizeof(dud<c>(0)) r 1, debug &>::type operator<< (c i) {
sim> struct rge {c b, e;};
sim> rge<c> range(c i, c j) {return rge<c>{i, j};}
sim> auto dud(c * x) -> decltype(cerr << *x, 2);
sim> char dud(...);
struct debug {
#ifdef LOCAL
~debug() {cerr << endl;}
eni(==) ris << range(begin(i), end(i));}
eni(!=) cerr << i; ris;}
sim dor rge<c> x) {
	cerr << "[";
	for (c it = x.b; it != x.e; ++it)
		*this << ", " + 2 * (x.b == it) << *it;
	ris << "]";
}
sim, class b dor pair <c,b> x) {ris << "(" << x.first << ", " << x.second << ")";}
#else
sim dor const c&) {ris;}
#endif
};
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) << ": " << a[i] << "] " 
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] " 
#define debug debug() << __FUNCTION__ << "#" << __LINE__ << ": "

using T = int;

class Flow {
	struct E {
		int dest;
		T orig, *lim, *rev;
	};
	
	int zr, uj, n = 0;
	vector <unique_ptr<T>> ts;
	vector <vector<E>> graf;
	vector <int> ptr, odl;
	
	void vert(int v) {
		n = max(n, v + 1);
		graf.resize(n);
		ptr.resize(n);
		odl.resize(n);
	}
	
	bool iszero(T v) {
		return !v;
	}
	
	void bfs() {
		fill(odl.begin(), odl.end(), 0);
		vector <int> kol = {zr};
		odl[zr] = 1;
		for (int i = 0; i < (int) kol.size(); ++i) {
			for (E& e : graf[kol[i]]) {
				if (!odl[e.dest] and !iszero(*e.lim)) {
					odl[e.dest] = odl[kol[i]] + 1;
					kol.push_back(e.dest);
				}
			}
		}
	}
	
	T dfs(int v, T lim) {
		if (v == uj) return lim;
		T ret = 0, wez;
		for (int &i = ptr[v]; i < (int) graf[v].size(); ++i) {
			E& e = graf[v][i];
			if (odl[e.dest] == odl[v] + 1 and !iszero(*e.lim) and !iszero(wez = dfs(e.dest, min(*e.lim, lim)))) {
				ret += wez;
				*e.lim -= wez;
				*e.rev += wez;
				lim -= wez;
				if (iszero(lim)) break;
			}
		}
		return ret;
	}
	
	public:
		void add_edge(int u, int v, T lim, bool bi = false) {
			vert(max(u, v));
			T *a = new T(lim), *b = new T(lim * bi);
			ts.emplace_back(a);
			ts.emplace_back(b);
			graf[u].push_back(E{v, lim, a, b});
			graf[v].push_back(E{u, lim * bi, b, a});
		}
		
		T dinic(int zr_, int uj_) {
			zr = zr_; uj = uj_;
			vert(max(zr, uj));
			T ret = 0;
			while (true) {
				bfs();
				fill(ptr.begin(), ptr.end(), 0);
				const T sta = dfs(zr, numeric_limits<T>::max());
				if (iszero(sta)) break;
				ret += sta;
			}
			return ret;
		}
		
		map <pair <int, int>, T> get_flowing() {
			map<pair <int, int>, T> ret;
			for (int i = 0; i < n; ++i) {
				for (E& e : graf[i]) {
					if (*e.lim < e.orig) {
						ret[make_pair(i, e.dest)] += e.orig - *e.lim;
					}
				}
			}
			for (auto &i : ret) {
				const pair <int, int> rev{i.first.second, i.first.first};
				const T x = min(i.second, ret[rev]);
				i.second -= x;
				ret[rev] -= x;
			}
			return ret;
		}
};

void solve() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector <int> wyn(m + 1, 0);
	vector <int> deg(n + 1, 0);
	vector <vector <int>> G(n + 1);
	int gkol = 1;
	
	Flow gra;
	
	for (int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		gra.add_edge(0, i, 1);
		gra.add_edge(i, a + m, 1);
		gra.add_edge(i, b + m, 1);
		deg[a]++;
		deg[b]++;
		G[a].push_back(i);
		G[b].push_back(i);
	}
	
	int suma = 0;
	
	for (int i = 1; i <= n; ++i) {
		int ile = 0;
		if (deg[i] > k) {
			ile = (deg[i] - k) * 2;
		}
		suma += ile;
		gra.add_edge(i + m, n + m + 1, ile);
	}
	
	if (gra.dinic(0, n + m + 1) == suma) {
		map <pair <int, int>, int> flo = gra.get_flowing();
		
		for (int i = 1; i <= n; ++i) {
			vector <int> przyp;
			for (int u : G[i]) {
				if (flo[{u, m + i}] > 0) {
					przyp.push_back(u);
				}
			}
			
			for (int i = 0; i + 1 < (int) przyp.size(); i += 2) {
				wyn[przyp[i]] = gkol;
				wyn[przyp[i + 1]] = gkol;
				gkol++;
			}
		}
		
		for (int i = 1; i <= m; ++i) {
			if (!wyn[i]) {
				wyn[i] = gkol++;
			}
		}
	}
	
	for (int i = 1; i <= m; ++i) printf("%d ", wyn[i]);
	printf("\n");
}

int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) solve();
	return 0;
}