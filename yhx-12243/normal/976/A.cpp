#include <bits/stdc++.h>
#define N 105
using namespace std;

int n;
char s[N];

int main() {
	int i, j = 0;
	scanf("%d%s", &n, s);
	if (*s == 48) putchar(48);
	else {
		for (i = 0; i < n; ++i) j += s[i] == 48;
		for (putchar(49); j; --j) putchar(48);
	}
	putchar(10);
	return 0;
}