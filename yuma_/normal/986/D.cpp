#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;


//namespace cent {
//
//	struct Edge {
//		int src;
//		int dst;
//		long long int cost;
//	};
//	using Graph = vector<vector<Edge>>;
//
//	class Centroid {
//	private:
//		int dfs(const Graph&g, const int now, const int from, vector<int>&ch_nums, const vector<int>&oks) {
//			int sum = 1;
//			for (auto &&e : g[now]) {
//				if (e.dst == from || oks[e.dst] != -1)continue;
//				else {
//					sum += dfs(g, e.dst, e.src, ch_nums, oks);
//				}
//			}
//			return ch_nums[now] = sum;
//		}
//
//		int find_centroid(const int asize, const vector<vector<Edge>>&graph, const int pre_root, const int pre_from, const vector<int>&ch_nums, const vector<int>&oks) {
//			for (auto&& e : graph[pre_root]) {
//				if (e.dst == pre_from)continue;
//				if (oks[e.dst] != -1)continue;
//				if (ch_nums[e.dst]>asize / 2)return find_centroid(asize, graph, e.dst, e.src, ch_nums, oks);
//			}
//			return pre_root;
//		}
//
//		void dfs2(const Graph&g, const int root,const int now, const int from, const vector<int>&oks,int depth) {
//			mp[make_pair(root,now)]=depth;
//			for (auto &&e : g[now]) {
//				if (e.dst == from || oks[e.dst] != -1)continue;
//				else {
//					dfs2(g,root,e.dst,e.src,oks,depth+1);
//				}
//			}
//		};
//
//
//		void cent(const vector<vector<Edge>>&graph, vector<int>&oks, const int root, const int from, vector<vector<int>>&centroid_edges, int& fst_centroid, int depth, vector<int>&ch_nums) {
//			dfs(graph, root, from, ch_nums, oks);
//
//			int cent_id = find_centroid(ch_nums[root], graph, root, from, ch_nums, oks);
//
//
//			dfs2(graph,cent_id,cent_id,-1,oks,0);
//			lens1[cent_id][make_pair(0,0)]--;
//			lens2[cent_id][0]--;
//
//
//			oks[cent_id] = depth;
//
//			//for (auto&& e : graph[cent_id]) {
//			//	if (e.dst == from)continue;
//			//	if (oks[e.dst] != -1)continue;
//
//			//	dfs2(graph, e.dst, e.dst, e.src, oks,e.cost%mod,e.cost%mod,1);
//
//			//	for (auto&& l1 : lens1[e.dst]) {
//			//		int keta = l1.first.second;
//			//		long long int num = l1.first.first;
//
//			//		long long int need = (mod - num) / mod_pow(10, keta);
//			//		need%=mod;
//			//		auto it = lens2[e.dst].find(need);
//			//		if (it != lens2[e.dst].end()) {
//			//			ans -= l1.second*it->second;
//			//		}
//			//	}
//			//	lens1[e.dst].clear();
//			//	lens2[e.dst].clear();
//			//}
//
//			if (from != -1) {
//				centroid_edges[from].push_back(cent_id);
//			}
//			else {
//				fst_centroid = cent_id;
//			}
//			for (auto&& e : graph[cent_id]) {
//				if (e.dst == from)continue;
//				if (oks[e.dst] != -1)continue;
//				cent(graph, oks, e.dst, e.src, centroid_edges, fst_centroid, depth + 1, ch_nums);
//			}
//		}
//
//	public:
//
//		map<pair<int,int>,int>mp;
//
//		vector<map<pair<long long int,int>, long long int>>lens1;
//		vector<map<long long int, long long int>>lens2;
//		vector<vector<int>> centroid_graph;
//		vector<int>ts;
//		vector<int>parents;
//		vector<int>oks;
//		vector<int>anss;
//
//		//fst:root  snd:centroid_graph
//		void init(const Graph&g) {
//			lens1.resize(g.size());
//			lens2.resize(g.size());
//			oks = vector<int>(g.size(), -1);
//			int root = -1;
//			centroid_graph.resize(g.size());
//			parents = vector<int>(g.size(), -1);
//			ts=vector<int>(g.size(),-1);
//			anss=vector<int>(g.size(),100000);
//
//			vector<int>ch_nums(g.size());
//			cent(g, oks, 0, -1, centroid_graph, root, 0, ch_nums);
//
//			for (int i = 0; i < centroid_graph.size(); ++i) {
//				for (auto&& e : centroid_graph[i]) {
//					parents[e] = i;
//				}
//			}
//			return ;
//		}
//	}centroid;
//
//
//	void addEdge(Graph& g, int a, int b, long long int c) {
//		g[a].push_back(Edge{ a,b,c });
//		g[b].push_back(Edge{ b,a,c });
//	}
//}


