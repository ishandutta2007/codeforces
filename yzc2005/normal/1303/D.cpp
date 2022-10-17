#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const long long INF = 1e18;
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
typedef long long ll;
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}

const int N = 1e5 + 5, K = 100;
int n, t, ans;
ll a[N], cnt[K];
ll m, sum;

int main() {
	rd(t); while(t--) {
		rd(m), rd(n); sum = 0, ans = 0; memset(cnt, 0, sizeof(cnt));
		fu(i, 1, n) {
			rd(a[i]), sum += a[i];
			fu(j, 0, 30) if(a[i] >> j & 1) ++cnt[j];
		}
		if(sum < m) {
			puts("-1");
			continue;
		}
		fu(i, 0, 30) if(cnt[i]) {
			ll tmp = 1LL * cnt[i] * (1 << i);
			fu(j, 0, i) 
				if((m >> j & 1)) {
					ans += i - j;
					break;
				}
			fu(j, 0, i) if(m >> j & 1) {
				if(tmp < (1 << j)) continue;
				tmp -= 1 << j, m -= 1 << j;
			}
			fu(j, 1, 20) if(tmp >= 1LL << (i + j)) {
				ll tmp1 = tmp / (1LL << (i + j));
				cnt[i + j] += tmp1;
				tmp -= tmp1 * (1LL << (i + j));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}