#include<stdio.h>
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <functional>
#include <stdio.h>
#include <array>
#include <algorithm>
#include <string>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <queue>
#include<iomanip>
#include<bitset>
#include<stack>
#include<set>
#include<limits>
#include <complex>
using namespace std;

map<long long int, int>soinnsuu(long long int a) {
	map<long long int, int>ans;
	for (long long i = 2; i*i <= a; ++i) {
		while (a%i == 0) {
			ans[i]++;
			a /= i;
		}
	}
	if (a != 1)ans[a]++;


	return ans;
}


const int mod = 1000000007;
struct Mod {
public:
	int num;
	Mod() : num(0) { ; }
	Mod(long long int n) : num((n % mod + mod) % mod) { ; }
	Mod(int n) : num((n % mod + mod) % mod) { ; }
	operator int() { return num; }
};

Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
Mod operator++(Mod &a) { return a + Mod(1); }
Mod operator-(const Mod a, const Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a - Mod(1); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
Mod operator^(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = (a * a) ^ (n / 2);
	if (n % 2) res = res * a;
	return res;
}
Mod inv(const Mod a) { return a ^ (mod - 2); }
Mod operator/(const Mod a, const Mod b) {
	assert(b.num != 0);
	return a * inv(b);
}
Mod operator/(const long long int a, const Mod b) {
	assert(b.num != 0);
	return Mod(a) * inv(b);
}
Mod operator/=(Mod &a, const Mod b) {
	assert(b.num != 0);
	return a = a * inv(b);
}

#define MAX_MOD_N 1024000

Mod fact[MAX_MOD_N], factinv[MAX_MOD_N];
void init() {
	fact[0] = Mod(1); factinv[0] = 1;
	for (int i = 0; i < MAX_MOD_N - 1; ++i) {
		fact[i + 1] = fact[i] * Mod(i + 1);
		factinv[i + 1] = factinv[i] / Mod(i + 1);
	}
}
Mod comb(const int a, const int b) {
	return fact[a] * factinv[b] * factinv[a - b];
}




#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(auto i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()


const int INF = 2147483647;
const long long int L_INF = 9223372036854775807;

typedef int Weight;
struct Edge {
	int src, dst;
	Weight capacity;
	Weight cost;
	Edge(int src, int dst, Weight acap,Weight acost) :
		src(src), dst(dst), capacity(acap),cost(acost) { }
};
bool operator < (const Edge &e, const Edge &f) {
	return e.cost > f.cost;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;
#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])


#define RCOST(u,v) (cost[u][v] + h[u] - h[v])

pair<Weight, Weight> minimumCostFlow(const Graph &ag, int s, int t) {
	Graph g(ag);
	for (int i = 0; i < ag.size(); ++i) {
		for (int j = 0; j < ag[i].size(); ++j) {
			int d = ag[i][j].dst;
			int s = ag[i][j].src;
	
			bool ok = false;
			for (int k = 0; k < ag[d].size(); ++k) {
				if (ag[d][k].src == s) {
					ok = true;
					break;
				}
			}
			if (!ok) {
g[d].push_back(Edge(d, s, 0, ag[i][j].cost));
			}
		}
	}
	const int n = g.size();
	Matrix capacity(n, Array(n)), cost(n, Array(n)), flow(n, Array(n));
	REP(u, n) FOR(e, g[u]) {
		capacity[e->src][e->dst] += e->capacity;
		cost[e->src][e->dst] += e->cost;
	}
	pair<Weight, Weight> total; // (cost, flow)
	vector<Weight> h(n);

	for (Weight F = INF; F > 0; ) { // residual flow
		vector<Weight> d(n, INF); d[s] = 0;
		vector<int> p(n, -1);
		priority_queue<Edge> Q; // "e < f" <=> "e.cost > f.cost"
		for (Q.push(Edge(-2, s, 0, 0)); !Q.empty(); ) {
			Edge e = Q.top(); Q.pop();
			if (p[e.dst] != -1) continue;
			p[e.dst] = e.src;
			FOR(f, g[e.dst]) if (RESIDUE(f->src, f->dst) > 0) {
				if (d[f->dst] > d[f->src] + RCOST(f->src, f->dst)) {
					d[f->dst] = d[f->src] + RCOST(f->src, f->dst);
					Q.push(Edge(f->src, f->dst, 0, d[f->dst]));
				}
			}
		}
		if (p[t] == -1) break;

		Weight f = F;
		for (int u = t; u != s; u = p[u])
			f = min(f, RESIDUE(p[u], u));
		for (int u = t; u != s; u = p[u]) {
			total.first += f * cost[p[u]][u];
			flow[p[u]][u] += f; flow[u][p[u]] -= f;
		}
		F -= f;
		total.second += f;
		REP(u, n) h[u] += d[u];
	}
	return total;
}





long long int powint(long long int a, long long int b) {
	assert(b >= 0);
	if (b == 0)return 1;
	if (b == 1)return a;
	long long int ans = 1;
	long long int aa = powint(a, b / 2);
	ans *= aa*aa;
	ans %= mod;
	if (b % 2)ans *= a;

	ans %= mod;
	return ans;
}
long long int gcd(long long int l, long long int r) {
	assert(l > 0 && r > 0);
	if (l > r)return gcd(r, l);
	else {
		if (r%l) {
			return gcd(l, r%l);

		}
		else {
			return l;
		}
	}
}



int main() {
	int n; cin >> n;
	int sx, sy; cin >> sx >> sy;
	vector<pair<int, int>>katamuki;
	for (int i = 0; i < n; ++i) {
		int x, y; cin >> x >> y;
		x -= sx; y -= sy;
		if (x == 0) {
			katamuki.push_back(make_pair(0, 1));
		}
		else if (y == 0) {
			katamuki.push_back(make_pair(1, 0));
		}
		else {
			bool xminus = false, yminus = false;
			if (x < 0) {
				xminus = true;
				x = -x;
			}
			if (y < 0) {
				yminus = true;
				y = -y;
			}
			int a = gcd(x, y);
			x /= a;
			y /= a;
			if ((xminus&&!yminus) || (!xminus&&yminus)){
				x = -x;

			}
			katamuki.push_back(make_pair(y, x));
		}
	}
	sort(katamuki.begin(), katamuki.end(), [](const pair<int, int>&l, const pair<int, int>&r) {return l.first == r.first ? l.second < r.second : l.first < r.first; });

	int ans = unique(katamuki.begin(), katamuki.end()) - katamuki.begin();
	cout << ans << endl;
	return 0;
}