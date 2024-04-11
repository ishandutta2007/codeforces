#include <bits/stdc++.h>

typedef long double ff;
typedef long long ll;

const int kMaxN = 1e5 + 5;
const ff kInf = 1e11;
const ff kEps = 1e-16;

ll x[kMaxN], y[kMaxN];

ff GetK(int i, int j) {
	if(x[i] == x[j]) return kInf;
	return (y[i] - y[j]) / (ff)(x[i] - x[j]);
}
ff Modl(int i, int j) {
	return (y[i] - y[j]) * (y[i] - y[j]) + (x[i] - x[j]) * (x[i] - x[j]);
}
ff Abs(ff w) { return w > 0 ? w : -w; }

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%lld%lld", x + i, y + i);
	if(n % 2 != 0) printf("NO");
	else {
		bool flag = true;
		for(int i = 1; i <= n / 2; ++i) {
			if(Abs(GetK(i, i + 1) - GetK(i + n / 2, (i + n / 2) % n + 1)) > kEps ||
				Abs(Modl(i, i + 1) - Modl(i + n / 2, (i + n / 2) % n + 1)) > kEps) {
				//printf("%d %d %d %d %lf %lf\n", i, i + 1, i + n / 2, i + n / 2 + 1, Modl(i, i + 1), Modl(i + n / 2, i + n / 2 + 1));
				flag = false; break;
			}
		}
		if(flag) printf("YES");
		else printf("NO");
	}
	return 0;
}