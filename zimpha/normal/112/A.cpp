#include <cctype>
#include <cstdio>
#include <cstring>

int main() {
	char s1[10000], s2[10000];
	scanf("%s%s", s1, s2);
	for (int i=0; s1[i]; i++)
		s1[i]=tolower(s1[i]);
	for (int i=0; s2[i]; i++)
		s2[i]=tolower(s2[i]);
	int t=strcmp(s1, s2);
	if (t<0) t=-1;
	else if (t>0) t=1;
	printf("%d\n", t);
	return 0;
}