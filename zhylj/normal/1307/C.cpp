#include <bits/stdc++.h>

typedef long long ll;

const int kMaxN = 1e5 + 5;
const int kMaxC = 30;

char s[kMaxN];
int pre[kMaxC][kMaxN];

int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1); ll ans = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < 26; ++j)
			pre[j][i] = pre[j][i - 1] + (s[i] - 'a' == j);
	}
	for(int i = 0; i < 26; ++i) ans = std::max(ans, (ll)pre[i][n]);
	for(int i = 0; i < 26; ++i)
		for(int j = 0; j < 26; ++j) {
			ll tmp = 0;
			for(int k = 1; k <= n; ++k)
				if(s[k] - 'a' == j) tmp += pre[i][k - 1];
			ans = std::max(ans, tmp);
		}
	printf("%lld\n", ans);
	return 0;
}