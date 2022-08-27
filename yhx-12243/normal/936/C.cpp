#include <bits/stdc++.h>
#define N 2005
#define orzscx 0
using namespace std;

int n, m;
char s[N], t[N];
char _s[N], _t[N];
int ord[N];
int cnt = 0, ans[10005];

inline int fail() {return putchar(45), putchar(49), 0;}

inline int find(int key) {for (int i = 0; i < n; ++i) if (ord[i] == key) return i; return -1;}

inline void push_back(int val) {ans[++cnt] = val; reverse(ord, ord + n); reverse(ord + val, ord + n);}

int main() {
	int i, j; char ch;
	scanf("%d%s%s", &n, s, t);
	memcpy(_s, s, n); sort(_s, _s + n);
	memcpy(_t, t, n); sort(_t, _t + n);
	if (memcmp(_s, _t, n)) return fail();
	for (i = 0; i < n; ++i)
		for (ch = t[n - i - 1], j = 0; j < n; ++j)
			if (s[j] == ch) {
				ord[j] = i; s[j] = 0; break;
			}
//	for (i = 0; i < n; ++i) printf("%d ", ord[i]); putchar(10);
	for (i = 0; i < n - 2; i += 2) {
		j = find(i + 1); push_back(n - j - 1);
		push_back(n - i);
		j = find(i); push_back(n - j);
		j = find(i); push_back(n - j);
		push_back(j - i);
	}
	if (i == n - 2 && ord[0] < ord[1]) push_back(n - 2), push_back(n);
	printf("%d\n", cnt);
	for (i = 1; i <= cnt; ++i) printf("%d%c", ans[i], i == cnt ? 10 : 32);
	return orzscx;
}