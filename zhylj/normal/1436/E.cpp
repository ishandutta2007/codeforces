#include <bits/stdc++.h>

const int kN = 4e5 + 5;

int n, m, a[kN], tag[kN << 3], seg[kN << 3], d[kN];

void Update(int cur) {
	seg[cur] = std::max(seg[cur << 1], seg[cur << 1 | 1]);
}
void PushTag(int cur) {
	if(~tag[cur]) {
		seg[cur << 1] = tag[cur]; seg[cur << 1 | 1] = tag[cur];
		tag[cur << 1] = tag[cur]; tag[cur << 1 | 1] = tag[cur];
		tag[cur] = -1;
	}
}
int Query(int cur, int l, int r, int v) {
	if(v > seg[cur]) return n + 1;
	if(l == r) return l;
	int mid = (l + r) >> 1;
	PushTag(cur);
	if(v <= seg[cur << 1]) return Query(cur << 1, l, mid, v);
	else return Query(cur << 1 | 1, mid + 1, r, v);
}
void Modify(int cur, int l, int r, int ql, int qr, int v) {
	if(qr < ql) return;
	if(ql <= l && r <= qr) {
		seg[cur] = tag[cur] = v;
	} else {
		int mid = (l + r) >> 1;
		PushTag(cur);
		if(ql <= mid) Modify(cur << 1, l, mid, ql, qr, v);
		if(qr > mid) Modify(cur << 1 | 1, mid + 1, r, ql, qr, v);
		Update(cur);
	}
}
void Build(int cur, int l, int r) {
	if(l < r) {
		int mid = (l + r) >> 1;
		Build(cur << 1, l, mid);
		Build(cur << 1 | 1, mid + 1, r);
		Update(cur);
	} else seg[cur] = d[l];
}

int cnt[kN], nxt[kN], app_mex[kN], mex_cnt = 0; std::map <int, int> lst;
void Solve() {
	int ptr = 1, cur_n = 1;
	for(int i = n; i; --i) {
		if(lst.count(a[i])) {
			nxt[i] = lst[a[i]];
		} else nxt[i] = n + 1;
		lst[a[i]] = i;
	}
	for(int i = 1; i <= n; ++i) {
		if(a[i] <= n) ++cnt[a[i]];
		while(cnt[cur_n]) ++cur_n;
		app_mex[++mex_cnt] = d[i] = cur_n;
	}
	Build(1, 1, n);
	for(int i = 1; i <= n; ++i) {
		int p = Query(1, 1, n, a[i]);
		Modify(1, 1, n, p, nxt[i] - 1, a[i]);
		if(std::max(p, i + 1) <= std::min(nxt[i] - 1, n)) {
			app_mex[++mex_cnt] = a[i];
		//	printf("%d ", a[i]);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	memset(tag, 0xff, sizeof(tag));
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	Solve();
	std::sort(app_mex + 1, app_mex + mex_cnt + 1);
	mex_cnt = std::unique(app_mex + 1, app_mex + mex_cnt + 1) - app_mex - 1;
	app_mex[mex_cnt + 1] = -114514;
	for(int i = 1; i <= mex_cnt + 1; ++i) {
		if(app_mex[i] != app_mex[i - 1] + 1) {
			return printf("%d\n", app_mex[i - 1] + 1), 0;
		}
	}
	return 0;
}