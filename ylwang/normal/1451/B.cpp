#include<bits/stdc++.h>
#define For(i, j, k) for(int i = (j); i <= (k); i++)
using namespace std;
int read() {
	int x = 0; char c = ' ';
	for(; !isdigit(c); c = getchar()) ;
	for(; isdigit(c); c = getchar()) x = x * 10 - '0' + c;
	return x;
}
const int MAXN = 105;
int n, Q, s[MAXN];
signed main() {
	int T = read();
	while(T--) {
		n = read(), Q = read();
		For(i, 1, n) scanf("%1d", &s[i]);
		while(Q--) {
			int l = read(), r = read(), ans = 0;
			For(i, 1, l - 1) ans |= s[i] == s[l];
			For(i, r + 1, n) ans |= s[i] == s[r];
			printf(ans ? "YES\n" : "NO\n");
		}
	}
	return 0;
}