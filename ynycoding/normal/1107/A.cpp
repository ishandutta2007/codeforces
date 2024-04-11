#include <bits/stdc++.h>
#define MAXN 3001
int n, t;
char s[MAXN];
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%s", &n, s);
		if(n<=2)
		{
			if(s[0]<s[1])
			{
				puts("YES\n2");
				printf("%c %s\n", s[0], s+1);
			}
			else puts("NO");
		}
		else
		{
			puts("YES\n2");
			printf("%c %s\n", s[0], s+1);
		}
	}
	return 0;
}