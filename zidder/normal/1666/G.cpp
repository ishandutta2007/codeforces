#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <functional>

using namespace std;

int eind = 0;

struct event {
	// add new points (merge)
	// add coefs
	// remove coefs
	// query surface
	// add surface
	int ind;
	string tp;
	int arg1=-1;
	long double arg2=0;
	long double arg3=0;
	event(){ind=eind++;}
	event(string tp, int arg1=-1, long double arg2=0, long double arg3=0): tp(tp), arg1(arg1), arg2(arg2), arg3(arg3){ind=eind++;}
	int pind=-1, qind=-1;
	event(int qind, int pind): qind(qind), pind(pind){tp="query";ind=eind++;}
	bool operator < (const event &other) const {
		if (tp == "add surface") {
			if (other.tp == "add surface") {
				return lessarg(other);
			}
			return true;
		}
		if (other.tp == "add surface") return false;
		if (tp == "remove coef") {
			if (other.tp == "remove coef") {
				return lessarg(other);
			}
			return true;
		}
		if (other.tp == "remove coef") return false;
		if (tp == "add coef") {
			if (other.tp == "add coef") {
				return lessarg(other);
			}
			return true;
		}
		if (other.tp == "add coef") return false;
		if (tp == "add point") {
			if (other.tp == "add point") {
				return lessarg(other);
			}
			return true;
		}
		if (other.tp == "add point") return false;
		if (tp == "query") {
			if (other.tp == "query") {
				return lessarg(other);
			}
			return true;
		}
		if (other.tp == "query") return false;
		return false;
	}

	bool lessarg(const event &other) const{
		return ind < other.ind;
	}
};

struct component {
	long double S = 0;
	long double a = 0;
	long double b = 0;
	// a + bz
	long double z;
	component(){}
	void to(int z1){
		if (z == z1) return;
		// integrate z to z1
		// cout << z << " " << z1 << endl;
		// cout << S << " " << a << " " << b << endl;
		S += (z1 - z) * a;
		S += (z1 * b * z1 - z * b * z) / 2;
		z = z1;
		// cout << "Send: " << S << endl;
	}
};

long double sqr(long double a){
	return a * a;
}

long double distance(pair<long double, pair<long double, long double> > a1, pair<long double, pair<long double, long double> > a2){
		return sqrtl(sqr(a1.first - a2.first) + sqr(a1.second.first - a2.second.first) + sqr(a1.second.second - a2.second.second));
}

