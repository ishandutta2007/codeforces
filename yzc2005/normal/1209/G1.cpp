#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, q, a[N];
set<int> pos[N];

struct node_t {
	int val, mx, pre, suf, res;
	int lazy;
} t[N << 2];

inline void push_up(int p) {
	t[p].val = min(t[p << 1].val, t[p << 1 | 1].val);
	t[p].mx = max(t[p << 1].mx, t[p << 1 | 1].mx);

	if (t[p << 1].val == t[p << 1 | 1].val) {
		t[p].res = t[p << 1].res + t[p << 1 | 1].res + max(t[p << 1].suf, t[p << 1 | 1].pre);
		t[p].pre = t[p << 1].pre;
		t[p].suf = t[p << 1 | 1].suf;
	} else if (t[p << 1].val < t[p << 1 | 1].val) {
		t[p].res = t[p << 1].res;
		t[p].pre = t[p << 1].pre;
		t[p].suf = max(t[p << 1].suf, t[p << 1 | 1].mx);
	} else {
		t[p].res = t[p << 1 | 1].res;
		t[p].suf = t[p << 1 | 1].suf;
		t[p].pre = max(t[p << 1].mx, t[p << 1 | 1].pre);
	}
}

inline void tag(int p, int x) {
	t[p].lazy += x;
	t[p].val += x;
}

inline void push_down(int p) {
	if (t[p].lazy) {
		tag(p << 1, t[p].lazy);
		tag(p << 1 | 1, t[p].lazy);
		t[p].lazy = 0;
	}
}

void add(int p, int l, int r, int ll, int rr, int x) {
	if (l >= ll && r <= rr) {
		tag(p, x);
		return;
	}
	push_down(p);
	int mid = (l + r) >> 1;
	if (mid >= ll) {
		add(p << 1, l, mid, ll, rr, x);
	}
	if (mid < rr) {
		add(p << 1 | 1, mid + 1, r, ll, rr, x);
	}
	push_up(p);
}

void modify(int p, int l, int r, int pos, int x) {
	if (l == r) {
		t[p].mx = t[p].res = x;
		return;
	}
	push_down(p);
	int mid = (l + r) >> 1;
	if (mid >= pos) {
		modify(p << 1, l, mid, pos, x);
	} else {
		modify(p << 1 | 1, mid + 1, r, pos, x);
	}
	push_up(p);
}

void update(int x, int y) {
	if (pos[x].empty()) {
		return;
	}
	int i = *pos[x].begin();
	add(1, 1, n, i, n, int(pos[x].size()) * y);
	modify(1, 1, n, i, y == 1 ? (int) pos[x].size() : 0);
}

void modify(int x, int y) {
	update(a[x], -1);
	pos[a[x]].erase(x);
	update(a[x], 1);

	update(y, -1);
	a[x] = y;
	pos[y].insert(x);
	update(y, 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pos[a[i]].insert(i);
		add(1, 1, n, i, n, -1);
	}
	for (int i = 1; i <= 200000; ++i) {
		update(i, 1);
	}

	cout << n - t[1].res - t[1].pre << "\n";
	while (q--) {
		int x, y;
		cin >> x >> y;
		modify(x, y);
		cout << n - t[1].res - t[1].pre << "\n";
	}

	return 0;
}