/*
 * olymp.cpp
 *
 *  Created on: 14.09.2011
 *      Author: zemen
 */

#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	/*
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
#endif
*/
	int n, max = 0;
	int a[2011];
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= n; ++i) {
		int cur = i;
		int h = 0;
		while (cur != -1) {
			++h;
			cur = a[cur];
		}
		if (max < h)
			max = h;
	}
	printf("%d", max);
}