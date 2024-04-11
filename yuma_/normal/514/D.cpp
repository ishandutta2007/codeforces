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


class Hei {


public:
	const int normalsize;
	vector<pair<vector<long long int>, long long int>>squares;


	Hei(const int n, const long long int initializenum) :normalsize(static_cast<int>(sqrt(static_cast<double>(n)))) {
		int rest = n;
		while (rest > 0) {
			squares.push_back(make_pair(vector<long long int>(min(rest, normalsize), initializenum), initializenum));
			rest -= normalsize;
		}
	}

	void update(const long long int i, const long long int x) {
		int square = i / normalsize;
		squares[square].first[i - square*normalsize] = x;
		long long int amax(0);
		for (int i = 0; i < squares[square].first.size(); ++i) {
			amax = max(squares[square].first[i], amax);
		}
		squares[square].second = amax;
	}

	//[l,r]
	long long int get(const int l, const int r) {
		assert(l <= r);

		const int lsquare = l / normalsize;
		const int rsquare = r / normalsize;
		if (lsquare == rsquare) {
			long long int amax(0);
			for (int i = l - lsquare*normalsize; i <= r - rsquare*normalsize; ++i) {
				amax = max(amax, squares[lsquare].first[i]);
			}
			return amax;
		}
		else {
			long long int amax(0);
			for (int i = l - lsquare*normalsize; i < squares[lsquare].first.size(); ++i) {
				amax = max(amax, squares[lsquare].first[i]);
			}
			for (int i = lsquare + 1; i < rsquare; ++i) {
				amax = max(amax, squares[i].second);
			}
			for (int i = 0; i <= r - rsquare*normalsize; ++i) {
				amax = max(amax, squares[rsquare].first[i]);
			}
			return amax;
		}
	}
};

bool operator<(const pair<long long int, long long int>&l, const pair<long long int, long long int>&r) {
	return l.first == r.first ? l.second < r.second : l.first < r.first;
}

int main() {
	int n;long long int  m, k; cin >> n >> m >> k;
	vector<Hei>bits;
	for (int i = 0; i < m; ++i) {
		bits.push_back(Hei(n, 0));
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			long long int a; cin >> a;
			bits[j].update(i, a);
		}
	}

	int ans = 0;
	int ansfrom = 0;
	int ansto = 0;
	int from = 0;//[
	int to = 0;//)
	while (to<=n-1) {

		long long int neednum = 0;
		vector<long long int>nums;
		for (int i = 0; i < m; ++i) {
			int a = bits[i].get(from, to);
			neednum += a;
			nums.push_back(a);
		}
		if (neednum <= k) {
			if (ans <= to - from + 1) {
				ans = max(ans, to - from + 1);
				ansfrom = from;
				ansto = to;
			}
			to++;
		}
		else {
			from++;
		}
		if (from > to) {
			to++;
		}
	}

	vector<long long int>ansattack;
	if (ans != 0) {
		for (int i = 0; i < m; ++i) {
			int a = bits[i].get(ansfrom, ansto);
			ansattack.push_back(a);
		}
	}
	else {
		for (int i = 0; i < m; ++i) {
			ansattack.push_back(0);
		}
	}
	
	for (int i = 0; i < ansattack.size(); ++i) {
		cout << ansattack[i];
		if (i != ansattack.size() - 1)cout << " ";
	}
	cout <<endl;
	return 0;
}