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

const int N = 505;
int n, m, q, p;
char a[N][N];

struct PrefixSum {
	int s[N][N];
	inline void init() {
		fu(i, 1, n)
			fu(j, 1, m) 
				s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
	} 
	inline int S(int x1, int y1, int x2, int y2) {
		return s[x1][y1] - s[x2][y1] - s[x1][y2] + s[x2][y2];
	} 
} s[4], ans[N >> 1];

int main() {
	rd(n), rd(m), rd(q);
	fu(i, 1, n) {
		scanf("%s", a[i] + 1);
		fu(j, 1, m) {
			if(a[i][j] == 'R') p = 0;
			if(a[i][j] == 'G') p = 1;
			if(a[i][j] == 'Y') p = 2;
			if(a[i][j] == 'B') p = 3;
			s[p].s[i][j] = 1;
		}
	}
	fu(i, 0, 3) s[i].init();
	fu(l, 1, min(n, m) >> 1) {
		p = l * l;
		fu(i, l, n - l) 
			fu(j, l, m - l) 
				ans[l].s[i][j] = s[0].S(i, j, i - l, j - l) == p && s[1].S(i, j + l, i - l, j) == p && s[2].S(i + l, j, i, j - l) == p && s[3].S(i + l, j + l, i, j) == p;			 
		ans[l].init();
	} 
	for(int x0, x1, y0, y1; q; --q) {
		rd(x0), rd(y0), rd(x1), rd(y1);
		int l = 1, r = min(x1 - x0 + 1, y1 - y0 + 1) >> 1, answer = 0, mid;
		while(l <= r) {
			mid = l + r >> 1;
			if(!ans[mid].S(x1 - mid, y1 - mid, x0 + mid - 2, y0 + mid - 2)) r = mid - 1;
			else l = mid + 1, answer = mid;  
		}
		printf("%d\n", 4 * answer * answer);
	}
	return 0;
}