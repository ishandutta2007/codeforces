#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
ll k, s, c;

int main() {
	scanf("%d%d%lld", &n, &m, &k);
	if (k < n) printf("%lld 1\n", k + 1);
	else {
		s = (k - n) / (m - 1);
		c = (k - n) % (m - 1);
		printf("%lld %lld", n - s, s & 1 ? m - c : c + 2);
	}
	return 0;
}