#include <cstdio>
#include <cstring>

bool check(int n) {
	do {
		if (n%10!=7 && n%10!=4) return false;
		n/=10;
	}while (n);
	return true;
}

int main() {
	char buf[1000]; scanf("%s", buf);
	int t=0;
	for (int i=0; buf[i]; i++)
		if (buf[i]=='7' || buf[i]=='4') t++;
	if (check(t)) puts("YES");
	else puts("NO");
	return 0;
}