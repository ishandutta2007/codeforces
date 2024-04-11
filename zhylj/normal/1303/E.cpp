#include <bits/stdc++.h>

const int kMaxN = 1e3 + 5;
const int kInf = 0x3f3f3f3f;

char s[kMaxN], t[kMaxN]; int n, m;
int f[kMaxN][kMaxN];

bool Check(char a[], char b[], int k) {
	f[0][0] = 0;
	for(int i = 1; i <= k; ++i) f[0][i] = -kInf;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= k; ++j) {
			f[i][j] = f[i - 1][j];
			if(s[i] == a[j] && j > 0) f[i][j] = std::max(f[i][j], f[i - 1][j - 1]);
			if(f[i - 1][j] < m - k && f[i - 1][j] >= 0 && s[i] == b[f[i - 1][j] + 1])
				f[i][j] = std::max(f[i][j], f[i - 1][j] + 1);
		}
	return f[n][k] == m - k;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%s%s", s + 1, t + 1);
		n = strlen(s + 1), m = strlen(t + 1);
		bool flag = false;
		for(int i = 0; i < m; ++i)
			if(Check(t, t + i, i)) { flag = true; break; }
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}