#include <cstdio>

int main() {
	char buf[1000]; gets(buf);
	bool flag=false;
	for (int i=0; !flag && buf[i]; i++)
		if (buf[i]=='H' || buf[i]=='Q' || buf[i]=='9') flag=true;
	if (flag) puts("YES");
	else puts("NO");
	return 0;
}