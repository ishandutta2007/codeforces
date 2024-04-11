#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, l[N], r[N], p[N << 1], s[N << 2], sum[N << 2], cnt, ans, Case;
#define rint register int
#define fu(i, a, b) for(rint i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(rint i = a, I = (b) - 1; i > I; --i)

int main() {
	scanf("%d", &Case); 
	while(Case--) {
		scanf("%d", &n); int cnt = 0;
		fu(i, 1, n) {
			scanf("%d%d", &l[i], &r[i]);
			p[++cnt] = l[i], p[++cnt] = r[i];
		}
		sort(p + 1, p + cnt + 1); cnt = unique(p + 1, p + cnt + 1) - p - 1; 
		fu(i, 1, n) {
			l[i] = lower_bound(p + 1, p + cnt + 1, l[i]) - p;
			r[i] = lower_bound(p + 1, p + cnt + 1, r[i]) - p;
			l[i] <<= 1, r[i] <<= 1;
			++s[l[i]], --s[r[i] + 1];
		}
		cnt <<= 1; 
		fu(i, 1, cnt) s[i] += s[i - 1]; s[cnt + 1] = 0;
		int val = 0, ans = 0; 
		fu(i, 1, cnt + 1) val += s[i - 1] && !s[i];
		s[0] = 2; fu(i, 1, cnt) sum[i] = sum[i - 1] + (s[i] == 1 && s[i - 1] != 1);
		fu(i, 1, n) ans = max(ans, val + sum[r[i]] - sum[l[i] - 1] - (s[l[i]] == 1 && !s[l[i] - 1]) - (s[r[i]] == 1 && !s[r[i] + 1]));
		printf("%d\n", ans);
		fu(i, 0, cnt) s[i] = 0;
	} 
	return 0;
}