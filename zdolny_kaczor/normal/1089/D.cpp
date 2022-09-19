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

using ll = long long;
const int N = 1e5 + 7;
ll wynik = 0;

vector<int> G[N];
int deg[N];
int n, m;
int wag[N];
int usu[N]; //czy usunelismy

int gruby[N];
int odw[N];

const int M = 107;
int odl[M][M];
int nnum[N];

struct lancuch {
	int a, b;
	vector<int> sci;
};

vector<lancuch> L;

void sciezka(vector<int> wagi, int dist) {
	debug << imie(wagi) imie(dist);
	ll ans = 0;
	int l = wagi.size();
	{//wzorcwka
		vector <ll> prefsum(l + 1), prefcou(l + 1);
		for (int i = 0; i < l; ++i) {
			prefsum[i + 1] = prefsum[i] + i * 1ll * wagi[i];
			prefcou[i + 1] = prefcou[i] + wagi[i];
		}
		debug << imie(prefsum) imie(prefcou);
		for (int i = 0; i < l; ++i) {
			int x = min(l - 1, (2 * i + 1 + dist + l) / 2);
			debug << imie(i) imie(x);
			ll add1 = prefsum[x + 1] - prefsum[i] - i * 1ll * (prefcou[x + 1] - prefcou[i]);
			ll add2 = (l + i + dist + 1) * (prefcou[l] - prefcou[x + 1]) - (prefsum[l] - prefsum[x + 1]);
			debug << imie(add1) imie(add2);
			ans += wagi[i] * (add1 + add2);
		}
	}
	#ifdef LOCAL
	ll brans = 0;
	for (int i = 0; i < l; ++i)
		for (int j = i + 1; j < l; ++j)
			brans += wagi[i] * 1ll * wagi[j] * min(j - i, dist + (l + 1) - (j - i));
	debug << imie(ans) imie(brans);
	assert(ans == brans);
	#endif
	debug << imie(ans);
	wynik += ans;
}
sim> c min4(c x, c y, c z, c t) {
	return min(min(x, y), min(z, t));
}
void dwieSciezki(vector<int> w1, vector<int> w2, int d00, int d01, int d10, int d11) {
	debug << imie(w1) imie(w2) imie(d00) imie(d01) imie(d10) imie(d11);
	ll ans = 0;
	int l1 = w1.size() , l2 = w2.size();
	{//wzorcwka
		vector <ll> prefsum(l2 + 1), prefcou(l2 + 1);
		for (int i = 0; i < l2; ++i) {
			prefsum[i + 1] = prefsum[i] + i * 1ll * w2[i];
			prefcou[i + 1] = prefcou[i] + w2[i];
		}
		debug << imie(prefsum) imie(prefcou);
		for (int i = 0; i < l1; ++i) {
			int db = min(d00 + i + 1, d10 + l1 - i);
			int de = min(d01 + i + 1, d11 + l1 - i);
			int h = de - db + l2 - 1;
			int x = (h < 0 ? -1 : min(l2 - 1, h / 2));
			debug << imie(de) imie(db) imie(h) imie(x);
			ll add1 = prefsum[x + 1] + (db + 1) * prefcou[x + 1];
			ll add2 = -(prefsum[l2] - prefsum[x + 1]) + (de + l2) * (prefcou[l2] - prefcou[x + 1]);
			debug << imie(add1) imie(add2);
			ans += w1[i] * (add1 + add2);
		}
	}
	#ifdef LOCAL
	ll brans = 0;
	for (int i = 0; i < l1; ++i)
		for (int j = 0; j < l2; ++j)
			brans += w1[i] * 1ll * w2[j] * min4(d00 + (i + 1) + (j + 1), d01 + (i + 1) + (l2 - j), d10 + (l1 - i) + (j + 1), d11 + (l1 - i) + (l2 - j));
	debug << imie(ans) imie(brans);
	assert(ans == brans);
	#endif
	debug << imie(ans);
	wynik += ans;
}

vector<int> spojna;

void dfs0(int v) {
	odw[v] = 1;
	spojna.push_back(v);
	for (int u : G[v]) {
		if (!odw[u]) dfs0(u);
	}
}

int bfsDist[N];
int bfsVis[N];

