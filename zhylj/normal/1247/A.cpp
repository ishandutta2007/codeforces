#include <bits/stdc++.h>

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	if(a == 9 && b == 1) printf("9 10");
	else if(a == b) printf("%d1 %d2", a, b);
	else if(a + 1 == b) printf("%d %d", a, b);
	else printf("-1");
	return 0;
}