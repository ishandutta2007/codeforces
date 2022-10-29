#include <cstdio>

int main() {
	char buf[1000];
	int n; scanf("%d%s", &n, buf);
	int ret=0;
	for (int i=0, j; i<n; i=j) {
		for (j=i; buf[j]==buf[i]; j++);
		ret+=j-i-1;
	}
	printf("%d\n", ret);
	return 0;
}