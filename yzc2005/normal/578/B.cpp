#include <bits/stdc++.h>
using namespace std;
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 
typedef long long ll;

const int N = 200005;
int n, k, x;
ll pre[N], suf[N], a[N], ans;

int main() {
	rd(n), rd(k), rd(x);
	fu(i, 1, n) rd(a[i]);
	fu(i, 1, n) pre[i] = pre[i - 1] | a[i];
	fd(i, n, 1) suf[i] = suf[i + 1] | a[i];
	fu(i, 1, n) {
		fu(j, 1, k) a[i] *= x;
		ans = max(ans, pre[i - 1] | suf[i + 1] | a[i]);
	} 
	printf("%lld\n", ans);
	return 0;
}