#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

int main() {
	int n, x, sum;
	scanf("%d%d", &n, &x);
	sum = 0;
	for (int i = 0, a; i < n; ++ i) {
		scanf("%d", &a);
		sum += a;
	}
	if (sum < 0) sum = -sum;
	if (sum % x) printf("%d\n", sum / x + 1);
	else printf("%d\n", sum / x);
	return 0;
}