#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 25;

int n, T, a[N], mx, cnt;

ll ans;

int main() {
	scanf("%d", &T);
	
	while (T--) {
		scanf("%d", &n), mx = 1, cnt = ans = 0;
		
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			
			while(a[i]%2 == 0) {
				a[i] /= 2;
				cnt++;
			}
			
			mx = max(mx, a[i]);
			ans += a[i];
		}
		
		ans = (ans - mx) + (1ll*mx<<cnt);
		
		printf("%lld\n", ans);
	}	
}