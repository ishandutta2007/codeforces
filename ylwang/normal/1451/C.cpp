#include<bits/stdc++.h>
#define For(i, j, k) for(int i = (j); i <= (k); i++)
using namespace std;
int read() {
	int x = 0; char c = ' ';
	for(; !isdigit(c); c = getchar()) ;
	for(; isdigit(c); c = getchar()) x = x * 10 - '0' + c;
	return x;
}
const int MAXN = 1e6 + 5;
int n, K, q[MAXN], p[MAXN]; char s[MAXN], t[MAXN];
signed main() {
	int T = read();
	while(T--) {
		For(i, 0, 100) q[i] = p[i] = 0;
		n = read(), K = read(); scanf("%s %s", s, t);
		For(i, 0, n - 1) p[s[i] - 'a']++;
		For(i, 0, n - 1) q[t[i] - 'a']++;
		int ans = 1;
		For(i, 0, 25) {
			if(p[i] < q[i] || ((p[i] -= q[i]) % K)) ans = 0;
			p[i + 1] += p[i];
		}
		printf(ans ? "Yes\n" : "No\n");
	}
	return 0;
}