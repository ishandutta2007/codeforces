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
	int c = 'a';
	for (int i = 0; i < n; ++i) {
		if (c == 'e')
			c = 'a';
		printf("%c", c);
		++c;
	}
}