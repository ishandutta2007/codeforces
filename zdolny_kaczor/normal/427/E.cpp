# include <cstdio>
# include <algorithm>
using namespace std;
const int MN = 1e6 + 44;
int a[MN];
int n, m;
long long dist(long long int x) {
// 	printf("dist %d\n", x);
	long long result = 0;
	for (int i = 0; i < n && a[i] <= x; i += m) {
// 		printf("add 2*(x - a[%d]) = 2*(%d - %d) = %d\n", i, x, a[i], 2 * (x - a[i]));
		result += 2 * (x - a[i]);
	}
	for (int i = n - 1; i >= 0 && a[i] >= x; i -= m) {
// 		printf("add 2*(a[%d] - x) = 2*(%d - %d) = %d\n", i, a[i], x, 2 * (a[i] - x));
		result += 2 * (a[i] - x);
	}
// 	printf("return %I64d\n", result);
	return result;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	sort(a, a + n);
	long long int low = -1e9 - 44, high = 1e9 + 44;
	while (low + 20 < high) {
		long long int spl1 = (low * 2 + high) / 3;
		long long int spl2 = (low + high * 2) / 3;
// 		printf("%d - %d - %d - %d\n", low, spl1, spl2, high);
		long long eval1 = dist(spl1);
		long long eval2 = dist(spl2);
		if (eval1 > eval2) {
			low = spl1;
		}
		else {
			high = spl2;
		}
	}
	long long res = 1LL << 60;
// 	printf("left with %d - %d\n", low, high);
	for (int i = low; i <= high; ++i) {
		res = min(res, dist(i));
	}
	printf("%I64d\n", res);
}