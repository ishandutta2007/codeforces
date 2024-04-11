#include <bits/stdc++.h>
using namespace std;

const int N = 1000005, P1 = 1e9 + 7, P2 = 1e9 + 9, base = 2333;
int t, n, p[N << 1], cnt;
char a[N], s[N << 1];

int main() {
	scanf("%d", &t); while(t--) {
		scanf("%s", a + 1); n = strlen(a + 1);	
		s[0] = s[1] = '@', cnt = 1;
		for(int i = 1; i <= n; ++i) s[++cnt] = a[i], s[++cnt] = '@';
		s[cnt + 1] = '\0';
		fill(p + 1, p + cnt + 1, 0);
		for(int i = 1, mid = 0, r = 0; i <= cnt; ++i) {
			if(i <= r) p[i] = min(r - i + 1, p[(mid << 1) - i]);
			while(s[i - p[i]] == s[i + p[i]]) ++p[i];
			if(i + p[i] - 1 > r) r = i + p[i] - 1, mid = i;
		}
		int len = 0;
		for(int i = 1; i <= cnt; ++i) if(s[i] != s[cnt - i + 1]) {len = i - 1; break;}
		int ans = 0, l1, r1, l2, r2; 
		for(int i = 1; i <= cnt; ++i) {
			int l = i - p[i], r = i + p[i], rp = r; r = cnt - r + 1;
			if(l <= r) {
				if(len < l) continue;
				int chk = p[i] - 1 + (l / 2) * 2;
				if(ans < chk) {
					ans = chk; 
					l1 = 1, r1 = rp - 1, l2 = cnt - l + 1, r2 = cnt;
				}
			} else {
				if(len < r) continue;
				int chk = p[i] - 1 + (r / 2) * 2;
				if(ans < chk) {
					ans = chk;
					l1 = 1, r1 = r, l2 = l + 1, r2 = cnt;
				}
			}
		}
		for(int i = l1; i <= r1; ++i) if(s[i] != '@') putchar(s[i]);
		for(int i = l2; i <= r2; ++i) if(s[i] != '@') putchar(s[i]);
		puts("");
	}
	return 0;
}