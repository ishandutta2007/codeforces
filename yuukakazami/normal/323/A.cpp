#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int main() {
	int k;
	cin >> k;
	if (k % 2 == 1) {
		return puts("-1"), 0;
	}
	const char col[] = "bw";
	for (int i = 0; i < k; ++i) {
		for (int a = 0; a < k; ++a) {
			for (int b = 0; b < k; ++b) {
				putchar(
						col[(i + max(abs(2 * a - k + 1), abs(2 * b - k + 1)) / 2)
								% 2]);
			}
			puts("");
		}
		puts("");
	}
	return 0;
}