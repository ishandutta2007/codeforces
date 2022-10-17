#include <bits/stdc++.h>
using namespace std;
const int N = 200010, M = 1000010, inf = 0x3f3f3f3f;
 
int t, n, k, d, a[N], last[M];
bool used[M];
 
int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &n, &k, &d);
		int cnt = 0, ans = inf;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			last[a[i]] = i;
			if(!used[a[i]]) {
				used[a[i]] = 1;
				++cnt;
			}
			if(i > d) {
				if(last[a[i - d]] == i - d) {
					used[a[i - d]] = 0;
					--cnt;
				}
			}
			if(i >= d) ans = min(ans, cnt);
		}
		printf("%d\n", ans);
		for(int i = 1; i <= n; ++i) last[a[i]] = 0, used[a[i]] = 0;
	}
	return 0;
}