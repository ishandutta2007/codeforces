//    
#include <bits/stdc++.h>
using namespace std;
#define mem(a, x) memset(a, x, sizeof(a))
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}

const int N = 200005;
int n, a[N], mod;

int main() {
	rd(n), rd(mod);
	fu(i, 1, n) rd(a[i]);
	sort(a + 1, a + n + 1);
	if(n <= mod) {
		int ans = 1;
		fu(i, 1, n) fu(j, 1, i - 1) ans = 1LL * ans * (a[i] - a[j]) % mod;
		cout << ans; 
	} else {
		cout << "0";
	}
	return 0;
}