void solve(int test_ind){
	int n;
	cin >> n;

	vector<pair<int, pair<int, int> > > points(n+1);
	multiset<pair<int, event> > events;
	for (int i=0;i<n;++i){
		scanf("%d%d%d", &points[i].second.first, &points[i].second.second, &points[i].first);
		events.insert(make_pair(points[i].first, event("add point", i)));
	}

	vector<int> sz(n, 0);
	vector<int> par(n, -1);
	vector<component> components(n);
	function<int(int)> dsu = [&](int v) -> int {
		if (par[v] == v) return v;
		return par[v] = dsu(par[v]);
	};

	auto merge = [&](int v, int u){
		v = dsu(v);
		u = dsu(u);
		if (u == v) return;
		if (sz[u] > sz[v]) swap(v, u);
		sz[v] += sz[u];
		par[u] = v;
		int mz = min(components[u].z, components[v].z);
		components[u].to(mz);
		components[v].to(mz);
		components[v].S += components[u].S;
		components[v].a += components[u].a;
		components[v].b += components[u].b;
	};

	auto dist = [&](int i1, int i2) -> long double {
		return distance(points[i1], points[i2]);
	};

	auto S1 = [&](int i1, int i2, pair<long double, pair<long double, long double> > other) -> long double {
		long double d1 = dist(i1, i2);
		long double d2 = distance(points[i1], other);
		long double d3 = distance(other, points[i2]);
		long double p = (d1 + d2 + d3) / 2;
		return sqrtl(p * (p - d1) * (p - d2) * (p - d3));
	};

	auto S = [&](int i1, int i2, int i3) -> long double {
		return S1(i1, i2, points[i3]);
	};

	auto point_at = [&](int i1, int i2, int z) -> pair<long double, long double> {
		long double coef1 = (points[i1].first - z) * ( (long double) 1) / (points[i1].first - points[i2].first);
		return make_pair(
			points[i1].second.first - (points[i1].second.first - points[i2].second.first) * coef1,
			points[i1].second.second - (points[i1].second.second - points[i2].second.second) * coef1
		);
	};

	vector<unordered_set<int> > g(n);
	int m;
	cin >> m;
	for (int i=0;i<m;++i) {
		vector<int> as(3);
		scanf("%d%d%d", &as[0], &as[1], &as[2]);
		as[0]--;
		as[1]--;
		as[2]--;
		vector<pair<int, int> > zas(3);
		for (int j=0;j<3;++j)zas[j].second = as[j];
		for (int j=0;j<3;++j)zas[j].first = points[zas[j].second].first;
		sort(zas.begin(), zas.end());
		for (int j=0;j<3;++j) as[j] = zas[j].second;
		// z is increasing
		g[as[0]].insert(as[1]);
		g[as[0]].insert(as[2]);
		g[as[1]].insert(as[0]);
		g[as[1]].insert(as[2]);
		g[as[2]].insert(as[1]);
		g[as[2]].insert(as[0]);
		
		if (points[as[0]].first == points[as[2]].first) {
			// horizontal plane
			events.insert(make_pair(points[as[0]].first, event("add surface", as[0], S(as[0], as[1], as[2]))));
		} else {
			if (points[as[0]].first == points[as[1]].first) {
				long double c = dist(as[0], as[1]);
				long double coef = S(as[0], as[1], as[2]) / (points[as[2]].first - points[as[0]].first) / c * 2;
				// a + bz , "add coef", point ind, a, b
				events.insert(make_pair(points[as[2]].first, event("add coef", as[2], coef*-points[as[2]].first * c / (points[as[2]].first - points[as[0]].first), coef*c / (points[as[2]].first - points[as[0]].first))));
				events.insert(make_pair(points[as[0]].first, event("remove coef", as[2], coef*-points[as[2]].first * c / (points[as[2]].first - points[as[0]].first), coef*c / (points[as[2]].first - points[as[0]].first))));
				// lower horizontal
			} else {
				if (points[as[2]].first == points[as[1]].first) {
					// upper horizontal
					long double c = dist(as[2], as[1]);
					long double coef = S(as[0], as[1], as[2]) / (points[as[2]].first - points[as[0]].first) / c * 2;
					events.insert(make_pair(points[as[2]].first, event("add coef", as[2], coef*points[as[0]].first * c / (points[as[1]].first - points[as[0]].first), -coef*c / (points[as[1]].first - points[as[0]].first))));
					events.insert(make_pair(points[as[0]].first, event("remove coef", as[2], coef*points[as[0]].first * c / (points[as[1]].first - points[as[0]].first), -coef*c / (points[as[1]].first - points[as[0]].first))));
				} else {
					// three different ones
					pair<long double, pair<long double, long double> > other = make_pair(points[as[1]].first, point_at(as[0], as[2], points[as[1]].first));
					long double c = distance(points[as[1]], other);
					long double coef1 = S1(as[1], as[2], other) / (points[as[2]].first - points[as[1]].first) / c * 2;
					long double coef2 = S1(as[0], as[1], other) / (points[as[1]].first - points[as[0]].first) / c * 2;

					events.insert(make_pair(points[as[2]].first, event("add coef", as[2], coef1*-points[as[2]].first * c / (points[as[2]].first - points[as[1]].first), coef1*c / (points[as[2]].first - points[as[1]].first))));
					events.insert(make_pair(points[as[1]].first, event("remove coef", as[2], coef1*-points[as[2]].first * c / (points[as[2]].first - points[as[1]].first), coef1*c / (points[as[2]].first - points[as[1]].first))));

					events.insert(make_pair(points[as[1]].first, event("add coef", as[2], coef2*points[as[0]].first * c / (points[as[1]].first - points[as[0]].first), -coef2*c / (points[as[1]].first - points[as[0]].first))));
					events.insert(make_pair(points[as[0]].first, event("remove coef", as[2], coef2*points[as[0]].first * c / (points[as[1]].first - points[as[0]].first), -coef2*c / (points[as[1]].first - points[as[0]].first))));
				}
			}
		}
	}

	int q;
	cin >> q;
	for (int i=0;i<q;++i){
		int h, p;
		scanf("%d%d", &h, &p);
		p--;
		events.insert(make_pair(h, event(i, p)));
	}

	vector<long double> ans(q);

	while (!events.empty()) {
		int z = events.rbegin()->first;
		event e = events.rbegin()->second;
		events.erase(events.find(make_pair(z, e)));
		if (e.tp == "add point") {
			components[e.arg1].z = z;
			par[e.arg1] = e.arg1;
			sz[e.arg1] = 1;
			for (int u: g[e.arg1]) {
				if (par[u] == -1) continue;
				merge(e.arg1, u);
			}
		} else if (e.tp == "query") {
			if (par[e.pind] == -1){
				ans[e.qind] = -1;
			} else {
				components[dsu(e.pind)].to(z);
				ans[e.qind] = components[dsu(e.pind)].S;
			}
		} else if (e.tp == "add coef") {
			components[dsu(e.arg1)].a += e.arg2;
			components[dsu(e.arg1)].b += e.arg3;
		} else if (e.tp == "remove coef") {
			components[dsu(e.arg1)].a -= e.arg2;
			components[dsu(e.arg1)].b -= e.arg3;
		} else if (e.tp == "add surface") {
			components[dsu(e.arg1)].S += e.arg2;
		}
	}

	for (auto &i: ans){
		printf("%.13Lf\n", i);
	}
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}