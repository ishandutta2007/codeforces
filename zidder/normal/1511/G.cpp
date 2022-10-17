#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int N = 200005;

int ST[8 * N];

int sz = N;

void build(int l=0, int r=-1, int v=1) {
	if (r == -1) r = sz;
	ST[v] = 0;
	if (l + 1 == r) return;
	int mid = (l + r) / 2;
	build(l, mid, v * 2);
	build(mid, r, v * 2 + 1);
}

void addd(int x, int l=0, int r=-1, int v=1) {
	if (r==-1) r = sz;
	ST[v]++;
	if (l+1==r) return;
	int mid = (l + r) / 2;
	if (mid > x) addd(x, l, mid, v * 2);
	else addd(x, mid, r, v * 2 + 1);
}

int qry(int ql, int qr, int l=0, int r=-1, int v=1){
	if (r == -1) r = sz;
	if (ql <= l && r <= qr) return ST[v];
	if (qr <= l || r <= ql) return 0;
	int mid = (l + r) / 2;
	return qry(ql, qr, l, mid, v * 2) + qry(ql, qr, mid, r, v * 2 + 1);
}

void solve(int test_ind){
	// (x-l) & 2^a == 1 <=> x % 2^(a+1) < l%2^(a+1) || x%2^(a+1) >= l%(2^a+1) + 2^a or x%2^(a+1) in [2^a - l, 2^(a+1) - l)
	int m;
	int n;
	cin >> n >> m;
	vector<int> c(n);
	for (int &i: c) scanf("%d", &i);
	map<int, int> mp;
	for (int i: c) mp[i]++;
	c.clear();
	for (auto &p: mp) if (p.second % 2) c.push_back(p.first);
	n = c.size();

	int qs = 0;
	cin >> qs;

	vector<pair<pair<int, int>, int> > q;
	for (int i=0;i<qs;++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		q.push_back({{l-1, i}, -l});
		q.push_back({{r, i}, l});
	}
	sort(q.begin(), q.end());

	vector<bool> res(qs, true);
	for (int p=0;p<20;++p){
		if ((1<<p) > m) break;
		sz = 1<<(p+1);
		build();
		vector<int> ans(qs);
		int qind = 0;
		for (int i=0;i<=n;++i) {
			while (qind < q.size() && (i == n || q[qind].first.first < c[i])) {
				if (q[qind].second < 0) {
					int cc = 0;
					if ((-q[qind].second) % sz < sz / 2) {
						int l = (-q[qind].second) % sz;
						// x - l & sz/2 => x - l >= sz/2 =>  x < l || x >= sz/2 + l
						cc = qry(0, l) + qry(sz/2+l, sz);
					} else {
						int l = sz - (-q[qind].second) % sz;
						// x + l & sz/2 => sz > x + l >= sz/2 =>  sz - l > x >= sz/2 - l
						cc = qry(sz/2-l, sz-l);
					}
					ans[q[qind].first.second] -= cc;
					// cout << q[qind].first.second << " " << cc << " " << ans[q[qind].first.second] << endl;
				} else {
					int cc = 0;
					if (q[qind].second % sz < sz / 2) {
						int l = q[qind].second % sz;
						cc = qry(0, l) + qry(sz/2+l, sz);
					} else {
						int l = sz - q[qind].second % sz;
						cc = qry(sz/2-l, sz-l);
					}
					ans[q[qind].first.second] += cc;
					if (ans[q[qind].first.second]%2) {
						res[q[qind].first.second] = false;
					}
					// cout << q[qind].first.second << " " << cc << " " << ans[q[qind].first.second] << endl;
				}
				++qind;
			}
			if (i == n) break;
			addd(c[i] % sz);
		}
	}
	string s = "";
	for (bool i: res) if (i) s += "B"; else s += "A";
	cout << s << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}