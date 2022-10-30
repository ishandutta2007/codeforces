#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int n, a[N];

vector <int> b;

void work_(int x) {
	for (int i = 2; 1ll*i*i <= x; i++) {
		if (x%i == 0) {
			b.push_back(i);
			
			while (x%i == 0) {
				x /= i;
			}
		}
	}
	
	if (x > 1) {
		b.push_back(x);
	}
}

int main() {
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	work_(a[1]);
	work_(a[2]);
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	ll ans = 1;
	
	for (int x : b) {
		int mn = 1e9, sn = 1e9;
		
		for (int i = 1; i <= n; i++) {
			int cnt = 0;
			
			while (a[i]%x == 0) {
				cnt++;
				a[i] /= x;
			}
			
			sn = min(sn, cnt);
			
			if (sn < mn) {
				swap(sn, mn);
			}
		}
		
		for (int i = 1; i <= sn; i++) {
			ans *= x;
		}
	}
	
	printf("%lld\n", ans);
}