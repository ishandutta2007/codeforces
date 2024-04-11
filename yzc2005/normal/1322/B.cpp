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

const int N = 400005;
int n, a[N], b[N], ans;

int main() {
	rd(n);
	fu(i, 1, n) rd(a[i]);
	for(int k = 1; k <= 2e7; k <<= 1) {
		fu(i, 1, n) b[i] = a[i] & (k - 1);
		sort(b + 1, b + n + 1);
		bool cnt = 0;
		fu(i, 1, n) if(a[i] & k) cnt ^= 1;
		if(cnt && ((n - 1) & 1)) ans ^= k;
		int p = n; cnt = 0;
		fu(i, 1, n) {
			while(p && b[i] + b[p] >= k) --p;
			cnt ^= ((n - max(p, i)) & 1);
		}
		if(cnt) ans ^= k;
	}
	printf("%d\n", ans);
	return 0;
}