# include <cstdio>
const int MN = 3e6 + 44;
int count[MN];
long long ways[MN];
long long ans[MN];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		count[x] ++;
	}
	for (int i = 1; i < MN; ++i) {
		for (int k = i; k < MN; k += i) {
			ways[k] += count[i] * (long long)count[k / i];
			if (k / i == i) {
				ways[k] -= count[i];
			}
		}
	}
	ans[1] = n * (n - 1LL);
	for (int i = 2; i < MN; ++i) {
		ans[i] = ans[i - 1] - ways[i - 1];
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int x;
		scanf("%d", &x);
		printf("%I64d\n", ans[x]);
	}
}