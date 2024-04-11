#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

ll m;

ll ask_(int l, int r) {
	ll x; 
	printf("? %d %d\n", l, r);
	fflush(stdout);
	scanf("%lld", &x);
	return x;
}

void calc_(int &a, int &b, ll c, ll d) {
	a = (2*d + round(sqrt(4*d*d - 8*(d*d - d - 2*c))))/4;
	b = d - a; 
}

int main() {
	int T;
	scanf("%d", &T);
	
	while (T--) {
		scanf("%d", &n);
		
		int l = 1, r = n, a, b, c, x, y;
		
		while (l < r) {
			int mid = (l + r + 1)>>1;
			
			if (!ask_(1, mid)) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		
		a = l, m = ask_(1, n);
		
		l = a, r = n;
		
		while (l < r) {
			int mid = (l + r)>>1;
			
			if (1ll*(mid - a)*(mid - a + 1)/2 >= m) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		
		calc_(x, y, ask_(a, l), l - a + 1);
		
		if (ask_(a, a + x - 1) != 1ll*x*(x - 1)/2) {
			swap(x, y);
		}
		
		b = a + x, m -= 1ll*x*(x - 1)/2;
		
		l = 1, r = n;
		
		while (l < r) {
			int mid = (l + r)>>1;
			
			if (1ll*mid*(mid - 1)/2 >= m) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		
		c = b + l - 1;
		
		printf("! %d %d %d\n", a, b, c);
		fflush(stdout);
	}
}