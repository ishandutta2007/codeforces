#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int inf2, inf1;

int lft[67 * 200000];
int rght[67 * 200000];
int d[67 * 200000];
int st1ind = 200000 * 4 + 5;


int get1(int qy, int l, int r, int v) {
	if (l >= qy + 1) return 0;
	if (r <= qy + 1) return d[v];
	int ans = 0;
	int m = (l + r) / 2;
	if (lft[v] != 0) ans = max(ans, get1(qy, l, m, lft[v]));
	if (rght[v] != 0) ans = max(ans, get1(qy, m, r, rght[v]));
	return ans;
}

void insert1(int y, int val, int l, int r, int v) {
	d[v] = max(d[v], val);
	if (l + 1 == r) return;
	int m = (l + r) / 2;
	if (y < m) {
		if (lft[v] == 0) lft[v] = st1ind++;
		insert1(y, val, l, m, lft[v]);
	} else {
		if (rght[v] == 0) rght[v] = st1ind++;
		insert1(y, val, m, r, rght[v]);
	}
}

vector<int> vs[4 * 200000 + 6];


int get2(int qx, int qy, int l, int r, int v) {
	if (l >= qx + 1) return 0;
	if (r <= qx + 1) {
		auto it = upper_bound(vs[v].begin(), vs[v].end(), qy);
		if (it == vs[v].begin()) return 0;
		--it;
		return get1(it - vs[v].begin(), 0, vs[v].size(), v);
	}
	int m = (l + r) / 2;
	int ans = 0;
	ans = max(ans, get2(qx, qy, l, m, v*2));
	ans = max(ans, get2(qx, qy, m, r, v*2+1));
	return ans;
}

void insert2(int x, int y, int val, int l, int r, int v) {
	auto it = lower_bound(vs[v].begin(), vs[v].end(), y);
	if (*it != y) throw "error";
	insert1(it - vs[v].begin(), val, 0, vs[v].size(), v);
	if (l + 1 == r) return;
	int m = (l + r) / 2;
	if (x < m) {
		insert2(x, y, val, l, m, v*2);
	} else {
		insert2(x, y, val, m, r, 2*v+1);
	}
}

void insert3(int x, int y, int l, int r, int v) {
	vs[v].push_back(y);
	if (l + 1 == r) return;
	int m = (l + r) / 2;
	if (x < m) {
		insert3(x, y, l, m, v*2);
	} else {
		insert3(x, y, m, r, 2*v+1);
	}
}

void solve(int test_ind){
	int n, v;
	cin >> n >> v;
	vector<int> a(n), t(n);
	
	for (int &i: t) scanf("%d", &i);
	for (int &i: a) scanf("%d", &i);
	set<long long> st1, st2;
	map<long long, int> mp1, mp2;
	for (int i=0;i<n;++i) {
		long long x, y;
		x = t[i] * 1ll * v - a[i];
		if (x < 0) continue;
		y = a[i] + t[i] * 1ll * v;
		if (y < 0) continue;
		st1.insert(x);
		st2.insert(y);
	}

	inf1 = 0;
	inf2 = 0;
	for (auto &i: st1) {
		mp1[i] = inf1++;
	}
	for (auto &i: st2) {
		mp2[i] = inf2++;
	}
	for (int i=0;i<n;++i) {
		long long x, y;
		x = t[i] * 1ll * v - a[i];
		if (x < 0) continue;
		y = a[i] + t[i] * 1ll * v;
		if (y < 0) continue;
		int xx = mp1[x], yy = mp2[y];
		insert3(xx, yy, 0, inf1, 1);
	}

	for (int i=0;i < 4 * n + 5;++i) {
		sort(vs[i].begin(), vs[i].end());
		vs[i].resize(unique(vs[i].begin(), vs[i].end()) - vs[i].begin());
	}

	st1.clear();
	st2.clear();

	int ans = 0;
	for (int i=0;i<n;++i) {
		long long x, y;
		x = t[i] * 1ll * v - a[i];
		if (x < 0) continue;
		y = a[i] + t[i] * 1ll * v;
		if (y < 0) continue;
		int xx = mp1[x], yy = mp2[y];
		int ans2 = get2(xx, yy, 0, inf1, 1) + 1;
		ans = max(ans, ans2);
		insert2(xx, yy, ans2, 0, inf1, 1);
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