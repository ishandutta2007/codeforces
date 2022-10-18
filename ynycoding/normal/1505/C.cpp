#include <cstdio>
#include <cmath>
#include <cstring>
char s[30];
int n;
int main()
{
	scanf("%s", s+1);
	n=strlen(s+1);
	if(n<=2) return puts("YES"), 0;
	for(int i=3; i<=n; ++i) if((s[i-2]+s[i-1]-'A')%26!=s[i]%26) return puts("NO"), 0;
	puts("YES");
	return 0;
}