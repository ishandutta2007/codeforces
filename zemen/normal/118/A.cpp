/*
 * olymp.cpp
 *
 *  Created on: 23.09.2011
 *      Author: zemen
 *
 *  Codeforces Beta Round #89(div. 2, out of competition)
 */
#include <stdio.h>

int main() {
	char s[102];
	gets(s);
	int cur = 0;
	while (s[cur]) {
		if (s[cur] <= 'Z') {
			s[cur] += 'a' - 'A';
		}
		if (s[cur] == 'a' || s[cur] == 'o' || s[cur] == 'y' || s[cur] == 'e' || s[cur] == 'u' || s[cur] == 'i') {
			++cur;
			continue;
		}
		printf(".%c", s[cur]);
		++cur;
	}
}