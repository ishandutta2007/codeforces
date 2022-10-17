
#include <bits/stdc++.h>
using namespace std;
#define rg register
#define fu(i, a, b) for(rg int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(rg int i = a, I = (b) - 1; i > I; --i)
#define go(u) for(rg int i = head[u], v = to[i], w = val[i]; i; i = nxt[i], v = to[i], w = val[i])
typedef pair<int, int> P;
typedef long long ll;
template <class T>
inline void read(T &x) {
	x = 0; T f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
	while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	x *= f;
} 
template <class T>
inline void print(T x) {
	if(x > 9) print(x / 10);
	putchar(x % 10 + 48);
}
template <class T> 
inline void ckmax(T &a, T b) {a = max(a, b);}
template <class T>
inline void ckmin(T &a, T b) {a = min(a, b);}
 
const int N = 1005;
int n, k, s, a[N], t;
set<int> ss;
 
int main() {
	read(t);
	while(t--) {
		ss.clear();
		read(n), read(s), read(k);
		fu(i, 1, k) read(a[i]), ss.insert(a[i]);
		int ans = INT_MAX;
		fd(i, s, 1) {
			if(ss.find(i) == ss.end()) {
				ans = s - i;
				break;
			}
		}
		fu(i, s, n) {
			if(ss.find(i) == ss.end()) {
				ckmin(ans, i - s);
				break;
			}
		}
		printf("%d\n", ans);
	}
}