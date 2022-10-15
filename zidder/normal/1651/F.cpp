#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int n;
const int N = 200005;
set<pair<int, pair<long long, long long> > > ST[4 * N]; // ST[v] = {(c/r, total c, total r), ...}

void build (vector<int> &reg, vector<int> &c, int l=0, int r=-1, int v=1){
	if (r == -1) r = n;

	vector<pair<int, pair<int, int> > > vec;
	long long total_reg = 0;
	for (int i=l;i<r;++i){
		vec.emplace_back((c[i] + reg[i] - 1) / reg[i], make_pair(c[i], reg[i]));
		total_reg += reg[i];
	}

	sort(vec.begin(), vec.end());
	int prv = 0;
	pair<long long, long long> p = {0, total_reg};
	for (int i=0;i<vec.size();++i){
		if (vec[i].first != prv){
			ST[v].insert(make_pair(prv, p));
			prv = vec[i].first;
		}
		p.second -= vec[i].second.second;
		p.first += vec[i].second.first;
	}

	ST[v].insert(make_pair(prv, p));
	if (l + 1 == r){
		return;
	}
	int m = (l + r) / 2;
	build(reg, c, l, m, v*2);
	build(reg, c, m, r, v*2+1);
}

const __int128 one = 1;
const long long HINF = 1000000000000ll;

long long get_sum(int dt, int v){
	auto it = ST[v].upper_bound({dt+1, {-1, -1}});
	--it;
	if (it->second.first + dt * one * it->second.second > HINF) return HINF + 1;
	return it->second.first + dt * it->second.second;
}

long long get_sm(int ql, int qr, int dt, int l=0, int r=-1, int v=1){
	if (r == -1) r = n;

	if (ql <= l && r <= qr){
		// if (ql == 0 && qr == 6 && dt == 1){
		// 	cout << "lr " << l << " " << r << " " << get_sum(dt, v) << endl;
		// }
		return get_sum(dt, v);
	}

	if (r <= ql || qr <= l){
		return 0;
	}

	int m = (l + r) / 2;
	return min(get_sm(ql, qr, dt, l, m, v*2) + get_sm(ql, qr, dt, m, r, v*2+1), HINF + 1);
}

set<pair<int, pair<int, int> > > ts; // ts[i] = {ind, {time, health} }
pair<int, pair<int, int> > tmp;
void sett(int t, int l, int h){
	tmp = {l, {t, h}};
}

int tt = 0;
// [to, remaining health]
pair<int, long long> query(int ql, long long h, int dt, int l=0, int r=-1, int v=1){
	if (r == -1) r = n;
	if (r <= ql) return {r, h};
	int m = (l + r) / 2;
	if (l >= ql) {
		// solve
		long long sm = get_sum(dt, v);
		if (sm < h) {
			// cout << l << " " << r << " " << h - sm << " at r" << endl;
			return {r, h - sm};
		}
		if (l + 1 == r){
			// cout << l << " " << r << " " << sm - h << " at l + 1 = r" << endl;
			sett(tt, l, sm - h);
			return {r, 0};
		}
		auto p = query(ql, h, dt, l, m, 2*v);
		if (p.second) {
			return query(ql, p.second, dt, m, r, 2*v+1);
		} else {
			return p;
		}
	}
	auto p = query(ql, h, dt, l, m, v*2);
	if (p.second) {
		return query(ql, p.second, dt, m, r, v*2+1);
	} else {
		return p;
	}
}

void solve(int test_ind){
	cin >> n;
	vector<int> r(n), c(n);
	for (int i=0;i<n;++i){
		scanf("%d%d", &c[i], &r[i]);
	}

	for (int i=0;i<n;++i){
		ts.insert({i, {0, c[i]}});
	}
	ts.insert({n, {0, 0}});
	build(r, c);

	int q;
	cin >> q;
	vector<int> t(q);
	vector<long long> h(q);
	for (int i=0;i<q;++i){
		scanf("%d%lld", &t[i], &h[i]);
	}

	long long ans = 0;

	for (int i=0;i<q;++i){
		int ql = 0;
		while (h[i] > 0){
			auto it = ts.lower_bound({ql, {0, 0}});
			tt = t[i];
			int dt = tt - it->second.first;
			tmp = {-1, {-1, -1}};
			auto p = query(ql, h[i], dt);
			// cout << i << " " << ql << " " << h[i] << " " << p.first << " " << p.second << endl;
			if (p.first > it->first || tmp.first == -1 && p.first == it->first){
				// go until it->first
				if (it->first == n) {
					ts.erase(it);
					ts.insert({n, {tt, 0}});
					ans += p.second;
					h[i] = 0;
				} else {
					int ind = it->first;
					int time = it->second.first;
					// cout << ind << " " << time << endl;
					h[i] -= get_sm(ql, ind, dt);
					// if (h[i] < 0) {
					// 	cout << i << " " << ql << " " << ind << " " << dt << " " << h[i] << endl;
					// }
					// cout << it->second.second << " " << dt << " " << r[ind] << endl;
					int hh = min(c[ind] * one, it->second.second + dt * one * r[ind]);
					ts.erase(it);
					if (hh >= h[i]){
						hh -= h[i];
						h[i] = 0;
						ts.insert({ind, {tt, hh}});
					} else {
						h[i] -= hh;
						ql = ind + 1;
					}
				}
			} else {
				// go until p.first
				h[i] = 0;
				// cout << "tmp: " << tmp.first << " " << tmp.second.first << " " << tmp.second.second << endl;
				ts.insert(tmp);
			}
		}
	}
	cout << ans << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}