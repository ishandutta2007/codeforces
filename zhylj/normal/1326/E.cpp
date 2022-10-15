#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

#define fi first
#define se second

typedef long long ll;
typedef double ff;
typedef std::pair<int, int> pii;

const int kN = 3e5 + 5;

int n, seg[kN * 6], tag[kN * 6], p[kN], q[kN], pre[kN];
void Update(int cur) { seg[cur] = std::max(seg[cur << 1], seg[cur << 1 | 1]); }
void PushTag(int cur) {
	seg[cur << 1] += tag[cur]; seg[cur << 1 | 1] += tag[cur];
	tag[cur << 1] += tag[cur]; tag[cur << 1 | 1] += tag[cur];
	tag[cur] = 0;
}
void Modify(int cur, int l, int r, int ql, int qr, int v) {
	//printf("%d %d %d %d %d %d\n", cur, l, r, ql, qr, v);
	if(ql <= l && r <= qr) tag[cur] += v, seg[cur] += v;
	else {
		int mid = (l + r) >> 1;
		PushTag(cur);
		if(ql <= mid) Modify(cur << 1, l, mid, ql, qr, v);
		if(qr > mid) Modify(cur << 1 | 1, mid + 1, r, ql, qr, v);
		Update(cur);
	}
}

int main() {
	rd(n);
	for(int i = 1; i <= n; ++i) rd(p[i]), pre[p[i]] = i;
	for(int i = 1; i <= n; ++i) rd(q[i]);
	int x = n + 1;
	for(int i = 1; i <= n; ++i) {
		while(seg[1] <= 0)
			Modify(1, 1, n, 1, pre[--x], 1);
		printf("%d ", x);
		Modify(1, 1, n, 1, q[i], -1);
	}
	return 0;
}