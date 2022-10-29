#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int a[5], tot = 0;
	memset(a, 0, sizeof(a));
	for (int i = 0; i < n; ++ i) {
		int x; scanf("%d", &x);
		a[x] ++; tot += x;
	}
	if ((tot < 3 && tot > 0) || tot == 5) puts("-1");
	else {
		int ret = 0, tmp;
		tmp = min(a[1], a[2]); ret += tmp;
		a[1] -= tmp; a[2] -= tmp; a[3] += tmp;
		if (a[1]) a[3] += tmp = a[1] / 3, a[1] %= 3, ret += 2 * tmp + (!a[1] ? 0 : (a[1] == 1 && a[3] ? 1 : 2));
		if (a[2]) a[3] += 2 * (tmp = a[2] / 3), a[2] %= 3, ret += 2 * tmp + (!a[2] ? 0 : (a[2] == 1 && a[4] ? 1 : 2));
		printf("%d\n", ret);
	}
	return 0;
}