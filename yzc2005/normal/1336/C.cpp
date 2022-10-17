#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
inline void add(int &a, int b) { (a += b) >= mod && (a -= mod); }

const int N = 3005;
int n, m, f[N][N], ans;
char s[N], t[N]; 

int main() {
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1), m = strlen(t + 1);
	for(int i = 1; i <= n; ++i) f[i][i] = (i > m || s[1] == t[i]) * 2;
	for(int len = 2; len <= n; ++len) 
		for(int i = 1, j = len; j <= n; ++i, ++j) {
			if(j > m || s[len] == t[j]) add(f[i][j], f[i][j - 1]);
			if(i > m || s[len] == t[i]) add(f[i][j], f[i + 1][j]);
		}
	for(int i = m; i <= n; ++i) add(ans, f[1][i]);
	printf("%d", ans);
}