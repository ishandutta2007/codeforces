#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n, m, q;

ll a[N], b[N], sum, ans;

namespace Seg {
	ll add[N<<2], sum[N<<2], mn[N<<2];
	
	void up_(int o) {
		sum[o] = sum[o<<1] + sum[o<<1|1];
		mn[o] = min(mn[o<<1], mn[o<<1|1]);
	}
	
	void add_(int o, int l, int r, ll v) {
		sum[o] += v*(r - l + 1);
		add[o] += v, mn[o] += v;
	}
	
	void down_(int o, int l, int r) {
		if (add[o]) {
			int mid = (l + r)>>1;
			add_(o<<1, l, mid, add[o]);
			add_(o<<1|1, mid + 1, r, add[o]);
			add[o] = 0;
		}
	}
	
	void build_(int o, int l, int r) {
		if (l == r) {
			sum[o] = b[l];
			mn[o] = b[l];
			return;
		}
		
		int mid = (l + r)>>1;
		build_(o<<1, l, mid);
		build_(o<<1|1, mid + 1, r);
		up_(o);
	}
	
	void upd_(int o, int l, int r, int x, int y, ll k) {
		if (x <= l && r <= y) {
			add_(o, l, r, k);
			return;
		}
		
		int mid = (l + r)>>1;
		down_(o, l, r);
		
		if (x <= mid) {
			upd_(o<<1, l, mid, x, y, k);
		}
		
		if (mid < y) {
			upd_(o<<1|1, mid + 1, r, x, y, k);
		}
		
		up_(o);
	}
	
	ll asks_(int o, int l, int r, int x, int y) {
		if (x <= l && r <= y) {
			return sum[o];
		}
		
		int mid = (l + r)>>1; ll res = 0;
		down_(o, l, r);
		
		if (x <= mid) {
			res += asks_(o<<1, l, mid, x, y);
		}
		
		if (mid < y) {
			res += asks_(o<<1|1, mid + 1, r, x, y);
		}
		
		return res;
	}
	
	int askp_(int o, int l, int r, ll k) {
		if (l == r) {
			return l;
		}
		
		int mid = (l + r)>>1;
		down_(o, l, r);
		
		if (mn[o<<1|1] < k) {
			return askp_(o<<1|1, mid + 1, r, k);
		} else {
			return askp_(o<<1, l, mid, k);
		}
	}
}

void solve_() {
	ans = sum + (a[1] + Seg :: asks_(1, 1, m, 1, 1))*(n + m - 1);
	
	for (int i = 1, l = 1, r; i <= n; i++) {
		r = Seg :: askp_(1, 1, m, a[i + 1]);
		
		if (i > 1) {
			ans += a[i]*(n - i + 1 + m - l);
		}
		
		if (l < r) {
			ans += Seg :: asks_(1, 1, m, l + 1, r)*(n - i);
		}
		
		l = r;
	}
	
	printf("%lld\n", ans);
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &b[i]);
	}
	
	for (int i = n; i; i--) {
		a[i] -= a[i - 1];
	}
	
	a[n + 1] = 1e18;
	
	for (int i = m; i; i--) {
		b[i] -= b[i - 1];
		
		if (i > 1) {
			sum += (m - i + 1)*b[i];
		}
	}
	
	Seg :: build_(1, 1, m);
	
	for (int op, x, y, i = 1; i <= q; i++) {
		scanf("%d%d%d", &op, &x, &y);
		
		if (op == 1) {
			for (int j = 0; j < x; j++) {
				a[n - j] += y;
			}
		} else {
			Seg :: upd_(1, 1, m, m - x + 1, m, y);
			sum += 1ll*y*(x + 1)*x/2;
			
			if (x == m) {
				sum -= 1ll*y*m;				
			}
		}
		
		solve_();
	}
}