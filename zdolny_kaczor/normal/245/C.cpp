# include <bits/stdc++.h>
using namespace std;
const int MN = 1e2 + 4;
int a[MN];
int main() {
	int n;
	scanf("%d", &n);
	if (n == 1 || n % 2 == 0) {
		printf("-1\n");
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	int count = 0;
	for (int k = n; k > 1; --k) {
		int x = k / 2;
		while (a[k] > 0) {
			a[x]--;
			a[x * 2]--;
			a[x * 2 + 1]--;
			count++;
		}
	}
	printf("%d\n", count + max(a[1], 0));
}