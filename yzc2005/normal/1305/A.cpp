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

const int N = 105;
int t, n, a[N], b[N];

int main() {
	for(rd(t); t; --t) {
		rd(n);
		fu(i, 1, n) rd(a[i]);
		fu(i, 1, n) rd(b[i]);
		sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
		fu(i, 1, n - 1) printf("%d ", a[i]);
		printf("%d\n", a[n]);
		fu(i, 1, n - 1) printf("%d ", b[i]);
		printf("%d\n", b[n]);
	}
	return 0;
}