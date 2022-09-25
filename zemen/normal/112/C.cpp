/*
 * main.cpp
 *
 *  Created on: 28.08.2011
 *      Author: zemen
 */
/*
#include <stdio.h>

int main() {
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	if (!((x == n / 2 || x == n / 2 + 1) && (y == n / 2 || y == n / 2 + 1))) {
		printf("YES");
		return 0;
	}
	printf("NO");
}
*/

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	long long n, x, y;
	cin >> n >> x >> y;
	if (y < n) {
		printf("-1");
		return 0;
	}
	long long max = y - n + 1;
	if (max * max + n - 1 >= x) {
		printf("%I64d\n", max);
		for (long long i = 1; i < n; ++i)
			printf("1\n");
		return 0;
	}
	printf("-1");
}