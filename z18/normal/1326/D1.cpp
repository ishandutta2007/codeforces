#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6;
int T, n, m, o, mx, p[maxn + 3], c[maxn + 3];
char s[maxn + 3];
bool mrk[maxn + 3];

int main() {
	scanf("%d", &T);
	while (T --> 0) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		for (int i = n; i; i--) {
			s[i * 2 - 1] = s[i], s[i * 2] = '#';
		}
		s[n * 2] = '.';
		s[0] = '$';
		m = n * 2 - 1;
		for (int i = 1; i < n * 2; i++) {
			c[i] = c[i - 1] + (s[i] >= 'a' && s[i] <= 'z');
			mrk[i] = false;
		}
		int L = 0, R = m + 1;
		while (L < R) {
			if (s[L + 1] == s[R - 1]) L++, R--;
			else break;
		}
		mx = 0, o = 0;
		int ans = 0, res = 0;
		for (int i = 1; i < n * 2; i++) {
			if (i <= mx) {
				p[i] = min(mx - i + 1, p[o * 2 - i]);
			} else {
				p[i] = 1;
			}
			while (s[i - p[i]] == s[i + p[i]]) p[i]++;
			if (i + p[i] - 1 > mx) {
				mx = i + p[i] - 1, o = i;
			}
			if ((i - p[i] <= L || i + p[i] >= R) && (c[i + p[i] - 1] - c[i - p[i]]) + min(c[i - p[i]], c[m] - c[i + p[i] - 1]) * 2 > ans) {
				ans = (c[i + p[i] - 1] - c[i - p[i]]) + min(c[i - p[i]], c[m] - c[i + p[i] - 1]) * 2, res = i;
			}
		}
		for (int i = 0; i < p[res]; i++) {
			mrk[res - i] = mrk[res + i] = true;
		}
		for (int i = 0; i < min(res - p[res], m - (res + p[res] - 1)); i++) {
			mrk[i + 1] = mrk[m - i] = true;
		}
		for (int i = 1; i <= m; i++) if (mrk[i] && (s[i] >= 'a' && s[i] <= 'z')) putchar(s[i]);
		puts("");
	}
	return 0;
}