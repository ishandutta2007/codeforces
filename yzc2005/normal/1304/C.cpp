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
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}

const int N = 105;
int T, n, m, l, r;
struct node {
	int t, l, r;
} a[N];

int main() {
	for(rd(T); T; --T) {
		rd(n), rd(m); l = r = m;
		fu(i, 1, n) rd(a[i].t), rd(a[i].l), rd(a[i].r);
		bool flg = 1;
		fu(i, 0, n - 1) {
			l -= a[i + 1].t - a[i].t;
			r += a[i + 1].t - a[i].t;
			ckmax(l, a[i + 1].l);
			ckmin(r, a[i + 1].r);
			if(l > r) {
				puts("NO");
				flg = 0;
				break;
			} 
		}
		if(flg) puts("YES");
	}
	return 0;
}