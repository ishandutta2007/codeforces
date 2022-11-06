#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;



 int mod = 1000000007;
struct Mod {
public:
	int num;
	Mod() : Mod(0) { ; }
	Mod(long long int n) : num((n % mod + mod) % mod) {
	}
	Mod(int n) : Mod(static_cast<long long int>(n)) { ; }
	operator int() { return num; }
};

#define MAX_MOD_N 1024000

Mod fact[MAX_MOD_N];
Mod pp[MAX_MOD_N];
Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
Mod operator+(const Mod a, const long long int  b) { return b + a; }
Mod operator++(Mod &a) { return a + Mod(1); }
Mod operator-(const Mod a, const Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a - Mod(1); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
Mod operator*(const Mod a, const long long int b) { return Mod(b)*a; }
Mod operator*(const Mod a, const int b) { return Mod(b)*a; }
Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
Mod operator*=(Mod& a, const long long int &b) { return a = a * b; }
Mod operator^(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = (a * a) ^ (n / 2);
	if (n % 2) res = res * a;
	return res;
}
Mod mod_pow(const Mod a, const long long  int n) {
	if(a.num==10&&n<=1e7)return pp[n];
	if (n == 0) return Mod(1);
	Mod res = mod_pow((a * a), (n / 2));
	if (n % 2) res = res * a;
	return res;
}

long long int gcd(long long int l, long long int r) {
	assert(l > 0 && r > 0);
	if (l > r)return gcd(r, l);
	else {
		const long long int num = r%l;
		if (num) {
			return gcd(l, num);
		}
		else {
			return l;
		}
	}
}
struct Extended_Euclid {
	static pair<long long int, long long int> solve(long long int l, long long int r) {
		const long long int agcd = gcd(l, r);
		l /= agcd;
		r /= agcd;
		bool flag = false;
		if (l < r) {
			flag = true;
			swap(l, r);
		}
		int x1 = 1, y1 = 0, z1 = l;
		int x2 = 0, y2 = 1, z2 = r;
		while (z2 != 1) {
			const int q = (z1 - (z1%z2)) / z2;
			const int px = x1;
			const int py = y1;
			const int pz = z1;
			x1 = x2;
			y1 = y2;
			z1 = z2;
			x2 = px - q*x2;
			y2 = py - q*y2;
			z2 = pz - q*z2;
		}
		if (flag)swap(x2, y2);
		return make_pair(x2, y2);
	}
}exeu;
map<int,int>mp;
Mod inv(const Mod a) { 
	if(mp.find(a.num)==mp.end())mp[a.num]=exeu.solve(a.num,mod).first;
	return mp[a.num];
	return a ^ (mod - 2); }
Mod operator/(const Mod a, const Mod b) {
	assert(b.num != 0);
	Mod c=inv(b);
	return a * inv(b);
}
Mod operator/(const long long int a, const Mod b) {
	if(mod==1)return 0;
	return Mod(a) / b;
}
Mod operator/=(Mod &a, const Mod b) {
	return a = a / b;
}

void init(const int amax = MAX_MOD_N) {
	fact[0] = Mod(1); 
	pp[0]=1;
	for (int i = 0; i < amax - 1; ++i) {
		fact[i + 1] = fact[i] * Mod(i + 1);
		pp[i+1]=pp[i]*10;
	}
}


long long int ans=0;

namespace cent {

	struct Edge {
		int src;
		int dst;
		long long int cost;
	};
	using Graph = vector<vector<Edge>>;

	class Centroid {
	private:
		int dfs(const Graph&g, const int now, const int from, vector<int>&ch_nums, const vector<int>&oks) {
			int sum = 1;
			for (auto &&e : g[now]) {
				if (e.dst == from || oks[e.dst] != -1)continue;
				else {
					sum += dfs(g, e.dst, e.src, ch_nums, oks);
				}
			}
			return ch_nums[now] = sum;
		}

		int find_centroid(const int asize, const vector<vector<Edge>>&graph, const int pre_root, const int pre_from, const vector<int>&ch_nums, const vector<int>&oks) {
			for (auto&& e : graph[pre_root]) {
				if (e.dst == pre_from)continue;
				if (oks[e.dst] != -1)continue;
				if (ch_nums[e.dst]>asize / 2)return find_centroid(asize, graph, e.dst, e.src, ch_nums, oks);
			}
			return pre_root;
		}

		void dfs2(const Graph&g, const int root,const int now, const int from, const vector<int>&oks,long long int t1,long long int t2,int depth) {
			lens1[root][make_pair(t1,depth)]++;
			lens2[root][t2]++;
			for (auto &&e : g[now]) {
				if (e.dst == from || oks[e.dst] != -1)continue;
				else {
					dfs2(g,root,e.dst,e.src,oks,(t1*10+e.cost)%mod,(t2+e.cost*mod_pow(10,depth))%mod,depth+1);
				}
			}
		};


		void cent(const vector<vector<Edge>>&graph, vector<int>&oks, const int root, const int from, vector<vector<int>>&centroid_edges, int& fst_centroid, int depth, vector<int>&ch_nums) {
			dfs(graph, root, from, ch_nums, oks);

			int cent_id = find_centroid(ch_nums[root], graph, root, from, ch_nums, oks);


			dfs2(graph,cent_id,cent_id,-1,oks,0,0,0);
			lens1[cent_id][make_pair(0,0)]--;
			lens2[cent_id][0]--;

			for (auto&& l1 : lens1[cent_id]) {
				int keta=l1.first.second;
				long long int num=l1.first.first;

				if (num == 0) {
					ans+=l1.second;
				}
				long long int need=(mod-num)/mod_pow(10,keta);

				auto it=lens2[cent_id].find(need);
				if (it != lens2[cent_id].end()) {
					ans += l1.second*it->second;
				}
			}
			for (auto&& l2 : lens2[cent_id]) {
				long long int num = l2.first;

				if (num == 0) {
					ans += l2.second;
				}
			}
			oks[cent_id] = depth;

			for (auto&& e : graph[cent_id]) {
				if (e.dst == from)continue;
				if (oks[e.dst] != -1)continue;

				dfs2(graph, e.dst, e.dst, e.src, oks,e.cost%mod,e.cost%mod,1);

				for (auto&& l1 : lens1[e.dst]) {
					int keta = l1.first.second;
					long long int num = l1.first.first;

					long long int need = (mod - num) / mod_pow(10, keta);
					need%=mod;
					auto it = lens2[e.dst].find(need);
					if (it != lens2[e.dst].end()) {
						ans -= l1.second*it->second;
					}
				}
				lens1[e.dst].clear();
				lens2[e.dst].clear();
			}

			if (from != -1) {
				centroid_edges[from].push_back(cent_id);
			}
			else {
				fst_centroid = cent_id;
			}
			for (auto&& e : graph[cent_id]) {
				if (e.dst == from)continue;
				if (oks[e.dst] != -1)continue;
				cent(graph, oks, e.dst, e.src, centroid_edges, fst_centroid, depth + 1, ch_nums);
			}
		}

	public:


		vector<map<pair<long long int,int>, long long int>>lens1;
		vector<map<long long int, long long int>>lens2;
		vector<vector<int>> centroid_graph;
		vector<int>parents;
		vector<int>oks;
		map<pair<int, int>, long long int>mp;

		//fst:root  snd:centroid_graph
		void init(const Graph&g) {
			lens1.resize(g.size());
			lens2.resize(g.size());
			oks = vector<int>(g.size(), -1);
			int root = -1;
			centroid_graph.resize(g.size());
			parents = vector<int>(g.size(), -1);
			vector<int>ch_nums(g.size());
			cent(g, oks, 0, -1, centroid_graph, root, 0, ch_nums);

			for (int i = 0; i < centroid_graph.size(); ++i) {
				for (auto&& e : centroid_graph[i]) {
					parents[e] = i;
				}
			}
			return ;
		}
	}centroid;


	void addEdge(Graph& g, int a, int b, long long int c) {
		g[a].push_back(Edge{ a,b,c });
		g[b].push_back(Edge{ b,a,c });
	}
}




int main()
{

	int N;cin>>N>>mod;
	init();
	using namespace cent;
	Centroid cc;
	Graph graph(N);
	for (int i = 0; i < N-1; ++i) {
		int a,b,c;scanf("%d %d %d",&a,&b,&c);
		addEdge(graph,a,b,c);
	}
	cc.init(graph);
	cout<<ans<<endl;
	return 0;
}