#include <bits/stdc++.h>
using namespace std;
// test
const int N = 2e5 + 5, B = 100;
int n, pos[N], sum[N];
char s[N];
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + (s[i] == '1'); 
	for (int d = 1; d <= B; ++d) {
		unordered_map<long long, int> cnt;
		for (int i = 0; i <= n; ++i) {
			long long val = i - 1ll * d * sum[i];
			ans += cnt[val]++;
		}
	}
	for (int i = 1; i <= n; ++i) {
		pos[sum[i]] = i;
		for (int x = 1; x <= min(i / B, sum[i]); ++x) {
			int l = i - pos[sum[i] - x], r = i - (x == sum[i] ? 0 : (pos[sum[i] - x - 1] + 1));
			ans += max(0, r / x - B) - max(0, (l - 1) / x - B);
		}
	}
	printf("%lld\n", ans);
	return 0;
}