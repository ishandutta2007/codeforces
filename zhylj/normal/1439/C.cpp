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
#define mkp std::make_pair
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 2e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, q, A[kN], mn[kN << 3], mx[kN << 3]; ll seg[kN << 3], tag[kN << 3];
void Update(int o) {
	seg[o] = seg[o << 1] + seg[o << 1 | 1];
	mx[o] = mx[o << 1]; mn[o] = mn[o << 1 | 1];
}
void PushTag(int o, int l, int r) {
	if(tag[o]) {
		int mid = (l + r) >> 1;
		seg[o << 1] = tag[o] * (mid - l + 1);
		seg[o << 1 | 1] = tag[o] * (r - mid);
		mn[o << 1] = mn[o << 1 | 1] = tag[o];
		mx[o << 1] = mx[o << 1 | 1] = tag[o];
		tag[o << 1] = tag[o << 1 | 1] = tag[o];
		tag[o] = 0;
	}
}
void Build(int o, int l, int r) {
	if(l < r) {
		int mid = (l + r) >> 1;
		Build(o << 1, l, mid);
		Build(o << 1 | 1, mid + 1, r);
		Update(o);
	} else mx[o] = mn[o] = seg[o] = A[l];
}
void Modify(int o, int l, int r, int x, ll y) {
	if(r <= x && mx[o] <= y) {
		seg[o] = y * (r - l + 1);
		tag[o] = mn[o] = mx[o] = y;
	} else {
		int mid = (l + r) >> 1;
		PushTag(o, l, r);
		if(mn[o << 1] <= y) Modify(o << 1, l, mid, x, y);
		if(x > mid) Modify(o << 1 | 1, mid + 1, r, x, y);
		Update(o);
	}
}
int Query(int o, int l, int r, int x, ll &y) {
	if(l >= x && seg[o] <= y) return y -= seg[o], r - l + 1;
	if(mn[o] > y) return 0;
	//printf("%d %d %d %d %d\n", o, l, r, x, y);
	int mid = (l + r) >> 1, ret = 0;
	PushTag(o, l, r);
	if(x <= mid) ret += Query(o << 1, l, mid, x, y);
	ret += Query(o << 1 | 1, mid + 1, r, x, y);
	return ret;
}
void Output(int o, int l, int r) {
	if(l < r) {
		int mid = (l + r) >> 1;
		PushTag(o, l, r);
		Output(o << 1, l, mid);
		Output(o << 1 | 1, mid + 1, r);
		Update(o);
	} else printf("%lld ", seg[o]);
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, q);
		for(int i = 1; i <= n; ++i) rd(A[i]);
		Build(1, 1, n);
		//Output(1, 1, n); printf("\n");
		while(q--) {
			int t, x; ll y; rd(t, x, y);
			if(t == 1) {
				Modify(1, 1, n, x, y);
			} else {
				printf("%d\n", Query(1, 1, n, x, y));
			}
			//Output(1, 1, n); printf("\n");
		}
	} return 0;
}