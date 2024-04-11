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
	char s[25];
	scanf("%s", s);
	int res = 0;
	for (int i = 0; i < strlen(s); ++i)
		res += (s[i] == '4' || s[i] == '7');
	bool ans = 0;
	if (res == 4 || res == 7 || res == 47 || res == 44 || res == 74 || res == 77)
		ans = 1;
	if (ans)
		printf("YES");
	else
		printf("NO");
}