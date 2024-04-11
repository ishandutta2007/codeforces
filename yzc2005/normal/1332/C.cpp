#include <bits/stdc++.h>
using namespace std;
#define mem(a, x) memset(a, x, sizeof(a))
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}
#define fail puts("NO"), exit(0)
typedef long long ll;
typedef pair<int, int> P;

const int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int t, n, k, cnt[200005][30];
char s[200005];

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%s", &n, &k, s + 1);
		fu(i, 1, k) fu(j, 0, 25) cnt[i][j] = 0;
		for(int j = 0; j < n; j += k) {
			fu(i, 1, k) ++cnt[i][s[i + j] - 'a'];
		}
		int ans = 0;
		fu(i, 1, k >> 1) {
			int mx = 0;
			fu(j, 0, 25) ckmax(mx, cnt[i][j] + cnt[k - i + 1][j]);
			ans += (n / k) * 2 - mx;
		}
		if(k & 1) ans += n / k - *max_element(cnt[k + 1 >> 1], cnt[k + 1 >> 1] + 26); 
		printf("%d\n", ans);
	}
	return 0;
}