void bfs(int s) {
	for (int i = 1; i <= n; ++i) bfsVis[i] = usu[i];
	vector<int> q;
	bfsDist[s] = 0;
	bfsVis[s] = 1;
	q.push_back(s);
	
	for (int it = 0; it < (int) q.size(); ++it) {
		int v = q[it];
		for (int u : G[v]) {
			if (!bfsVis[u]) {
				bfsVis[u] = 1;
				bfsDist[u] = bfsDist[v] + 1;
				q.push_back(u);
			}
		}
	}
	
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		if (!usu[i]) {
			if (!gruby[i] || i > s) {
				res += 1ll * wag[i] * bfsDist[i];
			}
		}
	}
	
	wynik += res * wag[s];
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		deg[a]++; deg[b]++;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	for (int i = 1; i <= n; ++i) wag[i] = 1;
	
	vector<int> liscie;
	for (int i = 1; i <= n; ++i) if (deg[i] == 1) liscie.push_back(i);
	
	int rem = n;
	while (!liscie.empty()) {
		int v = liscie.back();
		liscie.pop_back();
		usu[v] = 1;
		rem--;
		
		int par = 0;
		for (int u : G[v]) {
			if (!usu[u]) par = u;
		}
		
		if (par == 0) continue;
	
		wynik += 1ll * wag[v] * (n - wag[v]);
		wag[par] += wag[v];
		
		deg[par]--;
		if (deg[par] == 1) liscie.push_back(par);
	}
	
	if (rem == 0) {
		printf("%lld\n", wynik);
		return 0;
	}
	
	debug << "wynik przed " imie(wynik);
	debug << range(usu + 1, usu + n + 1);
	
	vector<int> grube;
	int last = 0;
	for (int i = 1; i <= n; ++i) {
		if (usu[i]) continue;
		last = i;
		if (deg[i] > 2) {
			gruby[i] = 1;
			grube.push_back(i);
		}
	}
	
	if (grube.empty()) {
		grube.push_back(last);
		gruby[last] = 1;
	}
	
	for (int i = 1; i <= n; ++i) if (usu[i] || gruby[i]) odw[i] = 1;
	
	int ileG = 0;
	for (int v : grube) {
		nnum[v] = ++ileG;
	}
	
	for (int i = 1; i <= ileG; ++i) {
		for (int j = 1; j <= ileG; ++j) odl[i][j] = n + 7;
	}
	
	for (int v : grube) {
		for (int u : G[v]) {
			if (!odw[u]) {
				dfs0(u);
				
				int kon = spojna.back();
				int zabr = v;
				if ((int) spojna.size() > 1) zabr = 0;
				int dokad = 0;
				
				for (int z : G[kon]) {
					if (gruby[z] && z != zabr) {
						dokad = z;
					}
				}
				
				assert (dokad);
				
				vector<int> swagi;
				for (int x : spojna) swagi.push_back(wag[x]);
				
				int a = nnum[v];
				int b = nnum[dokad];
				
				odl[a][b] = min(odl[a][b], (int) swagi.size() + 1);
				odl[b][a] = min(odl[b][a], (int) swagi.size() + 1);
				
				lancuch l;
				l.a = a;
				l.b = b;
				l.sci = swagi;
				L.push_back(l);
				
				spojna.clear();
			}
		}
	}
	
	for (int v : grube) {
		for (int u : G[v]) {
			if (gruby[u]) {
				odl[nnum[v]][nnum[u]] = odl[nnum[u]][nnum[v]] = 1;
			}
		}
	}
	
	for (int i = 1; i <= ileG; ++i) odl[i][i] = 0;
	
	for (int k = 1; k <= ileG; ++k) {
		for (int i = 1; i <= ileG; ++i) {
			for (int j = 1; j <= ileG; ++j) {
				odl[i][j] = min(odl[i][j], odl[i][k] + odl[k][j]);
			}
		}
	}
	
	for (int i = 0; i < (int) L.size(); ++i) {
		sciezka(L[i].sci, odl[L[i].a][L[i].b]);
		for (int j = i + 1; j < (int) L.size(); ++j) {
			int a = L[i].a;
			int b = L[i].b;
			int c = L[j].a;
			int d = L[j].b;
			dwieSciezki(L[i].sci, L[j].sci, odl[a][c], odl[a][d], odl[b][c], odl[b][d]);
		}
	}
	
	for (int v : grube) {
		bfs(v);
	}
	printf("%lld\n", wynik);
	return 0;
}
/*
dwieSciezki#94: [w1: [1]] [w2: [1]] [d00: 2] [d01: 1] [d10: 2] [d11: 3] 
dwieSciezki#103: [prefsum: [0, 0]] [prefcou: [0, 1]] 
dwieSciezki#109: [de: 2] [db: 3] [h: 0] [x: 0] 
dwieSciezki#112: [add1: 4] [add2: 0] 
dwieSciezki#121: [ans: 4] [brans: 3] 

*/