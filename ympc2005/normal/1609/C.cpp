#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

int n, e, a[N], T, p[N], cnt;

bool vis[N];

ll ans;

void init_(int n) {
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) {
			p[++cnt] = i;
		}
		
		for (int j = 1; j <= cnt && 1ll*p[j]*i <= n; j++) {
			vis[p[j]*i] = 1;
			
			if (i%p[j] == 0) {
				break;
			}
		}
	}
}
 
int main() {
	init_(1e6);
	
	scanf("%d", &T);
	
	while (T--) {
		scanf("%d%d", &n, &e), ans = 0;
		
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		
		for (int i = 1; i <= n; i++) {
			if (!vis[a[i]] && a[i] > 1) {
				int l = 1, r = 1;
				
				while (i - e*l > 0 && a[i - e*l] == 1) {
					l++;
				}
				
				while (i + e*r <= n && a[i + e*r] == 1) {
					r++;
				}
				
				ans += 1ll*l*r - 1;
			}
		}
		
		printf("%lld\n", ans);
	} 
}