#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#pragma GCC optimize "trapv"

using namespace std;

struct Vertex {
	int v;
	int m; // <= m
	bool flag; // >= or <
	Vertex(int a, int b, bool c): v(a), m(b), flag(c){}

	Vertex operator !() const {
		return Vertex(v, m, !flag);
	}

	int hash() const {
		return v * 100 + m * 5 + flag;
	}

	string print() const {
		if (flag) return "a[" + to_string(v) + "] <= " + to_string(m);
		else return "a[" + to_string(v) + "] > " + to_string(m);
	}
};

struct Sat {
	int mx;
	vector<bool> used;
	map<int, int> nodes;
	vector<Vertex> rnodes;
	vector<int> comp;

	vector<vector<int> > g, gr;

	vector<int> order;

	Sat() {
		mx = 0;
		g.emplace_back();
		g.emplace_back();
		g.emplace_back();
		g.emplace_back();
	}

	void dfs1(int v) {
		used[v] = true;
		for (int u : g[v]) {
			if (!used[u]){
				// cout << rnodes[v].print() << " to " << rnodes[u].print() << endl;
				dfs1(u);
			}
		}
		order.push_back(v);
	}

	void dfs2(int v, int cl) {
    	comp[v] = cl;
		for (int to: gr[v]) {
			if (comp[to] == -1) {
				dfs2(to, cl);
			}
		}
	}

	int get_node(const Vertex &p) {
		if (nodes.find(p.hash()) == nodes.end()) {
			rnodes.push_back(p);
			g.emplace_back();
			nodes[p.hash()] = mx++;
		}
		return nodes[p.hash()];
	}

	void implies(const Vertex &a, const Vertex &b) {
		// a -> b
		int ai = get_node(a), bi = get_node(b);
		int nai = get_node(!a), nbi = get_node(!b);
		g[ai].push_back(bi);
		g[nbi].push_back(nai);
	}

	void nand(const Vertex &a, const Vertex &b) {
		// not (a&b)
		// a -> !b
		// b -> !a
		int ai = get_node(a), bi = get_node(b);
		int nai = get_node(!a), nbi = get_node(!b);
		g[ai].push_back(nbi);
		g[bi].push_back(nai);
	}

	void set_true(const Vertex &a) {
		int ai = get_node(a);
		int nai = get_node(!a);
		g[nai].push_back(ai);
	}

	void solve(){
		gr = vector<vector<int> > (g.size());
		for (int i=0;i<g.size();++i) for (int j: g[i]) gr[j].push_back(i);
		used = vector<bool>(mx);
		comp = vector<int>(mx, -1);
		for (int i=0;i<mx;++i) if (!used[i]) dfs1(i);
		reverse(order.begin(), order.end());
		int timer = 0;
		for (int v: order) {
			if (comp[v] == -1) {
				dfs2(v, ++timer);
			}
		}
	}

	bool get_val(const Vertex& v) {
		// cout << inds[get_node(!v)] << " " << inds[get_node(v)] << endl;
		return comp[get_node(!v)] < comp[get_node(v)];
	}

	void print() {
		for (int i=0;i<mx;++i) {
			for (int j: g[i]) {
				cout << rnodes[i].print() << " then " << rnodes[j].print() << endl;
			}
		}
	}
};

void solve(int test_ind){
	int n, m, k;
	cin >> n >> m >> k;
	Sat sat;
	for (int i=0;i<n;++i) {
		for (int j=0;j<k;++j) {
			sat.implies(Vertex(i, j, true), Vertex(i, j+1, true));
		}
		sat.set_true(Vertex(i, 0, false));
		sat.set_true(Vertex(i, k, true));
	}
	for (int i=1;i<n;++i){
		for (int j=0;j<=k;++j){
			sat.implies(Vertex(i, j, true), Vertex(i-1, j, true));
		}
	}
	for (int i=0;i<m;++i) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int ind, val;
			scanf("%d%d", &ind, &val);
			ind--;
			sat.implies(Vertex(ind, val, true), Vertex(ind, val-1, true));
		} else {
			int ind1, ind2, val;
			scanf("%d%d%d", &ind1, &ind2, &val);
			ind1--;
			ind2--;
			if (t == 2) {
				for (int j=0;j<k;j++){
					for (int t=0;t<k;++t){
						if (j + 1 + t + 1 > val) {
							sat.nand(Vertex(ind1, j, false), Vertex(ind2, t, false));
						}
					}
				}
			} else {
				for (int j=1;j<=k;++j){
					for (int t=1;t<=k;++t){
						if (val > j + t) {
							sat.nand(Vertex(ind1, j, true), Vertex(ind2, t, true));
						}
					}
				}
			}
		}
	}

	sat.solve();

	vector<int> a(n);
	for (int i=0;i<n;++i) {
		for (int j=0;j<=k;++j) {
			// cout << Vertex(i, j, true).print() << " " << sat.get_val(Vertex(i, j, true)) << endl;
			// cout << Vertex(i, j, false).print() << " " << sat.get_val(Vertex(i, j, false)) << endl;
			if (sat.get_val(Vertex(i, j, true))) {
				a[i] = j;
				break;
			}
		}
	}

	// for (int i: a){
	// 	printf("%d ", i);
	// }
	// cout << endl;

	// sat.print();

	for (int i=0;i<sat.mx;++i) {
		int v = i;
		for (int u: sat.g[i]) {
			// v then u
			auto v1 = sat.rnodes[v];
			auto v2 = sat.rnodes[u];
			bool b1 = (a[v1.v] <= v1.m) ^ v1.flag ^ true;
			bool b2 = (a[v2.v] <= v2.m) ^ v2.flag ^ true;
			// cout << v1.v << " " << v1.m << " " << v1.flag << endl;
			// cout << v2.v << " " << v2.m << " " << v2.flag << endl;
			// cout << v1.print() << " " << b1 << endl;
			// cout << v2.print() << " " << b2 << endl;
			if (b1 && !b2) {
				cout << -1 << endl;
				return;
			}
		}
	}

	for (int i: a){
		printf("%d ", i);
	}

	cout << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}