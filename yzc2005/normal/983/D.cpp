#include <bits/stdc++.h>
using namespace std;
int n, l1[100005], r1[100005], l2[100005], r2[100005];
struct node_t {
	int l, r, val, mn;
	set<int> mx, lim;
} t[800005];
void build(int p, int l, int r) {
	t[p].l = l, t[p].r = r;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
}
inline void update(int p) {
	t[p].val = t[p].mn = 0;
	if (t[p].l != t[p].r) {
		t[p].val = max(t[p << 1].val, t[p << 1 | 1].val);
		t[p].mn = min(t[p << 1].mn, t[p << 1 | 1].mn);
	}
	if (!t[p].mx.empty()) t[p].val = max(t[p].val, *t[p].mx.rbegin());
	if (!t[p].lim.empty()) t[p].mn = max(t[p].mn, *t[p].lim.rbegin());
	if (t[p].val < t[p].mn) t[p].val = 0;
}
void ins(int p, int l, int r, int x) {
	if (t[p].l >= l && t[p].r <= r) {
		t[p].mx.insert(x);
		update(p);
		return;
	}
	int mid = (t[p].l + t[p].r) >> 1;
	if (mid >= l) ins(p << 1, l, r, x);
	if (mid < r) ins(p << 1 | 1, l, r, x);
	update(p);
}
void del(int p, int l, int r, int x) {
	if (t[p].l >= l && t[p].r <= r) {
		t[p].lim.insert(x);
		t[p].mx.erase(x);
		update(p);
		return;
	}
	int mid = (t[p].l + t[p].r) >> 1;
	if (mid >= l) del(p << 1, l, r, x);
	if (mid < r) del(p << 1 | 1, l, r, x);
	update(p);
}
void erase(int p, int l, int r, int x) {
	if (t[p].l >= l && t[p].r <= r) {
		t[p].mx.erase(x);
		t[p].lim.erase(x);
		update(p);
		return;
	}
	int mid = (t[p].l + t[p].r) >> 1;
	if (mid >= l) erase(p << 1, l, r, x);
	if (mid < r) erase(p << 1 | 1, l, r, x);
	update(p);
}
vector<int> event[200005];
int main() {
	scanf("%d", &n);
	vector<int> p1, p2;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d%d", &l1[i], &l2[i], &r1[i], &r2[i]);
		p1.emplace_back(l1[i]);
		p1.emplace_back(r1[i]);
		p2.emplace_back(l2[i]);
		p2.emplace_back(r2[i]);
	}
	sort(p1.begin(), p1.end());
	p1.erase(unique(p1.begin(), p1.end()), p1.end());
	sort(p2.begin(), p2.end());
	p2.erase(unique(p2.begin(), p2.end()), p2.end());
	auto get = [&](const vector<int> &p, int x) {
		return lower_bound(p.begin(), p.end(), x) - p.begin() + 1;	
	};
	for (int i = 1; i <= n; ++i) {
		l1[i] = get(p1, l1[i]);
		r1[i] = get(p1, r1[i]);
		l2[i] = get(p2, l2[i]);
		r2[i] = get(p2, r2[i]);
		event[l1[i]].emplace_back(i);
		event[r1[i]].emplace_back(-i);
	}
	int m = int(p2.size()) - 1;
	build(1, 1, m);
	int ans = 0;
	for (int x = 1; x <= (int) p1.size(); ++x) {
		sort(event[x].begin(), event[x].end());
		for (auto i : event[x]) {
			if (i < 0) erase(1, l2[-i], r2[-i] - 1, -i);
			else ins(1, l2[i], r2[i] - 1, i);
		}
		while (t[1].val) {
			++ans;
			int i = t[1].val;
			del(1, l2[i], r2[i] - 1, i);
		}
	}
	printf("%d\n", ans + 1);
	return 0;
}