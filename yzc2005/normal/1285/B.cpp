#include <bits/stdc++.h>
using namespace std;
#define rg register
#define fu(i, a, b) for(rg int i = a; i <= b; ++i)
#define fd(i, a, b) for(rg int i = a; i >= b; --i)
#define go(u) for(rg int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
inline void read(int &x) {
	int f = 1;
	x = 0; char ch = getchar();
	while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
	while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - 48, ch = getchar();
	x *= f;
} 
typedef long long ll;
const int N = 100005;

int Case, n, a;
ll s[N], mins, minn, ans;

int main() {
	read(Case);
	while(Case--) {
		read(n); mins = 0, ans = -1e18;
		fu(i, 1, n) {
			read(a), s[i] = s[i - 1] + a, mins = min(mins, s[i]);
			if(i != n) ans = max(ans, s[i] - mins);
		}
		minn = s[1];
		fu(i, 2, n) minn = min(minn, s[i]);
		ans = max(ans, s[n] - minn);
		puts(ans < s[n] ? "yes" : "no");
	}
	return 0;
}