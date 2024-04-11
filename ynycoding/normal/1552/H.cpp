#include <cstdio>
#include <algorithm>
int x, y, s, ans[9];
inline void ask(int k)
{
	printf("? %d\n", (200>>k)*200);
	for(int i=1<<k; i<=200; i+=1<<k) for(int j=1; j<=200; ++j)
		printf("%d %d\n", i, j);//, x+=calc(i, j);
	puts("");
	fprintf(stderr, "%d\n", k);
	fflush(stdout);
	scanf("%d", &x);
}
int main()
{
	int l=0, r=7;
	ask(0);
	s=x;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		x=0;
		ask(mid);
		ans[mid]=x;
		if((x<<mid)==s) l=mid;
		else r=mid-1;
	}
	y=std::abs((ans[l+1]<<1)-(s>>l));
	x=s/y;
	printf("! %d\n", 2*(x+y-2));
	return 0;
}