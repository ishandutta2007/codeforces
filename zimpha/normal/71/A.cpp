#include <cstdio>
#include <cstring>

int main() {
	int n;
	char buf[1000];
	scanf("%d", &n);
	while (n--) {
		scanf("%s", buf);
		if ((int)strlen(buf)>10) {
			printf("%c%d%c\n", buf[0], (int)strlen(buf)-2, buf[strlen(buf)-1]);
		}
		else puts(buf);
	}
	return 0;
}