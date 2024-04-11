#include <cstdio>
#include <cstring>

int main() {
	int n; char buf[10];
	scanf("%d", &n);
	int ret=0;
	while (n--) {
		scanf("%s", buf);
		if (buf[1]=='+') ret++;
		else ret--;
	}
	printf("%d\n", ret);
	return 0;
}