//const int mod = 1000000007;
//struct Mod {
//public:
//	int num;
//	Mod() : Mod(0) { ; }
//	Mod(long long int n) : num((n % mod + mod) % mod) {
//		static_assert(mod<INT_MAX / 2, "mod is too big, please make num 'long long int' from 'int'");
//	}
//	Mod(int n) : Mod(static_cast<long long int>(n)) { ; }
//	operator int() { return num; }
//};
//
//Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mod); }
//Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
//Mod operator+(const Mod a, const long long int  b) { return b + a; }
//Mod operator++(Mod &a) { return a + Mod(1); }
//Mod operator-(const Mod a, const Mod b) { return Mod((mod + a.num - b.num) % mod); }
//Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
//Mod operator--(Mod &a) { return a - Mod(1); }
//Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mod); }
//Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
//Mod operator*(const Mod a, const long long int b) { return Mod(b)*a; }
//Mod operator*(const Mod a, const int b) { return Mod(b)*a; }
//Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
//Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
//Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
//Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
//Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
//Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
//Mod operator*=(Mod& a, const long long int &b) { return a = a * b; }
//Mod operator^(const Mod a, const int n) {
//	if (n == 0) return Mod(1);
//	Mod res = (a * a) ^ (n / 2);
//	if (n % 2) res = res * a;
//	return res;
//}
//Mod mod_pow(const Mod a, const long long  int n) {
//	if (n == 0) return Mod(1);
//	Mod res = mod_pow((a * a), (n / 2));
//	if (n % 2) res = res * a;
//	return res;
//}
//
////mod extend euclid 
//Mod inv(const Mod a) { return a ^ (mod - 2); }
//Mod operator/(const Mod a, const Mod b) {
//	assert(b.num != 0);
//	return a * inv(b);
//}
//Mod operator/(const long long int a, const Mod b) {
//	return Mod(a) / b;
//}
//Mod operator/=(Mod &a, const Mod b) {
//	return a = a / b;
//}
//
//#define MAX_MOD_N 1024000
//
//Mod fact[MAX_MOD_N], factinv[MAX_MOD_N];
//void init(const int amax = MAX_MOD_N) {
//	fact[0] = Mod(1); factinv[0] = 1;
//	for (int i = 0; i < amax - 1; ++i) {
//		fact[i + 1] = fact[i] * Mod(i + 1);
//		factinv[i + 1] = factinv[i] / Mod(i + 1);
//	}
//}
//Mod comb(const int a, const int b) {
//	return fact[a] * factinv[b] * factinv[a - b];
//}
//
//vector<int>primes;
//void hurui(const int amax=3500) {
//	static bool flag = false;
//	if (flag)return;
//	vector<int>sos;
//	sos = vector<int>(amax + 1, true);
//	sos[0] = false; sos[1] = false;
//	for (int i = 2; i <= amax; ++i) {
//		if (sos[i]) {
//			for (int j = 2 * i; j <= amax; j += i)sos[j] = false;
//		}
//	}
//	for (int i = 0; i <= amax; ++i) {
//		if (sos[i]) {
//			primes.push_back(i);
//		}
//	}
//	flag = true;
//}
//
//
//struct query {
//	int u;
//	int v;
//	map<int,int>mp;
//};
//
//map<int, int>mk_mp(const int a) {
//	int rest(a);
//	map<int,int>as;
//	for (auto pr : primes) {
//		while (rest%pr == 0) {
//			as[pr]++;
//			rest /= pr;
//		}
//	}
//	if (rest!=1)as[rest]++;
//	return as;
//}
//
//#define Seg_Max_N (1<<18) 
//
//class Tree {
//public:
//	Tree(int V, int root) : V(V), root(root), cnum(V), place(V), id(V) {
//		T.resize(V);
//		for (int i = 0; i < MAXLOGV; i++) {
//			parent[i].resize(V);
//		}
//		depth.resize(V);
//	}
//	// uv
//	// lca
//	void unite(int u, int v) {
//		T[u].push_back(v);
//		T[v].push_back(u);
//	}
//	void unite(vector<vector<int>>&e) {
//		T = e;
//	}
//	// init
//	// lca
//	void init() {
//		dfs(root, 0, 0);
//		int id = 0;
//		getid(root, 0, id);
//	}
//	// uvlca
//	int lca(int u, int v) const {
//		if (depth[u] > depth[v]) swap(u, v);
//		for (int k = 0; k < MAXLOGV; k++) {
//			if ((depth[v] - depth[u]) >> k & 1) {
//				v = parent[k][v];
//			}
//		}
//		if (u == v) return u;
//		for (int k = MAXLOGV - 1; k >= 0; k--) {
//			if (parent[k][u] != parent[k][v]) {
//				u = parent[k][u];
//				v = parent[k][v];
//			}
//		}
//		return parent[0][u];
//	}
//	// uv
//	// edge
//	int dist(int u, int v) const {
//		int p = lca(u, v);
//		return (depth[u] - depth[p]) + (depth[v] - depth[p]);
//	}
//	int dfs(int v, int p, int d) {
//		parent[0][v] = p;
//		depth[v] = d;
//		cnum[v] = 0;
//		for (int i = 1; i < MAXLOGV; i++) {
//			parent[i][v] = parent[i - 1][parent[i - 1][v]];
//		}
//		for (int next : T[v]) {
//			if (next != p) cnum[v] += dfs(next, v, d + 1);
//		}
//		return cnum[v] + 1;
//	}
//
//	void dfs2(int v, int p, vector<vector<int>>&doubles, const vector<int>&nums) {
//		for (int next : T[v]) {
//			if (next != p) dfs2(next, v, doubles, nums);
//		}
//		doubles[0][v] = nums[v];
//		for (int j = 1; j < MAXLOGV; ++j) {
//			doubles[j][v] = min(doubles[j][v], doubles[j - 1][v]);
//		}
//		for (int j = 0; j < MAXLOGV - 1; ++j) {
//			doubles[j + 1][parent[j][v]] = min(doubles[j + 1][parent[j][v]], doubles[j][v]);
//		}
//	}
//	//2^i
//	vector<vector<int>>get_doubles(const vector<int>&nums) {
//		vector<vector<int>>doubles(MAXLOGV, vector<int>(V, 1e9));
//		dfs2(root, -1, doubles, nums);
//		return doubles;
//	}
//
//	void getid(const int v, const int p, int &nplace) {
//		place[v] = nplace;
//		id[nplace] = v;
//		nplace++;
//		for (int next : T[v]) {
//			if (next != p) getid(next, v, nplace);
//		}
//	}
//	static const int MAXLOGV = 25;
//	// 
//	vector<vector<int> > T;
//	// 
//	int V;
//	// 
//	int root;
//
//	// 
//	vector<int> parent[MAXLOGV];
//	// 
//	vector<int> depth;
//
//	//
//	vector<int>cnum;
//
//	//
//	vector<int>place;
//	vector<int>id;
//
//};
//
//vector<int>pas;
//void adfs(vector<pair<int, int>>&lrs, vector<int>&tos,const vector<vector<int>>&edges, const int now, const int from,int &id) {
//	tos[now]=id;
//	lrs[tos[now]].first=id++;
//	for (auto e : edges[now]) {
//		if (e == from) {
//			pas[now] = from;
//			continue;
//		}
//		adfs(lrs,tos,edges,e,now,id);
//	}
//	lrs[tos[now]].second=id;
//}
//
//vector<pair<int, int>>get_lrs(vector<int>&tos,const vector<vector<int>>&edges, const int root) {
//	pas.resize(tos.size());pas[0]=-1;
//	vector<pair<int,int>>lrs(edges.size());
//	int id=0;
//	adfs(lrs,tos,edges,0,-1,id);
//	return lrs;
//}


