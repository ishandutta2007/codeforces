/*
 * main.cpp
 *
 *  Created on: 28.08.2011
 *      Author: zemen
 */

#include <stdio.h>
//#include <vector>
#include <string>
#include <memory.h>

//using namespace std;

int main () {
	char a[105], b[105];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	scanf("%s%s", a, b);
	int res = 0;
	for (int i = 0; i < 105; ++i) {
		char x = a[i], y = b[i];
		if (x >= 'a' && x <= 'z') {
			x -= 'a'-'A';
		}
		if (y >= 'a' && y <= 'z') {
			y -= 'a'-'A';
		}
		if (x > y) {
			printf("1");
			return 0;
		}
		if (x < y) {
			printf("-1");
			return 0;
		}
	}
	printf("0");
}