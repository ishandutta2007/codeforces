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

#define MAX_N 1024000

Mod fact[MAX_N], factinv[MAX_N];
void init() {
	fact[0] = Mod(1); factinv[0] = 1;
	for (int i = 0; i < MAX_N - 1; ++i) {
		fact[i + 1] = fact[i] * Mod(i + 1);
		factinv[i + 1] = factinv[i] / Mod(i + 1);
	}
}
Mod comb(const int a, const int b) {
	return fact[a] * factinv[b] * factinv[a - b];
}


template<typename T>
vector<vector<T>> keisann(const vector<vector<T>>l, const vector<vector<T>>r) {
	vector<vector<T>>ans(l.size(), vector<T>(r[0].size()));
	assert(l[0].size() == r.size());
	for (unsigned int h = 0; h < l.size(); ++h) {
		for (unsigned int i = 0; i < r.size(); ++i) {
			for (unsigned int w = 0; w < r[0].size(); ++w) {

				ans[h][w] += l[h][i] * r[i][w];
			}
		}
	}
	return ans;
}
template<typename T>
vector<vector<T>>powgyou(vector<vector<T>>a, const long long int n) {
	assert(a.size() == a[0].size());
	if (!n) {
		vector<vector<T>>e(a.size(), vector<T>(a[0].size()));
		for (unsigned int i = 0; i < a.size(); ++i) {
			e[i][i] = 1;
		}
		return e;
	}
	if (n == 1)return a;
	else {
		vector<vector<T>>ans(a.size(), vector<T>(a[0].size(), 0));
		ans = powgyou(a, n / 2);
		ans = keisann(ans, ans);
		if (n % 2) {
			ans = keisann(ans, a);
		}
		return ans;
	}
}

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(auto i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

const int INF = 2147483647;
const long long int L_INF = 9223372036854775807;

typedef int Weight;
struct Edge {
	int src, dst;
	Weight weight;
	Edge(int src, int dst, Weight weight) :
		src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
	return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
	e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;
#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])

vector<pair<int, int>>uses;

//0t
Weight maximumFlow(const Graph &ag, int s, int t) {

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
				g[d].push_back(Edge(d, s, 0));
			}
		}
	}

	int n = g.size();
	Matrix flow(n, Array(n)), capacity(n, Array(n));
	REP(u, n) FOR(e, g[u]) capacity[e->src][e->dst] += e->weight;

	Weight total = 0;
	while (1) {
		queue<int> Q; Q.push(s);
		vector<int> prev(n, -1); prev[s] = s;
		while (!Q.empty() && prev[t] < 0) {
			int u = Q.front(); Q.pop();
			FOR(e, g[u]) if (prev[e->dst] < 0 && RESIDUE(u, e->dst) > 0) {
				prev[e->dst] = u;
				Q.push(e->dst);
			}
		}
		if (prev[t] < 0) return total; // prev[x] == -1 <=> t-side
		Weight inc = INF;
		for (int j = t; prev[j] != j; j = prev[j])
			inc = min(inc, RESIDUE(prev[j], j));
		for (int j = t; prev[j] != j; j = prev[j])
			flow[prev[j]][j] += inc, flow[j][prev[j]] -= inc;
		total += inc;
	}
}

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

bool isso(long long int a) {
	if (a == 1)return false;
	for (long long int i = 2; i*i <= a; ++i) {
		if (!(a%i)) {
			return false;
		}
		else {
		}
	}
	return true;
}


struct vert {
	int deg;
	int s;
	int id;
	vert(int a, int b, int c) {
		deg = a;
		s = b;
		id = c;
	}
};


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
class Compare {
public:
	bool operator()(const pair<int, int>&l, const pair<int, int>&r) {
		return l.second > r.second;
	}
};

long long int powint(long long int a, int b) {
	if (b == 0)return 1;
	if (b == 1)return a;
	else {
		long long int ans = 1;
		long long int c = powint(a, b / 2);
		ans *= c*c;
		ans *= (b % 2) ? a : 1;
		return ans;
	}

}

int asize;
long long int N;

vector<vector<bool>>anss;

void change(const vector<bool>from,int num) {
	{
		vector<bool>nans(asize, false);
		for (int i = 0; i < num; ++i) {
			for (int j = 0; j < (asize / num) / 2; ++j) {
				nans[i*(asize / num) + (asize / num)/2 + j] = !from[i*(asize / num) + (asize / num) / 2 + j];
			}
			for (int j = 0; j < (asize / num) / 2; ++j) {
				nans[i*(asize / num) + j] = from[i*(asize / num) + j];
			}

		}
		anss.push_back(nans);
		if (num*2 != asize) {
			change(nans, num*2);
		}
	}
	{
		vector<bool>nans(asize, false);
		for (int i = 0; i < num; ++i) {
			if (i < num / 2) {
				for (int j = 0; j < (asize / num) / 2; ++j) {
					nans[i*(asize / num) + (asize / num) / 2 + j] = from[i*(asize / num) + (asize / num) / 2 + j];
				}
				for (int j = 0; j < (asize / num) / 2; ++j) {
					nans[i*(asize / num) + j] = !from[i*(asize / num) + j];
				}
			}
			else {
				for (int j = 0; j < (asize / num) / 2; ++j) {
					nans[i*(asize / num) + (asize / num) / 2 + j] = !from[i*(asize / num) + (asize / num) / 2 + j];
				}
				for (int j = 0; j < (asize / num) / 2; ++j) {
					nans[i*(asize / num) + j] = from[i*(asize / num) + j];
				}
			}
		}
		anss.push_back(nans);
		if (num*2 != asize) {
			change(nans, num*2);
		}
	}
}

int main() {
cin >> N;
	asize = powint(2, N);
	
	anss.push_back(vector<bool>(asize, false));

	for (int i = 0; i < N; ++i) {
		
		int nownum = anss.size();
		for (int j = 0; j < nownum; ++j) {
			vector<bool>nans(asize);
			for (int l = 0; l < powint(2, i); ++l) {

				for (int k = l*(asize/powint(2,i)); k < l*(asize / powint(2, i))+(asize / powint(2, i))/2; ++k) {
					nans[k] = anss[j][k];
				}
				for (int k = l*(asize / powint(2, i))+(asize / powint(2, i)) / 2; k <l*(asize / powint(2, i))+ asize / powint(2, i); ++k) {
					nans[k] = !anss[j][k];
				}

			}
			anss.push_back(nans);
		}

	}

	for (int i = 0; i < anss.size(); ++i) {
		for (int j = 0; j < anss[i].size(); ++j) {
			if (anss[i][j])cout << "+";
			else cout << "*";

		}
		cout << endl;
	}


	return 0;
}