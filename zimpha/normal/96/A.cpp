#include <cstdio>

int main() {
	char buf[1000]; scanf("%s", buf);
	for (int i=0, j; buf[i]; i++) {
		for (j=i; buf[i]==buf[j]; j++);
		if (j-i>=7) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}