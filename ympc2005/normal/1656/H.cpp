#include <bits/stdc++.h>
using namespace std;

typedef __int128 ll;

const int N = 1005;

int T, n, m;

ll a[N], b[N];

bool ta[N], tb[N];

void read_(ll &x) {
	x = 0; char ch = getchar();
	
	for (; !isdigit(ch); ch = getchar());
	
	for (; isdigit(ch); ch = getchar()) {
		x = x*10 + ch - '0';
	}
}

ll gcd_(ll a, ll b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	
	return a;
}

struct Seg {
	ll val[N<<2], K;
	
	void up_(int o) {
		val[o] = gcd_(val[o<<1], val[o<<1|1]);
	}
	
	void build_(int o, int l, int r, ll *a) {
		if (l == r) {
			val[o] = K/gcd_(a[l], K);
			return;
		}
		
		int mid = (l + r)>>1;
		build_(o<<1, l, mid, a);
		build_(o<<1|1, mid + 1, r, a);
		up_(o);
	}
	
	void upd_(int o, int l, int r, int x) {
		if (l == r) {
			val[o] = K;
			return;
		}
		
		int mid = (l + r)>>1;
		
		if (x <= mid) {
			upd_(o<<1, l, mid, x);
		} else {
			upd_(o<<1|1, mid + 1, r, x);
		}
		
		up_(o);
	}
} A[N], B[N];

void write_(ll x) {
	if (x >= 10) {
		write_(x/10);
	}
	
	putchar(x%10 + '0');
}

int main() {
	scanf("%d", &T);
	
	while (T--) {
		scanf("%d%d", &n, &m);
		
		for (int i = 1; i <= n; i++) {
			read_(a[i]);	
			ta[i] = 0;
		}
		
		for (int i = 1; i <= m; i++) {
			read_(b[i]);
			tb[i] = 0;
		}
		
		queue <int> q; 
		
		for (int i = 1; i <= n; i++) {
			A[i].K = a[i];
			A[i].build_(1, 1, m, b);	
			
			if (A[i].val[1] > 1) {
				ta[i] = 1;
				q.push(i);
			}
		}
		
		for (int i = 1; i <= m; i++) {
			B[i].K = b[i];
			B[i].build_(1, 1, n, a);
			
			if (B[i].val[1] > 1) {
				tb[i] = 1;
				q.push(-i);
			}
		}
		
		int ca = n, cb = m;
		
		while (!q.empty()) {
			int u = q.front(); q.pop();
			
			if (u > 0) {
				ca--;
				
				for (int i = 1; i <= m; i++) {
					if (!tb[i]) {
						B[i].upd_(1, 1, n, u);
						
						if (B[i].val[1] > 1) {
							tb[i] = 1;
							q.push(-i);
						}
					}
				}
			} else {
				u = -u;
				cb--;
				
				for (int i = 1; i <= n; i++) {
					if (!ta[i]) {
						A[i].upd_(1, 1, m, u);
						
						if (A[i].val[1] > 1) {
							ta[i] = 1;
							q.push(i);
						}
					}
				}
			}
		}
		
		if (!ca || !cb) {
			puts("NO");
		} else {
			printf("YES\n%d %d\n", ca, cb);
			
			for (int i = 1; i <= n; i++) {
				if (!ta[i]) {
					write_(a[i]);
					putchar(' ');
				}
			}
			
			puts("");
			
			for (int i = 1; i <= m; i++) {
				if (!tb[i]) {
					write_(b[i]);
					putchar(' ');
				}
			}
			
			puts("");
		}
	}
}