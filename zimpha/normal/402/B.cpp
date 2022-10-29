#include <cstdio>
#include <cstring>

int main() {
	int n, k, a[2000];
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++ i) scanf("%d", &a[i]);
	int ret = 10000, hh;
	for (int h0 = 1; h0 <= 1000; ++ h0) {
		int tmp = 0;
		for (int i = 0, h = h0; i < n; ++ i) {
			if (a[i] != h) tmp ++;
			h += k;
		}
		if (tmp < ret) {
			ret = tmp;
			hh = h0;
		}
	}
	printf("%d\n", ret);
	for (int i = 0, h = hh; i < n; ++ i) {
		if (a[i] > h) printf("- %d %d\n", i + 1, a[i] - h);
		else if (a[i] < h) printf("+ %d %d\n", i + 1, h - a[i]);
		h += k;
	}
	return 0;
}