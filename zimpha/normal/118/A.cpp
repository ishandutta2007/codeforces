#include <cctype>
#include <cstdio>
#include <cstring>

int main() {
	char buf[1000];
	scanf("%s", buf);
	for (int i=0; buf[i]; i++) {
		buf[i]=tolower(buf[i]);
		if (buf[i]!='a' && buf[i]!='o' && buf[i]!='y' && buf[i]!='e' && buf[i]!='u' && buf[i]!='i') {
			printf(".%c", buf[i]);
		}
	}
	puts("");
	return 0;
}