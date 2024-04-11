#include <bits/stdc++.h>
using namespace std;
int a, b;
 
int main() {
	scanf("%d%d", &a, &b);
	if(a == 9 && b == 1) {
		printf("9 10\n");
	}
	else if(a + 1 == b) printf("%d %d\n", a, b);
	else if(a == b) printf("%d1 %d2\n", a, b);
	else puts("-1");
	return 0;
}