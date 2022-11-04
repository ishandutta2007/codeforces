#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n;
char str[105];

int main() {
	scanf("%d", &n);
	scanf("%s", str + 1);
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			reverse(str + 1, str + i + 1);
		}
	}
	
	printf("%s\n", str + 1);
	return 0;
}