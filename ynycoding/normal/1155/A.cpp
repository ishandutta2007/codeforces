#include <cstdio>
#include <cstring>
#define MAXN 300005
char s[MAXN], c;
int n, idx;
int main()
{
	scanf("%d%s", &n, s);
	c=s[0], idx=1;
	for(int i=1; i<n; ++i)
	{
		if(s[i]<c) return printf("YES\n%d %d", idx, i+1), 0;
		if(s[i]>c) c=s[i], idx=i+1;
	}
	puts("NO");
	return 0;
}