#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int n, p[maxn + 3], nxt[maxn + 3], l[maxn + 3], num[maxn + 3];
char s[maxn + 3], t[maxn + 3];

void manacher(char s[], int n) {
	int pos = 0, mx = 0;
	s[0] = '$';
	for (int i = 1; i <= n; i++) {
		p[i] = i <= mx ? min(p[2 * pos - i], mx - i + 1) : 1;
		while (s[i - p[i]] == s[i + p[i]]) p[i]++;
		if (i + p[i] - 1 > mx) {
			pos = i, mx = i + p[i] - 1;
		}
	}
}

void kmp(char s[], int n) {
	copy(s + 1, s + n + 1, t + 1);
	reverse(t + 1, t + n + 1);
	for (int i = 2, k = 0; i <= n; i++) {
		while (k && t[k + 1] != t[i]) k = nxt[k];
		if (t[k + 1] == t[i]) k++;
		nxt[i] = k;
	}
	for (int i = 1, k = 0; i <= n; i++) {
		while (k && t[k + 1] != s[i]) k = nxt[k];
		if (t[k + 1] == s[i]) k++;
		l[i] = k;
	}
}

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	manacher(s, n);
	kmp(s, n);
	l[0] = 0;
	for (int i = 1; i <= n; i++) {
		num[i] = l[i] >= l[i - 1] ? i : num[i - 1];
		l[i] = max(l[i], l[i - 1]);
	}
	int res = 0, a = 0, b = 0, c = 0, x = 0, y = 0, z = 0;
	for (int i = 1; i <= n; i++) {
		int t = min(l[i - p[i]], n + 1 - i - p[i]);
		if (p[i] * 2 - 1 + t * 2 > res) {
			res = p[i] * 2 - 1 + t * 2;
			a = num[i - p[i]] - t + 1, x = t;
			b = i - p[i] + 1, y = p[i] * 2 - 1;
			c = n - t + 1, z = t;
		}
	}
	int cnt = (x != 0) + (y != 0) + (z != 0);
	printf("%d\n", cnt);
	if (x) printf("%d %d\n", a, x);
	if (y) printf("%d %d\n", b, y);
	if (z) printf("%d %d\n", c, z);
	return 0;
}