namespace FastFourierTransform
{
	using C = complex< double >;

	void DiscreteFourierTransform(vector< C > &F, bool rev)
	{
		const int N = (int)F.size();
		const double PI = (rev ? -1 : 1) * acos(-1);
		for (int i = 0, j = 1; j + 1 < N; j++) {
			for (int k = N >> 1; k > (i ^= k); k >>= 1);
			if (i > j) swap(F[i], F[j]);
		}
		C w, s, t;
		for (int i = 1; i < N; i <<= 1) {
			for (int k = 0; k < i; k++) {
				w = polar(1.0, PI / i * k);
				for (int j = 0; j < N; j += i * 2) {
					s = F[j + k];
					t = C(F[j + k + i].real() * w.real() - F[j + k + i].imag() * w.imag(),
						F[j + k + i].real() * w.imag() + F[j + k + i].imag() * w.real());
					F[j + k] = s + t, F[j + k + i] = s - t;
				}
			}
		}
		if (rev) for (int i = 0; i < N; i++) F[i] /= N;
	}

	vector< int> Multiply(const vector< int > &A, const vector<int > &B)
	{
		int sz = 1;
		while (sz <= A.size() + B.size()) sz <<= 1;
		vector< C > F(sz), G(sz);
		for (int i = 0; i < A.size(); i++) F[i] = A[i];
		for (int i = 0; i < B.size(); i++) G[i] = B[i];
		DiscreteFourierTransform(F, false);
		DiscreteFourierTransform(G, false);
		for (int i = 0; i < sz; i++) F[i] *= G[i];
		DiscreteFourierTransform(F, true);
		vector< int > X(A.size() + B.size() - 1);
		for (int i = 0; i < A.size() + B.size() - 1; i++) X[i] = F[i].real() + 0.5;
		return (X);
	}
};

