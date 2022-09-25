/*
 * main.cpp
 *
 *  Created on: 28.08.2011
 *      Author: zemen
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main () {
	int n;
	scanf("%d", &n);
	int y;
	for (int x = n / 7; x >= 0; --x) {
		y = (n - x * 7) / 4;
		if (x * 7 + y * 4 == n) {
			for (int i = 0; i < y; ++i)
				printf("4");
			for (int i = 0; i < x; ++i)
				printf("7");
			return 0;
		}
	}
	printf("-1");
}