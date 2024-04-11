#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int n, q;

namespace Seg1 {
	ll sum[N<<2], add[N<<2];
	
	void up_(int o) {
		sum[o] = sum[o<<1] + sum[o<<1|1];
	}
	
	void padd_(int o, int l, int r, ll v) {
		sum[o] += (r - l + 1)*v;
		add[o] += v;
	}
	
	void down_(int o, int l, int r) {
		if (add[o]) {
			int mid = (l + r)>>1;
			padd_(o<<1, l, mid, add[o]);
			padd_(o<<1|1, mid + 1, r, add[o]);
			add[o] = 0;
		}
	}
	
	void add_(int o, int l, int r, int x, int y, ll v) {
		if (x <= l && r <= y) {
			padd_(o, l, r, v);
			return;
		}
		
		int mid = (l + r)>>1;
		down_(o, l, r);
		
		if (x <= mid) {
			add_(o<<1, l, mid, x, y, v);
		} 
		
		if (mid < y) {
			add_(o<<1|1, mid + 1, r, x, y, v);
		}
		
		up_(o);
	}
	
	ll ask_(int o, int l, int r, int x, int y) {
		if (x <= l && r <= y) {
			return sum[o];
		}
		
		int mid = (l + r)>>1; ll res = 0;
		down_(o, l, r);
		
		if (x <= mid) {
			res += ask_(o<<1, l, mid, x, y);
		} 
		
		if (mid < y) {
			res += ask_(o<<1|1, mid + 1, r, x, y);
		}
		
		return res;
	}
}

namespace Seg2 {
	int mx[N<<2], sx[N<<2], cx[N<<2];
	
	void up_(int o) {
		int lc = o<<1, rc = o<<1|1;
		
		if (mx[lc] > mx[rc]) {
			mx[o] = mx[lc];
			cx[o] = cx[lc];
			sx[o] = max(sx[lc], mx[rc]);
		} else if (mx[lc] == mx[rc]) {
			mx[o] = mx[lc];
			cx[o] = cx[lc] + cx[rc];
			sx[o] = max(sx[lc], sx[rc]);
		} else {
			mx[o] = mx[rc];
			cx[o] = cx[rc];
			sx[o] = max(mx[lc], sx[rc]);
		}
	}
	
	void pmin_(int o, int v) {
		mx[o] = min(mx[o], v);
	}
	
	void down_(int o) {
		pmin_(o<<1, mx[o]);
		pmin_(o<<1|1, mx[o]);
	}
	
	void build_(int o, int l, int r) {
		if (l == r) {
			mx[o] = l;
			sx[o] = -1e9;
			cx[o] = 1;
			return;
		}
		
		int mid = (l + r)>>1;
		build_(o<<1, l, mid);
		build_(o<<1|1, mid + 1, r);
		up_(o);
	}
	
	void min_(int o, int l, int r, int x, int y, int v) {
		if (mx[o] <= v) {
			return;
		}
		
		if (x <= l && r <= y && sx[o] < v) {
			Seg1 :: add_(1, 1, n, v + 1, mx[o], -cx[o]);
			pmin_(o, v);
			return;
		} 
		
		int mid = (l + r)>>1;
		down_(o);
		
		if (x <= mid) {
			min_(o<<1, l, mid, x, y, v);
		} 
		
		if (mid < y) {
			min_(o<<1|1, mid + 1, r, x, y, v);
		}
		
		up_(o);
	}
	
	void upd_(int o, int l, int r, int x, int v) {
		if (l == r) {
			if (mx[o] < v) {
				Seg1 :: add_(1, 1, n, mx[o] + 1, v, 1);
			} else if (mx[o] > v) {
				Seg1 :: add_(1, 1, n, v + 1, mx[o], -1);
			}
			
			mx[o] = v;
			return;
		}
		
		int mid = (l + r)>>1;
		down_(o);
		
		if (x <= mid) {
			upd_(o<<1, l, mid, x, v);
		} else {
			upd_(o<<1|1, mid + 1, r, x, v);
		}
		
		up_(o);
	}
}

int main() {
	scanf("%d%d", &n, &q);
	
	Seg2 :: build_(1, 1, n);
	
	for (int op, x, y, i = 1; i <= q; i++) {
		scanf("%d%d%d", &op, &x, &y);
		
		if (op == 1) {
			if (1 < x) {
				Seg2 :: min_(1, 1, n, 1, x - 1, x - 1);
			}
			
			Seg2 :: upd_(1, 1, n, x, y); 
		} else {
			printf("%lld\n", y - x + 1 + Seg1 :: ask_(1, 1, n, x, y));
		}
	}
	
	return 0;
}