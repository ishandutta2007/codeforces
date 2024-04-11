#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

const int N = 200000;

set<int> ST[2][4 * N];

int n;
void insrt(int sti, int ql, int qr, int ind, int l=0, int r=-1, int v=1){
	if (r == -1) r = 2 * n;
	if (ql >= r || qr <= l) return;
	if (ql <= l && r <= qr){
		ST[sti][v].insert(ind);
		return;
	}
	int m = (l + r) / 2;
	insrt(sti, ql, qr, ind, l, m, 2 * v);
	insrt(sti, ql, qr, ind, m, r, 2 * v + 1);
}

void rem(int sti, int ql, int qr, int ind, int l=0, int r=-1, int v=1){
	if (r == -1) r = 2 * n;
	if (ql >= r || qr <= l) return;
	if (ql <= l && r <= qr){
		ST[sti][v].erase(ind);
		return;
	}
	int m = (l + r) / 2;
	rem(sti, ql, qr, ind, l, m, 2 * v);
	rem(sti, ql, qr, ind, m, r, 2 * v + 1);
}

int gett(int sti, int x, int l=0, int r=-1, int v=1){
	if (r == -1) r = 2 * n;
	if (ST[sti][v].empty()) {
		if (l + 1 == r) return -1;
		int mid = (l + r) / 2;
		if (x < mid) return gett(sti, x, l, mid, 2 * v);
		else return gett(sti, x, mid, r, 2 * v + 1);
	} else {
		return *ST[sti][v].begin();
	}
}

void solve(int test_ind){
	scanf("%d", &n);
	vector<pair<int, pair<int, int> > > v(n);
	set<pair<pair<int, int>, int > > sl[2]; // ((l, r), ind)
	set<pair<pair<int, int>, int > > sr[2]; // ((r, l), ind)
	set<int> xs;
	for (int i=0;i<n;++i){
		int c, l, r;
		scanf("%d%d%d", &c, &l, &r);
		v[i] = make_pair(c, make_pair(l, r));
		xs.insert(l);
		xs.insert(r);
	}

	int indd = 0;
	map<int, int> inds;
	for (int i: xs) {
		inds[i] = indd++;
	}

	for (int i=0;i<n;++i){
		v[i].second.first = inds[v[i].second.first];
		v[i].second.second = inds[v[i].second.second];
	}

	for (int i=0;i<n;++i){
		int c = v[i].first;
		int l = v[i].second.first;
		int r = v[i].second.second;
		insrt(c, l, r, i);
		sl[c].insert(make_pair(make_pair(l, r), i));
		sr[c].insert(make_pair(make_pair(r, l), i));
	}

	vector<bool> visited(n);

	auto remove = [&](int ind){
		visited[ind] = true;
		rem(v[ind].first, v[ind].second.first, v[ind].second.second, ind);
		sl[v[ind].first].erase(make_pair(make_pair(v[ind].second.first, v[ind].second.second), ind));
		sr[v[ind].first].erase(make_pair(make_pair(v[ind].second.second, v[ind].second.first), ind));
	};

	function<void(int)> dfs = [&](int ind){
		remove(ind);
		int l = v[ind].second.first;
		int r = v[ind].second.second;
		int c = v[ind].first;
		while (true){
			auto it = sr[1 - c].lower_bound({{l, 0}, 0});
			if (it == sr[1-c].end()) break;
			if (it->first.first > r) break;
			// cout << "l " << ind << " " << it->second << endl;
			dfs(it->second);
		}
		while (true) {
			auto it = sl[1 - c].lower_bound({{r+1, 0}, 0});
			if (it == sl[1-c].begin()) break;
			--it;
			if (it->first.first < l) break;
			// cout << "r " << ind << " " << it->second << endl;
			dfs(it->second);
		}
		// contains ind
		while (true) {
			int ind2 = gett(1-c, l);
			if (ind2 == -1)	break;
			// cout << "ql " << ind << " " << ind2 << endl;
			dfs(ind2);
		}
		while (true) {
			int ind2 = gett(1-c, r);
			if (ind2 == -1)	break;
			// cout << "qr " << ind << " " << ind2 << endl;
			dfs(ind2);
		}
	};

	int ans = 0;
	// al <= x && x <= ar
	for (int i=0;i<n;++i){
		if (visited[i]) continue;
		ans++;
		dfs(i);
	}
	cout << ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}