#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int t, n, k, cnt[30];
char s[N];

int main() {
	for(scanf("%d", &t); t; --t) {
		scanf("%d%d%s", &n, &k, s + 1);
		memset(cnt, 0, sizeof(cnt));
		sort(s + 1, s + n + 1);
		printf("%c", s[k]);
		for(int i = 1; i <= n; ++i) ++cnt[s[i] - 'a'];
		int *pos = &cnt[0]; while(!*pos) pos++;
		if(*pos >= k) {
			for(int i = 1; i <= k; ++i) --cnt[s[i] - 'a'];
			int ch = max_element(cnt, cnt + 26) - cnt;
			if(cnt[ch] == n - k) {
				int m = (n + k - 1) / k;
				for(int i = 1; i < m; ++i) printf("%c", 'a' + ch);
			} else {
				for(int i = k + 1; i <= n; ++i) printf("%c", s[i]);
			}
		}
		puts("");
	}
}