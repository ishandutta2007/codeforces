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
#include <assert.h>
#include <stdio.h>
#include <queue>
#include<iomanip>
#include<bitset>
#include<stack>
using namespace std;

//7:10
//
//#define REP(i,n) for(int i=0;i<(int)n;++i)
//#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
//#define ALL(c) (c).begin(), (c).end()
//
//typedef int Weight;
//struct Edge {
//  int src, dst;
//  Weight weight;
//  Edge(int src, int dst, Weight weight) :
//      src(src), dst(dst), weight(weight) { }
//};
//bool operator < (const Edge &e, const Edge &f) {
//  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
//  e.src != f.src ? e.src < f.src : e.dst < f.dst;
//}
//typedef vector<Edge> Edges;
//typedef vector<Edges> Graph;
//
//typedef vector<Weight> Array;
//typedef vector<Array> Matrix;
//
//#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])
//Weight maximumFlow(const Graph &g, int s, int t) {
//  int n = g.size();
//  Matrix flow(n, Array(n)), capacity(n, Array(n));
//  REP(u, n) for (auto e = g[u].begin(); e != g[u].end();++e)capacity[e->src][e->dst] += e->weight;
//
//  Weight total = 0;
//  while (1) {
//      queue<int> Q; Q.push(s);
//      vector<int> prev(n, -1); prev[s] = s;
//      while (!Q.empty() && prev[t] < 0) {
//          int u = Q.front(); Q.pop();
//          for (auto e = g[u].begin(); e != g[u].end(); ++e) if (prev[e->dst] < 0 && RESIDUE(u, e->dst) > 0) {
//              prev[e->dst] = u;
//              Q.push(e->dst);
//          }
//      }
//      if (prev[t] < 0) return total; // prev[x] == -1 <=> t-side
//      Weight inc = 999999999;
//      for (int j = t; prev[j] != j; j = prev[j])
//          inc = min(inc, RESIDUE(prev[j], j));
//      for (int j = t; prev[j] != j; j = prev[j])
//          flow[prev[j]][j] += inc, flow[j][prev[j]] -= inc;
//      total += inc;
//  }
//  return total;
//}
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#include<assert.h>
const long long int mod = 1000000007;
const long long int mod2 = 1000000009;

struct Mod {
	int num;
	Mod() : num(0) { ; }
	Mod(long long int n) : num((n % mod + mod) % mod) { ; }
	Mod(int n) : num((n % mod + mod) % mod) { ; }
	operator int() { return num; }
};

Mod operator+(Mod a, Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator+(long long int a, Mod b) { return Mod(a) + b; }
Mod operator-(Mod a, Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator-(long long int a, Mod b) { return Mod(a) - b; }
Mod operator*(Mod a, Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator*(long long int a, Mod b) { return Mod(a)*b; }
Mod operator+=(Mod &a, Mod b) { return a = a + b; }
Mod operator+=(long long int &a, Mod b) { return a = a + b; }
Mod operator-=(Mod &a, Mod b) { return a = a - b; }
Mod operator-=(long long int &a, Mod b) { return a = a - b; }
Mod operator*=(Mod &a, Mod b) { return a = a * b; }
Mod operator*=(long long int &a, Mod b) { return a = a * b; }
Mod operator^(Mod a, long long int n) {
	if (n == 0) return Mod(1);
	Mod res = (a * a) ^ (n / 2);
	if (n % 2) res = res * a;
	return res;
}
Mod inv(Mod a) { return a ^ (mod - 2); }
Mod operator/(Mod a, Mod b) {
	assert(b != 0);
	return a * inv(b);
}
Mod operator/(long long int a, Mod b) {
	assert(b != 0);
	return Mod(a) * inv(b);
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
Mod comb(int a, int b) {
	return fact[a] * factinv[b] * factinv[a - b];
}




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

using namespace std;
//#define len(val) static_cast<long long>(val.size())
//#define rep(i, n) for(int i=0; i<(n); i++)
//typedef long long ll;
//typedef pair<int, int> P;
//
//struct RollingHash {
//	static const ll mul0 = 10009, mul1 = 10007;
//	static const ll add0 = 1000010007, add1 = 1003333331;
//	string s; int l;
//	ll hash_[300], pmo_[300];
//	void init(string s) {
//		this->s = s; l = s.size();
//		hash_[0] = 0; pmo_[0] = 1;
//		rep(i, l) pmo_[i + 1] = pmo_[i] * mul0;
//		rep(i, l) hash_[i + 1] = (hash_[i] * mul0 + s[i]);
//	}
//	ll hash(int l, int r) { // s[l..r]
//		return hash_[r + 1] - hash_[l] * pmo_[r + 1 - l];
//	}
//};
//
//int R, C;
//string S[2][300];
//ll ret;
//RollingHash rh[2][260];


int main() {
	int a[5];
	int w[5];
	for (int i = 0; i < 5; ++i) {
		int b;
		cin >> a[i];
	}
	for (int i = 0; i < 5; ++i) {
		int b;
		cin >> w[i];
	}
	int p = 0;
	for (int i = 0; i < 5; ++i) {
		p += max(75 * (i + 1) * 500, (250 - a[i])*(i + 1) * 500 - 12500 * w[i]);
	}
	p /= 250;
	int s;
	int f;
	cin >> s >> f;
	p += 100 * s - 50 * f;


	cout << p << endl;
	
}