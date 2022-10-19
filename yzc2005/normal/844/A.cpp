#include <bits/stdc++.h>
using namespace std;

int n, k, cnt[30];
char s[1005];

int main() {
	scanf("%s%d", s, &k), n = strlen(s);
	for(int i = 0; i < n; ++i) ++cnt[s[i] - 'a'];
	int ans = 0;
	for(int i = 0; i < 26; ++i) if(cnt[i]) ++ans;
	if(n < k) puts("impossible"), exit(0);
	printf("%d", max(0, k - ans));
}