bool operator<(const vector<int>&l, const vector<int>&r) {
	if (l.size() != r.size())return l.size()<r.size();
	else {
		for (int i = 0; i < l.size(); ++i) {
			if (l[i]<r[i])return true;
			else if (l[i]>r[i])return false;
		}
		return false;
	}
}

vector<int>operator*(const vector<int>&l, const vector<int>&r) {
	vector<int>v;
	if (r.size() == 1) {
		v = l;
		for (int i = 0; i< v.size(); ++i) {
			v[i] *= r[0];
		}
	}
	else {
		v = FastFourierTransform::Multiply(l, r);

	}
	for (int i = v.size() - 1; i >= 1; --i) {
		if (v[i] >= 100) {
			v[i - 1] += v[i] / 100;
			v[i] %= 100;
		}
	}
	if (v[0] >= 100) {
		v.insert(v.begin(), v[0] / 100);
		v[1] %= 100;
	}
	return v;
}

vector<int>vpow(vector<int>&a, int num) {
	if (num == 0)return vector<int>(1, 1);
	if (num == 1)return a;
	else {
		auto b = vpow(a, num / 2);
		vector<int>ans(b);
		ans = ans*b;
		if (num % 2) {
			ans = ans*a;
		}
		return ans;
	}
}

vector<int> check(const vector<int>&v, int n, int k) {
	vector<int>th(1, 3);
	vector<int>tw(1, 2);
	auto x = vpow(th, k);
	auto y = vpow(tw, n);
	vector<int>s = x*y;
	return s;
}

int solve(vector<int>v) {
	int ans = 1e9;

	int xmin = 0;

	if (v.size() >= 500000) {
		xmin = v.size() * 2 * 2.0959 - 3;
		if (v[0]>60)xmin += 2;
		else if (v[0]>15)xmin += 1;
	}
	else if (v.size()>1000) {
		xmin = v.size() * 2 * 2.0959 - 6;
		if (v[0]>60)xmin += 2;
		else if (v[0]>15)xmin += 1;
	}
	vector<int>ak = check(v, 0, xmin);
	for (int n = 0; n <= 2; ++n) {
		int amin = xmin;
		auto k = ak;
		vector<int>tt(1, 2);
		k = k*vpow(tt, n);

		//if (v.size() >= 50005)break;
		while (true) {
			//if (v.size() >= 50005)break;
			if (!(k < v)) {
				break;
			}
			else {

				int num = 1;
				vector<int>th(1, 3);
				if (k.size() < v.size()) {
					int a(k[0]);
					int b(v[0] * 100);
					if ((a + 1) * 85 < b) {
						num = 4;
						th = vector<int>(1, 81);
					}
					else if ((a + 1) * 30 < b) {
						num = 3;
						th = vector<int>(1, 27);
					}
					else if ((a + 1) * 10 < b) {
						num = 2;
						th = vector<int>(1, 9);
					}
				}
				else {
					int a(k[0]);
					int b(v[0]);
					if ((a + 1) * 85 < b) {
						num = 4;
						th = vector<int>(1, 81);
					}
					else if ((a + 1) * 30 < b) {
						num = 3;
						th = vector<int>(1, 27);
					}
					else if ((a + 1) * 10 < b) {
						num = 2;
						th = vector<int>(1, 9);
					}
				}
				k = k*th;
				amin += num;
			}
			//if(v.size()>=50005)break;
		}
		int nans = n * 2 + amin * 3;
		ans = min(ans, nans);
	}
	if (ans == 0)ans = 1;
	return ans;
}

char chs[2000000];
int main()
{
	string st;
	scanf("%s", chs);
	int i = 0;
	while (isdigit(chs[i])) {
		st.push_back(chs[i]);
		i++;
	}

	vector<int>v;
	for (int i = 0; i < st.size(); ++i) {
		if (st.size() % 2) {
			if (i == 0) {
				v.push_back(st[i] - '0');
			}
			else if (i % 2) {
				v.push_back(10 * (st[i] - '0'));
			}
			else {
				v[i / 2] += st[i] - '0';
			}
		}
		else {
			if (i % 2) {
				v[i / 2] += st[i] - '0';
			}
			else {
				v.push_back(10 * (st[i] - '0'));
			}
		}
	}
	int ans = solve(v);
	cout << ans << endl;

	return 0;
}