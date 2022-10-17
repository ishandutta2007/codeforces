#include <bits/stdc++.h>
using namespace std;
#define mem(a, x) memset(a, x, sizeof(a))
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}

const int N = 205;
int n, m, k, cnt;
char s[100000];
bool vis[N];

struct node {
	int x, y;
} a[N], b[N];

inline void change(int dx, int dy) {
	fu(i, 1, k) {
		a[i].x += dx, a[i].y += dy;
		ckmax(a[i].x, 1), ckmin(a[i].x, n);
		ckmax(a[i].y, 1), ckmin(a[i].y, m);
		if(a[i].x == b[i].x && a[i].y == b[i].y) vis[i] = 1;
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	fu(i, 1, k) scanf("%d%d", &a[i].x, &a[i].y);
	fu(i, 1, k) scanf("%d%d", &b[i].x, &b[i].y);
	fu(i, 1, m - 1) s[++cnt] = 'R';
	fu(k, 1, m) {
		fu(i, 1, n - 1) s[++cnt] = 'D';
		fu(i, 1, n - 1) s[++cnt] = 'U';
		if(k != m) s[++cnt] = 'L';
	}
	printf("%d\n", cnt);
	fu(i, 1, cnt) printf("%c", s[i]);
	return 0;
}