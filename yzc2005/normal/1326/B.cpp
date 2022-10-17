#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> P;
typedef pair<P, int> PI;
#define fi first
#define se second
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
int n, a[N], b[N];

int main() {
	rd(n);
	int x = 0;
	fu(i, 1, n) {
		rd(b[i]);
		a[i] = b[i] + x;
		printf("%d ", a[i]);
		x = max(x, a[i]);
	}
	return 0;
}