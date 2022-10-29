#include <cctype>
#include <cstdio>
#include <cstring>

int main() {
	char buf[10000];
	gets(buf);
	buf[0]=toupper(buf[0]);
	puts(buf);
	return 0;
}