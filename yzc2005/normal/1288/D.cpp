#include <bits/stdc++.h>
using namespace std;
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
typedef long long ll;
template <class T> inline void read(T &x) {
	x = 0; T f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
	while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	x *= f;
} 
template <class T> inline void print(T x) {
	if(x > 9) print(x / 10);
	putchar(x % 10 + 48);
}
 
const int N = 3e5 + 5, M = 10;
int n, m, a[N][M], f[N], whose[1 << M], ansi, ansj;
 
inline bool check(int mid) {
	memset(whose, 0, sizeof(whose));
	fu(i, 1, n) {
		f[i] = 0;
		fu(j, 0, m - 1) if(a[i][j] >= mid) f[i] |= 1 << j;
		whose[f[i]] = i;
	}
	int all = (1 << m) - 1; 
	fu(i, 1, n) 
		fu(j, 0, all)
			if(whose[j] && (f[i] | j) == all) {
				ansi = i, ansj = whose[j];
				return 1;
			}
	return 0;
}
 
int main() {
	read(n), read(m);
	fu(i, 1, n) fu(j, 0, m - 1) read(a[i][j]);
	int l = 0, r = 1e9;
	while(l <= r) {
		int mid = l + r >> 1;
		check(mid) ? l = mid + 1 : r = mid - 1;
	}
	print(ansi), printf(" "), print(ansj);
}