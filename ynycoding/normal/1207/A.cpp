#include <cstdio>
#include <algorithm>
int T, b, p, f, h, c;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d%d%d", &b, &p, &f, &h, &c);
		b/=2;
		if(h>c) if(p<=b) b-=p, f=std::min(f, b); else p=b, f=0;
		else if(f<=b) b-=f, p=std::min(p, b); else f=b, p=0;
		printf("%d\n", p*h+f*c);
	}
	return 0;
}