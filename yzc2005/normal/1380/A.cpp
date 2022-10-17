#include <bits/stdc++.h>
using namespace std;
int n, a[1005], pre[1005], suf[1005], p[1005];
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);	
			p[a[i]] = i;
		}
		pre[1] = a[1], suf[n] = a[n];
		for(int i = 2; i <= n; ++i) pre[i] = min(a[i], pre[i - 1]);
		for(int i = n - 1; i; --i) suf[i] = min(suf[i + 1], a[i]);
		bool ok = 0;
		for(int i = 2; i <= n - 1; ++i) {
			if(pre[i - 1] < a[i] && suf[i + 1] < a[i]) {
				puts("YES"); ok = 1;
				printf("%d %d %d\n", p[pre[i - 1]], i, p[suf[i + 1]]);
				break;
			}
		}
		if(!ok) puts("NO");
	}
	return 0; 
}