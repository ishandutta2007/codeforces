#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	int k, a, b, v;
	scanf("%d%d%d%d", &k, &a, &b, &v);
	int need = a / v + (!!(a % v));
	for (int ret = 1; ; ++ ret) {
		int has = ret * k;
		if (b % ret == 0) has = min(has, (b / ret + 1) * ret);
		else has = min(has, (b / ret + 1) * ret + b % ret);
		if (has >= need) {
			printf("%d\n", ret);
			break;
		}
	}
	return 0;
}