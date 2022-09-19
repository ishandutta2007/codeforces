# include <bits/stdc++.h>
using namespace std;
bool pr(int p) {
	for (int i = 2; i * i <= p; ++i)
		if (p % i == 0)
			return false;
	return true;
}
int cou = 0;
int calc(int n, int p) {
	cou++;
	if (n < p) {
		return min(n, 1);
	}
	int res = n;
	for (int i = 2; i < p; ++i)
		if (pr(i))
			res -= calc(n / i, i);
	return res;
}
int main() {
	int a, b, k;
	scanf("%d%d%d", &a, &b, &k);
	if (pr(k))
		printf("%d\n", calc(b / k, k) - calc((a - 1) / k, k));
	else
		printf("0\n");
	fprintf(stderr, "%d turns\n", cou);
}