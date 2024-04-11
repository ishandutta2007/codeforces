#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
char str[1000005];

int main() {
	scanf("%d", &n);
	scanf("%s", str + 1);
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (str[i] > str[i + 1]) {
			ans = i;
			break;
		}
	}
	
	if (ans == 0) {
		ans = n;
	}
	
	for (int i = 1; i <= n; i++) {
		if (i != ans) {
			printf("%c", str[i]);
		}
	}
		
	printf("\n");
	return 0;
}