#include <bits/stdc++.h>
using namespace std;
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

const int N = 100005, K = 40;
int n, a[N], s[K];

int main() {
	rd(n);
	fu(i, 1, n) {
		rd(a[i]);
		fu(k, 0, 31) if(a[i] >> k & 1) ++s[k];
	}
	int ans = 0, pos = 0;
	fu(i, 1, n) {
		int cnt = 0;
		fu(k, 0, 31) if(a[i] >> k & 1) if(s[k] == 1) cnt += 1 << k;
		if(cnt >= ans) ans = cnt, pos = i;
	}
	printf("%d ", a[pos]);
	fu(i, 1, n) if(pos != i) printf("%d ", a[i]);
	return 0;
}