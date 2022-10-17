#include <bits/stdc++.h>
using namespace std;
#define mem(a, x) memset(a, x, sizeof(a))
#define fail puts("NO"), exit(0)
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
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

const int N = 2e5 + 5;
int n, a[N];
ll dp[N], mx[N * 3];

int main() {
	rd(n);
	fu(i, 1, n) rd(a[i]);
	fu(i, 1, n) {
		dp[i] = mx[a[i] - i + n] + a[i];
		ckmax(mx[a[i] - i + n], dp[i]);
	}
	cout << *max_element(dp + 1, dp + n + 1) << endl;
}