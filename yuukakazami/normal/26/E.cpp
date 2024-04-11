#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <cstdlib>
using namespace std;
const int MAX_N = 100;
int a[MAX_N];
void check(bool a) {
	if (!a) {
		puts("No");
		exit(0);
	}
}

int main() {
	int n, w;
	cin >> n >> w;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int sum = accumulate(a, a + n, 0);
	check(w >= 1);
	check(w <= sum);
	if (n == 1) {
		//only w==a[0] is possible!
		check(w == a[0]);
		puts("Yes");
		for (int i = 0; i < a[0] * 2; ++i) {
			printf("%d ", 1);
		}
		puts("");
		return 0;
	}
	int mi = min_element(a, a + n) - a;
	if (w == 1) {
		check(a[mi] == 1);
		puts("Yes");
		printf("%d ", mi + 1);
		for (int i = 0; i < n; ++i)
			if (i != mi) {
				for (int j = 0; j < a[i] * 2; ++j) {
					printf("%d ", i + 1);
				}
			}
		printf("%d ", mi + 1);
		puts("");
		return 0;
	}
	puts("Yes");
	//w>=2
	int needLoop = sum - w;
	//1..do-some-thing..222221211111112
	printf("1 ");
	for (int i = 2; i < n; ++i) {
		while (a[i] > 0 && needLoop > 0) {
			--a[i];
			--needLoop;
			printf("%d %d ", i + 1, i + 1);
		}
	}
	--a[0], --a[1];
	while (a[1] > 0 && needLoop > 0) {
		--a[1];
		--needLoop;
		printf("%d %d ", 2, 2);
	}
	printf("1 ");
	printf("2 ");

	while (a[0] > 0 && needLoop > 0) {
		--a[0];
		--needLoop;
		printf("%d %d ", 1, 1);
	}
	printf("2 ");
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < a[i] * 2; ++j) {
			printf("%d ", i + 1);
		}
	}
	puts("");
	return 0;
}