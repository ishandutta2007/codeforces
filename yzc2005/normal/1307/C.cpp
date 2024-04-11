#include <bits/stdc++.h>
using namespace std;

#define int long long
int cnt[26], cur[26][26];
char s[100005];
signed main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1), ans = 0;
	for(int i = 1; i <= n; ++i) {
		int p = s[i] - 'a';
		for(int j = 0; j < 26; ++j) cur[j][p] += cnt[j];
		++cnt[p];
	}
	for(int i = 0; i < 26; ++i)
		for(int j = 0; j < 26; ++j)
			ans = max(ans, cur[i][j]);
	printf("%lld", max(ans, *max_element(cnt, cnt + 26)));
}