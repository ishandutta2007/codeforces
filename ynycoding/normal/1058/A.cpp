#include <cstdio>

int n;
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		int s;
		scanf("%d", &s);
		if(s==1) return puts("HARD"), 0;
	}
	puts("EASY");
	return 0;
}