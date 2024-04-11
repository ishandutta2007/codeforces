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
 
const int N = 105;
int n, t, a[N], s, ans;
 
int main() {
	rd(t);
	while(t--) {
		rd(n); s = 0, ans = 0;
		fu(i, 1, n) {
			rd(a[i]);
			if(!a[i]) a[i] = 1, ++ans;
			s += a[i];
		}
		if(!s) ++ans;
		printf("%d\n", ans);
	}
	return 0;
}