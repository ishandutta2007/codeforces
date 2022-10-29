#include <cctype>
#include <cstdio>
#include <cstring>

int main() {
	char buf[1000];
	int n;
	scanf("%s", buf); n=strlen(buf);
	for (int i=0; buf[i]; i++) {
		if (isupper(buf[i])) n--;
	}
	if (n==0 || (n==1 && islower(buf[0]))) {
		if (n!=0) putchar(toupper(buf[0]));
		else putchar(tolower(buf[0]));
		for (int i=1; buf[i]; i++)
			putchar(tolower(buf[i]));
		puts("");
	}
	else puts(buf);
	return 0;
}