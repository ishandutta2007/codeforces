#include <cstdio>
#include <algorithm>
int T, c, d;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &c, &d);
		if(!c&&!d) puts("0");
		else if(c==d) puts("1");
		else if((c+d)&1) puts("-1");
		else puts("2");
	}
	return 0;
}