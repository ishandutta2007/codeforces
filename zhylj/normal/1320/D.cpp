#include <bits/stdc++.h>

typedef long long ll;

const int kN = 2e5 + 5;
const ll kMod = 998244353;
const ll kBas = rand() % 998244353;

char c[kN]; ll s[2][kN], tot[kN], p[kN];

ll Query(int i, int x, int L) {
	return (s[i][x + L - 1] - s[i][x - 1] + kMod) % kMod;
}

int main() {
	int n, q; p[0] = 1;
	scanf("%d%s%d", &n, c + 1, &q);
	for(int i = 1; i <= n; ++i) p[i] = p[i - 1] * kBas % kMod;
	for(int i = 1, tmp = 1; i <= n; ++i) {
		tot[i] = tot[i - 1] + (c[i] == '0');
		if(c[i] == '0') {
			s[0][i] = (s[0][i - 1] + ((i & 1) + 1) * tmp % kMod) % kMod;
			s[1][i] = (s[1][i - 1] + ((~i & 1) + 1) * tmp % kMod) % kMod;
			tmp = tmp * kBas % kMod;
		} else s[0][i] = s[0][i - 1], s[1][i] = s[1][i - 1];
	}
	while(q--) {
		int a, b, L, i, j, tot_0;
		scanf("%d%d%d", &a, &b, &L);
		if(a > b) std::swap(a, b);
		tot_0 = tot[b - 1] - tot[a - 1];
		if(Query(a & 1, a, L) * p[tot_0] % kMod == Query(b & 1, b, L)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}