#include <bits/stdc++.h>

typedef long long ll;

const int kM = 4e4 + 5;
const int kN = 55;

int M, n, m, k; ll T[kM << 3], tag[kM << 3], a[kN][kM], pre[kM], s[kM], f[kN][kM];
void Update(int cur) { T[cur] = std::max(T[cur << 1], T[cur << 1 | 1]); }
void PushTag(int cur) {
	T[cur << 1] += tag[cur]; T[cur << 1 | 1] += tag[cur];
	tag[cur << 1] += tag[cur]; tag[cur << 1 | 1] += tag[cur];
	tag[cur] = 0;
}
void Build(int cur, int l, int r) {
	if(l < r) {
		int mid = (l + r) >> 1;
		Build(cur << 1, l, mid);
		Build(cur << 1 | 1, mid + 1, r);
		Update(cur);
	} else T[cur] = s[l];
}
void Modify(int cur, int l, int r, int ql, int qr, ll v) {
	if(l > qr || r < ql) return;
	if(ql <= l && r <= qr) T[cur] += v, tag[cur] += v;
	else {
		int mid = (l + r) >> 1;
		PushTag(cur);
		if(ql <= mid) Modify(cur << 1, l, mid, ql, qr, v);
		if(qr > mid) Modify(cur << 1 | 1, mid + 1, r, ql, qr, v);
		Update(cur);
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
	for(int i = 1; i <= m + k; ++i) pre[i] = pre[i - 1] + a[1][i];
	for(int i = 1; i <= m; ++i) f[1][i] = pre[i + k - 1] - pre[i - 1];
	for(int i = 2; i <= n; ++i) {
		for(int j = 1; j <= m + k; ++j) pre[j] = pre[j - 1] + a[i][j];
		for(int j = 1; j <= m; ++j) s[j] = pre[j + k - 1] - pre[std::max(k, j - 1)] + f[i - 1][j];
		memset(tag, 0, sizeof(tag)); Build(1, 1, m);
		for(int j = 1; j <= m; ++j) {
			f[i][j] = T[1] + pre[j + k - 1] - pre[j - 1];
			Modify(1, 1, m, j - k + 1, j, a[i][j]);
			Modify(1, 1, m, j + 1, j + k, -a[i][j + k]);
		}
	}
	ll ans = 0;
	for(int i = 1; i <= m; ++i)
		ans = std::max(ans, f[n][i]);
	printf("%lld", ans);
	return 0;
}